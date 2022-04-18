#include "game.h"

Game::Game(){

}
/**
 * @brief it assigns points for each player 
 * 
 * @param response ii defines if the player had a match or not 
 * @return int number of points 
 */
int Game::assign_points(int response){
    this->punish_player = 0;
    this->punish_points = 0;
    if(this->current_player == 1){
        if(response == 1){
            this->player1_wins += 1;
            if(this->player1_wins >1){
                check_powerups(this->current_player);
            }
            this->unused_cards -= 2;
            this->points_player1 += 5;
            this->player_points =this->current_player;
            if(this->unused_cards <= 0){
                check_winner();
            }

        }else{
            this->player1_wins = 0;
            this->player_points = 1;
            this->current_player = 2;
        }
        cout<<"[puntos] de player 1 "<<points_player1<<endl;
        return this->points_player1;
    }else{
        if(response == 1){
            this->player2_wins += 1;
            if(this->player2_wins > 1){
                check_powerups(this->current_player);
            }
            this->unused_cards -= 2;
            this->points_player2 += 5;
            this->player_points =this->current_player;
            if(this->unused_cards <= 0){
                check_winner();
            }
        }else{
            this->player2_wins = 0;
            this->player_points = 2;
            this->current_player = 1;
        }
        cout<<"[puntos] de player 2 "<<points_player2<<endl;
        return this->points_player2; 
    }
}
/**
 * @brief when there is none cards left it defines the winner 
 * 
 */
void Game::check_winner(){
    if(this->points_player1 > this->points_player2){
        this->winner = 1;
    }else{
        this->winner =2;
    }
}
/**
 * @brief it sets advantages to each player 
 * 
 * @param current_player 
 */
void Game::check_powerups(int current_player){
    if(current_player == 1){
        if(this->player1_wins == 2){
            this->punish_player = 2;
            this->points_player2 -= 5;
            this->punish_points = this->points_player2;
        }else if(this->player1_wins == 3){
            this->points_player1 += 5;
        }
    }else{
        if(this->player2_wins == 2){
            this->punish_player = 1;
            this->points_player1 -= 5;
            this->punish_points = this->points_player1;
        }else if(this->player2_wins == 3){
            this->points_player2 += 5;
        }   
    }
}
int Game::f_punish_points(){
    return this->punish_points;
}
int Game::f_punish_player(){
    return this->punish_player;
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
