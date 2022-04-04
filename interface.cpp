// wxWidgets "Hello World" Program
 
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <iostream>
#include <string>
#include "client.h"
#include "client.cpp"
#include <sstream>
#include "handeling_message.h"
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
    std::vector<wxBitmapButton*> vector_buttons;
    int old_id;
    int clicks=1;
    Client client =  Client();
    MyFrame(int i , int j);
 
private:
    const char* manage_response(int response);
    void image_manager(int id,const char* card, int response);
    void resetImage(int id, int responsess);
    void showImage(int id, const char* card);
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

MyFrame::MyFrame(int i, int j ): wxFrame(NULL, wxID_ANY, "Memory Game",wxDefaultPosition, wxSize(1000, 800))
{
    int x = 5;
    int y = 5;
    int name = 0;
    for(int m = 1; m < i+1 ; m++){
        for (int n = 1; n < j+1 ; n++){
            wxBitmapButton *btn =new wxBitmapButton(this, m*10 +n , wxBitmap("card.png", wxBITMAP_TYPE_PNG), wxPoint(x, y), wxSize(120,120));
            this->vector_buttons.push_back(btn);
            x = x + 120;
            btn->SetFocus();
            Connect(m*10 +n, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnClick));
        }
        x = 5;
        y = y + 120;
    }
    Centre();
    wxButton *btn_exit =new wxButton(this,100, wxT("EXIT"), wxPoint(900,700));
    btn_exit->SetFocus();
    Connect(100, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnExit));
    // Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}
const char*  MyFrame::manage_response(int response){
        if(response == 0){
            return "Falta presionar una carta";
        }else if(response== 1){
            return "Las cartas son iguales";
        }else{
            return "Las cartas son diferentes";
        }
}
void MyFrame::image_manager(int id, const char* card, int response){
    if (this->clicks == 1){
        showImage(id, card);
        this->old_id = id;
        this->clicks = 2;
    }else{
        showImage(id, card);
        wxMessageBox(manage_response(response));
        resetImage(id, response);
        resetImage(this->old_id, response);
        this->clicks = 1;
    }
}
void MyFrame::showImage(int id, const char* card){
    for(int i=0; i<30; i++){
        if(this->vector_buttons[i]->GetId()==id){
            this->vector_buttons[i]->SetBitmapLabel(wxBitmap(card, wxBITMAP_TYPE_PNG));
        }
    }
}
void MyFrame::resetImage(int id, int response){
    for(int i=0; i<30; i++){
        if(this->vector_buttons[i]->GetId()==id){
            if(response == 1){
                this->vector_buttons[i]->Enable(false);
                this->vector_buttons[i]->SetBitmapLabel(wxBitmap("Check.png", wxBITMAP_TYPE_PNG));
            }else{
                this->vector_buttons[i]->SetBitmapLabel(wxBitmap("card.png", wxBITMAP_TYPE_PNG));
            }
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
    request.id = id;
    request.type_message = 0;
    request.card_type = 0;

    std::cout<<"es id de boton "<<id<<std::endl;


    client.conexion(request);

    int cardtype = this->client.card_type;
    int response = this->client.response;
    const char* card;

    switch (cardtype)
    {
    case 1://dog
        card = "Dog.png";
        image_manager(id ,card, response);
        break;
    case 2://cat
        card = "Cat.png";
        image_manager(id, card, response);
        break;
    case 3://cow
        card = "Cow.png";
        image_manager(id, card, response );
        break;
    case 4:
        card = "Pig.png";
        image_manager(id, card, response );
        break;
    case 5:
        card = "Hen.png";
        image_manager(id, card, response );
        break;
    default:
        wxMessageBox("NONE");   
    }
}

