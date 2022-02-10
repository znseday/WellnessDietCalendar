﻿//---------------------------------------------------------------------------

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
    void __fastcall btnCancelClick(TObject *Sender);
    void __fastcall btnOkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmSettings(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSettings *frmSettings;
//---------------------------------------------------------------------------
#endif
