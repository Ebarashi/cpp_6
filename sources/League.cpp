#include<algorithm>
#include "League.hpp"



bool compare(Team * t1, Team *t2){

    if(t1->wins > t2->wins || t1->pointsDiff() >= t2->pointsDiff()) return true;
    

}

std::vector<string> ballT {
  "Cl_Cavaliers", "Br_Nets" , "NY_Knicks" , "Pho_Suns" ,
  "To_Raptors", "Ch_Bulls" , "Bo_Celtics" , "De_Pistons",
  "Mil_Bucks" , "Den_Nuggets", "Char_Hornets","Mi_Heat", 
  "Or_Magic" , "Wash_Wizards" , "At_Hawks" , "GS_Warriors", 
  "Da_Mavericks" , "Mi_Timberwolves" , "LA_Clippers","Ph_76"
};



Leauge::Leauge()
{

    for(size_t i =0; i <20; i++){
        teams[i] = new Team((double) rand() / (RAND_MAX), ballT.at(i));
    }
    s = new Schedule(teams);
}


void Leauge::startLeague(){

    s->startSeason();
    std::sort(teams.begin(), teams.begin() + 20, compare);

}

void Leauge::printTable(){

    for(Team* t: teams){

        cout<<t->getName()<<" | Wins:"<<t->wins<<" | Loses:"<<t->loses<<" | "
        <<" | "<<"points balance:"<<t->pointsDiff()<<std::endl;  
    }
}


    void Leauge::topTeams(int num){

        num = std::min(num, 20);
        cout << "=========== TOP " << num << " TEAM ===========\n" << endl;
        for(int i = 0 ; i < num; i++){
            cout<<i<<") "<<teams[i]->getName()<<std::endl;
        }

    }

    void Leauge::bottomTeams(int num)
    {

        num = std::min(num, 20);
        cout << "=========== BUTTOM " << num << " TEAM ===========\n" << endl;
        for(int i = 0 ; i < num; i++){
            cout<<i<<") "<<teams[19 - i]->getName()<<std::endl;
        }
    }

    void Leauge::longestWinStreak(){

        int i = 0, longest = -1, index = 0;
        cout << "=========== LONGEST WIN STREAK ===========\n" << endl;
        for(; i < 20; i++){
            if(teams[i]->getWinStreak() > longest){
                longest = teams[i]->getWinStreak();
                index = i;
            }

        }
            cout<<"The longest win streak is: "<<longest<<", Team: "<<teams[index]->getName()<<std::endl;
    }
    void Leauge::longestLoseStreak(){

        int i = 0, longest = -1, index = 0;
        cout << "=========== LONGEST LOSE STREAK ===========\n" << endl;
        for(; i < 20; i++){
            
            if(teams[i]->getLoseStreak() > longest){
                longest = teams[i]->getLoseStreak();
                index = i;
            }

        }
            cout<<"The longest Lose streak is: "<<longest<<", Team: "<<teams[index]->getName()<<std::endl;
    }
 
    void Leauge::positiveBalnce(){

        int posTeams = 0;

        for(int i = 0; i < 20; i++){
            if(teams[i]->pointsDiff() > 0) posTeams++;
        }        

        cout<<posTeams<<" Teams [positive points balance]"<<std::endl;
    }

    void Leauge::negetiveBalnce(){

        int negTeams = 0;

        for(int i = 0; i < 20; i++){
            if(teams[i]->pointsDiff() < 0) negTeams++;
        }        

        cout<<negTeams<<"  Teams [negetive points balance] "<<std::endl;
    }
   
 