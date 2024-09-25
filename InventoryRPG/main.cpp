#include "equipment.h"
#include "weapon.h"
#include <vector>
#include <iostream>

static int equipmentCountEverCreated = 0;
static vector<Equipment*> inventory;


void RemoveFromInventory(int id) {
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i]->GetID() == id) {
			inventory[i]->~Equipment();
			inventory.erase(inventory.begin() + i);
		}
	}
}

int main()
{
	Weapon firstWeapon = Weapon(&equipmentCountEverCreated, 10, 2, "Sword", "my super description", 1, 1, Common, 50);
	Weapon secondWeapon = Weapon(&equipmentCountEverCreated, 10, 2, "Sword", "my super description", 1, 1, Common, 20);


	inventory.push_back(&firstWeapon);
	inventory.push_back(&secondWeapon);

	Weapon* myWeapon = dynamic_cast<Weapon*>(inventory[0]);

	myWeapon->Repair();

	Weapon* myOtherWeapon = dynamic_cast<Weapon*>(inventory[1]);

	myOtherWeapon->Repair();

	printf("inventory size : %i \n", (int)inventory.size());

	myOtherWeapon->DeconstructEquipment();
	RemoveFromInventory(myOtherWeapon->GetID());

	printf("inventory size : %i \n", (int)inventory.size());
}