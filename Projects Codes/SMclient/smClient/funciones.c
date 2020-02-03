/* Funciones de creación, gestión y acceso a memorias compartidas
 * Autor: ErosHack
 * 
 * Descripción: 
 * Las siguientes funciones ayudan a:
 * 1) GESTIONAR la memoria total requerida para crear todas las 
 * memorias compartidas deseadas por el usuario.
 * 2) CREAR cada una de las memorias requeridas por el usuario
 * 3) ACCESO a lectura y escritura en las memorias creadas
 * por medio de la utilización de funciones.
 * la secuencia del uso del gestor de memorias compartidas es:
 * createMemoria() -> lectura/escritura -> freeMemorias()
 * 
 * 
 * Propósito: 
 * Se realiza un archivo de funciones separado al programa 
 * principal por motivo de centralizacion de tarea, al tener 
 * las funciones separadas del programa principal luego 
 * estas funciones podrán ser utilizadas tanto para la cración
 * de una .dll con cabeceras estándares, o la creación de una 
 * .dll con cabeceras para acceso de applicaciones en lenguaje
 * de programación Java, o a su vez se puede utilizar en 
 * otros proyectos independientes, teniendo centralizado
 * todo el proceso en este archivo y su cabecera de acceso.
 * En nuestro caso para la creación de la librería con cabeceras
 * estándares y la librería para acceso desde JAVA utilizan 
 * estas funciones sin realizar ningún cambio en las mismas
 * (centralización, abstracción y aislamiento de responsabilidades)
 * 
 * Como se realizará:
 * Para aislar todas las funciones del programa(s) principales
 * se declararán funciones estándares con su respectiva
 * implementación sin tener en cuenta ningún tipo de utilización
 * específica a futuro, quedando disponible su utilización
 * en cualquer proyecto futuro.
 * 
 * 
 * 
 * */


#include "functions.h"
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <tchar.h>

#define Palabra 13 //muestra el límite de caracteres para las memorias
				  // de tipo char* (string)

/*
 *hFile, esta variable unirá todas las memorias a ser creadas
 *por tanto esta será gestionada al inicio para que poseea el 
 *tamaño total (número total de memorias, cantidad), se gestiona 
 *su tamaño en la funcion funcion gestionMemoria(int cantidad)
*/

struct nodoMem{
	HANDLE hMem;
	struct nodoMem *siguiente;
};

/*
 * nodoHandle, con la ayuda de esta estructura se manejará
 * cada memoria para ser abierta y utilizada este guarda el acceso a la memoria
*/
struct nodoMap{
    HANDLE hMap;          //Esta variable apuntará a la memoria a ser abierta
    struct nodoMap *siguiente; // puntero auxiliar para crear una lista (gestión dinámica de memoria)
};

/*
 * nodos, esta estructura se utilizará para gestionar la vista a las memorias abiertas
 * una vez abierta una memoria se debe crear una vista para permitir leer y escribir
 * en Dicha memoria, estas vistas se gestionaran en este nodo
*/
struct nodoView{
    void *hView;
    char nombre[13];
    struct nodoView *siguiente;
};

typedef struct  strValues{
	char variable[Palabra];
} typeString;

//para gestionar nodos dinámicamente y no perder su inicio y final
//se utiliza dos nodos principal para el inicio y final de la cola
struct nodoMap *cabezaMap = NULL;

//para gestionar nodos dinámicamente y no perder su inicio y final
//se utiliza dos nodos principal para el inicio y final de la cola
struct nodoView *cabezaVista = NULL;

struct nodoMem *cabezaMem = NULL;

/* Abre un objeto mapeado en memoria y a la vez crea una vista del mismo
 * para permitir leer y escribir en las memorias compartidas
 * 
 * Para poder acceder a una memoria es necesario mapera el objeto (la memoria)
 * en una variable tipo HANDLE y luego de esto crear una vista hacia la memoria
 * para poder leer y escribir valores
 * 
 * Para esto se gestiona dos nuevos nodos, uno tipo nodoHandle que maneragá el mapeo
 * del objeto en memoria y un nodo tipo nodoView para creará la vista para manipulación
 * de los datos en la memoria, luego de gestionar estos dos objetos, son agregados a sus
 * correspondientes listas.
 */
int openMemoria(char *nombre, int tipo){
    //agregacion de nodo handle
    struct nodoMap *nuevoMap; //Para abrir el objeto mapeado en Memoria
    struct nodoView *nuevaView;     //Para gestionar la nueva vista al objeto mapeado en memoria

    nuevoMap = (struct nodoMap *)malloc(sizeof(struct nodoMap)); //Gestion de memoria para el nuevo nodo
	
	//Documentacion oficial de la funcion OpenFileMapping (Se abre un objeto mapeado en memoria)
	//https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-openfilemappinga
    nuevoMap->hMap = OpenFileMapping(FILE_MAP_ALL_ACCESS, //Acceso modo lectura y escritura
                            FALSE,  //No se hereda el nombre
                            _T(nombre));  //Nombre del objeto mapeado

									// siempre apuntará a null
    if(nuevoMap->hMap == NULL){ //Control de errores, si regresa NULL es porque no se pudo mapear la memoria
        printf("No se puede acceder a memoria:  \n");
        return 1;
    }else{
        printf("Memoria abierta\n");
    }
	nuevoMap->siguiente = cabezaMap; //como se utiliza una memoria dinámica tipo lista, el ultimo nodo ingresado 
    cabezaMap = nuevoMap;
	
	////Creación de nueva vista
	nuevaView = (struct nodoView *)malloc(sizeof(struct nodoView)); //Necesitamos gestionar la memoria de la nueva vista
	strcpy(nuevaView->nombre,nombre); //Guardamos el nombre de la memoria de la vista
				
    switch(tipo){
        case 1:
                nuevaView->hView = (int *)MapViewOfFile(nuevoMap->hMap,
                                     FILE_MAP_ALL_ACCESS, 
                                     0,
                                     0,
                                     0);
                break;
        case 2:
                nuevaView->hView = (float *)MapViewOfFile(nuevoMap->hMap,
                                     FILE_MAP_ALL_ACCESS,
                                     0,
                                     0,
                                     0);
                break;
        case 3:
                nuevaView->hView = (double *)MapViewOfFile(nuevoMap->hMap,
                                     FILE_MAP_ALL_ACCESS,
                                     0,
                                     0,
                                     0);
                break;

		case 4:
                nuevaView->hView = (typeString *)MapViewOfFile(nuevoMap->hMap,
                                     FILE_MAP_ALL_ACCESS,
                                     0,
                                     0,
                                     0);
                break;

    }

	if(nuevaView->hView == NULL){
		printf("No se puede hacer casting al handler\n");
		return 1;
	}else{
		printf("Acceso a memoria listo!\n");
	}
	
	nuevaView->siguiente = cabezaVista;
	cabezaVista = nuevaView;

    return 0;
}


int leerIntValue(char *nomMemoria, int posicion){
    struct nodoView *auxiliarInt;
    auxiliarInt = cabezaVista;
    int bandSalirTipo = 0;
    int valor=0;
    while(auxiliarInt != NULL && bandSalirTipo == 0){
        if(strcmp(auxiliarInt->nombre,nomMemoria)==0){
            valor = *( (int *)auxiliarInt->hView + posicion);
            bandSalirTipo = 1;
        }
        if(bandSalirTipo==0){
            auxiliarInt = auxiliarInt->siguiente;
        }
   }
    return valor;
}

void escribirIntValue(char *nomMemoria, int posicion,int valor){
    struct nodoView *auxiliarInt;
    auxiliarInt = cabezaVista;
    int bandSalirTipo = 0;
    while(auxiliarInt != NULL && bandSalirTipo == 0){
        if(strcmp(auxiliarInt->nombre,nomMemoria)==0){
            *( (int *)auxiliarInt->hView + posicion) = valor;
            bandSalirTipo = 1;
        }
        if(bandSalirTipo==0){
            auxiliarInt = auxiliarInt->siguiente;
        }
   }

}

void escribirFloatValue(char *nomMemoria, int posicion, float valor){
    struct nodoView *auxiliarFloat;
    auxiliarFloat = cabezaVista;
    int bandSalirTipo = 0;
    while(auxiliarFloat != NULL && bandSalirTipo == 0){
        if(strcmp(auxiliarFloat->nombre,nomMemoria)==0){
            *( (float *)auxiliarFloat->hView + posicion) = valor;
            bandSalirTipo = 1;
        }
        if(bandSalirTipo==0){
            auxiliarFloat = auxiliarFloat->siguiente;
        }
   }

}

float leerFloatValue(char *nomMemoria, int posicion){
    struct nodoView *auxiliarFloat;
    auxiliarFloat = cabezaVista;
    int bandSalirTipo = 0;
    float valor=0;
    while(auxiliarFloat != NULL && bandSalirTipo == 0){
        if(strcmp(auxiliarFloat->nombre,nomMemoria)==0){
            valor = *( (float *)auxiliarFloat->hView + posicion);
            bandSalirTipo = 1;
        }
        if(bandSalirTipo==0){
            auxiliarFloat = auxiliarFloat->siguiente;
        }
   }
    return valor;
}

void escribirDoubleValue(char *nomMemoria, int posicion, double valor){
    struct nodoView *auxiliarDouble;
    auxiliarDouble = cabezaVista;
    int bandSalirTipo = 0;
    //printf("valor double %lf \n",valor);
    while(auxiliarDouble != NULL && bandSalirTipo == 0){
        if(strcmp(auxiliarDouble->nombre,nomMemoria)==0){
            //printf("Encontro double");
            *( (double *)auxiliarDouble->hView + posicion) = valor;
            bandSalirTipo = 1;
        }
        if(bandSalirTipo==0){
            auxiliarDouble = auxiliarDouble->siguiente;
        }
   }

}

double leerDoubleValue(char *nomMemoria, int posicion){
    struct nodoView *auxiliarDouble;
    auxiliarDouble = cabezaVista;
    int bandSalirTipo = 0;
    double valor=0.0;
    while(auxiliarDouble != NULL && bandSalirTipo == 0){
        if(strcmp(auxiliarDouble->nombre,nomMemoria)==0){
            valor = *( (double *)auxiliarDouble->hView + posicion);
            bandSalirTipo = 1;
        }
        if(bandSalirTipo==0){
            auxiliarDouble = auxiliarDouble->siguiente;
        }
   }
    return valor;
}

void escribirStringValue(char *nomMemoria, int posicion, char *str){
    struct nodoView *auxiliarString;
    auxiliarString = cabezaVista;
	typeString tmp;
    int bandSalirTipo = 0;
    //printf("valor cadena %s \n",str);
    while(auxiliarString != NULL && bandSalirTipo == 0){
        if(strcmp(auxiliarString->nombre,nomMemoria)==0){
            //printf("Encontro double");
			         //   *( (double *)auxiliarDouble->hView + posicion) = valor;
			//printf("Entro a guardar \n");
			strcpy(tmp.variable,str);
			*( (typeString *)auxiliarString->hView + posicion) = tmp;
            //strcpy(*( (newType *)auxiliarString->hView + posicion)->variable,prueba);
            bandSalirTipo = 1;
            //printf("Palabra guardada\n");
        }
        if(bandSalirTipo==0){
            auxiliarString = auxiliarString->siguiente;
        }
   }
}

void leerStringValue(char *nomMemoria, int posicion, char *str){
    struct nodoView *auxiliarString;
    auxiliarString = cabezaVista;
	typeString tmp;
    int bandSalirTipo = 0;
    while(auxiliarString != NULL && bandSalirTipo == 0){
        if(strcmp(auxiliarString->nombre,nomMemoria)==0){
            //str = strdup(auxiliarString->hView[posicion]);
			//valor = *( (double *)auxiliarDouble->hView + posicion);
			tmp = *( (typeString *)auxiliarString->hView + posicion);
            strcpy(str,tmp.variable);
			//printf("Valor guardado %s \n", tmp.variable);
            bandSalirTipo = 1;
        }
        if(bandSalirTipo==0){
            auxiliarString = auxiliarString->siguiente;
        }
   }
}


void readStringValMatlab(char *nomMemoria, int posicion, char **str){
    struct nodoView *auxiliarString;
    auxiliarString = cabezaVista;
	typeString tmp;
    int bandSalirTipo = 0;
    while(auxiliarString != NULL && bandSalirTipo == 0){
        if(strcmp(auxiliarString->nombre,nomMemoria)==0){
            tmp = *( (typeString *)auxiliarString->hView + posicion);
            *str = strdup(tmp.variable);
            bandSalirTipo = 1;
        }
        if(bandSalirTipo==0){
            auxiliarString = auxiliarString->siguiente;
        }
   }

}


/* Esta función gestiona el espacio requerido por cada Memoria. Ejmp
 * La "Memoria0" contendrá 5 valores tipo Entero, entonces es necesario gestionar
 * un espacio en memoria que se llame "Memoria0" y que pueda contener 5 valores tipo Entero
 * 
 * Al estar trabajando con memoria dinámica, es necesario gestionar los espacios
 * de los punteros.
 * 
 * Para lorar esto solo se utiliza el nombre de acceso global que se va a asignar a la Memoria
 * la cantidad de valores que almacenará y el tipo de valor a ser almacenado.
 */
int createMemoria(char *nombre, int cantidad, int tipo){
        int tamanio; //Contendrá el tamanio requerido dependiendo del tipo de variable
        switch(tipo){
                case 1:
                        tamanio = sizeof(int); //Por lo general tipo entero es de 4 bytes
                        break;
                case 2:
                        tamanio = sizeof(float); //por lo general el tipo float es de 4 bytes
                        break;
                case 3:
                        tamanio = sizeof(double); //Por lo general el tipo double es de 8 bytes
                        break;
                case 4:
                        tamanio = sizeof(typeString); //tipo char es de 1byte pero para almacenar 
													// palabras completas lo multiplicamos por la cantidad
													// de caracteres que hemos especificados en la variable Palabra
								//printf("Tamanio nuevo - %d \n",(sizeof(newType)));
                        break;
						
        }
		//Documentacion oficial de la funcion CreateFileMapping
		//https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-createfilemappinga
		struct nodoMem *newMem = (struct nodoMem *)malloc(sizeof(struct nodoMem));
		
        newMem->hMem = CreateFileMapping(INVALID_HANDLE_VALUE,
                                      NULL, // default security
                                      0x04, // Las vistas de la memoria podrán leer y escribir
                                      0,    // max. object size
                                      tamanio * cantidad, // buffer size
                                      _T(nombre)); //Nombre del objeto mapeado

        if(newMem->hMem == NULL){ //Control ocurrió algún error al gestionar le espacio
                return 1;
        }

		newMem->siguiente = cabezaMem;
		cabezaMem = newMem;
        return 0;
}


void freeMemorias(){
	struct nodoMem *nextMem;
	while(cabezaMem != NULL){
		nextMem = cabezaMem->siguiente;
		CloseHandle(cabezaMem->hMem);
		free(cabezaMem);
		cabezaMem = nextMem;
	}
}

void freeVistas(){
	struct nodoView *nextVista;
	
	struct nodoMap *nextHandle;
	
	while(cabezaVista != NULL){
		//printf("Entro a limpiar vistas\n");
		nextVista = cabezaVista->siguiente;
		UnmapViewOfFile(cabezaVista->hView);
		free(cabezaVista);
		cabezaVista = nextVista;
	}
	
	while(cabezaMap != NULL){
		//printf("Entro a limpiar handles\n");
		nextHandle = cabezaMap->siguiente;
		CloseHandle(cabezaMap->hMap);
		free(cabezaMap);
		cabezaMap = nextHandle;
	}

}