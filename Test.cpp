#include "doctest.h"
#include "sources/League.hpp"


TEST_CASE("Team")
{
    
    cout << "im in" << endl;

    Team t1 {0.5, "BBB"};
    Team t2 {0.15, "ALT"};
    Team t3 {0.135, "CTRL"};
    Team t4 {0.515, "ESPN"};

    std::cout << "im in" << endl;
    Game g1 {&t1, &t2};
    if(g1.winner){
        CHECK(t1.pointsDiff() > 0);
        CHECK(t2.pointsDiff() < 0);
    }

    Game g2{&t3, &t4};

    if(g2.winner){
        CHECK(t3.pointsDiff() > 0);
        CHECK(t4.pointsDiff() < 0);
    }


    League league; 
    CHECK_THROWS(league.bottomTeams(5));
    CHECK_THROWS(league.bottomTeams(10));
    

    league.startLeague();
    CHECK_NOTHROW(league.bottomTeams(5));
    CHECK_NOTHROW(league.topTeams(5));
    CHECK_NOTHROW(league.longestLoseStreak());
    CHECK_NOTHROW(league.longestWinStreak());
    CHECK_NOTHROW(league.negetiveBalnce());
    CHECK_NOTHROW(league.positiveBalnce());

    
}