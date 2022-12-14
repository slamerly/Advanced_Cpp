#include "Character.h"
#include "Weapon.h"
#include <string>
#include <iostream>

using namespace std;

Character::Character():Creature()
{
	mCatchphrase = "";
	mMoney = 0;
	mWeapon = nullptr;
	mRace = Human;
	mCharacterClass = Less;
}

Character::Character(string name, string description, string catchphrase, int healthPoints, float money, Weapon* weapon, int defence, Race race, CharacterClass characterClass) :
	Creature(name, description, healthPoints, defence)
{
	mCatchphrase = catchphrase;
	mMoney = money;
	mWeapon = weapon;
	mRace = race;
	mCharacterClass = characterClass;
}

Character::Character(string name, string description, string catchphrase, int healthPoints, float money, Weapon* weapon, vector<Attack*> attacks, int defence, Race race, CharacterClass characterClass) :
	Creature(name, description, healthPoints, attacks, defence)
{
	mCatchphrase = catchphrase;
	mMoney = money;
	mWeapon = weapon;
	mRace = race;
	mCharacterClass = characterClass;
}

Character::~Character()
{
}

float Character::GetMoney()
{
	return mMoney;
}

Weapon* Character::GetWeapon()
{
	return mWeapon;
}

uint8_t Character::GetRace()
{
	return mRace;
}

void Character::AddMoney(float money)
{
	mMoney += money;
}

void Character::RemoveMoney(float money)
{
	mMoney -= money;
}

void Character::SetWeapon(Weapon* newWeapon)
{
	mWeapon = newWeapon;
}

void Character::Introduce()
{
	string race;
	string characterClass;
	switch (mRace)
	{
	case Elf:
		race = "Elf";
		break;
	case Orc:
		race = "Orc";
		break;
	case Gobelin:
		race = "Gobelin";
		break;
	case Human:
		race = "Human";
		break;
	case Dwarf:
		race = "Dwarf";
		break;
	default:
		race = "";
		break;
	}
	switch (mCharacterClass)
	{
	case Archer:
		characterClass = "Archer";
		break;
	case Warrior:
		characterClass = "Warrior";
		break;
	case Priest:
		characterClass = "Priest";
		break;
	case Paladin:
		characterClass = "Paladin";
		break;
	case Less:
		characterClass = "Less";
		break;
	default:
		characterClass = "";
		break;
	}

	cout << mCatchphrase << " I'm " << GetName() << " a/an " << GetDescription() << " and " << race << " " << characterClass << " class " << endl;
	cout << "I have ";
	if(mWeapon != nullptr)
	{
		mWeapon->ToString();
		cout << " and ";
	}
	cout << mMoney << " golds." << endl;
}

void Character::Buy(Weapon* weapon, Merchant* merchant)
{
	if (merchant->WeaponInInventory(weapon))
	{
		float finalCost = weapon->GetBuyingCost() * (1 + weapon->GetDurability());
		cout << "finalCost = " << finalCost << endl;
		if ((mMoney - finalCost) >= 0)
		{
			RemoveMoney(finalCost);
			merchant->AddMoney(finalCost);
			SetWeapon(weapon);
			merchant->RemoveWeapon(weapon);
			cout << GetName() << " has buy a new weapon.\n";
		}
		else
			cout << GetName() << " can't buy this weapon." << endl;
	}
	else
		cout << weapon->GetName() << " can't buy from " << merchant->GetName() << ".\n";
}

void Character::Sell(Merchant* merchant)
{
	if (mWeapon != nullptr) 
	{
		float finalCost = 0; 
		if(GetWeapon()->GetDurability() == 1)
			finalCost = GetWeapon()->GetBuyingCost() * 0.01f;
		else
			finalCost = GetWeapon()->GetBuyingCost()* (1 - GetWeapon()->GetDurability());

		cout << "finalCost = " << finalCost << endl;
		if ((merchant->GetMoney() - finalCost) >= 0)
		{
			merchant->RemoveMoney(finalCost);
			AddMoney(finalCost);
			merchant->AddWeapon(mWeapon);
			SetWeapon(nullptr);
			cout << GetName() << " has sell his weapon.\n";
		}
		else
			cout << merchant->GetName() << " can't buy your weapon." << endl;
	}
	else
		cout << GetName() << " doesn't have weapon." << endl;
}
