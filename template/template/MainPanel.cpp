#include "define.h"
#include "MainPanel.h"

#include "TitlePanel.h"
#include "MenuPanel.h"
#include "InfoPanel.h"
#include "ViewPanel.h"

MainPanel::MainPanel(wxWindow* parent)
    : wxPanel(parent, GID::ID_PANEL_MAIN)
{
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    {
        TitlePanel* header = new TitlePanel(this);
        wxBoxSizer* body = new wxBoxSizer(wxHORIZONTAL);
        {
            MenuPanel* menu = new MenuPanel(this);
            InfoPanel* info = new InfoPanel(this);
            ViewPanel* view = new ViewPanel(this);

            body->Add(menu, 0, wxEXPAND);
            body->Add(info, 0, wxEXPAND);
            body->Add(view, 1, wxEXPAND);
        }
        sizer->Add(header, 0, wxEXPAND);
        sizer->Add(body, 1, wxEXPAND);
    }
    SetSizer(sizer);
    Layout();

    SetBackgroundColour("#FF0000");
}