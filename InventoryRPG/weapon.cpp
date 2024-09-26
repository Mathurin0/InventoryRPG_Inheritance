#include "weapon.h"

Weapon::Weapon(
	int equipmentCountEverCreated,
	int damage, 
	int range, 
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
			WeaponItem,
			image,
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

void Weapon::DealDamage()
{
	printf("you have dealt %i damages \n", mDamage);
}

bool Weapon::DetectTarget()
{
	printf("Detecting targer in a range of %i", mRange);
	return false;
}
