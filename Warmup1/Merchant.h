#pragma once
#include <string>
#include <vector>
#include "Weapon.h"


using namespace std;

class Merchant {
private:
	string mName;
	string mShopsName;
	string mDescription;
	string mCatchphrase;
	float mMoney;
	vector<Weapon*> mInventory;

public:
	Merchant(string name);
	Merchant(string name, string shopsName, string description, string catchphrase, float money);
	Merchant(string name, string shopsName, string description, string catchphrase, float money, vector<Weapon*> inventory);

	string GetName();
	float GetMoney();
	size_t GetNbWeapon();
	bool WeaponInInventory(Weapon* weapon);

	void AddMoney(float money);
	void RemoveMoney(float money);
	void AddWeapon(Weapon* weapon);
	void RemoveWeapon(Weapon* weapon);
};