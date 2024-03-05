#include"RPG.h"

RPG :: RPG(){
    name = "NPC";
    health = 100;
    strength = 10;
    defense = 10;
    type = "warrior";
    skills[0] = "slash";
    skills[1] = "parry";
}

RPG :: RPG(string name, int health, int strength, int defense, string type){
    this->name = name;
    this->health = health;
    this->strength = strength;
    this->defense = defense;
    this->type = type;
    setSkills();
}
/**
 * @brief set the skills based on the RPG's role
 * 
 */
void RPG :: setSkills(){
    if (type == "mage"){
        skills[0] = "fire";
        skills[1]= "thunder";
    } else if (type == "theif"){
        skills[0] = "pilfer";
        skills[1] ="jab";
    } else if (type == "archer"){
        skills[0] = "parry";
        skills[1] = "crossbow_attack";
    } else {
        skills[0] = "slash";
        skills[1] = "parry";
    }   
}

/**
* @brief prints along the lines of NAME used SKILL on OPPONENT
*
* @param skill
* @param opponent
*/

void RPG :: printAction(string skill, RPG oppenent){
    printf("%s used %s on %s\n", name.c_str(),skill.c_str(), oppenent.getName().c_str());

}

string RPG::getName()const{
    return name;
}  
int RPG::getHealth()const{
    return health;
}
int RPG::getStrength()const{
    return strength;
}
int RPG::getDefense()const{
    return defense;
}

void RPG::updateHealth(int new_health){
    /**
     * @brief updates health into new_health
     * 
     * @param new_health
    */
    health = new_health;
}
bool RPG::isAlive()const{
    /**
     * @brief return wheather health is greater than 0
     * 
     * @return true
     * @return false
    */
   if (health > 0){
    return true;
   } else {
    return false;
   }
}

