#pragma once
#include "Weapon.h"
#include "IMagic.h"
#include "Creature.h"
#include "MagicType.h"

class MagicWeapon :
	public Weapon, IMagic
{
private:
	string mMagicName;
	string mMagicDescription;
	int mMagicDamage; //1 to 5
	MagicType mMagicType;
	bool mActivate = false;

public:
	MagicWeapon();
	MagicWeapon(string name, string description, string magicName, string magicDescription, int magicDamage, MagicType magicType, WeaponType type, float weigth, float damages, float buyingCost, float durability);
	~MagicWeapon();

	string GetMagicName();
	string GetMagicDescription();
	int GetMagicDamage();
	bool IsActivate();
	MagicType GetMagicType();

	void SetMagicType(MagicType magicType);
	void SetMagicDamage(int magicDamage);
	void SetActivate(bool activate);
	void MagicEffectActivation(Creature* creature);
};

