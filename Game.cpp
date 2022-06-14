//
// Created by eylon on 6/14/22.
//
#include "Game.hpp"

namespace ariel{
    void Game::play(){
        std::random_device rd{};
        std::mt19937 gen{rd()};
        std::normal_distribution<double> d{75,20};
        std::normal_distribution<double> d2{70,20};

        this->score_a = std::round(d(gen));
        while(this->score_a < 55 || this->score_a > 100){
            this->score_a = std::round(d(gen));
        }

        this->score_b = std::round(d(gen));
        while(this->score_b < 50 || this->score_b > 100){
            this->score_b = std::round(d2(gen));
        }

        if(this->home->get_talent_level() >= this->away->get_talent_level()){
            this->score_a += 10;
            if(this->score_a > 100){
                this->score_a = 100;
            }
        }else{
            this->score_b += 10;
            if(this->score_b > 100){
                this->score_b = 100;
            }
        }

        this->home->add_scored(this->score_a);
        this->home->add_neg_scored(this->score_b);
        this->away->add_scored(this->score_b);
        this->away->add_neg_scored(this->score_a);

        if(this->score_a >= this->score_b){
            this->home->inc_win();
            this->away->inc_lose();
            if(!this->home->get_win_last()) {
                this->home->set_win_last(true);
                this->home->reset_loss_streak();
                this->home->reset_win_streak();
                this->home->inc_win_streak();
            }else{
                this->home->inc_win_streak();
                this->home->reset_loss_streak();
            }
            if(!this->away->get_win_last()){
                this->away->inc_loss_streak();
                this->away->reset_win_streak();
            }else{
                this->away->set_win_last(false);
                this->away->reset_win_streak();
                this->away->reset_loss_streak();
                this->away->inc_loss_streak();
            }
        }else{
            this->away->inc_win();
            this->home->inc_lose();
            if(!this->away->get_win_last()){
                this->away->set_win_last(true);
                this->away->reset_loss_streak();
                this->away->reset_win_streak();
                this->away->inc_win_streak();
            }else{
                this->away->inc_win_streak();
                this->away->reset_loss_streak();
            }
            if(!this->home->get_win_last()){
                this->home->inc_loss_streak();
                this->home->reset_win_streak();
            }else{
                this->home->set_win_last(false);
                this->home->reset_win_streak();
                this->home->reset_loss_streak();
                this->home->inc_loss_streak();
            }
        }
    }
}