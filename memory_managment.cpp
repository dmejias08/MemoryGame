#include "memory_managment.h"
#include <string>
#include "card.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

Card* Memory_managment::get_from_csv(string n){
    fstream file;
    string line, word, name,id, img, status;

    file.open("example.csv", ios::in | ios::out);

        if(file.is_open()){

            for(int i =0; i<= 10; i++){
                getline(file, line);//read every line 
                stringstream str(line); //separate the line
                getline(str,word,','); //takes every word
                if (word == n){
                    id = word;
                    cout<<word<<endl;
                    for(int j=0;j<3; j++){
                        getline(str,word,',');
                        cout<<word<<endl;
                        if (j == 0){
                            name = word;
                            cout<<word<<endl;
                        }else if (j == 1){
                            img = word;
                            cout<<word<<endl;
                        }else if(j == 2){
                            status = word;
                            cout<<word<<endl;
                        }
                    }
                    Card* card = new Card(id,name,img,status);
                    // card.print();
                    file.close();
                    return card;
                    break;
                    
                }
                
            }
        }
}
// void Memory_managment::get_card(int i, int j){

// }
void Memory_managment::generateVector(){
    // int N = 5;
    cout<<"hola"<<endl;
    Card *card =  get_from_csv("3");
    card->print();
    this->vector_card.push_back(card);

    // for (int i = 0; i < N; i++){
    //     std::string id = to_string(i);
    //     Card card = get_from_csv(id);
    //     this->vector_card.push_back(card);
    // }
   

// vector_card.push_back(Card("1","perro", "perro.png","0"));
// vector_card.push_back(Card("1","perro", "perro.png","0"));
    // for (int j = 0; j<=1; j++){
    //     this->vector_card[j].print();
    // }

}