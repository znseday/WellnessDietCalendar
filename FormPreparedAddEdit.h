//---------------------------------------------------------------------------

#ifndef FormPreparedAddEditH
#define FormPreparedAddEditH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include "UnitPrepareds.h"
#include "UnitBasesBuilder.h"
#include "UnitPreparedsBuilder.h"
//---------------------------------------------------------------------------
class TfrmPreparedsAddEdit : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TRadioButton *rbFinished;
	TRadioButton *rbBuild;
	TStringGrid *gridList;
	TButton *btnAddFromBases;
	TButton *btnCancel;
	TButton *btnDone;
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
	TLabel *Label6;
	TEdit *EditM;
	TLabel *Label7;
	TEdit *EditCost;
	TButton *btnReCalc;
	TButton *btnEditM;
	TEdit *EditSearchBases;
	TListBox *lbBases;
	TLabel *Label8;
	void __fastcall rbFinishedClick(TObject *Sender);
	void __fastcall rbBuildClick(TObject *Sender);
	void __fastcall btnCancelClick(TObject *Sender);
	void __fastcall btnDoneClick(TObject *Sender);
	void __fastcall btnReCalcClick(TObject *Sender);
	void __fastcall btnAddFromBasesClick(TObject *Sender);
	void __fastcall btnEditMClick(TObject *Sender);
	void __fastcall EditSearchBasesChange(TObject *Sender);
	void __fastcall EditSearchBasesKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall lbBasesDblClick(TObject *Sender);
	void __fastcall lbBasesKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall EditSearchBasesKeyPress(TObject *Sender, System::WideChar &Key);


private:	// User declarations

    PreparedStruct Prepared;

	void ClearTable();

    BasesBuilder *pBases;
    PreparedsBuilder *pPrepareds;

    bool StateIsNew;

public:		// User declarations
	__fastcall TfrmPreparedsAddEdit(TComponent* Owner);

    void InitPointers(BasesBuilder *_pBases, PreparedsBuilder *_pPrepareds)
    {
    	pBases = _pBases;
        pPrepareds = _pPrepareds;
    }

    void ResetPrepared();
    void InitPrepared(const String _Name, const PreparedStruct &_Prepared);

    void SwitchToFinished();
    void SwitchToBuild();

    void SetItIsNew() {StateIsNew = true;}
	void SetItIsEdit() {StateIsNew = false;}

	void InitBasesList();

    void InitControls();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPreparedsAddEdit *frmPreparedsAddEdit;
//---------------------------------------------------------------------------
#endif
