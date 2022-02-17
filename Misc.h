//---------------------------------------------------------------------------
#ifndef MiscH
#define MiscH
//---------------------------------------------------------------------------

#include <vcl.h>

void CorrectDecSeparator(String &s);

struct SettingsStruct
{
    TTime StartDayTime;

    double M_Person = 80;
    double B_udel = 1.5;
    double J_udel = 0.8;
    double U_udel = 2.0;
    double K_target = 1800;

    double WarningPercent = 80;
};


#endif
