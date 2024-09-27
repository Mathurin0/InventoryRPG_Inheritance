#pragma once
#include "equipment.h"
#include <vector>
#include <sstream>

class Weapon : public Equipment
{
public :
	Weapon(
		int equipmentCountEverCreated,
		int damage,
		int range,
		string name,
		Texture2D image,
		string description = "",
		int buyPrice = 1,
		int sellPrice = 1,
		Rarity rarity = Common,
		float maxDurability = 1,
		bool isEquipped = false
	);
	~Weapon();

	void DealDamage();
	bool DetectTarget();

	string GetExtendedDescription() override;

private :
	int mDamage;
	int mRange;
};