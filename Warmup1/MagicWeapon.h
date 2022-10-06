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
	int mMagicDamage; //1 to 5

public:
	MagicWeapon();
	MagicWeapon(string name, string description, string magicName, string magicDescription, int magicDamage, WeaponType type, float weigth, float damages, float buyingCost, float durability);
	~MagicWeapon();

	string GetMagicName();
	string GetMagicDescription();
	int GetMagicDamage();

	void SetMagicDamage(int magicDamage);
	void MagicEffectActivation(Creature* creature);
};

