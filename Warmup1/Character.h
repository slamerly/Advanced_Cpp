#pragma once
#include "WeaponType.h"
#include "Weapon.h"
#include "Race.h"
#include "CharacterClass.h"
#include "Creature.h"
#include "Merchant.h"
#include <string>

using namespace std;

class Character :
	public Creature{
private:
	string mCatchphrase;
	float mMoney;
	Weapon* mWeapon;
	Race mRace;
	CharacterClass mCharacterClass;

public:
	Character();
	Character(string name, string description, string catchphrase, int healthPoints, float money, Weapon* weapon, int defence, Race race, CharacterClass characterClass);
	Character(string name, string description, string catchphrase, int healthPoints, float money, Weapon* weapon, vector<Attack*> attacks, int defence, Race race, CharacterClass characterClass);
	~Character();
	

	float GetMoney();
	Weapon* GetWeapon();
	void AddMoney(float money);
	void RemoveMoney(float money);
	void SetWeapon(Weapon* newWeapon);

	void Introduce();
	void Buy(Weapon* weapon, Merchant* merchant);
	void Sell(Merchant* merchant);
};