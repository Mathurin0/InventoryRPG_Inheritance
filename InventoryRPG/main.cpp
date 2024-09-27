#include "raylib.h"

#include "equipment.h"
#include "weapon.h"
#include "armor.h"
#include "potion.h"
#include "tool.h"
#include "accessory.h"

#include "inventorySystem.h"
#include "gameManager.h"

#include <vector>
#include <iostream>


void Load();
void Update();
void Draw();
void Unload();

void ShowTestText();

GameManager gameManager;

int main()
{
	Load();

	ShowTestText();

	while (!WindowShouldClose()) {
		Update();
		Draw();
	}

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



void ShowTestText()
{
	// INVENTORY
	Texture2D goldenSword = LoadTexture("ressource/Weapon&Tool/Golden Sword.png");
	Texture2D knife = LoadTexture("ressource/Weapon&Tool/Knife.png");
	Texture2D magicWand = LoadTexture("ressource/Weapon&Tool/Magic Wand.png");
	Texture2D woodenStaff = LoadTexture("ressource/Weapon&Tool/Wooden Staff.png");
	Texture2D ironChestplate = LoadTexture("ressource/Equipment/IronArmor.png");
	Texture2D boots = LoadTexture("ressource/Equipment/Leather Boot.png");
	Texture2D bluePotion = LoadTexture("ressource/Potion/Blue Potion 2.png");
	Texture2D redPotion = LoadTexture("ressource/Potion/Red Potion.png");
	Texture2D hammer = LoadTexture("ressource/Weapon&Tool/Hammer.png");

	
	InventorySystem* inventorySystem;
	inventorySystem = new InventorySystem();

	printf("Inventory : \n");

	Weapon* firstWeapon = new Weapon(inventorySystem->GetEquipmentCountEverCreated(), 8, 5, "Golden Sword", goldenSword, "an awesome weapon to attack at a good distance", 20, 10, Common, 20);
	Weapon* secondWeapon = new Weapon(inventorySystem->GetEquipmentCountEverCreated(), 8, 5, "Knife", knife, "an awesome weapon to attack at a good distance", 20, 10, Common, 20);
	Weapon* thirdWeapon = new Weapon(inventorySystem->GetEquipmentCountEverCreated(), 8, 5, "Magic Wand", magicWand, "an awesome weapon to attack at a good distance", 20, 10, Common, 20);

	inventorySystem->AddToInventory(firstWeapon);
	inventorySystem->AddToInventory(secondWeapon);

	Weapon* myWeapon = dynamic_cast< Weapon* >( inventorySystem->GetInventoryItemFromID(1) );
	Weapon* myOtherWeapon = dynamic_cast< Weapon* >( inventorySystem->GetInventoryItemFromID(2) );

	Equipment* myEquipment = inventorySystem->GetInventoryItemFromID(1);

	inventorySystem->Selling(myEquipment);
	inventorySystem->Buying(thirdWeapon);


	// EQUIPMENT

	printf("\nEquipment : \n");

	printf("inventory size : %i \n", inventorySystem->GetInventorySize());

	myOtherWeapon->DeconstructEquipment();
	inventorySystem->RemoveFromInventory(myOtherWeapon->GetID());

	printf("inventory size : %i \n", inventorySystem->GetInventorySize());


	 //WEAPON

	printf("\nWeapon : \n");

	Weapon* spear = new Weapon(inventorySystem->GetEquipmentCountEverCreated(), 8, 5, "Spear", woodenStaff, "an awesome weapon to attack at a good distance", 20, 10, Common, 20);

	inventorySystem->AddToInventory(spear);

	Weapon* mySpear = dynamic_cast< Weapon* >( inventorySystem->GetInventoryItemFromID(4) );

	mySpear->DealDamage();

	mySpear->DetectTarget();


	// ARMOR

	printf("\nArmor : \n");

	Armor* chestplate = new Armor(inventorySystem->GetEquipmentCountEverCreated(), Chest, 5, "Iron Chestplate", ironChestplate, "A classic iron chestplate", 40, 20, Common, 100);

	inventorySystem->AddToInventory(chestplate);

	Armor* myChestplate = dynamic_cast< Armor* >( inventorySystem->GetInventoryItemFromID(5) );

	myChestplate->Equip();


	// ACCESSORY

	printf("\nAccessory : \n");

	Accessory* boot = new Accessory(inventorySystem->GetEquipmentCountEverCreated(), .2, Strength, "Boots", boots, "shiny gloves", 70, 35, Common, 100);

	inventorySystem->AddToInventory(boot);

	Accessory* myBoot = dynamic_cast< Accessory* >( inventorySystem->GetInventoryItemFromID(6) );

	myBoot->Equip();


	// POTION

	printf("\nPotion : \n");

	Potion* speedPotion = new Potion(inventorySystem->GetEquipmentCountEverCreated(), .2, SpeedEffect, "Speed Potion", bluePotion, "look weird but is very efficient", 25, 12, Common, 1);
	Potion* resistancePotion = new Potion(inventorySystem->GetEquipmentCountEverCreated(), .2, ResistanceEffect, "Resistance Potion", redPotion, "look weird but is very efficient", 25, 12, Common, 1);

	inventorySystem->AddToInventory(speedPotion);
	inventorySystem->AddToInventory(resistancePotion);

	Potion* mySpeedPotion = dynamic_cast< Potion* >( inventorySystem->GetInventoryItemFromID(7) );
	Potion* myResistancePotion = dynamic_cast< Potion* >( inventorySystem->GetInventoryItemFromID(8) );

	printf("inventory size : %i \n", inventorySystem->GetInventorySize());

	mySpeedPotion->Throw();
	inventorySystem->RemoveFromInventory(mySpeedPotion->GetID());

	myResistancePotion->Consume();
	inventorySystem->RemoveFromInventory(myResistancePotion->GetID());

	printf("inventory size : %i \n", inventorySystem->GetInventorySize());


	// TOOL

	printf("\nTool : \n");

	Tool* repairTool = new Tool(inventorySystem->GetEquipmentCountEverCreated(), 10, RepairTool, "Repair tool", hammer, "use it to repair", 25, 12, Common, 1);

	inventorySystem->AddToInventory(repairTool);

	Tool* myRepairTool = dynamic_cast< Tool* >( inventorySystem->GetInventoryItemFromID(9) );

	myRepairTool->Repairing();


	printf("\nUnload : \n");


	for (Equipment* equipment : inventorySystem->GetContent())
	{
		inventorySystem->RemoveFromInventory(equipment->GetID());
	}
}
