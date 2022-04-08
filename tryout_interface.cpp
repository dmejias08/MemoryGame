// wxWidgets "Hello World" Program
 
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <iostream>
#include <string>
#include "client.h"
#include "client.cpp"
#include <sstream>
#include "handeling_message.h"
#include <unistd.h>
#include <vector>

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
    wxBitmapButton *btn1;
    wxBitmapButton *btn2;
    std::vector<wxBitmapButton*> vector_buttons;
    int old_id;
    int clicks=1;
    Client client =  Client();
    MyFrame(int i , int j);
 
private:
    
    void resetImage(int id);
    void showImage(int id);
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
    // wxStaticBitmap *image1;
    // wxStaticBitmap *image2;

    this->btn1 =new wxBitmapButton(this, 1,wxBitmap("card.png", wxBITMAP_TYPE_PNG), wxPoint(5,100 ), wxSize(200,200));
    btn1->SetFocus();
    Connect(1, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnClick));
    this->vector_buttons.push_back(btn1);
    // image1 = new wxStaticBitmap( this, 1, wxBitmap("card.png", wxBITMAP_TYPE_PNG), wxPoint(5,100 ), wxSize(200, 200));
    
    this->btn2 =new wxBitmapButton(this, 2 , wxBitmap("card.png", wxBITMAP_TYPE_PNG), wxPoint(5,400 ), wxSize(200,200));
    btn2->SetFocus();
    Connect(2, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnClick));
    this->vector_buttons.push_back(btn2);
    // image2 = new wxStaticBitmap( this, 2, wxBitmap("card.png", wxBITMAP_TYPE_PNG), wxPoint(5,400 ),wxSize(200, 200));
}
 
void MyFrame::showImage(int id){
    std::cout<<"estoy en show image"<<std::endl;
    for(int i=0; i<2; i++){
        if(this->vector_buttons[i]->GetId()==id){
            std::cout<<"estoy dentro del if en show image"<<std::endl;
            this->vector_buttons[i]->SetBitmapLabel(wxBitmap("dog.png", wxBITMAP_TYPE_PNG));
        }
    }
}
void MyFrame::resetImage(int id){
    for(int i=0; i<2; i++){
    std::cout<<"id de btn en vector "<<this->vector_buttons[i]->GetId()<<std::endl;
        if(this->vector_buttons[i]->GetId()==id){
            std::cout<<"estoy dentro del if en reset image"<<std::endl;
            this->vector_buttons[i]->SetBitmapLabel(wxBitmap("card.png", wxBITMAP_TYPE_PNG));
        }
    }
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
    // int pos = event.GetPos();
    request.id = id;
    request.type_message = 0;

    std::cout<<"es id de boton "<<id<<std::endl;
    // std::cout<<"es pos de boton "<<pos<<std::endl;

    client.conexion(request);

    if (this->clicks == 1){
        showImage(id);
        // this->btn1->SetBitmapLabel(wxBitmap("dog.png", wxBITMAP_TYPE_PNG));
        this->old_id = id;
        this->clicks = 2;
        // showImage((wxBitmapButton*)&event);
    }else if(this->clicks ==2){
        showImage(id);
        // this->btn2->SetBitmapLabel(wxBitmap("dog.png", wxBITMAP_TYPE_PNG));
        wxMessageBox("Dog");
        // sleep(2);
        resetImage(id);
        resetImage(this->old_id);
        // this->btn1->SetBitmapLabel(wxBitmap("card.png", wxBITMAP_TYPE_PNG));
        // this->btn2->SetBitmapLabel(wxBitmap("card.png", wxBITMAP_TYPE_PNG));
        // showImage((wxBitmapButton*)&event);
        this->clicks = 1;
    }
}