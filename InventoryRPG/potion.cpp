#include "potion.h"

Potion::Potion(
	int equipmentCountEverCreated, 
	float effectStrength, 
	enum EffectType effectType, 
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
		PotionItem,
		image,
		description,
		buyPrice,
		sellPrice,
		rarity,
		maxDurability,
		isEquipped
	),
	mEffectStrength(effectStrength),
	mEffectType(effectType) {}

Potion::~Potion()
{
}

void Potion::Throw()
{
	printf("You threw a ");

	switch (mEffectType)
	{
	case StrengthEffect:
		printf("Strength potion \n");
		break;
	case SpeedEffect:
		printf("Speed potion \n");
		break;
	case ResistanceEffect:
		printf("Resistance potion \n");
		break;
	default:
		break;
	}
}

void Potion::Consume()
{
	printf("You drank a ");

	switch (mEffectType)
	{
	case StrengthEffect:
		printf("Strength potion, your Strength");
		break;
	case SpeedEffect:
		printf("Speed potion, your Speed");
		break;
	case ResistanceEffect:
		printf("Resistance potion, your Resistance");
		break;
	default:
		break;
	}

	printf(" has been improved by %.0f%% \n", mEffectStrength * 100);
}
