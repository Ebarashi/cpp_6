#include "Schedule.hpp"
#include <algorithm>
#include <list>



Schedule::Schedule()
{
}


std::vector<Round> Schedule::startSeason(vector<Team*> t)
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
            round.games.emplace_back(t[teamsNumbers.at(j)],(t[(teamsNumbers.at(20 - 1 - j))]));
            round.games.emplace_back((t[(teamsNumbers.at(20 - 1 - j))]), (t[(teamsNumbers.at(j))]));
        }

        size_t last = teamsNumbers.at(teamsNumbers.size() - 1);
        for (size_t j = teamsNumbers.size() - 1; j >= 2; j--) {
            teamsNumbers.at(j) = teamsNumbers.at(j - 1);
        }
        teamsNumbers.at(1) = last;
        rounds.push_back(round);
    }
    
   return ans;
}