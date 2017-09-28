#include "define.h"
#include "MainApp.h"

#include "MainFrame.h"

wxIMPLEMENT_APP(MainApp);

bool MainApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    MainFrame* frame = new MainFrame();
    frame->Show();

    return true;
}