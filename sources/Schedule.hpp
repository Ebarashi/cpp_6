
#pragma once
#include "Game.hpp"

struct Round
{
    std::vector<Game> games;
    std::vector<Game>::iterator begin(){return games.begin();}
    std::vector<Game>::iterator end(){return games.end();}

};

class Schedule
{
     
    public:
        std::vector<Round> rounds;
        Schedule();
        void startSeason(vector<Team*> t);

};

