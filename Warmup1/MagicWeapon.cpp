#include "MagicWeapon.h"
#include <iostream>

MagicWeapon::MagicWeapon() :
	Weapon()
{
	mMagicName = "";
	mMagicDescription = "";
	mMagicDamage = 1;
	mMagicType = NONE;
}

MagicWeapon::MagicWeapon(string name, string description, string magicName, string magicDescription, int magicDamage, MagicType magicType, WeaponType type, float weigth, float damages, float buyingCost, float durability) :
	Weapon(name, description, type, weigth, damages, buyingCost, durability)
{
	mMagicName = magicName;
	mMagicDescription = magicDescription;
	mMagicType = magicType;
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

bool MagicWeapon::IsActivate()
{
	return mActivate;
}

MagicType MagicWeapon::GetMagicType()
{
	return mMagicType;
}

void MagicWeapon::SetMagicType(MagicType magicType)
{
	mMagicType = magicType;
}

void MagicWeapon::SetMagicDamage(int magicDamage)
{
	mMagicDamage = magicDamage;
}

void MagicWeapon::SetActivate(bool activate)
{
	mActivate = activate;
}

void MagicWeapon::MagicEffectActivation(Creature* creature)
{
	creature->SetTotalDamage(creature->GetTotalDamage() + mMagicDamage);
	mActivate = true;
}
