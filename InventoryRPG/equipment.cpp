#include "equipment.h"

Equipment::Equipment(int equipmentCountEverCreated, string name, enum EquipmentType equipmentType, string description, int buyPrice, int sellPrice, Rarity rarity, float maxDurability, bool isEquipped)
{
	mId = equipmentCountEverCreated;
	mName = name;
	mDescription = description;
	mBuyPrice = buyPrice;
	mSellPrice = sellPrice;
	mRarity = rarity;
	mCurrentDurability = maxDurability;
	mMaxDurability = maxDurability;
	mIsEquipped = isEquipped;
	mType = equipmentType;
}

Equipment::~Equipment()
{
}

int Equipment::GetID() {
	return mId;
}

void Equipment::Repair()
{
	mCurrentDurability = mMaxDurability;
	printf("you have repaired %s and it's durability is now %.0f \n", mName.c_str(), mCurrentDurability);
}

void Equipment::Equip()
{
	printf("you have equipped %s \n", mName.c_str());
	mIsEquipped = true;
}

void Equipment::UnEquip()
{
	printf("you have unequipped %s \n", mName.c_str());
	mIsEquipped = false;
}

void Equipment::DeconstructEquipment()
{
	printf("You have deconstructed %s, you got back some elements \n", mName.c_str());
}

int Equipment::GetBuyPrice()
{
	return mBuyPrice;
}

int Equipment::GetSellPrice()
{
	return mSellPrice;
}

string Equipment::GetName()
{
	return mName;
}
