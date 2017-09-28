#include "define.h"
#include "MenuPanel.h"

MenuPanel::MenuPanel(wxWindow* parent)
    : wxPanel(parent, GID::ID_PANEL_MENU, wxDefaultPosition, { 30, -1 })
{

    SetBackgroundColour("#BBBBBB");
}