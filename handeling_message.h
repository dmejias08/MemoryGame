#ifndef handeling_message_h
#define handeling_message_h
#include "client.h"
#include "memory_managment.h"
#include "memory_managment.cpp"
#include "game.h"
#include "game.cpp"

class Handeling_message{

    private:
    int current_player = 1;
    struct info_pack message;
    int flag_card1, flag_card2;
    int ptos_jug1 = 0;
    int ptos_jug2 = 0;

    

    public:
    int id_card1=0;
    int id_card2=0;
    int card_type1, card_type2;
    Memory_managment *memory = new Memory_managment();
    Handeling_message();
    Game *game = new Game();
    struct info_pack* manage_message(struct info_pack *message);
    int check_equals(int id1, Card card2);
    int assign_points(int result);


};



#endif