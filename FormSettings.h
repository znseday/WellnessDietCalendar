//---------------------------------------------------------------------------

#ifndef FormSettingsH
#define FormSettingsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmSettings : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TDateTimePicker *dtpStartDayTime;
    TButton *btnCancel;
    TButton *btnOk;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TEdit *EditM;
    TEdit *EditK;
    TEdit *EditB;
    TEdit *EditJ;
    TEdit *EditU;
    TLabel *Label6;
    TLabel *lblK_formal;
    TLabel *Label7;
    TEdit *EditWarningPercent;
    TLabel *Label8;
    void __fastcall btnCancelClick(TObject *Sender);
    void __fastcall btnOkClick(TObject *Sender);
    void __fastcall EditBChange(TObject *Sender);
    void __fastcall EditJChange(TObject *Sender);
    void __fastcall EditUChange(TObject *Sender);
    void __fastcall EditMChange(TObject *Sender);
private:	// User declarations

    void CalcAndPrintFormalK();

public:		// User declarations
    __fastcall TfrmSettings(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSettings *frmSettings;
//---------------------------------------------------------------------------
#endif
