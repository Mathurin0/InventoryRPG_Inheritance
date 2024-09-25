#pragma once
#include "equipment.h"
#include <vector>

class Weapon : public Equipment
{
public :
	Weapon(
		int equipmentCountEverCreated,
		int damage,
		int range,
		string name,
		string description = "",
		int buyPrice = 1,
		int sellPrice = 1,
		Rarity rarity = Common,
		float maxDurability = 1,
		bool isEquipped = false
	);
	~Weapon();

	void DealDamage(int);

private :
	int mDamage;
	int mRange;
};