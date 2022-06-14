//
// Created by eylon on 6/14/22.
//
#include <string>

namespace ariel{
    class Team{
    public:
        std::string name;
        double talent_level;
        int games_won;
        int games_loss;
        int win_streak;
        int loss_streak;
        int points_scored;
        int points_neg_scored;
        bool win_last;
        int longest_win_streak;
        int longest_loss_streak;

    public:
        Team(std::string name, double talent_level){
            this->name = name;
            this->talent_level = talent_level;
            this->games_won = 0;
            this->games_loss = 0;
            this->win_streak = 0;
            this->loss_streak = 0;
            this->points_scored = 0;
            this->points_neg_scored = 0;
            this->win_last = true;
            this->longest_loss_streak = 0;
            this->longest_win_streak = 0;
        }
        Team(){
            this->name = "";
            this->talent_level = 0;
            this->games_won = 0;
            this->games_loss = 0;
            this->win_streak = 0;
            this->loss_streak = 0;
            this->points_scored = 0;
            this->points_neg_scored = 0;
            this->win_last = true;
        }
        ~Team(){}

        void inc_win();
        void inc_lose();
        void inc_win_streak();
        void inc_loss_streak();
        void reset_win_streak();
        void reset_loss_streak();
        void add_scored(int score);
        void add_neg_scored(int score);
        int point_diff();
        double get_talent_level();
        bool get_win_last();
        void set_win_last(bool flag);
        std::string get_name();
    };
}

