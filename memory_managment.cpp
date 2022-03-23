#include "memory_managment.h"
#include <string>
#include "card.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>


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
            // cout<<"Estoy en file"<<endl;
            file.seekg((i-1)*(4)*sizeof(simple_card)+(j-1)*sizeof(simple_card), ios::beg);
            char *buffer = (char*) malloc(sizeof(simple_card));
            file.read(buffer, sizeof(simple_card));
            simple_card* card = (simple_card*) buffer;
            Card new_card = Card(card->i,card->j, card->type, card->status);
            // cout<<"Estoy despues de card"<<endl;
            new_card.get_image(card->type);
            // cout<<"Estoy despues de get image"<<endl;
            cout<<"Card from file: ";
            new_card.print();
            file.close();
            free(buffer);
            buffer = NULL;
            return new_card;
        // }
}

void Memory_managment::set_card_to_file(int i, int j, int type, int status){
    // cout<<"Estoy en set card"<<endl;
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
Card Memory_managment::get_card(int i, int j){
    int flag = 1;

    for(int n = 0; n<10; n++){
        if (this->vector_card[n].i == i && this->vector_card[n].j == j){
            cout<<"Found object in vector: ";
            this->vector_card[n].print();
            flag = 0;
            cout<<"return object ";
            this->vector_card[n].print();
            return this->vector_card[n];
        }
    }
    
    cout<<"value of flag "<<flag<<endl;
    if (flag == 1){
    cout<<"Did not find object in vector "<<endl;
    Card card = replace(i,j);
    return card;
    }
}

Card Memory_managment::replace(int i, int j){
    int n = rand()%10;
    cout<<"Delete position "<<n<<endl;
    cout<<"object deleted ";
    this->vector_card[n].print();

    int old_i = this->vector_card[n].i;
    int old_j = this->vector_card[n].j;
    int old_type = this->vector_card[n].type;
    int old_status = this->vector_card[n].status;
    set_card_to_file(old_i, old_j, old_type, old_status);
    this->vector_card.erase(this->vector_card.begin()+n);

    Card card = get_card_from_file(i,j);
    this->vector_card.push_back(card);
    cout<<"New object is: "<<endl;
    this->vector_card[9].print();
    cout<<"New vector is: "<<endl;
    this->print_vector();
    return card;

}
void Memory_managment::generate_vector(){
    for(int i = 1 ; i <= 2; i++){
        for(int j = 1; j<=5; j++){
            this->vector_card.push_back(get_card_from_file(i,j));
        }
    }
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