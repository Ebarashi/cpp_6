#include<algorithm>
#include "League.hpp"



bool compare(Team * t1, Team *t2){

    if(t1->wins > t2->wins || t1->pointsDiff() >= t2->pointsDiff()) return true;
    
    return false;
}

std::vector<string> ballT {
  "Cl_Cavaliers", "Br_Nets" , "NY_Knicks" , "Pho_Suns" ,
  "To_Raptors", "Ch_Bulls" , "Bo_Celtics" , "De_Pistons",
  "Mil_Bucks" , "Den_Nuggets", "Char_Hornets","Mi_Heat", 
  "Or_Magic" , "Wash_Wizards" , "At_Hawks" , "GS_Warriors", 
  "Da_Mavericks" , "Mi_Timberwolves" , "LA_Clippers","Ph_76"
};



League::League()
{

    for(size_t i =0; i <20; i++){
        teams.push_back((new Team((double) rand() / (RAND_MAX), ballT.at(i))));
    }
    
    s = new Schedule();
}


void League::startLeague(){

    started = true;
    s->startSeason(teams);
      for (auto &curr_round : (this->s->rounds))
    {
        for (auto &game : curr_round)
        {
            game.play();
        }
    }
    std::sort(teams.begin(), teams.end(), compare);

}

void League::printTable(){

    for(Team* t: teams){

        cout<<t->getName()<<" | Wins:"<<t->wins<<" | Loses:"<<t->loses<<" | "
        <<" | "<<"points balance:"<<t->pointsDiff()<<std::endl;  
    }
}


    void League::topTeams(int num){
        if(!started){
            throw runtime_error("the league has not yet been started");
        }
        num = std::min(num, 20);
        cout << "=========== TOP " << num << " TEAM ===========\n" << endl;
        for(unsigned int i = 0 ; i < num; i++){
            cout<<i<<") "<<teams[i]->getName()<<std::endl;
        }

    }

    void League::bottomTeams(int num)
    {
         if(!started){
            throw runtime_error("the league has not yet been started");
        }
        num = std::min(num, 20);
        cout << "=========== BUTTOM " << num << " TEAM ===========\n" << endl;
        for(unsigned int i = 0 ; i < num; i++){
            cout<<i<<") "<<teams[19 - i]->getName()<<std::endl;
        }
    }

    void League::longestWinStreak(){

         if(!started){
            throw runtime_error("the league has not yet been started");
        }
        unsigned int i = 0; 
        int longest = -1;
        unsigned int index = 0;
        cout << "=========== LONGEST WIN STREAK ===========\n" << endl;
        for(; i < 20; i++){
            if(teams[i]->getWinStreak() > longest){
                longest = teams[i]->getWinStreak();
                index = i;
            }

        }
            cout<<"The longest win streak is: "<<longest<<", Team: "<<teams[index]->getName()<<std::endl;
    }
    void League::longestLoseStreak(){

         if(!started){
            throw runtime_error("the league has not yet been started");
        }
        unsigned int i = 0; 
        int longest = -1;
        unsigned int index = 0;
        cout << "=========== LONGEST LOSE STREAK ===========\n" << endl;
        for(; i < 20; i++){
            
            if(teams[i]->getLoseStreak() > longest){
                longest = teams[i]->getLoseStreak();
                index = i;
            }

        }
            cout<<"The longest Lose streak is: "<<longest<<", Team: "<<teams[index]->getName()<<std::endl;
    }
 
    void League::positiveBalnce(){

        int posTeams = 0;
         if(!started){
            throw runtime_error("the league has not yet been started");
        }
        for(unsigned int i = 0; i < 20; i++){
            if(teams[i]->pointsDiff() > 0) posTeams++;
        }        

        cout<<posTeams<<" Teams [positive points balance]"<<std::endl;
    }

    void League::negetiveBalnce(){

        int negTeams = 0;
         if(!started){
            throw runtime_error("the league has not yet been started");
        }
        for(unsigned int i = 0; i < 20; i++){
            if(teams[i]->pointsDiff() < 0) negTeams++;
        }        

        cout<<negTeams<<"  Teams [negetive points balance] "<<std::endl;
    }
   
 