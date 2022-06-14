//
// Created by eylon on 6/14/22.
//
#include "League.hpp"
#include <iostream>

namespace ariel{
    std::string &League::Iterator::operator*() const {
        return this->ptr->name;
    }

    bool League::Iterator::operator!=(const Iterator &itr) const {
        if(this->ptr != itr.ptr){
            return true;
        }
        return false;
    }

    Team *League::Iterator::get_ptr() const {
        return this->ptr;
    }

    League::Iterator &League::Iterator::operator++() {
        if(this->seek == this->teams.size() - 1){
            this->ptr = nullptr;
        }else{
            this->seek++;
            this->ptr = this->teams[(uint)this->seek];
        }
        return *this;
    }

    League::Iterator League::Iterator::operator++(int) {
        League::Iterator itr = *this;
        if(this->seek == this->teams.size()){
            this->ptr = nullptr;
        }else{
            this->seek++;
            this->ptr = this->teams[(uint)this->seek];
        }
        return itr;
    }

    League::Iterator League::begin() {
        return League::Iterator(this->teams);
    }

    League::Iterator League::end() {
        std::vector<Team*> teams;
        return League::Iterator(teams);
    }
}