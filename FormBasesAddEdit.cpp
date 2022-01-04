//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormBasesAddEdit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmBasesAddEdit *frmBasesAddEdit;
//---------------------------------------------------------------------------
__fastcall TfrmBasesAddEdit::TfrmBasesAddEdit(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmBasesAddEdit::btnOkClick(TObject *Sender)
{
    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBasesAddEdit::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TfrmBasesAddEdit::FormShow(TObject *Sender)
{
	if (EditName->Enabled)
	{
        EditName->SetFocus();
	}
}
//---------------------------------------------------------------------------

