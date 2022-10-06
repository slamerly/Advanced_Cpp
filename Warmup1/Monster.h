#pragma once
#include <vector>
#include "Creature.h"
#include "Item.h"

class Monster :
    public Creature
{
private:
    //vector<Item*> mLoot;

public:
    Monster();
    Monster(string name, string description, int healthPoints, int defence);
    Monster(string name, string description, int healthPoints, int defence, vector<Item*> loot);
    Monster(string name, string description, int healthPoints, vector<Attack*> attacks, int defence);
    Monster(string name, string description, int healthPoints, vector<Attack*> attacks, int defence, vector<Item*> loot);
    ~Monster();

    void AttackCreature(Monster* target, Attack* attack);
    //void AddItem(Item* item);
    //void RemoveItem(Item* item);
};

