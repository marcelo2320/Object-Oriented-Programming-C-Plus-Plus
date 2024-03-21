#include<iostream>
#include<string>
#include"RPG.h"

using namespace std;

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
/**
 * @brief attack decreases the opponents health by (strenght - opponent's defense)
 * in other words the opponents defense should soften the blow from the attack
 * 
 * for example if oppenent health is 100 oppenent defense is 5 and player
 * strength is 20 then after the attack opponents health should be 85(i.e. 100 - (20-50)).
 * 
 * first calculate the opponents health then use (*opponent).getUpdate(new_health)
 * to update their health
 * 
 * @param oppnent
*/
void RPG::attack(RPG * opponent){
    int new_health = (*opponent).getHealth()-(strength - (*opponent).getDefense());
    // 100-(20-5)
   
   (*opponent).updateHealth(new_health);
}

/**
 * @brief prompts the user to choose a skill and calls printAction() and attack()
 * 
 * @param opponent
*/
void RPG::useSkill(RPG * opponent){

    for(int i = 0; i < SKILL_SIZE; i++){
       
    printf("Skill %i: %s\n", i, skills[i].c_str());
    }

    printf("Choose a skill to use: enter 0 or 1\n");
    
    int chosen_skills_index;
   
    string chosen_skill = skills[chosen_skills_index];
    printAction(chosen_skill, *opponent);
    attack(opponent);
}
