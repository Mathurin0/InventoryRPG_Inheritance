#pragma once
#include <iostream>
#include <vector>
#include "raylib.h"

using namespace std;

enum Rarity {
	Common,
	Rare,
	Epic,
	Legendary
};

enum EquipmentType {
	WeaponItem,
	ArmorItem,
	AccessoryItem,
	PotionItem,
	ToolItem
};

class Equipment
{
public :
	Equipment(
		int equipmentCountEverCreated,
		string name, 
		enum EquipmentType type,
		Texture2D image,
		string description = "", 
		int buyPrice = 1, 
		int sellPrice = 1, 
		Rarity rarity = Common,  
		float maxDurability = 1,
		bool isEquipped = false
	);
	~Equipment();

	int GetBuyPrice();
	int GetSellPrice();
	string GetName();
	string GetDescription();
	int GetID();
	Texture2D GetTexture();

	void UnEquip();
	void DeconstructEquipment();
	void Repair();

	virtual void Equip();

	virtual string GetExtendedDescription() = 0;

protected :
	int mId;
	string mName;
	string mDescription;
	int mBuyPrice;
	int mSellPrice;
	bool mIsEquipped;
	Rarity mRarity;
	float mCurrentDurability;
	float mMaxDurability;
	enum EquipmentType mType;
	Texture2D mTexture2D;
};