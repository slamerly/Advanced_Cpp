#include "Creature.h"
#include "Attack.h"
#include <vector>
#include <iostream>
#include "Character.h"

Creature::Creature()
{
	mName = "";
	mDescription = "";
	mHealthPoints = 100;
	mMaxHealthPoints = mHealthPoints;
	mDefense = 10;
}

Creature::Creature(string name, string description, int healthPoints, int defense)
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

Creature::Creature(string name, string description, int healthPoints, vector<Attack*> attacks, int defense)
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

Creature::Creature(string name, string description, int healthPoints, vector<Item*> inventory, int defense)
{
	mName = name;
	mDescription = description;
	mHealthPoints = healthPoints;
	mMaxHealthPoints = healthPoints;
	mInventory = inventory;
	if (defense > 0 && defense <= 20)
		mDefense = defense;
	else
		cout << defense << " not between 1 to 20.\n";
}

Creature::Creature(string name, string description, int healthPoints, vector<Attack*> attacks, vector<Item*> inventory, int defense)
{
	mName = name;
	mDescription = description;
	mHealthPoints = healthPoints;
	mMaxHealthPoints = healthPoints;
	mAttacks = attacks;
	mInventory = inventory;
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
	mTotalDamage = 2;

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

		Character* isCharacter = dynamic_cast<Character*>(target);
		if (isCharacter) 
		{
		}


		// --- DEAD ---
		if (target->mHealthPoints <= 0)
		{
			while (!target->mInventory.empty())
			{
				Item* save = target->mInventory.back();
				target->mInventory.pop_back();
				mInventory.push_back(save);
			}

			cout << target->GetName() << " is dead.\n";

			cout << target->GetName() << " is dead.\n";
		}
		else
			cout << "It hits.\n";
	}
	else
		cout << "It misses.\n";
}

void Creature::Heal(int amount)
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

int Creature::GetHealthPoints()
{
	return mHealthPoints;
}

int Creature::GetMaxHealthPoints()
{
	return mMaxHealthPoints;
}

int Creature::GetDefence()
{
	return mDefense;
}

int Creature::GetTotalDamage()
{
	return mTotalDamage;
}

vector<Item*> Creature::GetInventory()
{
	return mInventory;
}

size_t Creature::GetNbLoot()
{
	return mInventory.size();
}

void Creature::SetDescription(string description)
{
	mDescription = description;
}

void Creature::SetHealthPoints(int healthPoints)
{
	mHealthPoints = healthPoints;
}

void Creature::SetMaxHealthPoints(int maxHealthPoints)
{
	mMaxHealthPoints = maxHealthPoints;
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

void Creature::SetDefence(int defence)
{
	mDefense = defence;
}

void Creature::SetTotalDamage(int damage)
{
	mTotalDamage = damage;
}

void Creature::AddItem(Item* item)
{
	mInventory.push_back(item);
	cout << "Add " << item->GetName() << " to " << GetName() << endl;
}

void Creature::RemoveItem(Item* item)
{
	int position = -1;
	for (int i = 0; i < mInventory.size(); i++)
	{
		if (mInventory[i]->GetName() == item->GetName())
			position = i;
	}

	if (position >= 0)
	{
		mInventory.erase(mInventory.begin() + position);
		cout << "Remove " << item->GetName() << " from " << GetName() << endl;
	}
	else
		cout << "Item not found" << endl;
}