#include "button.h"
#include <wx/wx.h>
#include <wx/wxprec.h>

Button::Button(wxFrame *frame, int i, int j, int x, int y){
    this->i = i;
    this->j = j;
    button = new wxButton(*frame, wxID_ANY, wxT("CARD"), wxPoint(x,y));
}