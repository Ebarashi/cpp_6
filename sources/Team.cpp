#include "Team.hpp"


Team::Team(double skill, string name)
{
    skill = skill;
    name = name;
    Scored = 0; 
    absorbedPoints = 0;
    winStreak = 0;
    loseStreak = 0;
    wins = 0;
    loses = 0;
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
        Scored += scored;
        absorbedPoints += absorbed;
        loseStreak++;
        if(loseStreak > LongestloseStreak){
            LongestloseStreak = loseStreak;
        }
        winStreak = 0;
    }

