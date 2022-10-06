#pragma once
#include <string>

using namespace std;

class Item
{
private:
	string mName;
	string mDescription;
	float mWeigth;
	float mBuyingCost;

public:
	Item();
	Item(string name, string description, float weight, float buyingCost);

	string GetName();
	string GetDescription();
	float GetWeigth();
	float GetBuyingCost();

	void SetDescription(string description);
	void SetWeight(float weigth);
	void SetBuyingCost(float buyingCost);
};

