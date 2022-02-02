//---------------------------------------------------------------------------
#ifndef UnitPreparedsBuilderH
#define UnitPreparedsBuilderH
//---------------------------------------------------------------------------

#include "UnitPrepareds.h"

#include <Vcl.Grids.hpp>

class PreparedsBuilder : public PreparedsClass
{
public:

    void ClearTable(TStringGrid *grid) const;
    void PrintAllToTable(TStringGrid *grid, HowToSort _SortType,
                         String _SearchString) const;

    bool SaveToJSON(String _FullFileName);
    bool LoadFromJSON(String _FullFileName);

    void PrintToListBox(TListBox *lb, String _SearchString) const;
};

#endif
