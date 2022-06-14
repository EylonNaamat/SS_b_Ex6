//
// Created by eylon on 6/14/22.
//
#include "Game.hpp"
#include <vector>
#include <utility>
#include <stack>

namespace ariel{
    class League{
    public:
        std::vector<Team*> teams;
    public:
        League(std::vector<Team*> teams){
            this->teams = teams;
        }

        class Iterator{
        public:
            Team* ptr;
            int seek;
            std::vector<Team*> teams;
            std::string&  operator*() const;
            bool operator!=(const Iterator& itr) const;
            Team* get_ptr() const;
            Iterator(std::vector<Team*> teams){
                if(teams.empty()){
                    this->ptr = nullptr;
                }else{
                    this->teams = teams;
                    this->seek = 0;
                    this->ptr = this->teams[(uint)this->seek];
                }
            }
            Iterator& operator++();
            Iterator operator++(int);
        };

        Iterator begin();
        Iterator end();
    };
}
