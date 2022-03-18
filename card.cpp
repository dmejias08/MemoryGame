#include "card.h"
#include <string>

Card::Card(int id, int name, int img, int status){
    this->id = id;
    this->name = name;
    this->img = img;
    this->status = status;
}
void Card::print(){
    std::cout<<this->name<<" "<<this->id<<std::endl;
}
