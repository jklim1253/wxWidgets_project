#pragma once

class TitlePanel : public wxPanel
{
public :
    TitlePanel(wxWindow* parent);

private :
    void OnButton(wxCommandEvent&);
    void OnMouseEvent(wxMouseEvent&);
    void OnMouseCaptureLost(wxMouseCaptureLostEvent&);

    wxDECLARE_EVENT_TABLE();
};