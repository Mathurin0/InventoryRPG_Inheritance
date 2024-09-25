#include "equipment.h"
#include "weapon.h"
#include "inventorySystem.h"
#include <vector>
#include <iostream>


int main()
{
	InventorySystem inventorySystem = InventorySystem();

	Weapon firstWeapon = Weapon(inventorySystem.GetEquipmentCountEverCreated(), 10, 2, "Sword", "my super description", 20, 10, Common, 50);
	Weapon secondWeapon = Weapon(inventorySystem.GetEquipmentCountEverCreated(), 10, 2, "Sword", "my super description", 20, 10, Common, 20);


	inventorySystem.AddToInventory(&firstWeapon);
	inventorySystem.AddToInventory(&secondWeapon);

	Weapon* myWeapon = dynamic_cast<Weapon*>(inventorySystem.GetInventoryItemFromID(1));

	myWeapon->Repair();

	Weapon* myOtherWeapon = dynamic_cast<Weapon*>(inventorySystem.GetInventoryItemFromID(2));

	myOtherWeapon->Repair();

	printf("inventory size : %i \n", inventorySystem.GetInventorySize());

	myOtherWeapon->DeconstructEquipment();
	inventorySystem.RemoveFromInventory(myOtherWeapon->GetID());

	printf("inventory size : %i \n", inventorySystem.GetInventorySize());

	inventorySystem.Selling(myWeapon);
}