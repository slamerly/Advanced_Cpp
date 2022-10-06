#pragma once
#include <vector>
#include "Creature.h"
#include "Item.h"

class Monster :
    public Creature
{
private:
    vector<Item*> mLoot;

public:
    Monster();
    Monster(string name, string description, float healthPoints, float defence);
    Monster(string name, string description, float healthPoints, float defence, vector<Item*> loot);
    Monster(string name, string description, float healthPoints, vector<Attack*> attacks, float defence);
    Monster(string name, string description, float healthPoints, vector<Attack*> attacks, float defence, vector<Item*> loot);
    ~Monster();

    void AttackCreature(Creature* target, Attack* attack);
    void AttackCreature(Monster* target, Attack* attack);
    void AddItem(Item* item);
    void RemoveItem(Item* item);
};

