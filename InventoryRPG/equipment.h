#pragma once
#include <iostream>

using namespace std;

enum Rarity {
	Common,
	Rare,
	Epic,
	Legendary
};

class Equipment
{
public :
	Equipment(
		string name, 
		string description = "", 
		int buyPrice = 1, 
		int sellPrice = 1, 
		Rarity rarity = Common, 
		int durability = 1,
		bool isEquipped = false
	);
	~Equipment();

	void Buying();
	void Selling();

	virtual void DeconstructEquipment();
	virtual void Repair();

	virtual void Equip() = 0;
	virtual void UnEquip() = 0;

protected :
	string mName;
	string mDescription;
	int mBuyPrice;
	int mSellPrice;
	bool mIsEquipped;
	Rarity mRarity;
	float mDurability;
};