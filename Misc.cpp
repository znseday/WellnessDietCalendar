//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <Misc.h>

void CorrectDecSeparator(String &s)
{
    if (FormatSettings.DecimalSeparator == ',')
        s = StringReplace(s, ".", ",", TReplaceFlags() << rfReplaceAll);
    else if (FormatSettings.DecimalSeparator == '.')
        s = StringReplace(s, ",", ".", TReplaceFlags() << rfReplaceAll);
}
