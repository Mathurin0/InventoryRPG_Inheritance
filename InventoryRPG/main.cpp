#include "equipment.h"
#include "weapon.h"
#include "armor.h"
#include "potion.h"
#include "tool.h"
#include "accessory.h"
#include "inventorySystem.h"
#include <vector>
#include <iostream>


int main()
{
	InventorySystem inventorySystem = InventorySystem();

	// WEAPON

	Weapon firstWeapon = Weapon(inventorySystem.GetEquipmentCountEverCreated(), 10, 2, "Sword", "my super description", 20, 10, Common, 50);
	Weapon secondWeapon = Weapon(inventorySystem.GetEquipmentCountEverCreated(), 10, 2, "CombatAxe", "my super description", 20, 10, Common, 20);

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

	Equipment* myEquipment = inventorySystem.GetInventoryItemFromID(1);
	inventorySystem.Selling(myEquipment);

	Weapon thirdWeapon = Weapon(inventorySystem.GetEquipmentCountEverCreated(), 10, 2, "Polearm", "my super description", 20, 10, Common, 20);

	inventorySystem.Buying(&thirdWeapon);


	// ARMOR

	Armor chestplate = Armor(inventorySystem.GetEquipmentCountEverCreated(), Chest, 5, "Iron Chestplate", "A classic iron chestplate", 40, 20, Common, 100);

	inventorySystem.AddToInventory(&chestplate);

	Armor* myChestplate = dynamic_cast<Armor*>(inventorySystem.GetInventoryItemFromID(4));

	myChestplate->Equip();


	// ACCESSORY

	Accessory gloves = Accessory(inventorySystem.GetEquipmentCountEverCreated(), .2, Strength, "Gloves", "shiny gloves", 70, 35, Common, 100);

	inventorySystem.AddToInventory(&gloves);

	Accessory* myGloves = dynamic_cast<Accessory*>(inventorySystem.GetInventoryItemFromID(5));

	myGloves->Equip();


	// POTION

	Potion speedPotion = Potion(inventorySystem.GetEquipmentCountEverCreated(), .2, SpeedEffect, "Speed Potion", "look weird but is very efficient", 25, 12, Common, 1);
	Potion resistancePotion = Potion(inventorySystem.GetEquipmentCountEverCreated(), .2, ResistanceEffect, "Resistance Potion", "look weird but is very efficient", 25, 12, Common, 1);

	inventorySystem.AddToInventory(&speedPotion);
	inventorySystem.AddToInventory(&resistancePotion);

	Potion* mySpeedPotion = dynamic_cast<Potion*>(inventorySystem.GetInventoryItemFromID(6));
	Potion* myResistancePotion = dynamic_cast<Potion*>(inventorySystem.GetInventoryItemFromID(7));

	printf("inventory size : %i \n", inventorySystem.GetInventorySize());

	mySpeedPotion->Throw();
	inventorySystem.RemoveFromInventory(mySpeedPotion->GetID());

	myResistancePotion->Consume();
	inventorySystem.RemoveFromInventory(myResistancePotion->GetID());

	printf("inventory size : %i \n", inventorySystem.GetInventorySize());


	// TOOL

	Tool repairTool = Tool(inventorySystem.GetEquipmentCountEverCreated(), 10, RepairTool, "Repair tool", "use it to repair", 25, 12, Common, 1);

	inventorySystem.AddToInventory(&repairTool);

	Tool* myRepairTool = dynamic_cast<Tool*>(inventorySystem.GetInventoryItemFromID(8));

	myRepairTool->Repairing();
}