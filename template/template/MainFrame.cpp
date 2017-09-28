#include "define.h"
#include "MainFrame.h"

#include "MainPanel.h"

static const long style = wxCLIP_CHILDREN | wxBORDER_SIMPLE;
MainFrame::MainFrame()
    : wxFrame(NULL, wxID_ANY, wxT("template"), wxDefaultPosition, { 600, 400 }, style)
{
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    {
        MainPanel* main = new MainPanel(this);
        sizer->Add(main, 1, wxEXPAND);
    }
    SetSizer(sizer);
    Layout();

    Center();
}