#include "Game.hpp"

using namespace std;

std::random_device randomd;
std::mt19937 generator{randomd()};
normal_distribution<double> distribution{65, 17};

Game::Game(Team *home,Team * away)
{
    this->home = home;
    this->away = away; 
    homePoints = 0;
    awayPoints = 0;
    
    
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
        // std::random_device rd;
        // std::mt19937 gen{rd()};
        // std::normal_distribution<> score{27, 7};
        // std::normal_distribution<> bonus{5, 3};

        // int ran;
        // //calculate base score
        // do{
        //     ran = score(gen);
        // }while(ran > 45);
        // homePoints += ran;
        // do{
        //     ran = score(gen);
        // }while(ran > 50);
        // awayPoints += ran;

        // //calculate bocus score
        // do{
        //     ran = score(gen);
        // }while(ran > 10);
        // homePoints += ran * home->getSkill();   

        // do{
        //     ran = score(gen);
        // }while(ran > 10);
        // awayPoints += ran * away->getSkill();

        // cout<<home->getName()<<"[Home]: "<<homePoints<<std::endl;
        // cout<<away->getName()<<"[Out]: "<<awayPoints<<"\n~~~~~~~~~~~~~~~~~"<<std::endl;

        // if(homePoints >= awayPoints){
        //     winner = 0;
        //     home->wins++;
        //     away->loses++;
        //     home->won(homePoints, awayPoints);
        //     away->lost(awayPoints, homePoints);
        // }
        // else{
        //     winner = 1;
        //     home->loses++;
        //     away->wins++;
        //     home->lost(homePoints, awayPoints);
        //     away->won(awayPoints, homePoints);
        // }

}

    

