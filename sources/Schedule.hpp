
#pragma once
#include "Game.hpp"

class Schedule
{
private:
    vector<Team*> teams;
 
    
public:
    
    Schedule(vector<Team*>&teams);
    void startSeason();

};

struct Round
{
    std::vector<Game> games;
    std::vector<Game>::iterator begin(){return games.begin();}
    std::vector<Game>::iterator end(){return games.end();}

};