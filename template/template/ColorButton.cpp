#include "define.h"
#include "ColorButton.h"

wxDEFINE_EVENT(EVT_CLICK_BUTTON, wxCommandEvent);

ColorButton::ColorButton(wxWindow* parent,
                         wxWindowID id,
                         const wxString& label,
                         const wxPoint& pos,
                         const wxSize& size,
                         const wxColour& text,
                         const wxColour& normal,
                         const wxColour& hover,
                         const wxColour& pressed,
                         const wxColour& selected)
    : wxWindow(parent, id, pos, size)
    , m_current_state(STATE_NORMAL)
    , m_selected(false)
    , m_event_window(wxID_ANY)
    , m_color_table({ {
        {normal, text},
        {hover, text},
        {pressed, text},
        {selected, text},
    }})
{
    SetLabel(label);
}

wxBEGIN_EVENT_TABLE(ColorButton, wxWindow)
EVT_PAINT(ColorButton::OnPaint)
EVT_MOUSE_EVENTS(ColorButton::OnMouseEvent)
wxEND_EVENT_TABLE()

void ColorButton::SetColour(ButtonColorTag tag, const wxColour& color)
{
    if (tag == ButtonColorTag::TextColor)
    {
        for (auto& e : m_color_table)
        {
            e[ColorType::FORE_COLOR] = color;
        }
        Refresh(false);
    }
    else if (tag == ButtonColorTag::NormalColor ||
             tag == ButtonColorTag::HoverColor ||
             tag == ButtonColorTag::PressedColor ||
             tag == ButtonColorTag::SelectedColor)
    {
        m_color_table[tag][ColorType::BACK_COLOR] = color;
        Refresh(false);
    }
}
void ColorButton::OnPaint(wxPaintEvent&)
{
    wxPaintDC dc(this);

    wxRect stringrc = wxRect(dc.GetTextExtent(GetLabel()));
    wxRect rc = GetClientRect();

    stringrc = stringrc.CenterIn(rc);

    dc.SetBrush(wxBrush(m_color_table[m_current_state][ColorType::BACK_COLOR]));
    dc.SetPen(wxPen(m_color_table[m_current_state][ColorType::BACK_COLOR]));
    dc.DrawRectangle(rc);

    dc.SetTextForeground(m_color_table[m_current_state][ColorType::FORE_COLOR]);
    dc.DrawText(GetLabel(), stringrc.GetLeftTop());
}
void ColorButton::OnMouseEvent(wxMouseEvent& e)
{
    if (e.GetEventType() == wxEVT_ENTER_WINDOW)
    {
        m_current_state = STATE_HOVER;
        Refresh(false);
    }
    else if (e.GetEventType() == wxEVT_LEAVE_WINDOW)
    {
        if (m_selected)
            m_current_state = STATE_SELECTED;
        else
            m_current_state = STATE_NORMAL;
        Refresh(false);
    }
    else if (e.GetEventType() == wxEVT_LEFT_DOWN)
    {
        m_event_window = e.GetId();

        m_current_state = STATE_PRESSED;
        Refresh(false);
    }
    else if (e.GetEventType() == wxEVT_LEFT_UP)
    {
        if (m_event_window == e.GetId())
        {
            m_current_state = STATE_NORMAL;
            Refresh(false);

            wxCommandEvent click_event(EVT_CLICK_BUTTON, GetId());
            GetParent()->GetEventHandler()->AddPendingEvent(click_event);
        }
    }
}
