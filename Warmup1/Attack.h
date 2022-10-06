#pragma once
#include <string>
#include "Weapon.h"
#include "DamageType.h"

using namespace std;

class Attack
{
private:
	string mLabel;
	Weapon* mWeapon;
	float mDamagePoints;
	DamageType mDamageType;
	int mAttackBonus; // 0 to 5

public:
	Attack();
	Attack(string label, Weapon* weapon, float damagePoints, DamageType damageType, int attackBonus);
	~Attack();

	string GetLabel();
	Weapon* GetWeapon();
	float GetDamagePoints();
	int GetAttackBonus();

	void SetWeapon(Weapon* weapon);
	void SetDamagePoints(float damagePoints);
	void SetAttackBonus(int attackBonus);
};