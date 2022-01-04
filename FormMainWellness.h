//---------------------------------------------------------------------------

#ifndef FormMainWellnessH
#define FormMainWellnessH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Dialogs.hpp>

#include "UnitBasesBuilder.h"
#include "UnitPreparedsBuilder.h"
#include <Vcl.WinXCalendars.hpp>
#include "UnitCalendar.h"


//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TStatusBar *StatusBar1;
	TMainMenu *MainMenu;
	TMenuItem *N1;
	TActionList *ActionList;
	TAction *ActionFileClose;
	TMenuItem *N2;
	TPageControl *pcMain;
	TTabSheet *tsBases;
	TTabSheet *tsPrepared;
	TTabSheet *tsCalendar;
	TStringGrid *gridBases;
	TPanel *pnlBases;
	TSplitter *Splitter1;
	TButton *btnBasesAdd;
	TAction *ActionBasesSaveAs;
	TMenuItem *N3;
	TAction *ActionBasesSave;
	TAction *ActionBasesLoad;
	TSaveDialog *SaveDialog;
	TButton *btnBasesEdit;
	TAction *ActionBasesEdit;
	TMenuItem *N6;
	TMenuItem *N7;
	TAction *ActionBasesAdd;
	TMenuItem *N8;
	TButton *btnBasesDel;
	TAction *ActionBasesDel;
	TMenuItem *N9;
	TGroupBox *GroupBox1;
	TRadioButton *rbBasesSortName;
	TRadioButton *rbBasesSortB;
	TRadioButton *rbBasesSortJ;
	TRadioButton *rbBasesSortU;
	TRadioButton *rbBasesSortK;
	TButton *btnBasesSave;
	TPanel *Panel1;
	TButton *btnPreparedsAdd;
	TButton *btnPreparedsEdit;
	TButton *btnPreparedsDel;
	TGroupBox *GroupBox2;
	TRadioButton *rbPreparedSortName;
	TRadioButton *rbPreparedSortB;
	TRadioButton *rbPreparedSortJ;
	TRadioButton *rbPreparedSortU;
	TRadioButton *rbPreparedSortK;
	TButton *btnPreparedsSave;
	TSplitter *Splitter2;
	TStringGrid *gridPrepareds;
	TAction *ActionPreparedsAdd;
	TAction *ActionPreparedsEdit;
	TAction *ActionPreparedsDel;
	TAction *ActionPreparedsSave;
	TAction *ActionPreparedsSaveAs;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N12;
	TAction *ActionPreparedsLoad;
	TMenuItem *N13;
	TMenuItem *N14;
	TMenuItem *N15;
	TMenuItem *N16;
	TMenuItem *N17;
	TMenuItem *N18;
	TMenuItem *N19;
	TRadioButton *rbPreparedSortM;
	TRadioButton *rbBasesSortCost;
	TRadioButton *rbPreparedSortCost;
	TPanel *pnlBasesTop;
	TEdit *EditBasesSearch;
	TLabel *Label1;
	TPanel *Panel2;
	TLabel *Label2;
	TEdit *EditPreparedsSearch;
	TPanel *pnlCalendarRight;
	TStringGrid *gridCalendar;
	TCalendarView *cvCalendar;
	TEdit *EditCalendarPreparedSearch;
	TListBox *lbCalendarPrepareds;
	TButton *btnCalendarAdd;
	TPanel *Panel3;
	TLabel *Label3;
	TEdit *EditCalendarSearch;
	TAction *ActionCalendarLoad;
	TAction *ActionCalendarSave;
	TAction *ActionCalendarSaveAs;
	TButton *btnCalendarEdit;
	TButton *btnCalendarDelPrepared;
	TLabel *lblDate;
	TButton *Button1;
	TMenuItem *N20;
	TMenuItem *N21;
	TMenuItem *N22;
	TMenuItem *N23;
	TMenuItem *N24;
	TAction *ActionCalendarAdd;
	TAction *ActionCalendarEdit;
	TAction *ActionCalendarDel;
	void __fastcall ActionFileCloseExecute(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ActionBasesSaveAsExecute(TObject *Sender);
	void __fastcall ActionBasesSaveExecute(TObject *Sender);
	void __fastcall ActionBasesLoadExecute(TObject *Sender);
	void __fastcall ActionBasesEditExecute(TObject *Sender);
	void __fastcall ActionBasesAddExecute(TObject *Sender);
	void __fastcall ActionBasesDelExecute(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall ActionPreparedsAddExecute(TObject *Sender);
	void __fastcall ActionPreparedsEditExecute(TObject *Sender);
	void __fastcall ActionPreparedsDelExecute(TObject *Sender);
	void __fastcall ActionPreparedsSaveExecute(TObject *Sender);
	void __fastcall ActionPreparedsSaveAsExecute(TObject *Sender);
	void __fastcall ActionPreparedsLoadExecute(TObject *Sender);

	void __fastcall FormShow(TObject *Sender);
	void __fastcall gridPreparedsMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall EditBasesSearchChange(TObject *Sender);
	void __fastcall EditPreparedsSearchChange(TObject *Sender);
	void __fastcall EditCalendarPreparedSearchChange(TObject *Sender);
	void __fastcall EditCalendarPreparedSearchKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall lbCalendarPreparedsDblClick(TObject *Sender);
	void __fastcall lbCalendarPreparedsKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);

	void __fastcall PrintBases(TObject *Sender);
	void __fastcall PrintPrepareds(TObject *Sender);
	void __fastcall PrintCalendar(TObject *Sender);
	void __fastcall EditCalendarSearchChange(TObject *Sender);
	void __fastcall ActionCalendarLoadExecute(TObject *Sender);
	void __fastcall ActionCalendarSaveExecute(TObject *Sender);
	void __fastcall ActionCalendarSaveAsExecute(TObject *Sender);
	void __fastcall cvCalendarChange(TObject *Sender);
	void __fastcall cvCalendarDrawDayItem(TObject *Sender, TDrawViewInfoParams *DrawParams,
          TCellItemViewInfo *CalendarViewViewInfo);
	void __fastcall EditCalendarPreparedSearchKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall ActionCalendarAddExecute(TObject *Sender);
	void __fastcall ActionCalendarEditExecute(TObject *Sender);
	void __fastcall ActionCalendarDelExecute(TObject *Sender);


private:	// User declarations

	bool QuerySaveBases();
	bool QuerySavePrepareds();
	bool QuerySaveCalendar();

    TDate LastSelectedDate;

public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);

    BasesBuilder Bases;
	PreparedsBuilder Prepareds;
	CalendarClass Calendar;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
