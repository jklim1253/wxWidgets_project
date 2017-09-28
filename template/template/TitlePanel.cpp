#include "define.h"
#include "TitlePanel.h"

#include "MainApp.h"

static const wxSize buttonsize(30, 30);

TitlePanel::TitlePanel(wxWindow* parent)
    : wxPanel(parent, GID::ID_PANEL_TITLE, wxDefaultPosition, {-1, 30})
{
    wxFont font(wxFontInfo(10).FaceName("Webdings"));
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    {
        ColorButton* close = new ColorButton(this, GID::ID_CTRL_BUTTON_CLOSE, wxT("r"), wxDefaultPosition, buttonsize);
        {
            close->SetFont(font);
            close->SetColour(ButtonColorTag::TextColor, "#000000");
            close->SetColour(ButtonColorTag::NormalColor, "#AAAAAA");
            close->SetColour(ButtonColorTag::HoverColor, "#FF0000");
            close->SetColour(ButtonColorTag::PressedColor, "#555555");
            close->SetColour(ButtonColorTag::SelectedColor, "#0000FF");
        }

        sizer->AddStretchSpacer();
        sizer->Add(close, 0);
    }
    SetSizer(sizer);
    Layout();

    SetBackgroundColour("#aaaaaa");

    Bind(EVT_CLICK_BUTTON, &TitlePanel::OnButton, this, GID::ID_CTRL_BUTTON_CLOSE);
}

wxBEGIN_EVENT_TABLE(TitlePanel, wxPanel)
EVT_MOUSE_EVENTS(TitlePanel::OnMouseEvent)
EVT_MOUSE_CAPTURE_LOST(TitlePanel::OnMouseCaptureLost)
wxEND_EVENT_TABLE()

void TitlePanel::OnButton(wxCommandEvent& e)
{
    if (e.GetId() == GID::ID_CTRL_BUTTON_CLOSE)
    {
        wxGetApp().GetTopWindow()->Close(false);
    }
}

void TitlePanel::OnMouseEvent(wxMouseEvent& e)
{
    static wxPoint ptLast = wxGetMousePosition();

    if (e.GetEventType() == wxEVT_MOTION && e.Dragging())
    {
        if (!HasCapture()) return;

        wxPoint ptMouse = wxGetMousePosition();

        wxPoint ptDiff = ptMouse - ptLast;

        wxPoint pos = wxGetApp().GetTopWindow()->GetScreenPosition();

        wxGetApp().GetTopWindow()->Move(pos + ptDiff);

        ptLast = ptMouse;
    }
    else if (e.GetEventType() == wxEVT_LEFT_DOWN)
    {
        if (!HasCapture())
            CaptureMouse();

        ptLast = wxGetMousePosition();
    }
    else if (e.GetEventType() == wxEVT_LEFT_UP)
    {
        if (HasCapture())
            ReleaseCapture();
    }
}

void TitlePanel::OnMouseCaptureLost(wxMouseCaptureLostEvent&)
{
}