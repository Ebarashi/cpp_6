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
        Team& get_homeTeam(){return *this->home;}
        Team& get_outTeam(){return *this-> away;}
        void play();
        friend ostream& operator<<(ostream& out, Game& g);
        
};
