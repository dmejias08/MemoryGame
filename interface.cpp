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
    wxFrame parent;
    wxString player1;
    wxString player2;
    wxStaticText *label_play1 = new wxStaticText(this, 101, wxT("Jugador 1: "),wxPoint(700,100) );
    wxStaticText *label_play2 = new wxStaticText(this, 102, wxT("Jugador 2: "),wxPoint(700,300) );
    wxStaticText *lb_play1_points;
    wxStaticText *lb_play2_points;
    int current_player =1;;
    std::vector<wxBitmapButton*> vector_buttons;
    int old_id;
    int clicks=1;
    Client client =  Client();
    Client client2 = Client();
    MyFrame(int i , int j);
 
private:
    void update_turn(int player);
    void updateLabel(int player, int points);
    const char* manage_response(int response);
    void image_manager(int id,std::string card, int response);
    void resetImage(int id, int responsess);
    void showImage(int id, std::string card);
    void OnClick(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    std::string decodeImage(std::string image, int type);
};

class MyFrameStart : public wxFrame
{
public:
    wxTextCtrl *tc1;
    wxTextCtrl *tc2;
    wxString player1;
    wxString player2;
    MyFrameStart();
 
private:

    void OnStart(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
};
 
wxIMPLEMENT_APP(MyApp);

/**
 * @brief It inicialize the first frame
 * 
 * @return true 
 * @return false 
 */
bool MyApp::OnInit()
{
    MyFrameStart *frame1 = new MyFrameStart();
    frame1->Show(true);
    return true;
}
/**
 * @brief Construct a new My Frame Start:: My Frame Start object
 * It sets the basic elements in the firts panel
 */
MyFrameStart::MyFrameStart() :wxFrame(NULL, wxID_ANY, "Memory Game Start",wxDefaultPosition, wxSize(500, 500)){
    wxStaticText *label1 = new wxStaticText(this, wxID_ANY, wxT("Welcome to Memory Game"),wxPoint(150,20) );
    wxStaticText *label2 = new wxStaticText(this, wxID_ANY, wxT("Write your nicknames"),wxPoint(77,100) );
    wxStaticText *label3 = new wxStaticText(this, wxID_ANY, wxT("Player 1"),wxPoint(5,150) );
    wxStaticText *label4 = new wxStaticText(this, wxID_ANY, wxT("Player 2"),wxPoint(150,150) );
    this->tc1 = new wxTextCtrl(this, wxID_ANY, wxT(""),wxPoint(5,175));
    this->tc2 = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(150,175));
    wxButton *btn_start =new wxButton(this,1, wxT("START"), wxPoint(300,350));
    wxButton *btn_save =new wxButton(this,2, wxT("SAVE PLAYERS"), wxPoint(300,300));
    btn_start->SetFocus();
    btn_save->SetFocus();
    Connect(1, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrameStart::OnStart));
    Connect(2, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrameStart::OnSave));
}

/**
 * @brief It saves the player's names on gobal variables to later use 
 * 
 * @param event 
 */
void MyFrameStart::OnSave(wxCommandEvent& event){
    if (this->tc1->IsEmpty()==false && this->tc2->IsEmpty()== false){
        this->player1 = this->tc1->GetValue();
        this->player2 = this->tc2->GetValue();
        cout<<player1<<" "<<player2<<endl; 
        wxMessageBox("[Saved players] click Start");
    }else{
        wxMessageBox("[Warning] Add player's name");  
    }
    
}
/**
 * @brief it saves the player's name on frame and inicialize it. Closes the current frame 
 * 
 * @param event 
 */
void MyFrameStart::OnStart(wxCommandEvent& event){

    MyFrame *frame = new MyFrame(6,5);
    frame->label_play1->SetLabel(this->player1);
    frame->label_play2->SetLabel(this->player2);
    frame->player1 = this->player1;
    frame->player2 = this->player2;
    frame->Show(true);
    Close(true);
}
/**
 * @brief Construct a new My Frame:: My Frame object
 * 
 * @param i dimensions of interface 
 * @param j dimensions of interface 
 */
MyFrame::MyFrame(int i, int j ): wxFrame(NULL, wxID_ANY, "Memory Game",wxDefaultPosition, wxSize(1000, 800))
{
    int x = 5;
    int y = 5;
    int name = 0;
    /* Creates a vector of buttons that saves its position*/
    for(int m = 1; m < i+1 ; m++){
        for (int n = 1; n < j+1 ; n++){
            wxBitmapButton *btn =new wxBitmapButton(this, m*10 +n , wxBitmap("assets/card.png", wxBITMAP_TYPE_PNG), wxPoint(x, y), wxSize(120,120));
            this->vector_buttons.push_back(btn);
            x = x + 120;
            btn->SetFocus();
            Connect(m*10 +n, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnClick));
        }
        x = 5;
        y = y + 120;
    }
    Centre();
    /*Sets the basic elements: players label and points */
    wxStaticText *label_play1 = new wxStaticText(this, 101, wxT("Players "),wxPoint(700,50));
    wxStaticText *lb_points = new wxStaticText(this, 104, wxT("Points"),wxPoint(900,50) );
    this->lb_play1_points = new wxStaticText(this, 103, wxT("0"),wxPoint(900,100) );
    this->lb_play2_points = new wxStaticText(this, 104, wxT("0"),wxPoint(900,300) );
    
    this->label_play1->SetForegroundColour( wxColor(*wxBLUE));
    this->label_play2->SetForegroundColour( wxColor(*wxBLUE));

    srand(time(0));
    this->current_player = 1;
    update_turn(this->current_player);

    wxButton *btn_exit =new wxButton(this,100, wxT("EXIT"), wxPoint(900,700));
    btn_exit->SetFocus();
    Connect(100, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnExit));
    wxMessageBox("Each turn your name changes color. [Red indicates your turn]");
}
/**
 * @brief it changes the color of each player label to indicate turn 
 * 
 * @param player 
 */
void MyFrame::update_turn(int player){
    /*red indicates your turn*/
    if (player == 1){
        this->label_play1->SetForegroundColour( wxColor(*wxRED));
        this->label_play2->SetForegroundColour( wxColor(*wxBLUE));
    }else if(player ==2){
        this->label_play2->SetForegroundColour( wxColor(*wxRED));
        this->label_play1->SetForegroundColour( wxColor(*wxBLUE));
    }
}
/**
 * @brief it updates each player's points 
 * 
 * @param player current player 
 * @param points player's points 
 */
void MyFrame::updateLabel(int player, int points){
    std::string point = std::to_string(points);
    if(player == 1){
        this->lb_play1_points->SetLabel(point);
    }else if(player == 2){
        this->lb_play2_points->SetLabel(point);
    }
}

const char*  MyFrame::manage_response(int response){
        if(response == 0){
            return "Falta presionar una carta";
        }else if(response== 1){
            return "Congrats: You found a match";
        }else{
            return "Watch out next turn";
        }
}
/**
 * @brief It manages to show each image and define when you have two images shown 
 * 
 * @param id button's id 
 * @param card name of image address
 * @param response gets if it is a match 
 */
void MyFrame::image_manager(int id, std::string card, int response){
    if (this->clicks == 1){ // just one image shown 
        showImage(id, card);
        this->old_id = id;
        this->clicks = 2;
    }else{ // two images shown 
        showImage(id, card);
        wxMessageBox(manage_response(response));
        resetImage(id, response);
        resetImage(this->old_id, response);
        this->clicks = 1;
    }
}
/**
 * @brief it gets the image of the button in vector and changes it
 * 
 * @param id button's id 
 * @param card image 
 */
void MyFrame::showImage(int id, std::string card){
    for(int i=0; i<30; i++){
        if(this->vector_buttons[i]->GetId()==id){
            this->vector_buttons[i]->SetBitmapLabel(wxBitmap(card, wxBITMAP_TYPE_PNG));
            this->vector_buttons[i]->Enable(false);
        }
    }
}
/**
 * @brief if there is a match it disables the buttons and change image, if not it resets it as it was. 
 * 
 * @param id button's id 
 * @param response flag
 */
void MyFrame::resetImage(int id, int response){
    for(int i=0; i<30; i++){
        if(this->vector_buttons[i]->GetId()==id){
            if(response == 1){
                this->vector_buttons[i]->Enable(false);
                this->vector_buttons[i]->SetBitmapLabel(wxBitmap("assets/Check.png", wxBITMAP_TYPE_PNG));
            }else{
                this->vector_buttons[i]->SetBitmapLabel(wxBitmap("assets/card.png", wxBITMAP_TYPE_PNG));
                this->vector_buttons[i]->Enable(true);
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
/**
 * @brief 
 * 
 * @param event 
 */
void MyFrame::OnClick(wxCommandEvent& event)
{
    struct info_pack request;
    int id = event.GetId();
    request.id = id;
    request.type_message = 0;
    request.card_type = 0;
    request.points = 0;
    request.winner = 0;

    std::cout<<"es id de boton "<<id<<std::endl;

    /*It sets the conexions between server and client*/
    client.conexion(request);
    /* First conexion sends the info of button and gets response*/
    int cardtype = this->client.card_type;
    int response = this->client.response;
    int points = this->client.points;
    this->current_player = this->client.current_player;
    int point_player = this->client.player_points;
    int winner = this->client.winner;
    int punish_points = this->client.punish_points;
    int punish_player = this->client.punish_player;

    /*Second conexion gets the image */
    client.getImage(1);
    std::string img = this->client.client_img;
    std::string card = decodeImage(img, cardtype);

    /*Sets labels and points*/
    image_manager(id, card, response);
    update_turn(this->current_player);
    updateLabel(point_player, this->client.points);

    /*Sets punishments due to power ups and defines winner according to response from server*/
    if(punish_player != 0 ){
        wxMessageBox("Furious player, you have to be careful");
        updateLabel(punish_player, punish_points);
    }
    if(winner == 1){
        wxMessageBox("The winner is " +  this->player1);
        wxMessageBox("Click on exit");   
    }else if(winner == 2){
        wxMessageBox("The winner is " + this->player2);
        wxMessageBox("Click on exit");   
    }


}
/**
 * @brief It decodes the base 64 string and turns it into png image 
 * 
 * @param image base 64 
 * @param type number of each animal 
 * @return std::string 
 */
std::string MyFrame::decodeImage(std::string image, int type){
    std::string type_s = std::to_string(type) + ".png";
    ofstream image_file(type_s , ios::out | ios::trunc);
    char ch;
    while (image.size() > 0)
    {
        ch = image.substr(0,1).c_str()[0];
        image_file.put(ch);
        image = image.substr(1);

    }
    cout<<"Reloaded Successfully"<<endl;
    image_file.clear();
    return type_s;
}


    
    


