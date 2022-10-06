#pragma once
#include "Weapon.h"
#include "IMagic.h"
#include "Creature.h"

class MagicWeapon :
	public Weapon, IMagic
{
private:
	string mMagicName;
	string mMagicDescription;
	bool mPositive;
	int mMagicDamage; //1 to 5

public:
	MagicWeapon();
	MagicWeapon(string name, string description, string magicName, string magicDescription, bool positive, WeaponType type, float weigth, float damages, float buyingCost, float durability);
	~MagicWeapon();

	string GetMagicName();
	string GetMagicDescription();
	bool GetPositive();
	int GetMagicDamage();

	void SetPositive(bool positive);
	void SetMagicDamage(int magicDamage);
	void HealthPointsInteraction(Creature* creature);
};

