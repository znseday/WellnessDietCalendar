//---------------------------------------------------------------------------

#ifndef FormBasesAddEditH
#define FormBasesAddEditH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TfrmBasesAddEdit : public TForm
{
__published:    // IDE-managed Components
    TLabel *Label1;
    TEdit *EditName;
    TLabel *Label2;
    TEdit *EditB;
    TLabel *Label3;
    TEdit *EditJ;
    TLabel *Label4;
    TEdit *EditU;
    TLabel *Label5;
    TEdit *EditK;
    TButton *btnCancel;
    TButton *btnOk;
    TLabel *Label6;
    TEdit *EditCost;
    void __fastcall btnOkClick(TObject *Sender);
    void __fastcall btnCancelClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:    // User declarations
public:        // User declarations
    __fastcall TfrmBasesAddEdit(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmBasesAddEdit *frmBasesAddEdit;
//---------------------------------------------------------------------------
#endif
