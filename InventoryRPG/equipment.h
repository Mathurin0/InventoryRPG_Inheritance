#pragma once
#include <iostream>
#include <vector>

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
	int GetID();

	void Equip();
	void UnEquip();
	void DeconstructEquipment();

	virtual void Repair();

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
};