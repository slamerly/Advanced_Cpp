#include "MagicItem.h"

MagicItem::MagicItem(): Item()
{
	mMagicName = "";
	mMagicDescription = "";
	mMagicDamage = 0;
}

MagicItem::MagicItem(string name, string description, string magicName, string magicDescription, MagicType magicType, int magicDamage, float weigth, float buyingCost):
	Item(name, description, weigth, buyingCost)
{
	mMagicName = magicName;
	mMagicDescription = magicDescription;
	mMagicType = magicType;
	mMagicDamage = magicDamage;
}

string MagicItem::GetMagicName()
{
	return mMagicName;
}

string MagicItem::GetMagicDescription()
{
	return mMagicDescription;
}

int MagicItem::GetMagicDamage()
{
	return mMagicDamage;
}

MagicType MagicItem::GetMagicType()
{
	return mMagicType;
}

void MagicItem::SetMagicType(MagicType magicType)
{
	mMagicType = magicType;
}

void MagicItem::SetMagicDamage(int magicDamage)
{
	mMagicDamage = magicDamage;
}

void MagicItem::MagicEffectActivation(Creature* creature)
{
	switch (mMagicType)
	{
	case Fire:
		creature->SetTotalDamage(creature->GetTotalDamage() + mMagicDamage);
		break;
	case Ice:
		creature->SetTotalDamage(creature->GetTotalDamage() + mMagicDamage);
		break;
	case Shield:
		creature->SetMaxHealthPoints(creature->GetMaxHealthPoints() + mMagicDamage);
		break;
	case Heal:
		creature->Heal(mMagicDamage);
		break;
	default:
		break;
	}
}
