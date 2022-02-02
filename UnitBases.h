//---------------------------------------------------------------------------

#ifndef UnitBasesH
#define UnitBasesH
//---------------------------------------------------------------------------

#include <string>
#include <map>

enum class HowToSort
{
    Name,
    B,
    J,
    U,
    K,
    Cost,
    M
};

struct BJUK_Struct
{
    float B, J, U, K, Cost;

    BJUK_Struct() : B(0), J(0), U(0), K(0), Cost(0) {}

    BJUK_Struct(float _B, float _J, float _U, float _K, float _Cost)
              : B(_B), J(_J), U(_U), K(_K), Cost(_Cost) {}
};

using BasesMap  = std::map<std::wstring,BJUK_Struct>;
using BasesPair = std::pair<std::wstring,BJUK_Struct>;

class BasesClass
{
protected:
    BasesMap Data;
    bool IsSaved = true;

public:

    BasesClass() = default;

    bool Add(const std::wstring &_name, float _B, float _J, float _U, float _K, float _Cost);

    bool Edit(const std::wstring &_name, float _B, float _J, float _U, float _K, float _Cost);

    bool Del(const std::wstring &_name);

    int GetCount() const {return Data.size();}

    bool CheckBaseExists(const std::wstring &_name) const;

    BJUK_Struct GetBJUK(const std::wstring &_name) const;

    bool GetIsSaved() const {return IsSaved;}
};


#endif
