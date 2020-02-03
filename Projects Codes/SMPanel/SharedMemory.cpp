#include <windows.h>
#include <tchar.h>
#include <vcl.h>
#include <string.h>
HANDLE *hFile;
static int memPosicion;

//Este nodo solo guardara los datos de detalle de cada memoria
struct nodoHandle{
    HANDLE hFile;
    char nombre[13];
    int tipo;
    struct nodoHandle *siguiente;
};

struct nodoInts{
    int *hView;
    char nombre[13];
    struct nodoInts *siguiente;
};

struct nodoFloat{
    float *hView;
    char nombre[13];
    struct nodoFloat *siguiente;
};

struct nodoDouble{
    double *hView;
    char nombre[13];
    struct nodoDouble *siguiente;
};

struct nodoString{
    char **hView;
    char nombre[13];
    struct nodoString *siguiente;
};

struct nodoHandle *primeroHandle;
struct nodoHandle *ultimoHandle;

struct nodoInts *primeroInts;
struct nodoInts *ultimoInts;

struct nodoFloat *primeroFloat;
struct nodoFloat *ultimoFloat;

struct nodoDouble *primeroDouble;
struct nodoDouble *ultimoDouble;

struct nodoString *primeroString;
struct nodoString *ultimoString;

int abrirMemoria(char *nombre, int tipo){
    //agregacion de nodo handle
    struct nodoHandle *nuevoHandle;
    struct nodoInts *nuevoInt;
    struct nodoFloat *nuevoFloat;
    struct nodoDouble *nuevoDouble;

    nuevoHandle = (struct nodoHandle *)malloc(sizeof(struct nodoHandle));
    nuevoHandle->siguiente = NULL;
    strcpy(nuevoHandle->nombre,nombre);
    nuevoHandle->tipo = tipo;
    nuevoHandle->hFile = OpenFileMapping(FILE_MAP_ALL_ACCESS,
                            FALSE,
                            _T(nombre));

    if(nuevoHandle->hFile == NULL){
        //printf("No se puede acceder a memoria:  \n");
        return 1;
    }else{
        //printf("Memoria abierta\n");
    }
    if(primeroHandle == NULL){
        primeroHandle = ultimoHandle = nuevoHandle;
        //printf("Primer valor");
    }else{
        ultimoHandle->siguiente = nuevoHandle;
        ultimoHandle = nuevoHandle;
        //printf("segundo valor");
    }
    switch(tipo){
        case 1:
                nuevoInt = (struct nodoInts *)malloc(sizeof(struct nodoInts));
                strcpy(nuevoInt->nombre,nombre);
                nuevoInt->hView = (int *)MapViewOfFile(nuevoHandle->hFile,
                                     FILE_MAP_ALL_ACCESS,
                                     0,
                                     0,
                                     0);
                nuevoInt->siguiente = NULL;
                if(nuevoInt->hView == NULL){
                    //printf("No se puede hacer casting al handler\n");
                    return 1;
                }else{
                    //printf("Acceso a memoria Tipo entero listo!\n");
                }
                if(primeroInts == NULL){
                    primeroInts = ultimoInts = nuevoInt;
                    //printf("Primer valor");
                }else{
                    ultimoInts->siguiente = nuevoInt;
                    ultimoInts = nuevoInt;
                    //printf("segundo valor");
                }
                break;
        case 2:
                nuevoFloat = (struct nodoFloat *)malloc(sizeof(struct nodoFloat));
                strcpy(nuevoFloat->nombre,nombre);
                nuevoFloat->hView = (float *)MapViewOfFile(nuevoHandle->hFile,
                                     FILE_MAP_ALL_ACCESS,
                                     0,
                                     0,
                                     0);
                nuevoFloat->siguiente = NULL;
                if(nuevoFloat->hView == NULL){
                    //printf("No se puede hacer casting al handler\n");
                    return 1;
                }else{
                    //printf("Acceso a memoria Tipo Float listo!\n");
                }
                if(primeroFloat == NULL){
                    primeroFloat = ultimoFloat = nuevoFloat;
                    //printf("Primer valor");
                }else{
                    ultimoFloat->siguiente = nuevoFloat;
                    ultimoFloat = nuevoFloat;
                    //printf("segundo valor");
                }
                break;
        case 3:
                nuevoDouble = (struct nodoDouble *)malloc(sizeof(struct nodoDouble));
                strcpy(nuevoDouble->nombre,nombre);
                nuevoDouble->hView = (double *)MapViewOfFile(nuevoHandle->hFile,
                                     FILE_MAP_ALL_ACCESS,
                                     0,
                                     0,
                                     0);
                nuevoDouble->siguiente = NULL;
                if(nuevoDouble->hView == NULL){
                    //printf("No se puede hacer casting al handler\n");
                    return 1;
                }else{
                    //printf("Acceso a memoria Tipo Double listo!\n");
                }
                if(primeroDouble == NULL){
                    primeroDouble = ultimoDouble = nuevoDouble;
                    //printf("Primer valor");
                }else{
                    ultimoDouble->siguiente = nuevoDouble;
                    ultimoDouble = nuevoDouble;
                    //printf("segundo valor");
                }
                break;



    }

    return 0;
}


int abrirMemoriaString(char *nombre, int cantPalabras){
    struct nodoString *nuevoString;
    struct nodoHandle *nuevoHandle;
    int i;

    nuevoHandle = (struct nodoHandle *)malloc(sizeof(struct nodoHandle));
    nuevoHandle->siguiente = NULL;
    strcpy(nuevoHandle->nombre,nombre);
    nuevoHandle->tipo = 4;
    nuevoHandle->hFile = OpenFileMapping(FILE_MAP_ALL_ACCESS,
                            FALSE,
                            _T(nombre));

    if(nuevoHandle->hFile == NULL){
        //printf("No se puede acceder a memoria:  \n");
        return 1;
    }else{
        //printf("Memoria abierta\n");
    }
    if(primeroHandle == NULL){
        primeroHandle = ultimoHandle = nuevoHandle;
        //printf("Primer valor");
    }else{
        ultimoHandle->siguiente = nuevoHandle;
        ultimoHandle = nuevoHandle;
        //printf("segundo valor");
    }
    nuevoString = (struct nodoString *)malloc(sizeof(struct nodoString));
    strcpy(nuevoString->nombre,nombre);
    nuevoString->hView = (char **)MapViewOfFile(nuevoHandle->hFile,
                                     FILE_MAP_ALL_ACCESS,
                                     0,
                                     0,
                                     0);
    nuevoString->siguiente = NULL;
    if(nuevoString->hView == NULL){
        //printf("No se puede hacer casting al handler\n");
        return 1;
    }else{
        //printf("Acceso a memoria Tipo String listo!\n");
    }
    for (i=0;i<cantPalabras;i++){
            nuevoString->hView[i] = (char *)malloc(sizeof(char)*13);
    }

    if(primeroString == NULL){
        primeroString = ultimoString = nuevoString;
        //printf("Primer valor");
    }else{
        ultimoString->siguiente = nuevoString;
        ultimoString = nuevoString;
        //printf("segundo valor");
    }

    return 0;
}


int readIntValue(char *nomMemoria, int posicion){
    struct nodoInts *auxiliarInt;
    auxiliarInt = primeroInts;
    int bandSalirTipo = 0;
    int valor=0;
    while(auxiliarInt != NULL && bandSalirTipo == 0){
        if(strcmp(auxiliarInt->nombre,nomMemoria)==0){
            valor = auxiliarInt->hView[posicion];
            bandSalirTipo = 1;
        }
        if(bandSalirTipo==0){
            auxiliarInt = auxiliarInt->siguiente;
        }
   }
    return valor;
}

void writeIntValue(char *nomMemoria, int posicion,int valor){
    struct nodoInts *auxiliarInt;
    auxiliarInt = primeroInts;
    int bandSalirTipo = 0;
    while(auxiliarInt != NULL && bandSalirTipo == 0){
        if(strcmp(auxiliarInt->nombre,nomMemoria)==0){
            auxiliarInt->hView[posicion] = valor;
            bandSalirTipo = 1;
        }
        if(bandSalirTipo==0){
            auxiliarInt = auxiliarInt->siguiente;
        }
   }

}

void writeFloatValue(char *nomMemoria, int posicion, float valor){
    struct nodoFloat *auxiliarFloat;
    auxiliarFloat = primeroFloat;
    int bandSalirTipo = 0;
    while(auxiliarFloat != NULL && bandSalirTipo == 0){
        if(strcmp(auxiliarFloat->nombre,nomMemoria)==0){
            auxiliarFloat->hView[posicion] = valor;
            bandSalirTipo = 1;
        }
        if(bandSalirTipo==0){
            auxiliarFloat = auxiliarFloat->siguiente;
        }
   }

}

float readFloatValue(char *nomMemoria, int posicion){
    struct nodoFloat *auxiliarFloat;
    auxiliarFloat = primeroFloat;
    int bandSalirTipo = 0;
    float valor=0;
    while(auxiliarFloat != NULL && bandSalirTipo == 0){
        if(strcmp(auxiliarFloat->nombre,nomMemoria)==0){
            valor = auxiliarFloat->hView[posicion];
            bandSalirTipo = 1;
        }
        if(bandSalirTipo==0){
            auxiliarFloat = auxiliarFloat->siguiente;
        }
   }
    return valor;
}

void writeDoubleValue(char *nomMemoria, int posicion, double valor){
    struct nodoDouble *auxiliarDouble;
    auxiliarDouble = primeroDouble;
    int bandSalirTipo = 0;
    //printf("valor double %lf \n",valor);
    while(auxiliarDouble != NULL && bandSalirTipo == 0){
        if(strcmp(auxiliarDouble->nombre,nomMemoria)==0){
            //printf("Encontro double");
            auxiliarDouble->hView[posicion] = valor;
            bandSalirTipo = 1;
        }
        if(bandSalirTipo==0){
            auxiliarDouble = auxiliarDouble->siguiente;
        }
   }

}

double readDoubleValue(char *nomMemoria, int posicion){
    struct nodoDouble *auxiliarDouble;
    auxiliarDouble = primeroDouble;
    int bandSalirTipo = 0;
    double valor=0.0;
    while(auxiliarDouble != NULL && bandSalirTipo == 0){
        if(strcmp(auxiliarDouble->nombre,nomMemoria)==0){
            valor = auxiliarDouble->hView[posicion];
            bandSalirTipo = 1;
        }
        if(bandSalirTipo==0){
            auxiliarDouble = auxiliarDouble->siguiente;
        }
   }
    return valor;
}

void writeStringValue(char *nomMemoria, int posicion, char *str){
    struct nodoString *auxiliarString;
    auxiliarString = primeroString;
    int bandSalirTipo = 0;
    //printf("valor double %lf \n",valor);
    while(auxiliarString != NULL && bandSalirTipo == 0){
        if(strcmp(auxiliarString->nombre,nomMemoria)==0){
            //printf("Encontro double");
            strcpy(auxiliarString->hView[posicion],str);
            bandSalirTipo = 1;
            //printf("Palabra guardada\n");
        }
        if(bandSalirTipo==0){
            auxiliarString = auxiliarString->siguiente;
        }
   }
}

void readStringValue(char *nomMemoria, int posicion, char *str){
    struct nodoString *auxiliarString;
    auxiliarString = primeroString;
    int bandSalirTipo = 0;
    while(auxiliarString != NULL && bandSalirTipo == 0){
        if(strcmp(auxiliarString->nombre,nomMemoria)==0){
            //str = strdup(auxiliarString->hView[posicion]);
            //ShowMessage(auxiliarString->hView[posicion]);
            //strcpy(str,auxiliarString->hView[posicion]);
            bandSalirTipo = 1;
        }
        if(bandSalirTipo==0){
            auxiliarString = auxiliarString->siguiente;
        }
   }

   // *str = strdup("EROSHACK");
}

//Gestion la cantidad de moria tipo handle para administrar la memoria
int gestMemoria(int cantidad){
        hFile = (HANDLE *)malloc(cantidad * sizeof(HANDLE));
        memPosicion = 0;
        return 0;
}

//nombre de la memoria compartida, cantidad de espacios deseados y el tipo
//que ser�a 1 para enteros, 2 para flotantes, 3 para doubles y 4 para cadenas
// en cadena se envia una cantidad de 13 bytes, para que almacene palabras de
//hasta 13 letras
int crearMemoria(char *nombre, int cantidad, int tipo){
        int tamanio;
        switch(tipo){
                case 1:
                        tamanio = 4;
                        break;
                case 2:
                        tamanio = 4;
                        break;
                case 3:
                        tamanio = 8;
                        break;
                case 4:
                        tamanio = 13;
                        break;
        }
        *(hFile + memPosicion) = CreateFileMapping(INVALID_HANDLE_VALUE,
                                      NULL,
                                      0x40,

                                      0,
                                      tamanio * cantidad,
                                      _T(nombre));

        if(*(hFile + memPosicion) == NULL){
                return 1;
        }
        memPosicion++;
        return 0;
}
void liberarMemorias(){
        for(int iii = 0; iii < memPosicion;iii++){
                CloseHandle(*(hFile + iii));
        }
}
