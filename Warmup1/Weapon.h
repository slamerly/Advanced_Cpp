#pragma once
#include "WeaponType.h"
#include "Item.h"
#include <string>

using namespace std;

class Weapon : public Item{
private:
	//string mName;
	WeaponType mType;
	//float mWeight;
	float mDamages;
	//float mBuyingCost;
	float mDurability;

public:
	Weapon();
	Weapon(string name, string description, WeaponType type, float weigth, float damages, float buyingCost, float durability);
	~Weapon();

	//string GetName();
	float GetDamages();
	//float GetBuyingCost();
	float GetDurability();

	void SetDamages(float damages);
	void SetDurability(float durability);
	void ToString();
};