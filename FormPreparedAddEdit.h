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
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmPreparedsAddEdit : public TForm
{
__published:    // IDE-managed Components
    TPanel *pnlBottom;
    TListBox *lbBases;
    TButton *btnAddFromBases;
    TButton *btnCancel;
    TButton *btnDone;
    TButton *btnReCalc;
    TButton *btnEditM;
    TEdit *EditSearchBases;
    TPanel *pnlTop;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TGroupBox *GroupBox1;
    TRadioButton *rbFinished;
    TRadioButton *rbBuild;
    TEdit *EditName;
    TEdit *EditB;
    TEdit *EditJ;
    TEdit *EditU;
    TEdit *EditK;
    TEdit *EditM;
    TEdit *EditCost;
    TPanel *pnlCentral;
    TStringGrid *gridList;
    TPanel *pnlCentralTop;
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


private:    // User declarations

    PreparedStruct Prepared;

    void ClearTable();

    BasesBuilder *pBases;
    PreparedsBuilder *pPrepareds;

    bool StateIsNew;

public:        // User declarations
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
