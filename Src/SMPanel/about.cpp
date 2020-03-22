//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "about.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Label1Click(TObject *Sender)
{
        ShellExecute(NULL, "open", "https://github.com/EliGor1989/sharedMemoryClient", "", NULL, SW_RESTORE);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Label2Click(TObject *Sender)
{
        ShellExecute(NULL, "open", "https://www.giarsi.com/", "", NULL, SW_RESTORE);
}
//---------------------------------------------------------------------------
