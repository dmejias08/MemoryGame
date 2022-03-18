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


Card* Memory_managment::getCard(int i, int j){
    // cout<<"estoy en get card"<<endl;
    file.open("binary.txt", ios::in | ios::out | ios::binary);
        // if(file.is_open()){
            // cout<<"EStoy en file"<<endl;
            char *buffer = (char*) malloc(sizeof(simple_card));
            file.seekg((i-1)*(4)*sizeof(simple_card)+(j-1)*sizeof(simple_card), ios::beg);
            file.read(buffer, sizeof(simple_card));
            simple_card* card = (simple_card*) buffer;
            cout<<card->i<<" "<<card->j<<" "<<card->type<<" "<<card->status<<endl;
            file.close();
            
        // }
}

void Memory_managment::setCard(int i, int j, int type, int status){
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
void Memory_managment::generateVector(){
    int N = 5;

    for (int i = 0; i < N; i++){
        std::string id = to_string(i);
        //Card *card = get_from_csv(id);
        //this->vector_card.push_back(card);
    }

    for(int j=0; j < N ; j++){
        vector_card[j]->print();
    }
   
}