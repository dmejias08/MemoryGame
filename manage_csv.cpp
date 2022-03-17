#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "card.h"
#include "card.cpp"
using namespace std;

int main(){
    // fstream file;
    // string line, word, words;
    // int n;

    // file.open("example.csv", ios::in | ios::out);
    //     if(file.is_open()){
    //         for(int i =0; i<=4 ; i++){
    //             getline(file, line);
    //             stringstream str(line);
    //             getline(str,word,',');
    //             if (word == "3"){
    //                 cout<<word<<endl;
    //                 for(int j=0;j<3; j++){
    //                     getline(str,word,',');
    //                     cout<<word<<endl;
    //                 }break;
    //             }
    //         }
    //     }
    fstream file;
    string line, word, name, img, id, status;
    file.open("example.csv", ios::in | ios::out);
        if(file.is_open()){
            for(int i =0; i<= 10; i++){
                getline(file, line);//read every line 
                stringstream str(line); //separate the line
                getline(str,word,','); //takes every word
                if (word == "3"){
                    id = word;
                    cout<<"id "<<word<<endl;
                    for(int j=0;j<3; j++){
                        getline(str,word,',');
                        if (j == 0){
                            name = word;
                            cout<<"name "<<name<<endl;
                        }else if (j == 1){
                            img = word;
                            cout<<"img "<<img<<endl;
                        }else if(j == 2){
                            status = word;
                            cout<<"status "<<status<<endl;
                        }
                    }
                    Card card = Card(id,name,img,status);
                    cout<<"Clase"<<endl;
                    card.print();
                    file.close();
                    
                }
            }
        }
}