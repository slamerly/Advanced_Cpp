#pragma once
#include "Item.h"
#include "IMagic.h"
#include "Creature.h"
#include "MagicType.h"

class MagicItem:
	public Item, IMagic
{
private:
	string mMagicName;
	string mMagicDescription;
	MagicType mMagicType;
	int mMagicDamage; //1 to 5

public:
	MagicItem();
	MagicItem(string name, string description, string magicName, string magicDescription, MagicType magicType, int magicDamage, float weigth, float buyingCost);

	string GetMagicName();
	string GetMagicDescription();
	int GetMagicDamage();
	MagicType GetMagicType();

	void SetMagicType(MagicType magicType);
	void SetMagicDamage(int magicDamage);
	void MagicEffectActivation(Creature* creature);
};

