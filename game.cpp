#include "game.h"
#include "card.h"

int Game::check_equals(int pos1, int pos2){
    int i1 = pos1/10;
    int j1 = pos1%10;
    int i2 = pos2/10;
    int j2 = pos2%10;

    Card card1 = this->memory.get_card(i1,j1);
    Card card2 = this->memory.get_card(i2,j2);

    if(card1.type == card2.type){
        return 0;
    }
    return 1;
}