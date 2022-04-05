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
#include <ctime> 


using namespace std;
fstream file;
struct simple_card
{
    int i, j, type, status;
};
Memory_managment::Memory_managment(){
    create_file();
    cout<<"file created"<<endl;
    print_file();
    cout<<"vector"<<endl;
    generate_vector(10);
    print_vector();
}
Card Memory_managment::get_card_from_file(int i, int j){
    file.open("binary.txt", ios::in | ios::out | ios::binary);
            file.seekg((i-1)*(5)*sizeof(simple_card)+(j-1)*sizeof(simple_card), ios::beg);
            char *buffer = (char*) malloc(sizeof(simple_card));
            file.read(buffer, sizeof(simple_card));
            simple_card* card = (simple_card*) buffer;
            Card new_card = Card(card->i,card->j, card->type, card->status);
            new_card.get_image(card->type);
            // cout<<"Card from file: ";
            // new_card.print();
            file.close();
            free(buffer);
            buffer = NULL;
            return new_card;
}
void Memory_managment::set_card_to_file(int i, int j, int type, int status){
    simple_card card;
    card.i = i;
    card.j = j;
    card.type = type;
    card.status = status;
    file.open("binary.txt", ios::in | ios::out | ios::binary);
        file.seekg(((i-1)*(5)*sizeof(simple_card)+(j-1)*sizeof(simple_card)),ios::beg);
        file.write((char*)&card, sizeof(simple_card));
        file.close();
}
Card Memory_managment::get_card(int i, int j){
    this->flag = 1;
    int limit = this->size_vector;
    for(int n = 0; n< limit; n++){
        if (this->vector_card[n].i == i && this->vector_card[n].j == j){
            cout<<"Found object in vector: ";
            this->vector_card[n].print();
            this->flag= 0;
            // cout<<"return object ";
            // this->vector_card[n].print();
            return this->vector_card[n];
        }
    }
    if (this->flag == 1){
    cout<<"Did not find object in vector "<<endl;
    Card card = replace(i,j);
    return card;
    }
}
Card Memory_managment::replace(int i, int j){
    srand(time(0));
    if (this->size_vector > 0){
    int n = rand()%this->size_vector;
    cout<<"Delete position "<<n<<endl;
    cout<<"object deleted ";
    this->vector_card[n].print();

    int old_i = this->vector_card[n].i;
    int old_j = this->vector_card[n].j;
    int old_type = this->vector_card[n].type;
    int old_status = this->vector_card[n].status;
    set_card_to_file(old_i, old_j, old_type, old_status);
    this->vector_card.erase(this->vector_card.begin()+n);
    }
    Card card = get_card_from_file(i,j);
    this->vector_card.push_back(card);
    cout<<"New object is: "<<endl;
    card.print();
    cout<<"New vector is: "<<endl;
    this->print_vector();
    return card;
}
void Memory_managment::generate_vector(int size){
    srand(time(0));
    this->vector_card.clear();
    this->size_vector = size;
    // int int_vector = 6;
    int i;
    int j;
    int n =0;
    while(true){
        if(n == size){
            break;
        }else{
            i = rand()%6+1;
            j = rand()%5+1;
            if (verify(i*10+j)){
                cout<<"generate position: "<<"("<<i<<","<<j<<")"<<endl;
                Card card_temp = get_card_from_file(i,j);
                if (card_temp.status != 1){
                    this->vector_card.push_back(card_temp);
                    n++;
                }
            }
        }
    }
}
bool Memory_managment::verify(int pos){
    int limit = this->vect_pos.size();
    for (int i =0 ; i<limit ; i++){
        if(this->vect_pos[i]==pos){
            return false;
        }
    }
    this->vect_pos.push_back(pos);
    return true;

}
void Memory_managment::print_vector(){
    int limit = this->size_vector;
    for(int n = 0; n < limit ; n++){
        this->vector_card[n].print();
    }
}
void Memory_managment::create_file(){ 
    srand(time(0));
    int size_vect = 30;
    vector<int> vect{1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
    int random;
    for (int i = 1; i <= 6; i++){
        for (int j = 1; j<=5; j++){
            random = rand()%size_vect;
            int n = vect[random];  
            set_card_to_file(i,j,n,0);
            vect.erase(vect.begin()+random);
            size_vect = size_vect - 1;
        }
    }  
}
void Memory_managment::print_file(){
        for (int i = 1; i <= 6; i++){
        for (int j = 1; j<=5; j++){
            get_card_from_file(i,j).print();
        }
    }
}
void Memory_managment::delete_cards(Card card){
    int limit = this->size_vector;
        for(int n = 0; n< limit; n++){
            if (this->vector_card[n].i == card.i && this->vector_card[n].j == card.j){
                int old_i = this->vector_card[n].i;
                int old_j = this->vector_card[n].j;
                int old_type = this->vector_card[n].type;
                int old_status = 1;
                set_card_to_file(old_i, old_j, old_type, old_status);
                cout<<"Delete card: ";
                this->vector_card[n].print();
                this->vector_card.erase(this->vector_card.begin()+n);
            }
        }
}
void Memory_managment::shuffle(){
    this->card_unused = this->card_unused - 2;
    this->size_vector = this->card_unused / 3;
    cout<<"Print vector con elementos borrados"<<endl;
    print_vector();
    cout<<"Print despues de suffle"<<endl;
    generate_vector(this->size_vector);
    cout<< "new vector despues de suffle"<<endl;
    print_vector();
}
