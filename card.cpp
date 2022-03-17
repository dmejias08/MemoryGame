#include "card.h"
#include <string>

Card::Card(std::string id, std::string name, std::string img, std::string status){
    this->id = id;
    this->name = name;
    this->img = img;
    this->status = status;
}
void Card::print(){
    std::cout<<this->name<<" "<<this->id<<std::endl;
}
