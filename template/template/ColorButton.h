#pragma once

enum ButtonColorTag
{
    TextColor = -1,
    NormalColor,
    HoverColor,
    PressedColor,
    SelectedColor
};

wxDECLARE_EVENT(EVT_CLICK_BUTTON, wxCommandEvent);

class ColorButton : public wxWindow
{
    enum ButtonState
    {
        STATE_NORMAL = 0,
        STATE_HOVER,
        STATE_PRESSED,
        STATE_SELECTED,
        STATE_MAX,
    };
    enum ColorType
    {
        BACK_COLOR = 0,
        FORE_COLOR,
        MAX_COLOR
    };
public :
    ColorButton(wxWindow* parent,
                wxWindowID id,
                const wxString& label = wxEmptyString,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                const wxColour& text = wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNTEXT),
                const wxColour& normal = wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE),
                const wxColour& hover = wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHILIGHT),
                const wxColour& pressed = wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW),
                const wxColour& selected = wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHILIGHT));

    void SetSelection(bool selected) { m_selected = selected; }
    bool GetSelection() const { return m_selected; }

    void SetColour(ButtonColorTag tag, const wxColour& color);

private :
    int m_current_state;
    bool m_selected;
    wxWindowID m_event_window;
    std::array<std::array<wxColour, ColorType::MAX_COLOR>, ButtonState::STATE_MAX> m_color_table;

    void OnPaint(wxPaintEvent&);
    void OnMouseEvent(wxMouseEvent&);

    wxDECLARE_EVENT_TABLE();
};