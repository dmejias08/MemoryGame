#include "handeling_message.h"
#include <iostream>

Handeling_message::Handeling_message(){

}
/**
 * @brief It recieves message from server, defines the answer 
 * 
 * @param message package of information from server 
 * @return struct info_pack* package of inforfamtion to client 
 */
struct info_pack* Handeling_message::manage_message(struct info_pack *message){
    if(message->type_message == 0){
        if(this->id_card1 == 0){ // fist card 
            this->id_card1 = message->id;
            int i1 = id_card1/10;
            int j1 = id_card1%10;
            Card card1 = this->memory->get_card(i1,j1); 
            /*Define response */
            this->flag_card1 = this->memory->flag;
            message->id = 0; //need to click one more card
            message->card_type = card1.type;
            message->punish_player = 0;
            message->punish_points = 0;
            this->img1 = card1.img;
            message->size = this->img1.size();
            return message;
        }else{ //second card 
            this->id_card2 = message->id;
            int i2 = id_card2/10;
            int j2 = id_card2%10;
            Card card2 = this->memory->get_card(i2,j2);
            this->flag_card2 = this->memory->flag;
            int result = check_equals(this->id_card1, card2); //checks if both card are equals 
            /*Define response */
            message->points = this->game->assign_points(result);
            message->current_player = this->game->next_turn();
            message->player_points = this->game->assing_points_to();
            message->winner = this->game->determine_winner();
            message->punish_player = this->game->f_punish_player();
            message->punish_points = this->game->f_punish_points();
            message->id = result;
            message->card_type = card2.type;
            this->img1 = card2.img;
            message->size = this->img1.size();
            this->id_card1 =0;
            this->id_card2 =0;
            return message;
        }
    }

}
/**
 * @brief checks if card selected are equals 
 * 
 * @param id1 id of first card 
 * @param card2 second object card 
 * @return int: 1 are equals, 2 are not equals 
 */
int Handeling_message::check_equals(int id1, Card card2){
    int i1 = id1/10;
    int j1 = id1%10;
    Card card1 = this->memory->get_card(i1,j1);
    this->memory->page_hits -= 1;
    std::cout<<"La carta1 es ";
    card1.print();
    std::cout<<"La carta2 es ";
    card2.print();


    if(card1.type == card2.type){
            card1.status = 1;
            card2.status = 1;
            this->memory->delete_cards(card1);
            this->memory->delete_cards(card2);
            this->memory->shuffle();
            return 1;
    }
    return 2;
}
std::string Handeling_message::getImage(){
        return this->img1;
}


