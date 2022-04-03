#include "handeling_message.h"

Handeling_message::Handeling_message(){
}
    
struct info_pack* Handeling_message::manage_message(struct info_pack *message){
    if(message->type_message == 0){
        if(this->id_card1 == 0){
            this->id_card1 = message->id;
            message->id = 0;
            return message;
        }else{
            this->id_card2 == message->id;
            int result = check_equals(this->id_card1, this->id_card2);
            message->id = result;
            this->id_card1 =0;
            this->id_card2 =0;
            return message;
        }
    }

}

int Handeling_message::check_equals(int id1, int id2){
    int i1 = id1/10;
    int j1 = id1%10;
    int i2 = id2/10;
    int j2 = id2%10;

    Card card1 = this->memory.get_card(i1,j1);
    Card card2 = this->memory.get_card(i2,j2);

    if(card1.type == card2.type){
        return 1;
    }
    return 2;
}


