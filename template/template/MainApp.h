#pragma once

class MainApp : public wxApp
{
public :
    bool OnInit() override final;
};

wxDECLARE_APP(MainApp);