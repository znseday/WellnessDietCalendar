//---------------------------------------------------------------------------
#include <fstream>
#include <vcl.h>
#include <System.JSON.hpp>
#include <System.JSON.Writers.hpp>
#include <inifiles.hpp>
#include <dateutils.hpp>
#pragma hdrstop

#include "FormMainWellness.h"
#include "FormBasesAddEdit.h"
#include "FormPreparedAddEdit.h"
#include "FormSettings.h"
#include "FormExport.h"

#include "Misc.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ccalendr"
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::ActionFileCloseExecute(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormCreate(TObject *Sender)
{
    LoadSettings();

    ActionBasesLoad->Execute();
    ActionPreparedsLoad->Execute();
    ActionCalendarLoad->Execute();

    cvCalendar->Date = Now() - Settings.StartDayTime;
    LastSelectedDate = cvCalendar->Date;

    PrintBases(this);
    PrintPrepareds(this);
    PrintCalendar(this);

    lbCalendarPrepareds->Height = 200;

    pcMain->ActivePage = tsCalendar;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::ActionBasesSaveAsExecute(TObject *Sender)
{
    if (SaveDialog->Execute())
    {
        if ( !Bases.SaveToJSON(SaveDialog->FileName) )
        {
            ShowMessage(L"ActionBasesSaveAsExecute: Что-то пошло не так");
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ActionBasesSaveExecute(TObject *Sender)
{
    if ( !Bases.SaveToJSON(ExtractFilePath(Application->ExeName) + "Bases.json") )
    {
        ShowMessage(L"ActionBasesSaveExecute: Что-то пошло не так.");
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ActionBasesLoadExecute(TObject *Sender)
{
    if ( !Bases.LoadFromJSON(ExtractFilePath(Application->ExeName) + "Bases.json") )
    {
        ShowMessage(L"ActionBasesLoadExecute: Что-то пошло не так");
    }

    PrintBases(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ActionBasesEditExecute(TObject *Sender)
{
    int row = gridBases->Selection.Top;

    if (Bases.GetCount() < 1 || row < 1 || row > Bases.GetCount())
    {
        ShowMessage(L"Не выбраны данные для редактирования");
        return;
    }

    frmBasesAddEdit->Caption = L"Редактировать";
    frmBasesAddEdit->EditName->Enabled = false;
    frmBasesAddEdit->EditName->Text = gridBases->Cells[0][row];
    frmBasesAddEdit->EditName->ReadOnly = true;

    frmBasesAddEdit->EditB->Text = gridBases->Cells[1][row];
    frmBasesAddEdit->EditJ->Text = gridBases->Cells[2][row];
    frmBasesAddEdit->EditU->Text = gridBases->Cells[3][row];
    frmBasesAddEdit->EditK->Text = gridBases->Cells[4][row];
    frmBasesAddEdit->EditCost->Text = gridBases->Cells[5][row];

     if ( frmBasesAddEdit->ShowModal() == mrOk )
    {
        float b, j, u, k, cost;
        String Name = frmBasesAddEdit->EditName->Text;

        String t = frmBasesAddEdit->EditB->Text;
        CorrectDecSeparator(t);
        b = StrToFloatDef(t, -1);
        if (b < 0)
            ShowMessage(L"Некорректно задано кол-во белков.\nПо умолчанию будет задано 0.");

        t = frmBasesAddEdit->EditJ->Text;
        CorrectDecSeparator(t);
        j = StrToFloatDef(t, -1);
        if (j < 0)
            ShowMessage(L"Некорректно задано кол-во жиров.\nПо умолчанию будет задано 0.");

        t = frmBasesAddEdit->EditU->Text;
        CorrectDecSeparator(t);
        u = StrToFloatDef(t, -1);
        if (u < 0)
            ShowMessage(L"Некорректно задано кол-во углеводов.\nПо умолчанию будет задано 0.");

        t = frmBasesAddEdit->EditK->Text;
        CorrectDecSeparator(t);
        k = StrToFloatDef(t, -1);
        if (k < 0)
            ShowMessage(L"Некорректно задано кол-во калорий.\nПо умолчанию будет задано 0.");

        t = frmBasesAddEdit->EditCost->Text;
        CorrectDecSeparator(t);
        cost = StrToFloatDef(t, -1);
        if (cost < 0)
            ShowMessage(L"Некорректно задана стоимость.\nПо умолчанию будет задано 0.");

        if ( !Bases.Edit(Name.c_str(), b, j, u, k, cost) )
        {
            ShowMessage(L"Не удается отредактировать запись");
            return;
        }

        PrintBases(this);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ActionBasesAddExecute(TObject *Sender)
{
    String Name;
    float b, j, u, k, cost;

    frmBasesAddEdit->Caption = L"Добавить";

    frmBasesAddEdit->EditName->Enabled = true;
    frmBasesAddEdit->EditName->ReadOnly = false;

    frmBasesAddEdit->EditName->Text = "";
    frmBasesAddEdit->EditB->Text = "";
    frmBasesAddEdit->EditJ->Text = "";
    frmBasesAddEdit->EditU->Text = "";
    frmBasesAddEdit->EditK->Text = "";
    frmBasesAddEdit->EditCost->Text = "";


    if ( frmBasesAddEdit->ShowModal() == mrOk )
    {
        Name = frmBasesAddEdit->EditName->Text;

        String t = frmBasesAddEdit->EditB->Text;
        CorrectDecSeparator(t);
        b = StrToFloatDef(t, -1);
        if (b < 0)
            ShowMessage(L"Некорректно задано кол-во белков.\nПо умолчанию будет задано 0.");

        t = frmBasesAddEdit->EditJ->Text;
        CorrectDecSeparator(t);
        j = StrToFloatDef(t, -1);
        if (j < 0)
            ShowMessage(L"Некорректно задано кол-во жиров.\nПо умолчанию будет задано 0.");

        t = frmBasesAddEdit->EditU->Text;
        CorrectDecSeparator(t);
        u = StrToFloatDef(t, -1);
        if (u < 0)
            ShowMessage(L"Некорректно задано кол-во углеводов.\nПо умолчанию будет задано 0.");

        t = frmBasesAddEdit->EditK->Text;
        CorrectDecSeparator(t);
        k = StrToFloatDef(t, -1);
        if (k < 0)
            ShowMessage(L"Некорректно задано кол-во калорий.\nПо умолчанию будет задано 0.");

        t = frmBasesAddEdit->EditCost->Text;
        CorrectDecSeparator(t);
        cost = StrToFloatDef(t, -1);
        if (cost < 0)
            ShowMessage(L"Некорректно задана стоимость.\nПо умолчанию будет задано 0.");

        if ( !Bases.Add(Name.c_str(), b, j, u, k, cost) )
        {
            ShowMessage(L"Не удается добавить запись");
            return;
        }

        PrintBases(this);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ActionBasesDelExecute(TObject *Sender)
{
    int row = gridBases->Selection.Top;

    if (Bases.GetCount() < 1 || row < 1 || row > Bases.GetCount())
    {
        ShowMessage(L"Не выбраны данные для редактирования");
        return;
    }

    if (Application->MessageBox(L"Удалить из списка выделенный продукт",
        L"Вопрос", MB_YESNO | MB_ICONQUESTION) != IDYES)
        return;

    String Name = gridBases->Cells[0][row];

    if ( !Bases.Del(Name.c_str()) )
    {
        ShowMessage(L"Не удается удалить запись");
        return;
    }

    PrintBases(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::PrintBases(TObject *Sender)
{
    String SearchString = EditBasesSearch->Text;

    HowToSort hts = HowToSort::Name;

    if (rbBasesSortName->Checked)
        hts = HowToSort::Name;
    else if (rbBasesSortB->Checked)
        hts = HowToSort::B;
    else if (rbBasesSortJ->Checked)
        hts = HowToSort::J;
    else if (rbBasesSortU->Checked)
        hts = HowToSort::U;
    else if (rbBasesSortK->Checked)
        hts = HowToSort::K;
    else if (rbBasesSortCost->Checked)
        hts = HowToSort::Cost;
    else
    {
        ShowMessage(L"Ошибка! Не задан тип сортировки");
        return;
    }

    Bases.PrintToTable(gridBases, hts, SearchString);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormCloseQuery(TObject *Sender, bool &CanClose)
{
    if ( (!QuerySaveBases() ))
    {
        CanClose = false;
        return;
    }
    if ( (!QuerySavePrepareds() ))
    {
        CanClose = false;
        return;
    }
    if ( (!QuerySaveCalendar() ))
    {
        CanClose = false;
        return;
    }
}
//---------------------------------------------------------------------------

bool TfrmMain::QuerySaveBases() const
{
    if ( !Bases.GetIsSaved() )
    {
        String mes = L"Изменения в списке базовых продуктов не сохранены. Сохранить?";
        int res = Application->MessageBox( mes.c_str(),
                        Application->Title.c_str(), 3);
        if (res == mrYes)
        {
            ActionBasesSave->Execute();
        }
        else if (res == mrCancel)
        {
            return false;
        }
        else if (res == mrNo)
        {
            return true;
        }
    }
    return true;
}
//---------------------------------------------------------------------------

bool TfrmMain::QuerySavePrepareds() const
{
    if ( !Prepareds.GetIsSaved() )
    {
        String mes = L"Изменения в списке готовых продуктов не сохранены. Сохранить?";
        int res = Application->MessageBox( mes.c_str(),
                        Application->Title.c_str(), 3);
        if (res == mrYes)
        {
            ActionPreparedsSave->Execute();
        }
        else if (res == mrCancel)
        {
            return false;
        }
        else if (res == mrNo)
        {
            return true;
        }
    }
    return true;
}
//---------------------------------------------------------------------------

bool TfrmMain::QuerySaveCalendar() const
{
    if ( !Calendar.GetIsSaved() )
    {
        String mes = L"Изменения в календаре не сохранены. Сохранить?";
        int res = Application->MessageBox( mes.c_str(),
                        Application->Title.c_str(), 3);
        if (res == mrYes)
        {
            ActionCalendarSave->Execute();
        }
        else if (res == mrCancel)
        {
            return false;
        }
        else if (res == mrNo)
        {
            return true;
        }
    }
    return true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ActionPreparedsAddExecute(TObject *Sender)
{
    if ( frmPreparedsAddEdit->Showing )
    {
        frmPreparedsAddEdit->WindowState = wsNormal;
    }

    frmPreparedsAddEdit->SetItIsNew();
    frmPreparedsAddEdit->Caption = L"Новое блюдо";

//    frmPreparedsAddEdit->SwitchToBuild();

    frmPreparedsAddEdit->EditName->Enabled = true;
    frmPreparedsAddEdit->ResetPrepared();
    frmPreparedsAddEdit->rbFinished->Checked = true;
    frmPreparedsAddEdit->SwitchToFinished();
    frmPreparedsAddEdit->InitBasesList();

    frmPreparedsAddEdit->Show();

    frmPreparedsAddEdit->EditName->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ActionPreparedsEditExecute(TObject *Sender)
{
    int row = gridPrepareds->Selection.Top;

    if (Prepareds.GetCount() < 1 || row < 1 || row > Prepareds.GetCount())
    {
        ShowMessage(L"Не выбраны данные для редактирования");
        return;
    }

    if ( frmPreparedsAddEdit->Showing )
    {
        frmPreparedsAddEdit->WindowState = wsNormal;
    }

    frmPreparedsAddEdit->SetItIsEdit();
    frmPreparedsAddEdit->Caption = L"Редактировать";
    frmPreparedsAddEdit->EditName->Enabled = false;
    String Name = gridPrepareds->Cells[0][row];

    frmPreparedsAddEdit->InitPrepared(Name, Prepareds.GetPrepared(Name.c_str()));
    //frmPreparedsAddEdit->SwitchToFinished();
    frmPreparedsAddEdit->InitBasesList();
    frmPreparedsAddEdit->Show();
    frmPreparedsAddEdit->InitControls();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ActionPreparedsDelExecute(TObject *Sender)
{
    int row = gridPrepareds->Selection.Top;

    if (Prepareds.GetCount() < 1 || row < 1 || row > Prepareds.GetCount())
    {
        ShowMessage(L"Не выбраны данные для редактирования");
        return;
    }

    if (Application->MessageBox(L"Удалить из списка выделенное блюдо?",
        L"Вопрос", MB_YESNO | MB_ICONQUESTION) != IDYES)
        return;

    String Name = gridPrepareds->Cells[0][row];

    if ( !Prepareds.Del(Name.c_str()) )
    {
        ShowMessage(L"Не удается удалить запись");
        return;
    }

    PrintPrepareds(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ActionPreparedsSaveExecute(TObject *Sender)
{
    if (!Prepareds.SaveToJSON(ExtractFilePath(Application->ExeName) + "Prepareds.json"))
    {
        ShowMessage(L"ActionPreparedSaveExecute: Что-то пошло не так.");
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ActionPreparedsSaveAsExecute(TObject *Sender)
{
    if (SaveDialog->Execute())
    {
        if ( !Prepareds.SaveToJSON(SaveDialog->FileName) )
        {
            ShowMessage(L"ActionPreparedSaveAsExecute: Что-то пошло не так");
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ActionPreparedsLoadExecute(TObject *Sender)
{
    if ( !Prepareds.LoadFromJSON(ExtractFilePath(Application->ExeName) + "Prepareds.json") )
    {
        ShowMessage(L"ActionPreparedLoadExecute: Что-то пошло не так");
    }

    PrintPrepareds(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::PrintPrepareds(TObject *Sender)
{
    String SearchString = EditPreparedsSearch->Text;

    HowToSort hts = HowToSort::Name;

    if (rbPreparedSortName->Checked)
        hts = HowToSort::Name;
    else if (rbPreparedSortB->Checked)
        hts = HowToSort::B;
    else if (rbPreparedSortJ->Checked)
        hts = HowToSort::J;
    else if (rbPreparedSortU->Checked)
        hts = HowToSort::U;
    else if (rbPreparedSortK->Checked)
        hts = HowToSort::K;
    else if (rbPreparedSortM->Checked)
        hts = HowToSort::M;
    else if (rbPreparedSortCost->Checked)
        hts = HowToSort::Cost;
    else
    {
        ShowMessage(L"Ошибка! Не задан тип сортировки");
        return;
    }

    Prepareds.PrintAllToTable(gridPrepareds, hts, SearchString);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormShow(TObject *Sender)
{
    frmExport->dtpFrom->Date = Date();
    frmExport->dtpTo->Date   = Date();

    frmPreparedsAddEdit->InitPointers(&Bases, &Prepareds);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::gridPreparedsMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
    //---
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::EditBasesSearchChange(TObject *Sender)
{
    PrintBases(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::EditPreparedsSearchChange(TObject *Sender)
{
    PrintPrepareds(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::EditCalendarPreparedSearchChange(TObject *Sender)
{
    String SearchString = EditCalendarPreparedSearch->Text;
    Prepareds.PrintToListBox(lbCalendarPrepareds, SearchString);

    if (SearchString.Length() > 0)
       ActionCalendarAdd->Enabled = true;
//        btnCalendarAdd->Enabled = true;
    else
//        btnCalendarAdd->Enabled = false;
       ActionCalendarAdd->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::EditCalendarPreparedSearchKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
    if ( !lbCalendarPrepareds->Visible )
        return;

    if (Key == vkDown)
    {
        if (lbCalendarPrepareds->ItemIndex < lbCalendarPrepareds->Count-1)
        {
            lbCalendarPrepareds->ItemIndex++;
        }
        Key = 0;
    }
    if (Key == vkUp)
    {
        if (lbCalendarPrepareds->ItemIndex > 0)
        {
            lbCalendarPrepareds->ItemIndex--;
        }
        Key = 0;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::EditCalendarPreparedSearchKeyPress(TObject *Sender, System::WideChar &Key)
{
//    if ( !lbCalendarPrepareds->Visible )
//        return;

    if (Key == vkReturn)
    {
        if ( lbCalendarPrepareds->Visible )
        {
            EditCalendarPreparedSearch->Text = lbCalendarPrepareds->Items->Strings[lbCalendarPrepareds->ItemIndex];
            lbCalendarPrepareds->Clear();
            lbCalendarPrepareds->Visible = false;
        }

        Key = 0;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::lbCalendarPreparedsDblClick(TObject *Sender)
{
    EditCalendarPreparedSearch->Text = lbCalendarPrepareds->Items->Strings[lbCalendarPrepareds->ItemIndex];
    lbCalendarPrepareds->Clear();
    lbCalendarPrepareds->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::lbCalendarPreparedsKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
    if (Key == vkReturn)
    {
        EditCalendarPreparedSearch->Text = lbCalendarPrepareds->Items->Strings[lbCalendarPrepareds->ItemIndex];
        lbCalendarPrepareds->Clear();
        lbCalendarPrepareds->Visible = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::PrintCalendar(TObject *Sender)
{
    TDate Date = cvCalendar->Date;

    lblDate->Caption = Date.toAnsiString();

    String SearchString = EditCalendarSearch->Text;

    HowToSort hts = HowToSort::Name;

    if (rbCalendarSortName->Checked)
        hts = HowToSort::Name;
    else if (rbCalendarSortB->Checked)
        hts = HowToSort::B;
    else if (rbCalendarSortJ->Checked)
        hts = HowToSort::J;
    else if (rbCalendarSortU->Checked)
        hts = HowToSort::U;
    else if (rbCalendarSortK->Checked)
        hts = HowToSort::K;
    else if (rbCalendarSortCost->Checked)
        hts = HowToSort::Cost;
    else
    {
        ShowMessage(L"Ошибка! Не задан тип сортировки");
        return;
    }

    Calendar.PrintOneDayToTable(Date, gridCalendar, hts, SearchString, &Prepareds);
    cvCalendar->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::EditCalendarSearchChange(TObject *Sender)
{
    PrintCalendar(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ActionCalendarLoadExecute(TObject *Sender)
{
    if ( !Calendar.LoadFromJSON(ExtractFilePath(Application->ExeName) + "Calendar.json") )
    {
        ShowMessage(L"ActionCalendarLoadExecute: Что-то пошло не так");
    }

    PrintCalendar(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ActionCalendarSaveExecute(TObject *Sender)
{
    if ( !Calendar.SaveToJSON(ExtractFilePath(Application->ExeName) + "Calendar.json") )
    {
        ShowMessage(L"ActionCalendarSaveExecute: Что-то пошло не так.");
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ActionCalendarSaveAsExecute(TObject *Sender)
{
    if (SaveDialog->Execute())
    {
        if ( !Calendar.SaveToJSON(SaveDialog->FileName) )
        {
            ShowMessage(L"ActionCalendarSaveAsExecute: Что-то пошло не так");
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::cvCalendarChange(TObject *Sender)
{
    if ( cvCalendar->Date == TDate(-700000) ) // число, на которое он сбрасывает
        cvCalendar->Date = LastSelectedDate;
    else
        LastSelectedDate = cvCalendar->Date;

    PrintCalendar(this);
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::cvCalendarDrawDayItem(TObject *Sender, TDrawViewInfoParams *DrawParams,
          TCellItemViewInfo *CalendarViewViewInfo)
{
    //DrawParams->ForegroundColor = clRed;
    //DrawParams->FocusedColor = clRed;
    //DrawParams->SelectionColor = clRed;
    //DrawParams->FocusedColor = clRed;
    DrawParams->FocusRectWidth = 5;

    //DrawParams->BkColor = clRed;

    if ( Calendar.GetCountForDay(CalendarViewViewInfo->Date) > 0 )
        DrawParams->BkColor = clTeal; //clAqua; // clSkyBlue;// clTeal;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ActionCalendarAddExecute(TObject *Sender)
{
    String Name;
    int ind = lbCalendarPrepareds->ItemIndex;

    if (ind < 0)
    {
        Name = EditCalendarPreparedSearch->Text;

        if (! Prepareds.CheckPreparedExists(Name.c_str()) )
        {

            ShowMessage(L"Такого блюда не существует в базе");
            return;
        }
    }
    else
    {
        Name = lbCalendarPrepareds->Items->Strings[ind];
        if (! Prepareds.CheckPreparedExists(Name.c_str()) )
        {

            ShowMessage(L"Такого блюда не существует в базе");
            return;
        }
    }

    String res = InputBox(L"Вопрос", L"Кол-во порций\n" + Name + L"\n?", "");
    if (res == "")
        return;

    CorrectDecSeparator(res);
    float amount = StrToFloatDef(res, -1);
    if (amount <= 0)
    {
        ShowMessage(L"Неверно введено кол-во порций");
        return;
    }

    TDate Date = cvCalendar->Date;

    if ( !Calendar.Add(Date, std::make_pair(Name.c_str(), amount)) )
    {
        ShowMessage(L"Ошибка при добавлении блюда. Возможно такое блюдо уже есть в списке или еще что-то не так.");
        return;
    }

    PrintCalendar(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ActionCalendarEditExecute(TObject *Sender)
{
    TDate Date = cvCalendar->Date;
    int row = gridCalendar->Selection.Top;
    int CountForDay = Calendar.GetCountForDay(Date);

    if ( CountForDay < 1 || row < 1 || row > CountForDay )
    {
        ShowMessage(L"Не выбраны данные для редактирования");
        return;
    }

    String Name = gridCalendar->Cells[0][row];

    if (Name == "")
    {
        ShowMessage(L"Не выбраны данные для редактирования");
        return;
    }

    float amount = StrToFloatDef( gridCalendar->Cells[5][row], 0);

    String res = InputBox(L"Вопрос", L"Кол-во порций\n" + Name + L"\n?", amount);

    CorrectDecSeparator(res);
    amount = StrToFloatDef(res, -1);

//    if (res == amount)
//    {
//        return;
//    }

    if (amount <= 0)
    {
        ShowMessage(L"Неверно введено кол-во порций");
        return;
    }

    if ( !Calendar.Edit(Date, std::make_pair(Name.c_str(), amount)) )
    {
        ShowMessage(L"Ошибка при изменении кол-ва порций. Что-то пошло не так");
        return;
    }

    PrintCalendar(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ActionCalendarDelExecute(TObject *Sender)
{
    TDate Date = cvCalendar->Date;
    int row = gridCalendar->Selection.Top;
    int CountForDay = Calendar.GetCountForDay(Date);

    if ( CountForDay < 1 || row < 1 || row > CountForDay )
    {
        ShowMessage(L"Не выбраны данные для удаления");
        return;
    }

    String Name = gridCalendar->Cells[0][row];

    if (Name == "")
    {
        ShowMessage(L"Не выбраны данные для удаления");
        return;
    }

    if ( !Calendar.Del(Date, Name.c_str()) )
    {
        ShowMessage(L"Ошибка. Не удается удалить блюдо");
        return;
    }

    PrintCalendar(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ActionSettingsSettingsExecute(TObject *Sender)
{
    frmSettings->dtpStartDayTime->Time = Settings.StartDayTime;
    frmSettings->EditM->Text = Settings.M_Person;
    frmSettings->EditB->Text = Settings.B_udel;
    frmSettings->EditJ->Text = Settings.J_udel;
    frmSettings->EditU->Text = Settings.U_udel;
    frmSettings->EditK->Text = Settings.K_target;

    if ( frmSettings->ShowModal() == mrOk )
    {
        Settings.StartDayTime = frmSettings->dtpStartDayTime->Time;

        Settings.M_Person = frmSettings->EditM->Text.ToDouble();
        Settings.B_udel = frmSettings->EditB->Text.ToDouble();
        Settings.J_udel = frmSettings->EditJ->Text.ToDouble();
        Settings.U_udel = frmSettings->EditU->Text.ToDouble();
        Settings.K_target = frmSettings->EditK->Text.ToDouble();
    }
}
//---------------------------------------------------------------------------

void TfrmMain::SaveSettings() const
{
    String dn = ExtractFilePath(Application->ExeName);
    String fn = dn + "Settings.ini";

    std::unique_ptr<TIniFile> Ini;

    try
    {
        Ini = std::make_unique<TIniFile>(fn);
    }
    catch (...)
    {
        ShowMessage(L"Ошибка открытия ini-файла с настройками программы");
    }

    Ini->WriteTime("Global", "StartDayTime", Settings.StartDayTime);

    Ini->WriteFloat("Global", "M_Person", Settings.M_Person);
    Ini->WriteFloat("Global", "B_udel",   Settings.B_udel);
    Ini->WriteFloat("Global", "J_udel",   Settings.J_udel);
    Ini->WriteFloat("Global", "U_udel",   Settings.U_udel);
    Ini->WriteFloat("Global", "K_target", Settings.K_target);
}
//---------------------------------------------------------------------------

void TfrmMain::LoadSettings()
{
    String dn = ExtractFilePath(Application->ExeName);
    String fn = dn + "Settings.ini";

    std::unique_ptr<TIniFile> Ini;

    try
    {
        Ini = std::make_unique<TIniFile>(fn);
    }
    catch (...)
    {
        ShowMessage(L"Ошибка открытия ini-файла с настройками программы");
    }

    Settings.StartDayTime = TimeOf(Ini->ReadTime("Global", "StartDayTime", String("00:00:00")));

    Settings.M_Person = Ini->ReadFloat("Global", "M_Person", 80);
    Settings.B_udel =   Ini->ReadFloat("Global", "B_udel",   1.8);
    Settings.J_udel =   Ini->ReadFloat("Global", "J_udel",   0.8);
    Settings.U_udel =   Ini->ReadFloat("Global", "U_udel",   2.0);
    Settings.K_target = Ini->ReadFloat("Global", "K_target", 1800);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormClose(TObject *Sender, TCloseAction &Action)
{
    SaveSettings();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ActionCalendarExportExecute(TObject *Sender)
{
    if (frmExport->ShowModal() == mrOk)
    {
        String fn = frmExport->dlgSave->FileName;
        if (fn.Length() > 3)
        {
            std::ofstream f(AnsiString(fn).c_str());

            Calendar.ExportToStdStream(frmExport->dtpFrom->Date,
                                       frmExport->dtpTo->Date,
                                       &Prepareds,
                                       f);

            f.close();
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::lbCalendarPreparedsExit(TObject *Sender)
{
    //lbCalendarPrepareds->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::lbCalendarPreparedsMouseLeave(TObject *Sender)
{
//    int ind = lbCalendarPrepareds->ItemIndex;
//    if (ind >= 0)
//    {
//        EditCalendarPreparedSearch->Text = lbCalendarPrepareds->Items->Strings[ind];
//    }
//
//    lbCalendarPrepareds->Hide();
}
//---------------------------------------------------------------------------


