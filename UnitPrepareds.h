//---------------------------------------------------------------------------
#ifndef UnitPreparedsH
#define UnitPreparedsH
//---------------------------------------------------------------------------

#include <string>
#include <map>
#include <vector>

#include "UnitBases.h"

struct BJUKM_Struct : BJUK_Struct
{
	float M;

    BJUKM_Struct() : BJUK_Struct(), M(0) {}

	BJUKM_Struct(float _B, float _J, float _U, float _K, float _Cost, float _M) :
		BJUK_Struct(_B, _J, _U, _K, _Cost) , M(_M)  {}
};

using PreparedsList = std::vector<std::pair<std::wstring,float>>;

struct PreparedStruct
{
    BJUKM_Struct Finished;
	PreparedsList List;
};

using PreparedsMap = std::map<std::wstring,PreparedStruct>;
using PreparedsPair = std::pair<std::wstring,PreparedStruct>;

class PreparedsClass
{
protected:
	PreparedsMap Data;

	bool IsSaved = true;

public:

    PreparedsClass() = default;

    bool Add(const std::wstring &_name, const PreparedStruct &_Prepared);

	bool Edit(const std::wstring &_name, const PreparedStruct &_Prepared);

	bool Del(const std::wstring &_name);

	int GetCount() const {return Data.size();}
	PreparedStruct GetPrepared(const std::wstring &_name) const;
	bool CheckPreparedExists(const std::wstring &_name) const;

	BJUKM_Struct GetBJUKM(const std::wstring &_name) const;

	bool GetIsSaved() const {return IsSaved;}
};


#endif
