#include "define.h"
#include "InfoPanel.h"

InfoPanel::InfoPanel(wxWindow* parent)
    : wxPanel(parent, GID::ID_PANEL_INFO, wxDefaultPosition, { 150, -1 })
{

    SetBackgroundColour("#DDDDDD");
}