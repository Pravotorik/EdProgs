#include "HomePage.h"

#include "GlobalSettings.h"
#include "FilteredResultsForm.h"
#include <Windows.h>


using namespace EdProgs;

// ������������ ������, �������. � COM 
// ���������� ����������, ��������. �����.,
// ������.������, ���� 

[STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew HomePage);
    return 0;
}