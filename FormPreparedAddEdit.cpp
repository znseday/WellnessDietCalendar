//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormPreparedAddEdit.h"
#include "FormMainWellness.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmPreparedsAddEdit *frmPreparedsAddEdit;
//---------------------------------------------------------------------------
__fastcall TfrmPreparedsAddEdit::TfrmPreparedsAddEdit(TComponent* Owner)
	: TForm(Owner)
{
	pBases = NULL;
	pPrepareds = NULL;

	StateIsNew = true;
}
//---------------------------------------------------------------------------

void TfrmPreparedsAddEdit::InitBasesList()
{
	if (!pBases)
		return;

	//pBases->PrintToComboBox(ComboBox);
}
//---------------------------------------------------------------------------

void TfrmPreparedsAddEdit::ResetPrepared()
{
    Prepared = PreparedStruct();
    EditName->Text = L"";
}
//---------------------------------------------------------------------------

void TfrmPreparedsAddEdit::InitPrepared(const String _Name, const PreparedStruct &_Prepared)
{
    Prepared = _Prepared;
	EditName->Text = _Name;

	if ( Prepared.List.empty() )
	{
		rbFinished->Checked = true;
	}
	else
	{
		rbBuild->Checked = true;
	}
}
//---------------------------------------------------------------------------

void TfrmPreparedsAddEdit::SwitchToFinished()
{
    gridList->RowCount = 2;

    //ClearTable();
    InitControls();

    EditB->Enabled = true;
    EditJ->Enabled = true;
    EditU->Enabled = true;
    EditK->Enabled = true;
    EditM->Enabled = true;
    EditCost->Enabled = true;

	gridList->Enabled = false;

	btnAddFromBases->Enabled = false;
	btnReCalc->Enabled = false;
	btnEditM->Enabled = false;
	EditSearchBases->Enabled = false;

    //gridList->Options << goEditing;
}
//---------------------------------------------------------------------------

void TfrmPreparedsAddEdit::SwitchToBuild()
{
    gridList->RowCount = 10;

    EditB->Enabled = false;
    EditJ->Enabled = false;
    EditU->Enabled = false;
    EditK->Enabled = false;
    EditM->Enabled = false;
    EditCost->Enabled = false;

	gridList->Enabled = true;

	btnAddFromBases->Enabled = true;
	btnReCalc->Enabled = true;
    btnEditM->Enabled = true;
    EditSearchBases->Enabled = true;

	InitControls();

    //gridList->Options >> goEditing;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPreparedsAddEdit::rbFinishedClick(TObject *Sender)
{
    SwitchToFinished();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPreparedsAddEdit::rbBuildClick(TObject *Sender)
{
	SwitchToBuild();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPreparedsAddEdit::btnCancelClick(TObject *Sender)
{
    Close();
    // ModalResult = mrClose;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPreparedsAddEdit::btnDoneClick(TObject *Sender)
{
    if (rbFinished->Checked)
    {
        Prepared.List.clear();

    }
    else if (rbBuild->Checked)
    {
		//
	}

	Prepared.Finished.B = StrToFloatDef( EditB->Text, 0 );
	Prepared.Finished.J = StrToFloatDef( EditJ->Text, 0 );
	Prepared.Finished.U = StrToFloatDef( EditU->Text, 0 );
	Prepared.Finished.K = StrToFloatDef( EditK->Text, 0 );
	Prepared.Finished.M = StrToFloatDef( EditM->Text, 0 );
	Prepared.Finished.Cost = StrToFloatDef( EditCost->Text, 0 );

	if (StateIsNew)
	{
		if ( pPrepareds->Add(EditName->Text.c_str(), Prepared) )
		{
			Close();
			frmMain->PrintPrepareds(this);
		}
		else
		{
			ShowMessage(L"Ошибка при добавлении новой записи. Возможно такая запись уже существует");
			return;
		}
	}
	else
	{
		if ( pPrepareds->Edit(EditName->Text.c_str(), Prepared) )
		{
			Close();
			frmMain->PrintPrepareds(this);
            frmMain->PrintCalendar(this);
		}
		else
		{
			ShowMessage(L"Ошибка при добавлении новой записи. Возможно такая запись уже существует");
			return;
		}
	}

	// ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void TfrmPreparedsAddEdit::ClearTable()
{
    gridList->RowCount = 2;

    gridList->ColWidths[0] = 160;

    gridList->Cells[0][0] = L"Название, г";
    gridList->Cells[1][0] = L"Белки, г";
    gridList->Cells[2][0] = L"Жиры, г";
    gridList->Cells[3][0] = L"Углеводы, г";
    gridList->Cells[4][0] = L"Калории, ккал";
    gridList->Cells[5][0] = L"Стоимость, руб";
	gridList->Cells[6][0] = L"Масса, г";

    for (int j = 0; j < gridList->ColCount; j++)
    	gridList->Cells[j][1] = L"";
}
//---------------------------------------------------------------------------

void TfrmPreparedsAddEdit::InitControls()
{
    ClearTable();

	EditB->Text = FloatToStrF(Prepared.Finished.B, ffFixed, 12,1);
	EditJ->Text = FloatToStrF(Prepared.Finished.J, ffFixed, 12,1);
	EditU->Text = FloatToStrF(Prepared.Finished.U, ffFixed, 12,1);
	EditK->Text = FloatToStrF(Prepared.Finished.K, ffFixed, 12,1);
	EditM->Text = FloatToStrF(Prepared.Finished.M, ffFixed, 12,1);
	EditCost->Text = FloatToStrF(Prepared.Finished.Cost, ffFixed, 12,1);

	if (rbBuild->Checked)
	{
		if (Prepared.List.size() > 1)
			gridList->RowCount = Prepared.List.size() + 1;
		else
			gridList->RowCount = 2;

		int i = 1;

		for (PreparedsList::iterator it = Prepared.List.begin();
												it != Prepared.List.end(); ++it, ++i)
		{
			gridList->Cells[0][i] = it->first.c_str();

			BJUK_Struct BJUK = pBases->GetBJUK(it->first.c_str());

			gridList->Cells[1][i] = FloatToStrF(BJUK.B, ffFixed, 12,1);
			gridList->Cells[2][i] = FloatToStrF(BJUK.J, ffFixed, 12,1);
			gridList->Cells[3][i] = FloatToStrF(BJUK.U, ffFixed, 12,1);
			gridList->Cells[4][i] = FloatToStrF(BJUK.K, ffFixed, 12,1);
			gridList->Cells[5][i] = FloatToStrF(BJUK.Cost, ffFixed, 12,1);
			gridList->Cells[6][i] = FloatToStrF(it->second, ffFixed, 12,1);
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TfrmPreparedsAddEdit::btnReCalcClick(TObject *Sender)
{
	int i = 1;

	float sum_B = 0;
	float sum_J = 0;
	float sum_U = 0;
	float sum_K = 0;
	float sum_M = 0;
	float sum_Cost = 0;

	for (auto it = Prepared.List.cbegin(); it != Prepared.List.cend(); ++it, ++i)
    {
        gridList->Cells[0][i] = it->first.c_str();

        BJUK_Struct BJUK = pBases->GetBJUK(it->first.c_str());

		sum_B += BJUK.B * it->second / 100.0f;
		sum_J += BJUK.J * it->second / 100.0f;
		sum_U += BJUK.U * it->second / 100.0f;
		sum_K += BJUK.K * it->second / 100.0f;
		sum_Cost += BJUK.Cost * it->second / 100.0f;
		sum_M += it->second;
	}

	Prepared.Finished = BJUKM_Struct(sum_B, sum_J, sum_U, sum_K, sum_Cost, sum_M);

    InitControls();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPreparedsAddEdit::btnAddFromBasesClick(TObject *Sender)
{

	String Name = EditSearchBases->Text;

	if (! pBases->CheckBaseExists( Name.c_str()) )
	{
		ShowMessage(L"Такого продукта не существует в базе");
		return;
	}

	String res = InputBox(L"Вопрос", L"Сколько грамм\n" + Name + L"\n?", "");
	if (res == "") {
		return;
	}

	float m = StrToFloatDef(res, 0);

	Prepared.List.push_back(std::make_pair(Name.c_str(), m));

	btnReCalc->Click();

	InitControls();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPreparedsAddEdit::btnEditMClick(TObject *Sender)
{
	size_t row = gridList->Selection.Top;

	if (Prepared.List.size() < 1 || row < 1 || row > Prepared.List.size())
	{
		ShowMessage(L"Не выбраны данные для редактирования");
		return;
	}

	String Name = gridList->Cells[0][row];
	float m = StrToFloatDef( gridList->Cells[6][row], 0 );

	String res = InputBox(L"Вопрос", L"Сколько грамм\n" + Name + L"\n?", m);
	if (res == "")
	{
		return;
	}

	m = StrToFloatDef(res, 0);

	for (auto it = Prepared.List.begin(); it != Prepared.List.end(); ++it)
	{
		if ( it->first == Name.c_str() )
		{
			it->second = m;
            break;
		}
	}

	btnReCalc->Click();

	InitControls();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPreparedsAddEdit::EditSearchBasesChange(TObject *Sender)
{
	String SearchString = EditSearchBases->Text;
	pBases->PrintToListBox(lbBases, SearchString);

	if (SearchString.Length() > 0)
		btnAddFromBases->Enabled = true;
	else
		btnAddFromBases->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPreparedsAddEdit::EditSearchBasesKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
	if ( !lbBases->Visible )
		return;

	if (Key == vkDown)
	{
		if (lbBases->ItemIndex < lbBases->Count-1)
		{
			lbBases->ItemIndex++;
		}
		Key = 0;
	}
	if (Key == vkUp)
	{
		if (lbBases->ItemIndex > 0)
		{
			lbBases->ItemIndex--;
		}
        Key = 0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmPreparedsAddEdit::lbBasesDblClick(TObject *Sender)
{
	EditSearchBases->Text = lbBases->Items->Strings[lbBases->ItemIndex];
	lbBases->Clear();
	lbBases->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPreparedsAddEdit::lbBasesKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key == vkReturn)
	{
		EditSearchBases->Text = lbBases->Items->Strings[lbBases->ItemIndex];
		lbBases->Clear();
		lbBases->Visible = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmPreparedsAddEdit::EditSearchBasesKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key == vkReturn)
	{
		if ( lbBases->Visible )
		{
			EditSearchBases->Text = lbBases->Items->Strings[lbBases->ItemIndex];
			lbBases->Clear();
			lbBases->Visible = false;
		}

		Key = 0;
	}
}
//---------------------------------------------------------------------------

