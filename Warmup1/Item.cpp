#include "Item.h"

Item::Item()
{
	mName = "";
	mDescription = "";
	mWeigth = 0;
	mBuyingCost = 0;
}

Item::Item(string name, string description, float weight, float buyingCost)
{
	mName = name;
	mDescription = description;
	mWeigth = weight;
	mBuyingCost = buyingCost;
}

string Item::GetName()
{
	return mName;
}

string Item::GetDescription()
{
	return mDescription;
}

float Item::GetWeigth()
{
	return mWeigth;
}

float Item::GetBuyingCost()
{
	return mBuyingCost;
}

void Item::SetDescription(string description)
{
	mDescription = description;
}

void Item::SetWeight(float weigth)
{
	mWeigth = weigth;
}

void Item::SetBuyingCost(float buyingCost)
{
	mBuyingCost = buyingCost;
}
