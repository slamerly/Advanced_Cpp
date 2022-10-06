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
	float mHealthPoints;
	float mMaxHealthPoints;
	int mTotalDamage = 2;
	vector<Attack*> mAttacks;
	float mDefense; // 1 to 20

public:
	Creature();
	Creature(string name, string description, float healthPoints, float defense);
	Creature(string name, string description, float healthPoints, vector<Attack*> attacks, float defense);
	~Creature();

	void AttackCreature(Creature* target, Attack* attack);
	void Heal(float amount);

	string GetName();
	string GetDescription();
	float GetHealthPoints();
	float GetMaxHealthPoints();
	float GetDefence();
	int GetTotalDamage();

	void SetDescription(string description);
	void SetHealthPoints(float healthPoints);
	void AddAttack(Attack* attack);
	void RemoveAttack(Attack* attack);
	void SetDefence(float defence);
	void SetTotalDamage(int damage);
};