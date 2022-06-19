#include "Game.hpp"

using namespace std;



Game::Game(Team *home,Team * away)
{
    home = home;
    away = away; 
    homePoints = 0; 
    awayPoints = 0;
    
}


void Game::play()
{
    std::random_device randomd;
    std::mt19937 generator{randomd()};
    normal_distribution<double> distribution{65, 17};
    do {
        homePoints = distribution(generator);
    } while (homePoints > 100 || homePoints < 0);
    do {
        awayPoints = distribution(generator);
    } while (awayPoints > 100 || awayPoints < 0);
    homePoints += 10 * this->home->getSkill();
    awayPoints += 10 * this->away->getSkill();
    
    cout<<home->getName()<<"[Home]: "<<homePoints<< endl;
    cout<<away->getName()<<"[Away]: "<<awayPoints<<"\n" << endl;

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

    

