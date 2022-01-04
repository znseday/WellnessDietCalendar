//---------------------------------------------------------------------------

#pragma hdrstop

#include "UnitPrepareds.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace std;

//---------------------------------------------------------------------------

bool PreparedsClass::Add(const std::wstring &_name, const PreparedStruct &_Prepared)
{
	auto res = Data.insert( make_pair(_name, _Prepared) );

	if (res.second)
        IsSaved = false;

	return res.second;
}
//---------------------------------------------------------------------------

bool PreparedsClass::Edit(const std::wstring &_name, const PreparedStruct &_Prepared)
{
	auto it = Data.find(_name);

    if (it == Data.end())
        return false;

	it->second = _Prepared;

    IsSaved = false;

	return true;
}
//---------------------------------------------------------------------------

bool PreparedsClass::Del(const std::wstring &_name)
{
	auto it = Data.find(_name);

    if (it == Data.end())
        return false;

    Data.erase(it);

    IsSaved = false;

    return true;
}
//---------------------------------------------------------------------------

PreparedStruct PreparedsClass::GetPrepared(const std::wstring &_name) const
{
	auto it = Data.find(_name);

	if (it == Data.end())
		return PreparedStruct();

    return it->second;
}
//---------------------------------------------------------------------------

bool PreparedsClass::CheckPreparedExists(const std::wstring &_name) const
{
	auto it = Data.find(_name);

	return it != Data.end();
}
//---------------------------------------------------------------------------

BJUKM_Struct PreparedsClass::GetBJUKM(const std::wstring &_name) const
{
	auto it = Data.find(_name);

    if (it == Data.end())
		return BJUKM_Struct();

    return it->second.Finished;
}
//---------------------------------------------------------------------------


