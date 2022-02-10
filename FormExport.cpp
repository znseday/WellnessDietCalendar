//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormExport.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmExport *frmExport;
//---------------------------------------------------------------------------
__fastcall TfrmExport::TfrmExport(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmExport::btnExportClick(TObject *Sender)
{
    if (dlgSave->Execute())
    {

        ModalResult = mrOk;
    }
}
//---------------------------------------------------------------------------
