#pragma once
#include "../service/remote_info.hpp"

#include <wx/wx.h>

#include <memory>


namespace gui
{

class Utils
{
public:
    static Utils* get();
    static wxString makeIntResource( int resource );

    const wxFont& getHeaderFont() const;
    wxColour getHeaderColor() const;

    static void drawTextEllipse( wxDC& dc, const wxString& text,
        const wxPoint& pnt, const wxCoord maxWidth );

    static wxString getStatusString( srv::RemoteStatus status );

private:
    // We need a friend to create a unique_ptr
    friend std::unique_ptr<Utils> std::make_unique<Utils>();

    Utils();

    static std::unique_ptr<Utils> s_inst;

    wxFont m_headerFont;
    wxColour m_headerColor;
};

};