#ifndef client_h
#define client_h
#include <wx/wx.h>
#include <wx/wxprec.h>

class Button{

    private:
    int i,j, x,y;
    

    public:
    wxButton *button;
    Button(wxFrame *frame, int i, int j, int x, int y);
};



#endif