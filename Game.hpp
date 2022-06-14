//
// Created by eylon on 6/14/22.
//
#include <random>
#include <cmath>
#include "Team.hpp"

namespace ariel{
    class Game{
    public:
        Team* home;
        Team* away;
        int score_a;
        int score_b;

    public:
        Game(ariel::Team& a, ariel::Team& b){
            this->home = &a;
            this->away = &b;
            this->score_a = 0;
            this->score_b = 0;
        }
        ~Game(){}

        void play();

    };
}
