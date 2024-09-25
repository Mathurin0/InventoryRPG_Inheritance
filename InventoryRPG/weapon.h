#pragma once
#include "equipment.h"

class Weapon : public Equipment
{
public :
	Weapon(
		int damage,
		int range,
		string name,
		string description = "",
		int buyPrice = 1,
		int sellPrice = 1,
		Rarity rarity = Common,
		int durability = 1,
		bool isEquipped = false
	);
	~Weapon();

	void DealDamage(int);

	void DeconstructEquipment() override;
	void Repair() override;

	void Equip() override;
	void UnEquip() override;

private :
	int mDamage;
	int mRange;
};