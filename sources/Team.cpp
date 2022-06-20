#include "Team.hpp"


Team::Team(double skill, string &name)
{
    this->skill = skill;
    this->name = name;
    this->Scored = 0; 
    this->absorbedPoints = 0;
    this->winStreak = 0;
    this->loseStreak = 0;
    this->wins = 0;
    this->loses = 0;
    this->LongestwinStreak = 0;
    this->LongestloseStreak = 0;
}

string Team::getName(){return this->name;}
double Team::getSkill(){return this->skill;}

    void Team::won(int scored, int absorbed){
        this->Scored += scored;
        absorbedPoints += absorbed;
        winStreak++;
        if(winStreak > LongestwinStreak){
            LongestwinStreak = winStreak;
        }
        loseStreak = 0;    
    }

    void Team::lost(int scored, int absorbed){
        this->Scored += scored;
        absorbedPoints += absorbed;
        loseStreak++;
        if(loseStreak > LongestloseStreak){
            LongestloseStreak = loseStreak;
        }
        winStreak = 0;
    }

