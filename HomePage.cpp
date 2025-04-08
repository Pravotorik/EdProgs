#include "HomePage.h"

#include "FilteredResultsForm.h"
#include <Windows.h>

using namespace EdProgs;

// однопоточна€ модель, взаимод. с COM 
// дескриптор экземпл€ра, предыдущ. дескр.,
// команд.строка, флаг 

[STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew HomePage);
    return 0;
}