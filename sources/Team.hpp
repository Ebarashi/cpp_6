
#include <string>
#pragma once

using namespace std;
class Team
{
    private:
        
        string name;    
        double skill;
        int LongestwinStreak, LongestloseStreak;
        int winStreak, loseStreak;
        int Scored, absorbedPoints;
        

    public:
        
        int wins, loses;
        Team(double skill, string name);
        
        string getName();
        double getSkill();
        int pointsDiff(){return Scored - absorbedPoints;}
        int getWinStreak(){return LongestwinStreak;}
        int getLoseStreak(){return LongestloseStreak;}

        void resetWins(){winStreak = 0;}
        void resetLoses() {loseStreak = 0;}
        
        void won(int scored, int absorbed);
        void lost(int scored, int absorbed);
};