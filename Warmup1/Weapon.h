#pragma once
#include "WeaponType.h"
#include "Item.h"
#include <string>

using namespace std;

class Weapon : public Item{
private:
	WeaponType mType;
	float mDamages;
	float mDurability;

public:
	Weapon();
	Weapon(string name, string description, WeaponType type, float weigth, float damages, float buyingCost, float durability);
	~Weapon();

	float GetDamages();
	float GetDurability();

	void SetDamages(float damages);
	void SetDurability(float durability);
	void ToString();
};