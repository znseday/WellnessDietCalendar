//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("FormBasesAddEdit.cpp", frmBasesAddEdit);
USEFORM("FormMainWellness.cpp", frmMain);
USEFORM("FormPreparedAddEdit.cpp", frmPreparedsAddEdit);
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
