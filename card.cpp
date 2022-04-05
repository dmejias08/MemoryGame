#include "card.h"
#include <string>




Card::Card(int i, int j, int type, int status){
    this->i = i;
    this->j = j;
    this->type = type;
    this->status = status;

}
void Card::get_image(int type){
    switch (type)
    {
    case 1:
        this->img = "Dog.png";
        break;
    case 2:
        this->img = "Cat.png";
        break;
    case 3:
        this->img = "Cow.png";
        break;
    case 4:
        this->img = "Pig.png";
        break;
    case 5:
        this->img = "Hen.png";
        break;
    default:
        cout<<"Cannot find image"<<endl;
        break;
    }
}
void Card::print(){
    std::cout<<"Coordenadas"<<"("<<this->i<<","<<this->j<<")"<<" "<<this->img<<" El status: "<<this->status<<std::endl;
}
