#include "equipment.h"
#include "weapon.h"
#include "armor.h"
#include "potion.h"
#include "tool.h"
#include "accessory.h"
#include "inventorySystem.h"
#include <vector>
#include <iostream>
#include "raylib.h"
#include "gameManager.h"

void Load();
void Update();
void Draw();
void Unload();

GameManager gameManager;

int main()
{
	Load();

	while (!WindowShouldClose()) {
		Update();
		Draw();
	}


	/*// INVENTORY

	printf("Inventory : \n");

	inventorySystem.AddToInventory(&firstWeapon);
	inventorySystem.AddToInventory(&secondWeapon);

	Weapon* myWeapon = dynamic_cast<Weapon*>(inventorySystem.GetInventoryItemFromID(1));
	Weapon* myOtherWeapon = dynamic_cast<Weapon*>(inventorySystem.GetInventoryItemFromID(2));

	Equipment* myEquipment = inventorySystem.GetInventoryItemFromID(1);

	inventorySystem.Selling(myEquipment);
	inventorySystem.Buying(&thirdWeapon);


	// EQUIPMENT

	printf("\nEquipment : \n");

	printf("inventory size : %i \n", inventorySystem.GetInventorySize());

	myOtherWeapon->DeconstructEquipment();
	inventorySystem.RemoveFromInventory(myOtherWeapon->GetID());

	printf("inventory size : %i \n", inventorySystem.GetInventorySize());


	// WEAPON

	printf("\nWeapon : \n");

	Weapon spear = Weapon(inventorySystem.GetEquipmentCountEverCreated(), 8, 5, "Spear", "an awesome weapon to attack at a good distance", 20, 10, Common, 20);

	inventorySystem.AddToInventory(&spear);

	Weapon* mySpear = dynamic_cast<Weapon*>(inventorySystem.GetInventoryItemFromID(4));

	mySpear->DealDamage();

	mySpear->DetectTarget();


	// ARMOR

	printf("\nArmor : \n");

	Armor chestplate = Armor(inventorySystem.GetEquipmentCountEverCreated(), Chest, 5, "Iron Chestplate", "A classic iron chestplate", 40, 20, Common, 100);

	inventorySystem.AddToInventory(&chestplate);

	Armor* myChestplate = dynamic_cast<Armor*>(inventorySystem.GetInventoryItemFromID(5));

	myChestplate->Equip();


	// ACCESSORY

	printf("\nAccessory : \n");

	Accessory gloves = Accessory(inventorySystem.GetEquipmentCountEverCreated(), .2, Strength, "Gloves", "shiny gloves", 70, 35, Common, 100);

	inventorySystem.AddToInventory(&gloves);

	Accessory* myGloves = dynamic_cast<Accessory*>(inventorySystem.GetInventoryItemFromID(6));

	myGloves->Equip();


	// POTION

	printf("\nPotion : \n");

	Potion speedPotion = Potion(inventorySystem.GetEquipmentCountEverCreated(), .2, SpeedEffect, "Speed Potion", "look weird but is very efficient", 25, 12, Common, 1);
	Potion resistancePotion = Potion(inventorySystem.GetEquipmentCountEverCreated(), .2, ResistanceEffect, "Resistance Potion", "look weird but is very efficient", 25, 12, Common, 1);

	inventorySystem.AddToInventory(&speedPotion);
	inventorySystem.AddToInventory(&resistancePotion);

	Potion* mySpeedPotion = dynamic_cast<Potion*>(inventorySystem.GetInventoryItemFromID(7));
	Potion* myResistancePotion = dynamic_cast<Potion*>(inventorySystem.GetInventoryItemFromID(8));

	printf("inventory size : %i \n", inventorySystem.GetInventorySize());

	mySpeedPotion->Throw();
	inventorySystem.RemoveFromInventory(mySpeedPotion->GetID());

	myResistancePotion->Consume();
	inventorySystem.RemoveFromInventory(myResistancePotion->GetID());

	printf("inventory size : %i \n", inventorySystem.GetInventorySize());


	// TOOL

	printf("\nTool : \n");

	Tool repairTool = Tool(inventorySystem.GetEquipmentCountEverCreated(), 10, RepairTool, "Repair tool", "use it to repair", 25, 12, Common, 1);

	inventorySystem.AddToInventory(&repairTool);

	Tool* myRepairTool = dynamic_cast<Tool*>(inventorySystem.GetInventoryItemFromID(9));

	myRepairTool->Repairing();


	printf("\n");*/

	Unload();

	return 0;
}

void Load()
{
	InitWindow(1080, 720, "Inventory RPG");
	SetTargetFPS(60);

	gameManager.Init();
}

void Update()
{
	gameManager.Update();
}

void Draw()
{
	BeginDrawing();

	ClearBackground(BEIGE);
	gameManager.Draw();

	EndDrawing();
}

void Unload()
{
	gameManager.Unload();

	CloseWindow();
}
