#include "Merchant.h"
#include <iostream>

Merchant::Merchant(string name)
{
	mName = name;
	mShopsName = "";
	mDescription = "";
	mCatchphrase = "";
	mMoney = 100;
}

Merchant::Merchant(string name, string shopsName, string description, string catchphrase, float money)
{
	mName = name;
	mShopsName = shopsName;
	mDescription = description;
	mCatchphrase = catchphrase;
	mMoney = money;
}

Merchant::Merchant(string name, string shopsName, string description, string catchphrase, float money, vector<Weapon*> inventory)
{
	mName = name;
	mShopsName = shopsName;
	mDescription = description;
	mCatchphrase = catchphrase;
	mMoney = money;
	mInventory = inventory;
}

string Merchant::GetName()
{
	return mName;
}

float Merchant::GetMoney()
{
	return mMoney;
}

int Merchant::GetNbWeapon()
{
	return mInventory.size();
}

bool Merchant::WeaponInInventory(Weapon* weapon)
{
	bool inInventory = false;

	for (int i = 0; i < mInventory.size(); i++)
	{
		if (mInventory[i]->GetName() == weapon->GetName())
			inInventory = true;
	}

	return inInventory;
}

void Merchant::AddMoney(float money)
{
	mMoney += money;
}
void Merchant::RemoveMoney(float money)
{
	mMoney -= money;
}
void Merchant::AddWeapon(Weapon* weapon)
{
	mInventory.push_back(weapon);
}
void Merchant::RemoveWeapon(Weapon* weapon)
{
	int position = -1;
	for (int i = 0; i < mInventory.size(); i++)
	{
		if (mInventory[i]->GetName() == weapon->GetName())
			position = i;
	}

	if (position >= 0)
		mInventory.erase(mInventory.begin() + position);
	else
		cout << "Weapon not found" << endl;
}
