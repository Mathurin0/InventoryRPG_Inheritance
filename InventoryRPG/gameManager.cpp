#include "gameManager.h"
#include "inventorySystem.h"
#include "equipment.h"
#include "weapon.h"
#include "armor.h"
#include "accessory.h"
#include "potion.h"
#include "tool.h"
#include "raylib.h"

InventorySystem* inventorySystem = nullptr;

void GameManager::Init()
{
	inventorySystem = new InventorySystem();

	Weapon ironSword = Weapon(
		inventorySystem->GetEquipmentCountEverCreated(), 
		10, 
		2, 
		"Iron Sword",
		LoadTexture("ressource/Weapon & Tool/Iron Sword.png"),
		"a simple iron sword.", 
		20, 
		10,
		Common, 
		50);
	
	Armor ironChestplate = Armor(
		inventorySystem->GetEquipmentCountEverCreated(), 
		Chest,
		5, 
		"Iron Chestplate", 
		LoadTexture("ressource/Equipment/Iron Armor.png"),
		"a solid iron chestplate.", 
		20, 
		10, 
		Common, 
		20);
	
	Accessory runeStone = Accessory(
		inventorySystem->GetEquipmentCountEverCreated(), 
		.2, 
		Speed, 
		"Rune Stone",
		LoadTexture("ressource/Misc/Rune Stone.png"),
		"a powerfull rune stone.",
		20, 
		10, 
		Common, 
		20);

	Potion strengthPotion = Potion(
		inventorySystem->GetEquipmentCountEverCreated(),
		.4,
		StrengthEffect,
		"Strength Potion",
		LoadTexture("ressource/Potion/Green Potion 3.png"),
		"a very efficient potion.",
		20,
		10,
		Common,
		20);

	Tool pickaxe = Tool(
		inventorySystem->GetEquipmentCountEverCreated(),
		3,
		Pickaxe,
		"Pickaxe",
		LoadTexture("ressource/Weapon & Tool/Pickaxe.png"),
		"a very effective pickaxe.",
		20,
		10,
		Common,
		20);

	inventorySystem->AddToInventory(&ironSword);
	inventorySystem->AddToInventory(&ironChestplate);
	inventorySystem->AddToInventory(&runeStone);
	inventorySystem->AddToInventory(&strengthPotion);
	inventorySystem->AddToInventory(&pickaxe);
}

void GameManager::Update()
{

}

void GameManager::Draw()
{
	int x = 0;
	int y = 0;

	Rectangle source{ 0, 0, 32, 32 };
	Rectangle destination{ x, y, 0, 0 };

	Vector2 origin{ 32 / 1.3f, 32 / 2};

	for (Equipment* equipment : inventorySystem->GetContent())
	{
		//DrawTextureEx(equipment->GetTexture(), { (float)x, (float)y }, 0, 1, WHITE);
		//DrawTexture(equipment->GetTexture(), x, y, WHITE);
		DrawTexturePro(equipment->GetTexture(), { 0.0f, 0.0f, (float)equipment->GetTexture().width, (float)equipment->GetTexture().height },
			{ GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f, (float)equipment->GetTexture().width, (float)equipment->GetTexture().height }, { (float)equipment->GetTexture().width / 2, (float)equipment->GetTexture().height / 2}, 0.0f, WHITE);
		x += 64;
		y += 64;
	}
}

void GameManager::Unload()
{

}
