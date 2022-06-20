#pragma once
#include <vector>
#include <iostream>
#include "Game.hpp"
#include "Schedule.hpp"


class League
{
    private:
        
        vector<Team*> teams;
        Schedule* s;

    public:
        
        bool started = false;
        League();
        void startLeague();
        void printTable();

        void topTeams(int num);
        void bottomTeams(int num);
        
        void longestWinStreak();
        void longestLoseStreak();
        
        void positiveBalnce();
        void negetiveBalnce();
        
};