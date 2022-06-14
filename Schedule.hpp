//
// Created by eylon on 6/14/22.
//
#include "League.hpp"
#include <iostream>
#include <algorithm>

namespace ariel{
    class Schedule{
    public:
        std::vector<Team*> home;
        std::vector<Team*> away;
        std::vector<Team*> final_season;
        int period;
        int longest;

    public:
        Schedule(ariel::League& league){
            auto itr = league.begin();
            for(int i = 0; i < league.teams.size()/2; ++i){
                ariel::Team team;
                ariel::Team* team_point = &team;
                team_point = itr.ptr;
                itr++;
                this->home.push_back(team_point);
            }
            for(int i = 19; i >= 10; --i){
                ariel::Team team;
                ariel::Team* team_point = &team;
                team_point = league.teams[(uint)i];
                this->away.push_back(team_point);
            }
            this->period = 1;
            this->longest = 0;
        }

        void play();
        void play_full_season();
        void sort_final_season();
        static bool compare_teams(Team* a, Team* b);
        static bool compare_win_streaks(Team* a, Team* b);
        static bool compare_loss_streaks(Team* a, Team* b);
        void top_teams(int num);
        void longest_win_streak();
        void longest_loss_streak();
        void count_positive();

    };
}
