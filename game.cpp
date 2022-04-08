#include "game.h"

Game::Game(){

}

int Game::assign_points(int response){
    if(this->current_player == 1){
        if(response == 1){
            this->points_player1 += 10;
            this->player_points =this->current_player;
        }else{

            this->current_player = 2;
        }
        cout<<"[puntos]"<<points_player1<<endl;
        return this->points_player1;
    }else{
        if(response == 1){
            this->points_player2 += 10;
            this->player_points =this->current_player;
        }else{
            this->current_player = 1;
        }
        cout<<"[puntos]"<<points_player2<<endl;
        return this->points_player2; 
    }
}
// void Game::assign_turns(int player){
//     if(this->current_player == 0){
//         this->current_player = player;
//     }
// }
 
int Game::next_turn(){
    return this->current_player;
}

int Game::assing_points_to(){
    return this->player_points;
}