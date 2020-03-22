//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TStringGrid *MemoriesDetailsGrid;
        TButton *btnMore;
        TButton *btnLess;
        TComboBox *ComboBox1;
        TStringGrid *sgViews;
        TLabel *Label4;
        TMainMenu *MainMenu1;
        TMenuItem *Archivo1;
        TMenuItem *Edicion1;
        TMenuItem *Ejecutar1;
        TMenuItem *Ayuda1;
        TMenuItem *Open;
        TMenuItem *Save;
        TMenuItem *Exit;
        TMenuItem *Visualize;
        TMenuItem *Hide;
        TMenuItem *Create;
        TMenuItem *Liberate;
        TMenuItem *Acercade1;
        TSaveDialog *SaveDialog1;
        TOpenDialog *OpenDialog1;
        void __fastcall btnMoreClick(TObject *Sender);
        void __fastcall btnLessClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall MemoriesDetailsGridClick(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall CreateClick(TObject *Sender);
        void __fastcall LiberateClick(TObject *Sender);
        void __fastcall VisualizeClick(TObject *Sender);
        void __fastcall HideClick(TObject *Sender);
        void __fastcall ExitClick(TObject *Sender);
        void __fastcall SaveClick(TObject *Sender);
        void __fastcall OpenClick(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall Acercade1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
       int stopThread;
       HINSTANCE hInst;
		
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
