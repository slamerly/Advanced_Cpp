#include "MagicWeapon.h"
#include <iostream>

MagicWeapon::MagicWeapon() :
	Weapon()
{
	mMagicName = "";
	mMagicDescription = "";
	mMagicDamage = 1;
}

MagicWeapon::MagicWeapon(string name, string description, string magicName, string magicDescription, int magicDamage, WeaponType type, float weigth, float damages, float buyingCost, float durability) :
	Weapon(name, description, type, weigth, damages, buyingCost, durability)
{
	mMagicName = magicName;
	mMagicDescription = magicDescription;
	if (magicDamage > 0 && magicDamage <= 5)
		mMagicDamage = magicDamage;
	else
		cout << "Magic damages: " << magicDamage << " is not between 1 and 5." << endl;
}

MagicWeapon::~MagicWeapon()
{
}

string MagicWeapon::GetMagicName()
{
	return mMagicName;
}

string MagicWeapon::GetMagicDescription()
{
	return mMagicDescription;
}

int MagicWeapon::GetMagicDamage()
{
	return mMagicDamage;
}

void MagicWeapon::SetMagicDamage(int magicDamage)
{
	mMagicDamage = magicDamage;
}

void MagicWeapon::MagicEffectActivation(Creature* creature)
{
	creature->SetTotalDamage(creature->GetTotalDamage() + mMagicDamage);
}
