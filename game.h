#ifndef game_h
#define game_h



class Game{
    public:
    Game();
    int assign_points(int response);
    void assign_turns(int player);
    int next_turn();
    int assing_points_to();
    int determine_winner();
    void check_winner();
    void check_powerups(int current_player);
    int f_punish_points();
    int f_punish_player();

    private:
    int punish_points = 0;
    int player1_wins;
    int player2_wins;
    int winner = 0;
    int unused_cards = 30;
    int points_player1 = 0;
    int points_player2 = 0;
    int current_player = 1;
    int player_points;
    int punish_player = 0;

};



#endif