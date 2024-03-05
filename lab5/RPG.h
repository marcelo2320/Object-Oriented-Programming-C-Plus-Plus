#ifndef RPG_H
#define RPG_H
#include <string>

using namespace std;


const int SKILL_SIZE =2;

class RPG{
    public: 

        RPG();
        RPG(string name, int health, int strenth, int defense, string type);
        void setSkills();
        void printAction(string name, RPG);
        void updateHealth(int);
        void attack(RPG*);
        void useSkill(RPG*);
        bool isAlive()const;
        string getName()const;
        int getHealth()const;
        int getStrength()const;
        int getDefense()const;

    
    private:
        string type;
        /// @brief 
        string skills[SKILL_SIZE];
        string name;
        int health;
        int strength;
        int defense;
        
       
};
#endif