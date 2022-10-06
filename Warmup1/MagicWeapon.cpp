#include "MagicWeapon.h"

MagicWeapon::MagicWeapon():
	Weapon()
{
	mMagicName = "";
	mMagicDescription = "";
	mPositive = false;
}

MagicWeapon::MagicWeapon(string name, string description, string magicName, string magicDescription, bool positive, WeaponType type, float weigth, float damages, float buyingCost, float durability):
	Weapon(name, description, type, weigth, damages, buyingCost, durability)
{
	mMagicName = magicName;
	mMagicDescription = magicDescription;
	mPositive = positive;
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

bool MagicWeapon::GetPositive()
{
	return mPositive;
}

int MagicWeapon::GetMagicDamage()
{
	return mMagicDamage;
}

void MagicWeapon::SetPositive(bool positive)
{
	mPositive = positive;
}

void MagicWeapon::SetMagicDamage(int magicDamage)
{
	mMagicDamage = magicDamage;
}

void MagicWeapon::HealthPointsInteraction(Creature* creature)
{
	if (mPositive)
	{
		creature->SetTotalDamage(creature->GetTotalDamage() + mMagicDamage);
	}
	else
	{
		creature->Heal(mMagicDamage);
	}
}
