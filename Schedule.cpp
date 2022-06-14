//
// Created by eylon on 6/14/22.
//
#include "Schedule.hpp"

namespace ariel{
    void Schedule::play(){
        if(this->period == 20){
            std::vector<Team*> tmp = this->home;
            this->home = this->away;
            this->away = tmp;
            this->period++;
        }else{
            for(int i = 0; i < 10; ++i){
                Game g{*(this->home[(uint)i]), *(this->away[(uint)i])};
                g.play();
            }
            ariel::Team team;
            ariel::Team* team_point = &team;
            team_point = this->home[9];
            for(int i = 9; i >= 2; --i){
                this->home[i] = this->home[i-1];
            }
            ariel::Team team2;
            ariel::Team* team_point2 = &team2;
            team_point2 = this->away[0];
            for(int i = 0; i < 9; ++i){
                this->away[i] = this->away[i+1];
            }
            this->home[1] = team_point2;
            this->away[9] = team_point;
            this->period++;
        }
    }

    void Schedule::play_full_season(){
        for(int i = 0; i < 19; ++i){
            this->play();
        }
        this->play();
        this->period = 1;
        for(int i = 0; i < 19; ++i){
            this->play();
        }
        this->play();

        for(int i = 0; i < 10; ++i){
            this->final_season.push_back(this->home[i]);
        }
        for(int i = 0; i < 10; ++i){
            this->final_season.push_back(this->away[i]);
        }

//        for(int i = 0; i < this->home.size(); ++i){
//            std::cout << i << " " << this->home[i]->name << std::endl;
//        }
//        for(int i = 0; i < this->away.size(); ++i){
//            std::cout << i << " " << this->away[i]->name << std::endl;
//        }
    }

    bool Schedule::compare_teams(Team* a, Team* b){
        if(a->games_won != b->games_won){
            return a->games_won > b->games_won;
        }
        return a->point_diff() > b->point_diff();
    }

    void Schedule::sort_final_season(){
        std::sort(this->final_season.begin(), this->final_season.end(), Schedule::compare_teams);
    }

    void Schedule::top_teams(int num){
        std::cout << "The Top Teams In The League Are:" << std::endl;
        for(int i = 0; i < num; ++i){
            std::cout << (i+1) << " - " << this->final_season[i]->name << std::endl;
        }
    }

    bool Schedule::compare_win_streaks(Team* a, Team* b){
        return ((a->longest_win_streak) < (b->longest_win_streak));
    }

    bool Schedule::compare_loss_streaks(Team* a, Team* b){
        return ((a->longest_loss_streak) < (b->longest_loss_streak));
    }

    void Schedule::longest_win_streak(){
        auto num = std::max_element(this->final_season.begin(), this->final_season.end(), Schedule::compare_win_streaks);
        std::cout << "The Longest Win Streak is "<< (*num)->longest_win_streak << std::endl;
    }

    void Schedule::longest_loss_streak(){
        auto num = std::max_element(this->final_season.begin(), this->final_season.end(), Schedule::compare_loss_streaks);
        std::cout << "The Longest Loss Streak is "<< (*num)->longest_loss_streak << std::endl;
    }

    void Schedule::count_positive(){
        int num = std::count_if(this->final_season.begin(), this->final_season.end(), [](Team* a){return a->point_diff() > 0;});
        std::cout << "The Number Of Teams That Scored More Than Get Scored Are: " << num << std::endl;
    }

}