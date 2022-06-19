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
        normal_distribution<double> distribution{65, 17};
        std::random_device rd{};
        std::mt19937 generator{rd()};
    public:

        Game(Team *home,Team * away);
        
        bool winner;
        int homePoints, awayPoints;
        Team& get_homeTeam(){return *this->home;}
        Team& get_outTeam(){return *this-> away;}
        void play();
        friend ostream& operator<<(ostream& out, Game& g);
        
    };
