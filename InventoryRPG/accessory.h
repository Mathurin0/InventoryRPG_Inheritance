#pragma once
#include "equipment.h"
#include <vector>

enum StatType {
	Strength,
	Speed,
	Resistance
};

class Accessory : public Equipment
{
public:
	Accessory(
		int equipmentCountEverCreated,
		float statBuffStrenght,
		enum StatType statType,
		string name,
		string description = "",
		int buyPrice = 1,
		int sellPrice = 1,
		Rarity rarity = Common,
		float maxDurability = 1,
		bool isEquipped = false
	);
	~Accessory();

	void StatBuff();

	void Equip() override;

private:
	float mStatBuffStrenght;
	enum StatType mStatType;
};