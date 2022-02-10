//---------------------------------------------------------------------------

#ifndef FormExportH
#define FormExportH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.WinXPickers.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmExport : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TLabel *Label2;
    TButton *btnExport;
    TSaveDialog *dlgSave;
    TDateTimePicker *dtpFrom;
    TDateTimePicker *dtpTo;
    void __fastcall btnExportClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmExport(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmExport *frmExport;
//---------------------------------------------------------------------------
#endif
