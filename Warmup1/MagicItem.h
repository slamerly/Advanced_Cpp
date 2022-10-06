#pragma once
#include "Item.h"
#include "IMagic.h"
#include "Creature.h"

class MagicItem:
	public Item, IMagic
{
private:
	string mMagicName;
	string mMagicDescription;
	bool mPositive;
	int mMagicDamage; //1 to 5

public:
	MagicItem();
	MagicItem(string name, string description, string magicName, string magicDescription, bool positive, int magicDamage, float weight, float buyingCost);

	string GetMagicName();
	string GetMagicDescription();
	bool GetPositive();
	int GetMagicDamage();

	void SetPositive(bool positive);
	void SetMagicDamage(int magicDamage);
	void HealthPointsInteraction(Creature* creature);
};

