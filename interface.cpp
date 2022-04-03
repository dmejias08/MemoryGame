// wxWidgets "Hello World" Program
 
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <iostream>
#include <string>
#include "client.h"
#include "client.cpp"
#include <sstream>
#include "handeling_message.h"


#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
 
using namespace std;

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};
 
class MyFrame : public wxFrame
{
public:
    
    Client client =  Client();
    MyFrame(int i , int j);
 
private:
    
    void OnClick(wxCommandEvent& event);
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};

// class MyFrameInit : public wxFrame
// {
// public:
    // MyFrameInit();
// private:
    // void OnEntry(wxCommandEvent& event);
    // void OnHello(wxCommandEvent& event);
    // void OnExit(wxCommandEvent& event);
    // void OnAbout(wxCommandEvent& event);
// };
// enum
// {
    // ID_Hello = 1
// };
 
wxIMPLEMENT_APP(MyApp);
 
bool MyApp::OnInit()
{
    // MyFrameInit *frame_init = new MyFrameInit();
    // frame_init->Show(true);
    MyFrame *frame = new MyFrame(6,5); // estos parametros los debe enviar servidor
    frame->Show(true);
    return true;
}
 


// MyFrameInit::MyFrameInit():wxFrame(NULL, wxID_ANY, "Memory Game Entry",wxDefaultPosition, wxSize(800, 600))
// {
// 
// }

MyFrame::MyFrame(int i, int j ): wxFrame(NULL, wxID_ANY, "Memory Game",wxDefaultPosition, wxSize(800, 600))
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
    Centre();
    wxButton *btn_exit =new wxButton(this,100, wxT("EXIT"), wxPoint(600,500));
    btn_exit->SetFocus();
    Connect(100, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnExit));
    // Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}
 
void MyFrame::OnExit(wxCommandEvent& event)
{
    std::cout<<"estoy en onExit"<<std::endl;
    struct info_pack request;
    request.id = 0;
    request.type_message = -1;
    client.conexion(request);
    Close(true);
}

void MyFrame::OnClick(wxCommandEvent& event)
{
    struct info_pack request;
    int id = event.GetId();
    request.id = id;
    request.type_message = 0;
    // char number_array[1024];
    //conversion to char array
    //"%d" format specifier is used for integers
    // sprintf(number_array, "%d", id);
    // stringstream temp_str;
    // temp_str<<id; //passing number to the stream
    // char  *number_array = temp_str.str().c_str();//converting to char array
    // wxLogMessage("Hello");
    // std::cout<<number_array<<std::endl;
    std::cout<<"es id de boton "<<id<<std::endl;
    // char *buffer_transmiter = new char[1024];
    // buffer_transmiter = (char*) this->id;
    client.conexion(request);

}

