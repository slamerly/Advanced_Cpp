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
	//string mFirstName;
	//string mLastName;
	string mCatchphrase;
	float mMoney;
	//float mLifePoints;
	Weapon* mWeapon;
	Race mRace;
	CharacterClass mCharacterClass;

public:
	/*
	Character(string fName, string lName);
	Character(string fName, string lName, string catchphrase, float money, float lifePoints, Race race, CharacterClass characterClass);
	Character(string fName, string lName, string catchphrase, float money, float lifePoints, Weapon &weapon, Race race, CharacterClass characterClass);
	*/
	Character();
	Character(string name, string description, string catchphrase, float healthPoints, float money, Weapon* weapon, float defence, Race race, CharacterClass characterClass);
	Character(string name, string description, string catchphrase, float healthPoints, float money, Weapon* weapon, vector<Attack*> attacks, float defence, Race race, CharacterClass characterClass);
	~Character();
	

	float GetMoney();
	Weapon* GetWeapon();
	void AddMoney(float money);
	void RemoveMoney(float money);
	void SetWeapon(Weapon* newWeapon);

	void Introduce();
	void Buy(Weapon* weapon, Merchant* merchant);
	void Sell(Merchant* merchant);
	//void UseWeapon(Weapon* weapon, Character* targetCharacter);
};