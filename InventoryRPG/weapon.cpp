#include "weapon.h"

Weapon::Weapon(
	int damage, 
	int range, 
	string name, 
	string description = "", 
	int buyPrice = 1, 
	int sellPrice = 1, 
	Rarity rarity = Common, 
	int durability = 1, 
	bool isEquipped = false) : 
		Equipment(
			name, 
			description, 
			buyPrice, 
			sellPrice, 
			rarity, 
			durability, 
			isEquipped), 
		mRange(range),
		mDamage(damage) {}

Weapon::~Weapon()
{
}

void Weapon::DealDamage(int damage)
{
	printf("you have dealt %i damages", damage);
}

void Weapon::DeconstructEquipment()
{
	printf("you have deconstruct %s damages", mName);
}

void Weapon::Repair()
{
}

void Weapon::Equip()
{
}

void Weapon::UnEquip()
{
}
