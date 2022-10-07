#pragma once
#include <string>
#include <vector>
#include "Attack.h"

using namespace std;

class Creature 
{
private:
	string mName;
	string mDescription;
	int mHealthPoints;
	int mMaxHealthPoints;
	int mTotalDamage = 2;
	vector<Attack*> mAttacks;
	vector<Item*> mInventory;
	int mDefense; // 1 to 20

	virtual void Polymorph() {};

public:
	Creature();
	Creature(string name, string description, int healthPoints, int defense);
	Creature(string name, string description, int healthPoints, vector<Attack*> attacks, int defense);
	Creature(string name, string description, int healthPoints, vector<Item*> inventory, int defense);
	Creature(string name, string description, int healthPoints, vector<Attack*> attacks, vector<Item*> inventory, int defense);
	~Creature();

	void AttackCreature(Creature* target, Attack* attack);
	void Heal(int amount);

	string GetName();
	string GetDescription();
	int GetHealthPoints();
	int GetMaxHealthPoints();
	int GetDefence();
	int GetTotalDamage();
	vector<Item*> GetInventory();
	size_t GetNbLoot();

	void SetDescription(string description);
	void SetHealthPoints(int healthPoints);
	void SetMaxHealthPoints(int maxHealthPoints);
	void AddAttack(Attack* attack);
	void RemoveAttack(Attack* attack);
	void SetDefence(int defence);
	void SetTotalDamage(int damage);
	void AddItem(Item* item);
	void RemoveItem(Item* item);
};