//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormSettings.h"

#include "Misc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSettings *frmSettings;
//---------------------------------------------------------------------------
__fastcall TfrmSettings::TfrmSettings(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmSettings::btnCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSettings::btnOkClick(TObject *Sender)
{
    String t = EditM->Text;
    CorrectDecSeparator(t);
    double M = StrToFloatDef(t, -1);
    if (M < 0)
    {
        ShowMessage(L"Некорректно задана масса.\n");
        return;
    }
    EditM->Text = t;

    t = EditB->Text;
    CorrectDecSeparator(t);
    double B = StrToFloatDef(t, -1);
    if (B < 0)
    {
        ShowMessage(L"Некорректно задано значение для нормы белков.\n");
        return;
    }
    EditB->Text = t;

    t = EditJ->Text;
    CorrectDecSeparator(t);
    double J = StrToFloatDef(t, -1);
    if (J < 0)
    {
        ShowMessage(L"Некорректно задано значение для нормы жиров.\n");
        return;
    }
    EditJ->Text = t;

    t = EditU->Text;
    CorrectDecSeparator(t);
    double U = StrToFloatDef(t, -1);
    if (U < 0)
    {
        ShowMessage(L"Некорректно задано значение для нормы углеводов.\n");
        return;
    }
    EditU->Text = t;

    t = EditK->Text;
    CorrectDecSeparator(t);
    double K = StrToFloatDef(t, -1);
    if (K < 0)
    {
        ShowMessage(L"Некорректно задано значение для целевой каллорийности.\n");
        return;
    }
    EditK->Text = t;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
