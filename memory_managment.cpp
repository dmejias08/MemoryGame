#include "memory_managment.h"
#include <string>
#include "card.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;
fstream file;
struct simple_card
{
    int i, j, type, status;
};


Card Memory_managment::get_card_from_file(int i, int j){
    // cout<<"estoy en get card"<<endl;
    file.open("binary.txt", ios::in | ios::out | ios::binary);
        // if(file.is_open()){
            cout<<"Estoy en file"<<endl;
            file.seekg((i-1)*(4)*sizeof(simple_card)+(j-1)*sizeof(simple_card), ios::beg);
            char *buffer = (char*) malloc(sizeof(simple_card));
            file.read(buffer, sizeof(simple_card));
            simple_card* card = (simple_card*) buffer;
            // cout<<card->i<<" "<<card->j<<" "<<card->type<<" "<<card->status<<endl;
            Card new_card = Card(card->i,card->j, card->type, card->status);
            cout<<"Estoy despues de card"<<endl;
            new_card.get_image(card->type);
            cout<<"Estoy despues de get image"<<endl;
            file.close();
            new_card.print();
            free(buffer);
            buffer = NULL;
            return new_card;
        // }
}

void Memory_managment::set_card_to_file(int i, int j, int type, int status){
    cout<<"Estoy en set card"<<endl;
    simple_card card;
    card.i = i;
    card.j = j;
    card.type = type;
    card.status = status;
    file.open("binary.txt", ios::in | ios::out | ios::binary);
    //if(file.is_open()){
        // cout<<"EStoy en setCard"<<endl;
        file.seekg(((i-1)*(4)*sizeof(simple_card)+(j-1)*sizeof(simple_card)),ios::beg);
        file.write((char*)&card, sizeof(simple_card));
        file.close();
        
    // }
    
}
// void Memory_managment::get_card(int i, int j){

// }

//arregar este metodo
void Memory_managment::generate_vector(){
    for(int i = 1 ; i <= 2; i++){
        for(int j = 1; j<=5; j++){
            this->vector_card.push_back(get_card_from_file(i,j));
            // this->vector_card.push_back(get_card_from_file(1,2));
            // this->vector_card.push_back(get_card_from_file(1,3));
            // cout<<"estoy en generate vector"<<endl;
            // this->vector_card[0].print();
            // this->vector_card[1].print();
            // this->vector_card[2].print();
        }
    }
    // for(int n = 0; n<10; n++){
    //     vector_card[n].print();
    // }
}


void Memory_managment::print_vector(){
    for(int n = 0; n < 10; n++){
        this->vector_card[n].print();
    }
}

void Memory_managment::create_file(){
    int n = 1;
    for (int i = 1; i <= 6; i++){
        for (int j = 1; j<=5; j++){
            if (n > 3){
                n = 1;
                set_card_to_file(i,j,n,0);
                n+=1;
            }else{
                set_card_to_file(i,j,n,0);
                n+=1;
            } 
        }
    }  
}