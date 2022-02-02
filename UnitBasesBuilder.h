//---------------------------------------------------------------------------
#ifndef UnitBasesBuilderH
#define UnitBasesBuilderH
//---------------------------------------------------------------------------

#include "UnitBases.h"
//#include <vcl.h>
#include <Vcl.Grids.hpp>

class BasesBuilder : public BasesClass
{
public:

    void ClearTable(TStringGrid *grid) const;
    void PrintToTable(TStringGrid *grid, HowToSort _SortType, String _SearchString) const;

    void PrintToComboBox(TComboBox *cb, String _SearchString) const;

    void PrintToListBox(TListBox *lb, String _SearchString) const;

    bool SaveToJSON(String _FullFileName);
    bool LoadFromJSON(String _FullFileName);
};



#endif
