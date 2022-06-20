#include "Game.hpp"

using namespace std;

std::random_device randomd;
std::mt19937 generator{randomd()};
normal_distribution<double> distribution{77, 9};

Game::Game(Team *home,Team * away)
{
    this->home = home;
    this->away = away; 
    this->homePoints = 0;
    this->awayPoints = 0;
    
    
}

void Game::play()
{
    do {
        homePoints = distribution(generator);
    } while (homePoints > 100 || homePoints < 0);
    do {
        awayPoints = distribution(generator);
    } while (awayPoints > 100 || awayPoints < 0);
    homePoints += 10 * (int)this->home->getSkill();
    awayPoints += 10 * (int)this->away->getSkill();
    

    if(homePoints >= awayPoints)
    {
        winner = true;
        home->wins++;
        away->loses++;
        home->won(homePoints, awayPoints);
        away->lost(awayPoints, homePoints);
    }
    else
    {
        winner = false;
        home->loses++;
        away->wins++;
        home->lost(homePoints, awayPoints);
        away->won(awayPoints, homePoints);
    }
    
}

    

