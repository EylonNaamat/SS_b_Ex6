//
// Created by eylon on 6/14/22.
//
#include "Team.hpp"

void ariel::Team::inc_win(){
    this->games_won++;
}
void ariel::Team::inc_lose(){
    this->games_loss++;
}
void ariel::Team::inc_win_streak(){
    this->win_streak++;
    if(this->win_streak > this->longest_win_streak){
        this->longest_win_streak = this->win_streak;
    }
}
void ariel::Team::inc_loss_streak(){
    this->loss_streak++;
    if(this->loss_streak > this->longest_loss_streak){
        this->longest_loss_streak = this->loss_streak;
    }
}
void ariel::Team::reset_win_streak(){
    this->win_streak = 0;
}
void ariel::Team::reset_loss_streak(){
    this->loss_streak = 0;
}
void ariel::Team::add_scored(int score){
    this->points_scored += score;
}
void ariel::Team::add_neg_scored(int score){
    this->points_neg_scored += score;
}
int ariel::Team::point_diff(){
    return this->points_scored - this->points_neg_scored;
}
double ariel::Team::get_talent_level(){
    return this->talent_level;
}
bool ariel::Team::get_win_last(){
    return this->win_last;
}
void ariel::Team::set_win_last(bool flag){
    this->win_last = flag;
}

std::string ariel::Team::get_name(){
    return this->name;
}