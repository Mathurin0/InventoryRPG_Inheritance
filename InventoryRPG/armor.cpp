#include "armor.h"


Armor::Armor(
	int equipmentCountEverCreated, 
	ArmorPiece armorPiece, 
	float protectionStregth, 
	string name, 
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
			description,
			buyPrice,
			sellPrice,
			rarity,
			maxDurability,
			isEquipped
		),
		mArmorPiece(armorPiece),
		mProtectionStregth(protectionStregth) {}

Armor::~Armor()
{
}
