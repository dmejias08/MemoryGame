#ifndef handeling_message_h
#define handeling_message_h
#include "client.h"
#include "memory_managment.h"
#include "memory_managment.cpp"

class Handeling_message{

    private:
    struct info_pack message;
    int flag_card1, flag_card2;

    

    public:
    Memory_managment *memory = new Memory_managment();
    int id_card1=0;
    int id_card2=0;
    int card_type1, card_type2;
    Handeling_message();
    struct info_pack* manage_message(struct info_pack *message);
    int check_equals(int id1, Card card2);


};



#endif