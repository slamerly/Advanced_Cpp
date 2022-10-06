#include "Weapon.h"
#include "WeaponType.h"
#include <string>
#include <iostream>

using namespace std;

Weapon::Weapon(): Item()
{
	mType = Empty;
	mDamages = 0;
	mDurability = 1;
}

Weapon::Weapon(string name, string description, WeaponType type, float weigth, float damages, float buyingCost, float durability):
	Item(name, description, weigth, buyingCost)
{
	mType = type;
	mDamages = damages;
	mDurability = durability;
}

Weapon::~Weapon()
{
}

/*
string Weapon::GetName()
{
	return mName;
}
*/

float Weapon::GetDamages()
{
	return mDamages;
}

/*
float Weapon::GetBuyingCost()
{
	return mBuyingCost;
}
*/

float Weapon::GetDurability()
{
	return mDurability;
}

void Weapon::SetDamages(float damages)
{
	mDamages = damages;
}

void Weapon::SetDurability(float durability)
{
	mDurability -= durability;
}

void Weapon::ToString()
{
	string type;
	switch (mType)
	{
	case Bow:
		type = "Bow";
		break;
	case Dagger:
		type = "Dagger";
		break;
	case Staff:
		type = "Staff";
		break;
	case Sword:
		type = "Sword";
		break;
	case Empty:
		type = "Empty";
		break;
	default:
		type = "";
		break;
	}

	cout << GetName() << " a/an " << type << " of " << GetWeigth() << " kg, can does " << mDamages << " damages, have a buying cost of " << GetBuyingCost() << " golds and a durability of " << mDurability * 100 << "%";
}
