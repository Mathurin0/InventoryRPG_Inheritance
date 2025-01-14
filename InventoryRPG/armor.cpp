#include "armor.h"


Armor::Armor(
	int equipmentCountEverCreated, 
	enum ArmorPiece armorPiece, 
	float protectionStrength, 
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
			ArmorItem,
			image,
			description,
			buyPrice,
			sellPrice,
			rarity,
			maxDurability,
			isEquipped
		),
		mArmorPiece(armorPiece),
		mProtectionStrength(protectionStrength) {}

Armor::~Armor()
{
}

void Armor::ApplyProtection()
{
	printf("Your potection strength is improved by %.0f \n", mProtectionStrength);
}

void Armor::Equip()
{
	std::cout << "you have equipped " << mName << " \n";
	mIsEquipped = true;

	ApplyProtection();
}

string Armor::GetExtendedDescription()
{
	std::ostringstream returnValue;
	returnValue << "This is an Armor ! \n\n\nArmor piece : " << mArmorPiece << "\n\n\nProtection strength : " << mProtectionStrength;
	return returnValue.str();
}
