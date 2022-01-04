
#pragma hdrstop

#include "UnitBases.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace std;

//---------------------------------------------------------------------------

bool BasesClass::Add(const std::wstring &_name, float _B, float _J, float _U, float _K, float _Cost)
{
//    pair<BasesMap::iterator, bool> res =
	auto res = Data.insert( make_pair(_name, BJUK_Struct(_B, _J, _U, _K, _Cost)) );

    if (res.second)
        IsSaved = false;

    return res.second;
}
//---------------------------------------------------------------------------

bool BasesClass::Edit(const std::wstring &_name, float _B, float _J, float _U, float _K, float _Cost)
{
	auto it = Data.find(_name);

    if (it == Data.end())
        return false;

	it->second = BJUK_Struct(_B, _J, _U, _K, _Cost);

    IsSaved = false;

    return true;
}
//---------------------------------------------------------------------------

bool BasesClass::Del(const std::wstring &_name)
{
	auto it = Data.find(_name);

    if (it == Data.end())
        return false;

    Data.erase(it);

    IsSaved = false;

    return true;
}
//---------------------------------------------------------------------------

BJUK_Struct BasesClass::GetBJUK(const std::wstring &_name) const
{
	auto it = Data.find(_name);

    if (it == Data.end())
		return BJUK_Struct();

    return it->second;
}
//---------------------------------------------------------------------------

bool BasesClass::CheckBaseExists(const std::wstring &_name) const
{
	auto it = Data.find(_name);

	return it != Data.end();
}
//---------------------------------------------------------------------------


