#include "Creature.h"
#include "Attack.h"
#include <vector>
#include <iostream>

Creature::Creature()
{
	mName = "";
	mDescription = "";
	mHealthPoints = 100;
	mMaxHealthPoints = mHealthPoints;
	mDefense = 10;
}

Creature::Creature(string name, string description, float healthPoints, float defense)
{
	mName = name;
	mDescription = description;
	mHealthPoints = healthPoints;
	mMaxHealthPoints = healthPoints;
	if (defense > 0 && defense <= 20)
		mDefense = defense;
	else
		cout << defense << " not between 1 to 20.\n";
}

Creature::Creature(string name, string description, float healthPoints, vector<Attack*> attacks, float defense)
{
	mName = name;
	mDescription = description;
	mHealthPoints = healthPoints;
	mMaxHealthPoints = healthPoints;
	mAttacks = attacks;
	if (defense > 0 && defense <= 20)
		mDefense = defense;
	else
		cout << defense << " not between 1 to 20.\n";
}

Creature::~Creature()
{
}

void Creature::AttackCreature(Creature* target, Attack* attack)
{
	int dice;
	int pass = rand() % 20 + 1;

	pass += attack->GetAttackBonus();

	if (pass >= target->GetDefence())
	{
		cout << "Damages : ";
		for (int i = 0; i < 3; i++)
		{
			dice = rand() % 6 + 1;
			mTotalDamage += dice;
			cout << dice << " + ";
		}
		cout << "2 = " << mTotalDamage << endl;
		target->mHealthPoints -= mTotalDamage;

		//target->mHealthPoints -= attack->GetDamagePoints();

		// --- DEAD ---
		if (target->mHealthPoints <= 0)
		{
			cout << target->GetName() << " is dead.\n";
		}
		else
			cout << "It hits.\n";
	}
	else
		cout << "It misses.\n";
}

void Creature::Heal(float amount)
{
	if (mHealthPoints == mMaxHealthPoints)
		cout << "HP MAX!\n";
	else
	{
		mHealthPoints += amount;
		if (mHealthPoints > mMaxHealthPoints)
			mHealthPoints = mMaxHealthPoints;
	}
	cout << "Healing finish.\n";
}

string Creature::GetName()
{
	return mName;
}

string Creature::GetDescription()
{
	return mDescription;
}

float Creature::GetHealthPoints()
{
	return mHealthPoints;
}

float Creature::GetMaxHealthPoints()
{
	return mMaxHealthPoints;
}

float Creature::GetDefence()
{
	return mDefense;
}

int Creature::GetTotalDamage()
{
	return mTotalDamage;
}

void Creature::SetDescription(string description)
{
	mDescription = description;
}

void Creature::SetHealthPoints(float healthPoints)
{
	mHealthPoints = healthPoints;
}

void Creature::AddAttack(Attack* attack)
{
	mAttacks.push_back(attack);
	cout << mName << " has learned a new attack: " << attack->GetLabel() << endl;
}

void Creature::RemoveAttack(Attack* attack)
{
	int position = -1;
	for (int i = 0; i < mAttacks.size(); i++)
	{
		if (mAttacks[i]->GetLabel() == attack->GetLabel())
			position = i;
	}

	if (position >= 0)
		mAttacks.erase(mAttacks.begin() + position);
	else
		cout << "Attack not found" << endl;
}

void Creature::SetDefence(float defence)
{
	mDefense = defence;
}

void Creature::SetTotalDamage(int damage)
{
	mTotalDamage = damage;
}
