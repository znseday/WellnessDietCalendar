//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("FormPreparedAddEdit.cpp", frmPreparedsAddEdit);
USEFORM("FormMainWellness.cpp", frmMain);
USEFORM("FormBasesAddEdit.cpp", frmBasesAddEdit);
USEFORM("FormSettings.cpp", frmSettings);
USEFORM("FormExport.cpp", frmExport);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
    try
    {
        Application->Initialize();
        Application->MainFormOnTaskBar = true;
        Application->Title = "Wellness Diet Calendar (by TsynkinSA)";
        Application->CreateForm(__classid(TfrmMain), &frmMain);
         Application->CreateForm(__classid(TfrmBasesAddEdit), &frmBasesAddEdit);
         Application->CreateForm(__classid(TfrmPreparedsAddEdit), &frmPreparedsAddEdit);
         Application->CreateForm(__classid(TfrmSettings), &frmSettings);
         Application->CreateForm(__classid(TfrmExport), &frmExport);
         Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    catch (...)
    {
        try
        {
            throw Exception("");
        }
        catch (Exception &exception)
        {
            Application->ShowException(&exception);
        }
    }
    return 0;
}
//---------------------------------------------------------------------------
