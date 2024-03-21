#include <iostream>
#include "RPG.h"

using namespace std;


void displayStats(RPG player1, RPG player2){

    printf("%s health: %i\n",player1.getName().c_str(),(player1).getHealth());
    printf("%s health: % i\n",player2.getName().c_str(),(player2).getHealth());


}



void displayEnd(RPG player1, RPG player2){

    if(player1.isAlive()){
        printf("%sdefeated%s!Good Game!\n",player1.getName().c_str(),player2.getName().c_str());
    } 
    else{
        printf("%sdefeated%sGood Game!\n",player2.getName().c_str(),player1.getName().c_str());
      
}
}






void gameLoop(RPG * player1, RPG * player2){
    
    while(player1.isAlive() && player2.isAlive()){
        displayStats(player1, player2);
        printf("%s's turn",player1.getName().c_str());
        (player1).useSkill(player2);
        printf("----------------------------------\n");

        displayStats(player1, player2);
        printf("%s's turn",player2.getName().c_str());
        (player2).useSkill(player1);
        printf("----------------------------------\n");
    }
    

}



int main(){
    RPG p1 = RPG("wiz", 70, 45, 15, "mage");
    RPG p2 = RPG();

    gameLoop(&p1,&p2);
    displayEnd(p1,p2);
    return 0;
}