
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