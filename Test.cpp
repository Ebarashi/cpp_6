#include "doctest.h"
#include "sources/League.hpp"


TEST_CASE("Team"){

    Team t1 {0.5, "BBB"};
    Team t2 {0.15, "ALT"};
    Team t3 {0.135, "CTRL"};
    Team t4 {0.515, "ESPN"};

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


    Leauge lig; 
    CHECK_THROWS(lig.bottomTeams(5));
    CHECK_THROWS(lig.bottomTeams(10));
    

    lig.startLeague();
    CHECK_NOTHROW(lig.bottomTeams(5));
    CHECK_NOTHROW(lig.topTeams(5));
    CHECK_NOTHROW(lig.longestLoseStreak());
    CHECK_NOTHROW(lig.longestWinStreak());
    CHECK_NOTHROW(lig.negetiveBalnce());
    CHECK_NOTHROW(lig.positiveBalnce());

    
}