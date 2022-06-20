#pragma once
#include <string>
#include <random>
#include <iomanip>
#include "Team.hpp"
#include <iostream>

using namespace std;


class Game
{
    private:
        Team *home, *away;
        
       
    public:

        Game(Team *home,Team* away);

        
        bool winner;
        int homePoints, awayPoints;
        void play();
        friend ostream& operator<<(ostream& out, Game& g);
        
};
