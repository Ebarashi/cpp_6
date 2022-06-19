#include "Schedule.hpp"
#include <algorithm>
#include <list>

struct Round
{
    std::vector<Game> games;
    std::vector<Game>::iterator begin(){return games.begin();}
    std::vector<Game>::iterator end(){return games.end();}

};


Schedule::Schedule(vector<Team*>& t)
{
    teams = t;
}


void Schedule::startSeason()
{
    std::vector<Round> ans;

    vector<size_t> teamsNumbers;
    teamsNumbers.reserve(20);
    for (size_t i = 0; i < 20; i++) {
        teamsNumbers.emplace_back(i);
    }

    for (size_t i = 0; i < 20 - 1; i++) {
        Round round;
        for (size_t j = 0; j < 20 / 2; j++) {
            round.games.emplace_back(*(teams.at(teamsNumbers.at(j))),
                                         *(teams.at(teamsNumbers.at(20 - 1 - j))));
            round.games.emplace_back(*(teams.at(teamsNumbers.at(20 - 1 - j))),
                                         *(teams.at(teamsNumbers.at(j))));
        }

        size_t last = teamsNumbers.at(teamsNumbers.size() - 1);
        for (size_t j = teamsNumbers.size() - 1; j >= 2; j--) {
            teamsNumbers.at(j) = teamsNumbers.at(j - 1);
        }
        teamsNumbers.at(1) = last;
        ans.emplace_back(round);
    }
    
    //start season after finished to make all rounds
    for (auto &curr_round : ans)
    {
        for (auto &game : curr_round)
        {
            game.play();
        }
    }
}