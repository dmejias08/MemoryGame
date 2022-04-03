#ifndef handeling_message_h
#define handeling_message_h
#include "client.h"
#include "memory_managment.h"
#include "memory_managment.cpp"

class Handeling_message{

    private:
    struct info_pack message;
    Memory_managment memory = Memory_managment();

    public:
    int id_card1=0;
    int id_card2=0;
    Handeling_message();
    struct info_pack* manage_message(struct info_pack *message);
    int check_equals(int id1, int id2);


};



#endif