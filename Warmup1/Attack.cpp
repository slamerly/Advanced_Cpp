#include "Attack.h"

Attack::Attack()
{
	mLabel = "";
	mWeapon = nullptr;
	mDamagePoints = 1; 
	mDamageType = Default;
	mAttackBonus = 0; // 0 to 5
}

Attack::Attack(string label, Weapon* weapon, float damagePoints, DamageType damageType, int attackBonus)
{
	mLabel = label;
	mWeapon = weapon;
	mDamagePoints = damagePoints;
	mDamageType = damageType;
	mAttackBonus = attackBonus; // 0 to 5
}

Attack::~Attack()
{
}

string Attack::GetLabel()
{
	return mLabel;
}

Weapon* Attack::GetWeapon()
{
	return mWeapon;
}

float Attack::GetDamagePoints()
{
	return mDamagePoints;
}

int Attack::GetAttackBonus()
{
	return mAttackBonus;
}

void Attack::SetWeapon(Weapon* weapon)
{
	mWeapon = weapon;
}

void Attack::SetDamagePoints(float damagePoints)
{
	mDamagePoints = damagePoints;
}

void Attack::SetAttackBonus(int attackBonus)
{
	mAttackBonus = attackBonus;
}
