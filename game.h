#ifndef game_h
#define game_h



class Game{
    public:
    Game();
    int assign_points(int response);
    void assign_turns(int player);
    int next_turn();
    int assing_points_to();

    private:
    int points_player1 = 0;
    int points_player2 = 0;
    int current_player = 1;
    int player_points;

};



#endif