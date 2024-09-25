#pragma once
#include "equipment.h"
#include <vector>

enum ArmorPiece {
	Head,
	Chest,
	Legs,
	Feet,
	Gloves
};

class Armor : public Equipment
{
public:
	Armor(
		int equipmentCountEverCreated,
		enum ArmorPiece armorPiece,
		float protectionStregth,
		string name,
		string description = "",
		int buyPrice = 1,
		int sellPrice = 1,
		Rarity rarity = Common,
		float maxDurability = 1,
		bool isEquipped = false
	);
	~Armor();

private:
	enum ArmorPiece mArmorPiece;
	float mProtectionStregth;
};