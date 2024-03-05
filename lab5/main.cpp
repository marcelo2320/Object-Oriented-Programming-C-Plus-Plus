#include <iostream>
#include "RPG.h"

using namespace std;

int main(){

    RPG p1 = RPG("Wiz", 70,40,15,"mage");
    RPG p2 = RPG();

    printf("%s Current Stats\n", p1.getName().c_str());
    printf("Health: %i\t Strength: %i\t Defense: %i\n", p1.getHealth(), p1.getStrength(), p1.getDefense());

    printf("%s Current Stats\n", p2.getName().c_str());
    printf("Health: %i\t Strength: %i\t Defense: %i\n", p2.getHealth(), p2.getStrength(), p2.getDefense());
    
    p1.updateHealth(0);
    cout<<p1.getHealth()<<endl;

    cout<<p1.isAlive()<<endl;
    cout<<p2.isAlive()<<endl;

    return 0;
}
