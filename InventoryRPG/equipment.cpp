#include "equipment.h"

Equipment::Equipment(string name, string description, int buyPrice, int sellPrice, Rarity rarity, int durability, bool isEquipped)
{
	mName = name;
	mDescription = description;
	mBuyPrice = buyPrice;
	mSellPrice = sellPrice;
	mRarity = rarity;
	mDurability = durability;
	mIsEquipped = isEquipped;
}

Equipment::~Equipment()
{
}

void Equipment::Buying()
{
	printf("You buyed %s for %i", mName.c_str(), mBuyPrice);
}

void Equipment::Selling()
{
	printf("You selled %s for %i", mName.c_str(), mSellPrice);
}

void Equipment::DeconstructEquipment()
{
	printf("You have deconstructed %s, you got back some elements", mName.c_str());
}

void Equipment::Repair()
{
	printf("You have repaired your %s", mName.c_str());
}
