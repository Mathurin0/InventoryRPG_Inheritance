#include "accessory.h"

Accessory::Accessory(
	int equipmentCountEverCreated,
	float statBuffStrenght,
	enum StatType statType,
	string name,
	Texture2D image,
	string description, 
	int buyPrice, 
	int sellPrice, 
	Rarity rarity, 
	float maxDurability, 
	bool isEquipped
	) : Equipment(
		equipmentCountEverCreated,
		name,
		AccessoryItem,
		image,
		description,
		buyPrice,
		sellPrice,
		rarity,
		maxDurability,
		isEquipped
	),
	mStatBuffStrenght(statBuffStrenght),
	mStatType(statType) {}

Accessory::~Accessory()
{
}

void Accessory::StatBuff()
{
	switch (mStatType)
	{
	case Strength:
		printf("Your Strength");
		break;
	case Speed:
		printf("Your Speed");
		break;
	case Resistance:
		printf("Your Resistance");
		break;
	default:
		break;
	}

	printf(" has been improved by %.0f%% \n", mStatBuffStrenght * 100);
}

void Accessory::Equip() {
	std::cout << "you have equipped " << mName << " \n";
	mIsEquipped = true;

	StatBuff();
}