// wxWidgets "Hello World" Program
 
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include "button.h"
#include <iostream>
#include <string>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
 
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};
 
class MyFrame : public wxFrame
{
public:
    MyFrame(int i , int j);
 
private:
    void OnClick(wxCommandEvent& event);
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};
 
// enum
// {
    // ID_Hello = 1
// };
 
wxIMPLEMENT_APP(MyApp);
 
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame(8,8);
    frame->Show(true);
    return true;
}
 
MyFrame::MyFrame(int i, int j ): wxFrame(NULL, wxID_ANY, "Memory Game",wxDefaultPosition, wxSize(1500, 900))
{
    int x = 5;
    int y = 5;
    int name = 0;
    for(int m = 1; m < i+1 ; m++){
        x = 5;
        y = y + 50;
        for (int n = 1; n < j+1 ; n++){
            wxButton *btn =new wxButton(this, m*10 +n , wxT("CARD"), wxPoint(x, y));
            x = x + 95;
            btn->SetFocus();
            Connect(m*10 +n, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnClick));
        }
    }
    // wxButton *button1 = new wxButton(this, 10, wxT("Quit"), wxPoint(100, 5));
    // wxButton *button2 = new wxButton(this, 11, wxT("Quit"), wxPoint(5, 5));
    // Button *btn = new Button(this, 1,1,5,5)1
    // wxButton *button = btn->button;
    // Connect(10, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnClick));

    // button1->SetFocus();
    // button2->SetFocus();
    // button->SetFocus();
    Centre();
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}
 
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
 
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}
 
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

void MyFrame::OnClick(wxCommandEvent& event)
{
    int id = event.GetId();
    wxLogMessage("hello");
    std::cout<<"es id "<< id<<std::endl;
    std::cout<<event.GetId()<<std::endl;;
    
}

