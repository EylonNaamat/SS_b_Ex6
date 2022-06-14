//
// Created by eylon on 6/14/22.
//
#include <random>
#include <iostream>
#include <cmath>
#include "Schedule.hpp"

int main(){
//    std::random_device rd{};
//    std::mt19937 gen{rd()};
//    std::normal_distribution<double> d{75,20};
//    std::normal_distribution<double> d2{70,20};
//
//    std::cout << std::round(d(gen)) << std::endl;
//    std::cout << std::round(d2(gen)) << std::endl;
//
//    ariel::Team la{"lakers", 1};
//    std::cout << la.get_name() << std::endl;
//    la.inc_win();
//    std::cout << la.games_loss << std::endl;
//
//    ariel::Team newyork{"newyork", 0.5};
//    ariel::Team team;
//
//    ariel::Game g1{la, newyork};
//
//    g1.play();
//
//    std::cout << g1.score_a << std::endl;
//    std::cout << g1.score_b << std::endl;
//
//    std::cout << la.points_scored << std::endl;
//    std::cout << newyork.points_scored << std::endl;
//
//    ariel::Game g2{newyork, la};
//
//    g2.play();
//
//    std::cout << g2.score_a << std::endl;
//    std::cout << g2.score_b << std::endl;
//
//    std::cout << la.points_scored << std::endl;
//    std::cout << newyork.points_scored << std::endl;
//
//    std::vector<ariel::Team*> teams;
////    teams.push_back(new ariel::Team("lakers", 1));
////    teams.push_back(new ariel::Team("newyork", 0.5));
//
//    teams.push_back(&la);
//    teams.push_back(&newyork);
//    teams.push_back(&team);
//
//
//    ariel::League l1{teams};
//
////    auto it1 = l1.begin();
////    auto it2 = l1.end();
////
////    std::cout << (*it1) << std::endl;
////    ++it1;
////    std::cout << (*it1) << std::endl;
////    ++it1;
////    std::cout << (*it1) << std::endl;
////    ++it1;
////
////    std::cout << (it1 != it2) << std::endl;
////    std::cout << (it1.ptr == nullptr) << std::endl;
////    std::cout << it2.ptr << std::endl;
////
////    std::cout << it1.seek << std::endl;
////    std::cout << it1.teams.size() << std::endl;
//
//    for(auto itr = l1.begin(); itr != l1.end(); ++itr){
//        std::cout << itr.ptr << std::endl;
//    }
//
////    la = newyork;
//
//    teams[2] = teams[1];
//    std::cout << teams[2]->name << std::endl;
//
//    ariel::Team teama;
//    ariel::Team* p = &teama;
//
//    std::cout << p->name << std::endl;

//    auto i = teams.begin();
//    std::cout << teams[0] << std::endl;
//    std::cout << (*i)->name << std::endl;
//    teams.erase(i);
//    std::cout << teams[0] << std::endl;
//
//
//    ariel::Schedule sc{l1};

    std::vector<ariel::Team*> myTeams;
    myTeams.push_back(new ariel::Team("Golden State Warriors", 1));
    myTeams.push_back(new ariel::Team("Boston Celtics", 0.4));
    myTeams.push_back(new ariel::Team("Brooklyn Nets", 0.5));
    myTeams.push_back(new ariel::Team("Denver Nuggets", 0.3));
    myTeams.push_back(new ariel::Team("Philadelphia 76ers", 0.4));
    myTeams.push_back(new ariel::Team("Minnesota Timberwolves", 0.5));
    myTeams.push_back(new ariel::Team("Chicago Bulls", 0.3));
    myTeams.push_back(new ariel::Team("Portland Trail Blazers", 0.2));
    myTeams.push_back(new ariel::Team("LA Clippers", 0.5));
    myTeams.push_back(new ariel::Team("Los Angeles Lakers", 1));
    myTeams.push_back(new ariel::Team("Milwaukee Bucks", 0.7));
    myTeams.push_back(new ariel::Team("Atlanta Hawks", 0.3));
    myTeams.push_back(new ariel::Team("Charlotte Hornets", 0.2));
    myTeams.push_back(new ariel::Team("Miami Heat", 0.6));
    myTeams.push_back(new ariel::Team("Phoenix Suns", 0.8));
    myTeams.push_back(new ariel::Team("Dallas Mavericks", 0.6));
    myTeams.push_back(new ariel::Team("Memphis Grizzlies", 0.5));
    myTeams.push_back(new ariel::Team("Utah Jazz", 0.3));
    myTeams.push_back(new ariel::Team("Washington Wizards", 0));
    myTeams.push_back(new ariel::Team("Oklahoma City Thunder", 0.1));


    ariel::League league{myTeams};
    ariel::Schedule schedule{league};
    for(int i = 0; i < 10; ++i){
        std::cout << schedule.home[i]->name << std::endl;
        std::cout << schedule.home[i]->points_scored << std::endl;
    }

    std::cout << "-----------------" << std::endl;

    for(int i = 0; i < 10; ++i){
        std::cout << schedule.away[i]->name << std::endl;
        std::cout << schedule.away[i]->points_scored << std::endl;
    }

    std::cout << "**********************" << std::endl;

    schedule.play_full_season();

    for(int i = 0; i < 10; ++i){
        std::cout << schedule.home[i]->name << std::endl;
        std::cout << schedule.home[i]->points_scored << std::endl;
    }

    std::cout << "-----------------" << std::endl;

    for(int i = 0; i < 10; ++i){
        std::cout << schedule.away[i]->name << std::endl;
        std::cout << schedule.away[i]->points_scored << std::endl;
    }

    schedule.sort_final_season();

//    auto itr = myTeams.begin();
//    std::cout << (*itr) << std::endl;
//    ++itr;
//    std::cout << (*itr) << std::endl;

//    schedule.sort_final_season();
    for(int i = 0; i < schedule.final_season.size(); ++i){
        std::cout << schedule.final_season[i]->name << "    " << schedule.final_season[i]->games_won <<  "  " << schedule.final_season[i]->point_diff() << std::endl;
    }

    schedule.top_teams(4);
    schedule.longest_win_streak();
    schedule.longest_loss_streak();
    schedule.count_positive();


//    schedule.play();
//
//    for(int i = 0; i < 10; ++i){
//        std::cout << schedule.home[i]->name << std::endl;
//        std::cout << schedule.home[i]->points_scored << std::endl;
//    }
//
//    std::cout << "-----------------" << std::endl;
//
//    for(int i = 0; i < 10; ++i){
//        std::cout << schedule.away[i]->name << std::endl;
//        std::cout << schedule.away[i]->points_scored << std::endl;
//    }


    return 0;
}