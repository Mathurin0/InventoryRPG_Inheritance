#include "weapon.h"

Weapon::Weapon(
	int equipmentCountEverCreated,
	int damage, 
	int range, 
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
			WeaponItem,
			description, 
			buyPrice, 
			sellPrice, 
			rarity, 
			maxDurability,
			isEquipped
		), 
		mRange(range),
		mDamage(damage) {}

Weapon::~Weapon()
{
}

void Weapon::DealDamage(int damage)
{
	printf("you have dealt %i damages \n", damage);
}

bool Weapon::DetectTarget()
{
	printf("Detecting targer in a range of %i", mRange);
	return false;
}
