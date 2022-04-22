#include "card.h"
#include <string>



/**
 * @brief Construct a new Card:: Card object
 * 
 * @param i position i in matrix
 * @param j position j in matrix
 * @param type type of object
 * @param status status(used or unused) of card 
 */
Card::Card(int i, int j, int type, int status){
    this->i = i;
    this->j = j;
    this->type = type;
    this->status = status;

}
/**
 * @brief Defines the image of each object. It load a base 64 array of each objec image attribute 
 * 
 * @param type type of each card, it depends on each animal 
 */
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
    std::cout<<"Type: "<<this->type<<" Coordenadas"<<"("<<this->i<<","<<this->j<<")"<<" El status: "<<this->status<<std::endl;
}
/**
 * @brief It encode each image txt file 
 * 
 * @param picture each image address
 * @return string  base 64
 */
string Card::encodeImage(std::string picture){
    ifstream image(picture, ios::in | ios::binary);
    string img;
    char ch;
    while(!image.eof())
    {
        ch = image.get();
        img.push_back(ch);
    }
    image.close();
    return img;
}