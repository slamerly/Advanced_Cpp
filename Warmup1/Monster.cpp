#include "Monster.h"
#include <iostream>

Monster::Monster():Creature()
{
}

Monster::Monster(string name, string description, float healthPoints, float defence):
	Creature(name, description, healthPoints, defence)
{
}

Monster::Monster(string name, string description, float healthPoints, float defence, vector<Item*> loot):
	Creature(name, description, healthPoints, defence)
{
	mLoot = loot;
}

Monster::Monster(string name, string description, float healthPoints, vector<Attack*> attacks, float defence):
	Creature(name, description, healthPoints, attacks, defence)
{
}

Monster::Monster(string name, string description, float healthPoints, vector<Attack*> attacks, float defence, vector<Item*> loot) :
	Creature(name, description, healthPoints, attacks, defence)
{
	mLoot = loot;
}

Monster::~Monster()
{
}

void Monster::AttackCreature(Creature* target, Attack* attack)
{
	int dice;
	int totalDamage = 2;
	int pass = rand() % 20 + 1;

	pass += attack->GetAttackBonus();

	if (pass >= target->GetDefence())
	{
		cout << "Damages : ";
		for (int i = 0; i < 3; i++)
		{
			dice = rand() % 6 + 1;
			totalDamage += dice;
			cout << dice << " + ";
		}
		cout << "2 = " << totalDamage << endl;
		target->SetHealthPoints(target->GetHealthPoints() - totalDamage);

		//target->mHealthPoints -= attack->GetDamagePoints();

		// --- DEAD ---
		if (target->GetHealthPoints() <= 0)
		{
			cout << target->GetName() << " is dead.\n";
		}
		else
			cout << "It hits.\n";
	}
	else
		cout << "It misses.\n";
}

void Monster::AttackCreature(Monster* target, Attack* attack)
{
	int dice;
	int totalDamage = 2;
	int pass = rand() % 20 + 1;

	pass += attack->GetAttackBonus();

	if (pass >= target->GetDefence())
	{
		cout << "Damages : ";
		for (int i = 0; i < 3; i++)
		{
			dice = rand() % 6 + 1;
			totalDamage += dice;
			cout << dice << " + ";
		}
		cout << "2 = " << totalDamage << endl;
		target->SetHealthPoints(target->GetHealthPoints() - totalDamage);

		//target->mHealthPoints -= attack->GetDamagePoints();

		// --- DEAD ---
		if (target->GetHealthPoints() <= 0)
		{
			Monster* test = dynamic_cast<Monster*>(target); // return NULL if target is not a Monster
			if (test != NULL)
			{
				while (!target->mLoot.empty())
				{
					Item* save = target->mLoot.back();
					target->mLoot.pop_back();
					mLoot.push_back(save);
				}
			}

			cout << target->GetName() << " is dead.\n";
		}
		else
			cout << "It hits.\n";
	}
	else
		cout << "It misses.\n";
}

void Monster::AddItem(Item* item)
{
	mLoot.push_back(item);
	cout << "Add " << item->GetName() << " to " << GetName() << endl;
}

void Monster::RemoveItem(Item* item)
{
	int position = -1;
	for (int i = 0; i < mLoot.size(); i++)
	{
		if (mLoot[i]->GetName() == item->GetName())
			position = i;
	}

	if (position >= 0)
	{
		mLoot.erase(mLoot.begin() + position);
		cout << "Remove " << item->GetName() << " from " << GetName() << endl;
	}
	else
		cout << "Item not found" << endl;
}