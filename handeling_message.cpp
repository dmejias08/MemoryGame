#include "handeling_message.h"
#include <iostream>

Handeling_message::Handeling_message(){

}
    
struct info_pack* Handeling_message::manage_message(struct info_pack *message){
    if(message->type_message == 0){
        if(this->id_card1 == 0){
            this->id_card1 = message->id;
            int i1 = id_card1/10;
            int j1 = id_card1%10;
            Card card1 = this->memory->get_card(i1,j1);
            std::cout<<"el id1 del boton es: "<<this->id_card1<<std::endl;
            message->id = 0; //need to click one more card
            message->card_type = card1.type;
            return message;
        }else{
            std::cout<<"El segundo id "<<message->id<<std::endl;
            this->id_card2 = message->id;
            std::cout<<"el id1 del boton es: "<<this->id_card1<<std::endl;
            std::cout<<"el id2 del boton es: "<<this->id_card2<<std::endl;
            int i2 = id_card2/10;
            int j2 = id_card2%10;
            Card card2 = this->memory->get_card(i2,j2);
            int result = check_equals(this->id_card1, card2);
            message->id = result;
            message->card_type = card2.type;
            this->id_card1 =0;
            this->id_card2 =0;
            return message;
        }
    }

}

int Handeling_message::check_equals(int id1, Card card2){
    int i1 = id1/10;
    int j1 = id1%10;
    // int i2 = id2/10;
    // int j2 = id2%10;

    Card card1 = this->memory->get_card(i1,j1);
    // Card card2 = this->memory->get_card(i2,j2);

    std::cout<<"La carta1 es ";
    card1.print();
    std::cout<<"La carta2 es ";
    card2.print();

    if(card1.type == card2.type){
        this->memory->delete_cards(card1, card2);
        std::cout<<"nuevo vector"<<std::endl;
        this->memory->print_vector();
        return 1;
    }
    return 2;
}


