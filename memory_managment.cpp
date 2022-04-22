#include "memory_managment.h"
#include <string>
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
/**
 * @brief Construct a new Memory_managment object
 * It creates a file randomly
 * It creates a vector of objectos in memory
 */
Memory_managment::Memory_managment(){
    create_file();
    cout<<"file created"<<endl;
    cout<<"memory"<<endl;
    generate_vector(10);
    print_vector();
    cout<<"Disk"<<endl;
    print_file();
}
/**
 * @brief Get a card object from disk 
 * 
 * @param i position i in disk's matix 
 * @param j position j in disk's matrix
 * @return object Card 
 */
Card Memory_managment::get_card_from_file(int i, int j){
    file.open("binary.txt", ios::in | ios::out | ios::binary);
            file.seekg((i-1)*(5)*sizeof(simple_card)+(j-1)*sizeof(simple_card), ios::beg); // seeks the position 
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
/**
 * @brief Set a card object on disk
 * @param i position i in disk's matrix
 * @param j position j in disk's matrix
 * @param type defines the type of card object
 * @param status defines the status (use, unused) of card
 */
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
/**
 * @brief get Card from memory or disk 
 * 
 * @param i position i in interface's matrix
 * @param j position j in interface's matrix
 * @return Card 
 */

Card Memory_managment::get_card(int i, int j){
    this->flag = 1;
    int limit = this->size_vector;
    for(int n = 0; n< limit; n++){
        if (this->vector_card[n].i == i && this->vector_card[n].j == j){ // found vector 
            cout<<"Found object in memory: ";
            this->page_hits += 1;
            this->vector_card[n].print();
            this->flag= 0;
            return this->vector_card[n];
        }
    }
    if (this->flag == 1){ //object not found on vector
    cout<<"Did not find object in vector "<<endl;
    this->page_faults += 1;
    Card card = replace(i,j); // calls replace to get the card needed
    int total = memory_consumption();
    cout<<"SERVER INTERFACE"<<endl;
    cout<<"**************************************************************************************************"<<endl;
    cout<<"Memory usage: "<<total<<" bytes"<<"   Cards in memory: "<<this->vector_card.size()<<endl;
    cout<<"**************************************************************************************************"<<endl;
    cout<<"Page hits: "<<this->page_hits<<" "<<"Page faults: "<<this->page_faults<<endl;
    cout<<"**************************************************************************************************"<<endl;
    return card;
    }
}
/**
 * @brief Replace an object in memory for an object from disk 
 * 
 * @param i position i in disk's matrix
 * @param j position j in disk's matrix
 * @return Card 
 */
Card Memory_managment::replace(int i, int j){
    srand(time(0));
    if (this->size_vector > 0){
    int n = rand()%this->size_vector; // generates a random position in vector 
    cout<<"Delete position "<<n<<endl;
    cout<<"object deleted ";
    this->vector_card[n].print();

    int old_i = this->vector_card[n].i;
    int old_j = this->vector_card[n].j;
    int old_type = this->vector_card[n].type;
    int old_status = this->vector_card[n].status;
    set_card_to_file(old_i, old_j, old_type, old_status); // set the random objetc from vector in disk 
    this->vector_card.erase(this->vector_card.begin()+n); // erase card object
    }
    Card card = get_card_from_file(i,j); // get the card needed
    this->vector_card.push_back(card); // save it in vector 
    cout<<"New object is: "<<endl;
    card.print();
    cout<<"New cards in memory : "<<endl;
    this->print_vector();
    return card;
}
/**
 * @brief Generates a random vector of cards with a dynamic size
 * 
 * @param size it defines size of vector 
 */
void Memory_managment::generate_vector(int size){
    srand(time(0));
    this->vector_card.clear(); // deletes all objevts in current vector 
    this->vector_card.shrink_to_fit(); 
    this->vect_pos.clear(); //clears the position vector 
    this->size_vector = size;
    int i;
    int j;
    int n =0;
    while(true){
        if(n >= size){
            break;
        }else{
            i = rand()%6+1; //random i position
            j = rand()%5+1; // random j position
            if (verify(i*10+j)){ // it verifies the position is not already used
                Card card_temp = get_card_from_file(i,j);
                if (card_temp.status != 1){ //checks the card is unused
                    this->vector_card.push_back(card_temp);
                    n++;
                }
            }
        }
    }
    int total = memory_consumption();
    cout<<"SERVER INTERFACE"<<endl;
    cout<<"**************************************************************************************************"<<endl;
    cout<<"Memory usage: "<<total<<" bytes"<<"   Cards in memory: "<<this->vector_card.size()<<endl;
    cout<<"**************************************************************************************************"<<endl;
    cout<<"Page hits: "<<this->page_hits<<" "<<"Page faults: "<<this->page_faults<<endl;
    cout<<"**************************************************************************************************"<<endl;
}
/**
 * @brief It determines the memory consumption of vector
 * 
 * @return int 
 */
int Memory_managment::memory_consumption(){
    int total = 0;
    int size = this->vector_card.size();
    for(int i = 0; i < size ; i++){
        total += sizeof(this->vector_card[i]); //size of each object
        total += this->vector_card[i].img.size(); // size of image in each object 
    }
    return total;
}
/**
 * @brief Verifies if a position have been used 
 * 
 * @param pos needed position 
 * @return true 
 * @return false 
 */
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
/**
 * @brief Loops on each element of vector and prints it 
 * 
 */
void Memory_managment::print_vector(){
    int limit = this->size_vector;
    for(int n = 0; n < limit ; n++){
        this->vector_card[n].print();
    }
}
/**
 * @brief Ceates a files of objects in random positions
 * 
 */
void Memory_managment::create_file(){ 
    srand(time(0));
    int size_vect = 30;
    vector<int> vect{1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5}; // vector of types
    int random;
    for (int i = 1; i <= 6; i++){
        for (int j = 1; j<=5; j++){
            random = rand()%size_vect;
            int n = vect[random];  
            set_card_to_file(i,j,n,0); //it sets objects of random types 
            vect.erase(vect.begin()+random);
            size_vect = size_vect - 1;
        }
    }  
}
/**
 * @brief prints each object of file 
 * 
 */
void Memory_managment::print_file(){
        for (int i = 1; i <= 6; i++){
        for (int j = 1; j<=5; j++){
            get_card_from_file(i,j).print();
        }
    }
}
/**
 * @brief It delets card from vectors and set it used
 * 
 * @param card found card 
 */
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
            }
        }
}
/**
 * @brief it updates size of vector and calls generate vector 
 * 
 */
void Memory_managment::shuffle(){
    this->card_unused = this->card_unused - 2;
    this->size_vector = this->card_unused / 3;
    generate_vector(this->size_vector);
    cout<< "Cards in memory after shuffle "<<endl;
    print_vector();
}
