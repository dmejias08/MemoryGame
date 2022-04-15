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
        this->img = encodeImage("assets/Dog.png");
        break;
    case 2:
        this->img = encodeImage("assets/Cat.png");
        break;
    case 3:
        this->img = encodeImage("assets/Cow.png");
        break;
    case 4:
        this->img = encodeImage("assets/Pig.png");
        break;
    case 5:
        this->img = encodeImage("assets/Hen.png");
        break;
    default:
        cout<<"Cannot find image"<<endl;
        break;
    }
}
void Card::print(){
    std::cout<<"Type: "<<this->type<<"Coordenadas"<<"("<<this->i<<","<<this->j<<")"<<" El status: "<<this->status<<std::endl;
}

string Card::encodeImage(std::string picture){
    ifstream image(picture, ios::in | ios::binary);
    string img;
    char ch;
    while(!image.eof())
    {
        ch = image.get();
        img.push_back(ch);
    }
    cout<<"Loaded Successfully"<<endl;

    image.close();
    return img;
}