//---------------------------------------------------------------------------
#ifndef UnitCalendarH
#define UnitCalendarH
//---------------------------------------------------------------------------

#include <system.hpp>
#include <Vcl.Grids.hpp>
#include <System.JSON.Writers.hpp>

#include <string>
#include <map>
#include <memory>

#include "UnitBases.h"
#include "UnitPreparedsBuilder.h"


using OnePreparedPair = std::pair<std::wstring, float>;
using OneDayMap       = std::map<std::wstring, float>;
using CalendarMap     = std::map<TDate, OneDayMap >;

class CalendarClass
{
protected:
    CalendarMap Calendar;
    bool IsSaved = true;

public:
    CalendarClass() = default;

    bool Add(TDate _Date, const OnePreparedPair &_OnePreparedPair);

    bool Edit(TDate _Date, const OnePreparedPair &_OnePreparedPair);

    bool Del(TDate _Date, const std::wstring &_name);

    int GetCountOfMonth() const {return Calendar.size();}
    int GetCountForDay(TDate _Date) const;

    bool GetIsSaved() const {return IsSaved;}

    void ClearTable(TStringGrid *grid) const;
    void PrintOneDayToTable(TDate _Date, TStringGrid *grid,
                HowToSort _SortType, String _SearchString,
                PreparedsBuilder *pPrepareds) const;

    bool SaveToJSON(String _FullFileName);

    void ProcessOneDay(TDate _Date, std::unique_ptr<TJsonTextReader> &Reader);
    bool LoadFromJSON(String _FullFileName);

    void ExportToStdStream(TDate _DateFrom, TDate _DateTo,
                                 PreparedsBuilder *pPrepareds,
                                 std::ostream &stream) const;
};


#endif
