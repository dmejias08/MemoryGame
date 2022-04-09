#include "game.h"

Game::Game(){

}

int Game::assign_points(int response){
    if(this->current_player == 1){
        if(response == 1){
            this->unused_cards -= 2;
            this->points_player1 += 10;
            this->player_points =this->current_player;
            if(this->unused_cards <= 0){
                if(this->points_player1 > this->points_player2){
                    this->winner = 1;
                }else{
                    this->winner =2;
                }
            }
        }else{
            this->player_points = 1;
            this->current_player = 2;
        }
        cout<<"[puntos] de player 1 "<<points_player1<<endl;
        return this->points_player1;
    }else{
        if(response == 1){
            this->unused_cards -= 2;
            this->points_player2 += 10;
            this->player_points =this->current_player;
            if(this->unused_cards <= 0){
                if(this->points_player1 > this->points_player2){
                    this->winner = 1;
                }else{
                    this->winner = 2;
                }
            }
        }else{
            this->player_points = 2;
            this->current_player = 1;
        }
        cout<<"[puntos] de player 2 "<<points_player2<<endl;
        return this->points_player2; 
    }
}

int Game::next_turn(){
    return this->current_player;
}

int Game::assing_points_to(){
    return this->player_points;
}

int Game::determine_winner(){
    return this->winner;
}
