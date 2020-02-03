//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "main.h"
#include "thView.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//

typedef int(*FN1PTR)(char *, int); // Pointer to the function "int abrirMemoria(char *nombre, int tipo);"
                                  // The same pointer to the function "int readIntValue(char *nomMemoria, int posicion);"
typedef float(*FNRFLOATPTR)(char *, int); // Pointer to the function "float readFloatValue(char *nomMemoria, int posicion);"
typedef double(*FNRDOUBLEPTR)(char *, int); // Pointer to the function "double readDoubleValue(char *nomMemoria, int posicion);"
typedef void(*FNRWSTRINGPTR)(char *, int, char *); //Pointer to the function "void writeStringValue(char *nomMemoria, int posicion, char *str);"
                                      // The same pointer to the function "void readStringValue(char *nomMemoria, int posicion, char *str);"
typedef void(*FNFREEMPTR)(void); //Pointer to the function "void liberarMemorias();"
                                 // Pointer to the function "void liberarVistas();"
                                 // Pointer to the function "void readStringValue(char *nomMemoria, int posicion, char *str);"
FN1PTR fnAbrir;
FN1PTR fnReadInt;
FNRFLOATPTR fnReadFloat;
FNRDOUBLEPTR fnReadDouble;
FNRWSTRINGPTR fnReadString;
FNFREEMPTR fnLibViews;

void __fastcall thView::UpdateCaption()
{
       int jjj=0;
        char valor[13];
        //valor = (char *)malloc(sizeof(char)*13);
        for(int iii=1;iii<Form1->MemoriesDetailsGrid->RowCount;iii++){
                jjj = 1;
                while(jjj <= atoi(Form1->MemoriesDetailsGrid->Cells[1][iii].c_str())){
                        if(Form1->MemoriesDetailsGrid->Cells[2][iii] == "Integer"){
                                if(Form1->sgViews->Cells[iii-1][jjj] !=
                                        fnReadInt(Form1->MemoriesDetailsGrid->Cells[0][iii].c_str(),jjj-1))
                                        Form1->sgViews->Cells[iii-1][jjj] =
                                                fnReadInt(Form1->MemoriesDetailsGrid->Cells[0][iii].c_str(),jjj-1);
                        }

                        if(Form1->MemoriesDetailsGrid->Cells[2][iii] == "Float"){
                                if(Form1->sgViews->Cells[iii-1][jjj] !=
                                        fnReadFloat(Form1->MemoriesDetailsGrid->Cells[0][iii].c_str(),jjj-1))
                                        Form1->sgViews->Cells[iii-1][jjj] =
                                                fnReadFloat(Form1->MemoriesDetailsGrid->Cells[0][iii].c_str(),jjj-1);
                        }
                        if(Form1->MemoriesDetailsGrid->Cells[2][iii] == "Double"){
                                if(Form1->sgViews->Cells[iii-1][jjj] !=
                                        fnReadDouble(Form1->MemoriesDetailsGrid->Cells[0][iii].c_str(),jjj-1))
                                        Form1->sgViews->Cells[iii-1][jjj] =
                                                fnReadDouble(Form1->MemoriesDetailsGrid->Cells[0][iii].c_str(),jjj-1);
                        }

                        if(Form1->MemoriesDetailsGrid->Cells[2][iii] == "String"){
                                fnReadString(Form1->MemoriesDetailsGrid->Cells[0][iii].c_str(),
                                        jjj-1, valor);
                                if(strcmp(Form1->sgViews->Cells[iii-1][jjj].c_str(),valor) != 0)
                                        Form1->sgViews->Cells[iii-1][jjj] = valor;
                        }

                        jjj++;
                }
        }

}
//---------------------------------------------------------------------------

__fastcall thView::thView(bool CreateSuspended)
        : TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall thView::Execute()
{
        FreeOnTerminate = True;
        fnAbrir = (FN1PTR)GetProcAddress(Form1->hInst, "openMemory");
        fnReadInt = (FN1PTR)GetProcAddress(Form1->hInst, "getInt");
	fnReadFloat = (FNRFLOATPTR)GetProcAddress(Form1->hInst, "getFloat");
 	fnReadDouble = (FNRDOUBLEPTR)GetProcAddress(Form1->hInst, "getDouble");
 	fnReadString = (FNRWSTRINGPTR)GetProcAddress(Form1->hInst, "getString");
        fnLibViews = (FNFREEMPTR)GetProcAddress(Form1->hInst, "freeViews");
        //Sleep(200);
        //Apertura de las memorias para poder leerlas
         for(int iii = 1;iii<Form1->MemoriesDetailsGrid->RowCount;iii++){
                if(Form1->MemoriesDetailsGrid->Cells[2][iii] == "Integer")
                        fnAbrir(Form1->MemoriesDetailsGrid->Cells[0][iii].c_str(),1);
                if(Form1->MemoriesDetailsGrid->Cells[2][iii] == "Float")
                        fnAbrir(Form1->MemoriesDetailsGrid->Cells[0][iii].c_str(),2);
                if(Form1->MemoriesDetailsGrid->Cells[2][iii] == "Double")
                        fnAbrir(Form1->MemoriesDetailsGrid->Cells[0][iii].c_str(),3);
                if(Form1->MemoriesDetailsGrid->Cells[2][iii] == "String"){
                        fnAbrir(Form1->MemoriesDetailsGrid->Cells[0][iii].c_str(),4);
                }
         }
        //lanza el hilo de ejecucion de visualizacion de valores de la SharedMemory

        while(Form1->stopThread == 0){
            Synchronize(UpdateCaption);
            Sleep(60);
        }
        //Sleep(200);
        fnLibViews();


}
//---------------------------------------------------------------------------
