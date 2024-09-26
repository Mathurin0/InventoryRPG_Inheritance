#include "equipment.h"

Equipment::Equipment(
			int equipmentCountEverCreated, 
			string name, 
			enum EquipmentType type, 
			Texture2D image,
			string description, 
			int buyPrice,	
			int sellPrice, 
			Rarity rarity, 
			float maxDurability, 
			bool isEquipped)
{
	mId = equipmentCountEverCreated;
	mName = name;
	mDescription = description;
	mTexture2D = image;
	mBuyPrice = buyPrice;
	mSellPrice = sellPrice;
	mRarity = rarity;
	mCurrentDurability = maxDurability;
	mMaxDurability = maxDurability;
	mIsEquipped = isEquipped;
	mType = type;
}

Equipment::~Equipment()
{
}

int Equipment::GetID() {
	return mId;
}

Texture2D Equipment::GetTexture()
{
	return mTexture2D;
}

void Equipment::Repair()
{
	mCurrentDurability = mMaxDurability;
	std::cout << "you have repaired " << mName << " and it's durability is now " << mCurrentDurability <<" \n";
}

void Equipment::Equip()
{
	std::cout << "you have equipped " << mName << " \n";
	mIsEquipped = true;
}

void Equipment::UnEquip()
{
	std::cout << "you have unequipped " << mName << " \n";
	mIsEquipped = false;
}

void Equipment::DeconstructEquipment()
{
	std::cout << "You have deconstructed " << mName << ", you got back some elements \n";
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
