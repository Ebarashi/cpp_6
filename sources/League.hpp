#pragma once
#include <vector>
#include <iostream>
#include "Game.hpp"
#include "Schedule.hpp"


class Leauge
{
    private:
        
        vector<Team*> teams;
        Schedule * s;

    public:
        
        Leauge();
        void startLeague();
        void printTable();

        void topTeams(int num);
        void bottomTeams(int num);
        
        void longestWinStreak();
        void longestLoseStreak();
        
        void positiveBalnce();
        void negetiveBalnce();
        
};