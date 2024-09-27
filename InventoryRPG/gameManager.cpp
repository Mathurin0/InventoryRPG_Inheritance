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
	int column = 0;
	int maxColum = 5;
	int row = 0;

	int padding = 20;

	const int maxButtonsNbr = 25;
	const float buttonSize = 64;

	for(int i = 0; i < maxButtonsNbr; i++)
	{
		Button button{};
		button.mButtonRec = {column * (buttonSize + padding) + 65, row * (buttonSize + padding) + 150, buttonSize, buttonSize};
		button.mId = i;
		mButtons.push_back(button);

		column += 1;

		if(column >= maxColum)
		{
			row += 1;
			column = 0;
		}
	}

	inventorySystem = new InventorySystem();

	Weapon* ironSword = new Weapon(
		inventorySystem->GetEquipmentCountEverCreated(), 
		10, 
		2, 
		"Iron Sword",
		LoadTexture("ressource/Weapon&Tool/IronSword.png"),
		"A simple iron sword.", 
		20, 
		10,
		Common, 
		50);


	Weapon* bow = new Weapon(
		inventorySystem->GetEquipmentCountEverCreated(),
		5,
		20,
		"Bow",
		LoadTexture("ressource/Weapon&Tool/Bow.png"),
		"Bow of evil spirits.",
		20,
		10,
		Rare,
		50);
	
	Armor* ironChestplate = new Armor(
		inventorySystem->GetEquipmentCountEverCreated(), 
		Chest,
		5, 
		"Iron Chestplate", 
		LoadTexture("ressource/Equipment/IronArmor.png"),
		"A solid iron chestplate.", 
		20, 
		10, 
		Common, 
		20);

	Armor* ironHelmet = new Armor(
		inventorySystem->GetEquipmentCountEverCreated(),
		Head,
		2,
		"Iron Helmet",
		LoadTexture("ressource/Equipment/Iron Helmet.png"),
		"A solid head protector.",
		20,
		10,
		Common,
		20);
	
	Accessory* runeStone = new Accessory(
		inventorySystem->GetEquipmentCountEverCreated(), 
		.2, 
		Speed, 
		"Rune Stone",
		LoadTexture("ressource/Misc/RuneStone.png"),
		"A powerfull rune stone.",
		20, 
		10, 
		Common, 
		20);

	Accessory* book = new Accessory(
		inventorySystem->GetEquipmentCountEverCreated(),
		.5,
		Strength,
		"Book",
		LoadTexture("ressource/Misc/Book 3.png"),
		"An all knowing book.",
		20,
		10,
		Common,
		20);

	Potion* strengthPotion = new Potion(
		inventorySystem->GetEquipmentCountEverCreated(),
		.4,
		StrengthEffect,
		"Strength Potion",
		LoadTexture("ressource/Potion/GreenPotion3.png"),
		"A very efficient potion.",
		20,
		10,
		Common,
		20);

	Potion* resistancePotion = new Potion(
		inventorySystem->GetEquipmentCountEverCreated(),
		.6,
		ResistanceEffect,
		"Resistance Potion",
		LoadTexture("ressource/Potion/Red Potion 2.png"),
		"An incredible potion.",
		20,
		10,
		Common,
		20);

	Tool* hammer = new Tool(
		inventorySystem->GetEquipmentCountEverCreated(),
		10,
		RepairTool,
		"Hammer",
		LoadTexture("ressource/Weapon&Tool/Hammer.png"),
		"A solid hammer.",
		20,
		10,
		Common,
		20);

	Tool* pickaxe = new Tool(
		inventorySystem->GetEquipmentCountEverCreated(),
		3,
		Pickaxe,
		"Pickaxe",
		LoadTexture("ressource/Weapon&Tool/Pickaxe.png"),
		"A very effective pickaxe.",
		20,
		10,
		Common,
		20);

	inventorySystem->AddToInventory(ironSword);
	inventorySystem->AddToInventory(bow);
	inventorySystem->AddToInventory(ironChestplate);
	inventorySystem->AddToInventory(ironHelmet);
	inventorySystem->AddToInventory(runeStone);
	inventorySystem->AddToInventory(book);
	inventorySystem->AddToInventory(strengthPotion);
	inventorySystem->AddToInventory(resistancePotion);
	inventorySystem->AddToInventory(hammer);
	inventorySystem->AddToInventory(pickaxe);
}

void GameManager::Update()
{
	//inventory with equipment
	auto inventory = inventorySystem->GetContent();

	for(int i = 0; i < mButtons.size(); i++)
	{
		Button& button = mButtons[i];

		if(button.mId >= inventory.size())
		{
			continue;
		}
		
		Equipment* equipment = inventory[button.mId];

		if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if(CheckCollisionPointRec(GetMousePosition(), button.mButtonRec))
			{
				mNameOfObject = equipment->GetName();
				mDescription = equipment->GetDescription();
				mExtendedDescription = equipment->GetExtendedDescription();
			}
		}
		if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
		{
			if(CheckCollisionPointRec(GetMousePosition(), button.mButtonRec))
			{
				inventorySystem->Selling(equipment);
			}
		}

	}
}

void GameManager::Draw()
{
	//Sell Text
	
	DrawText("Right click to sell.", 70, 100, 30, BLACK);

	//Description Box
	DrawRectangleRounded({ static_cast< float >( GetScreenWidth() / 2),
		100, 
		static_cast< float >( GetScreenWidth() / 2 - 50 ), 
		static_cast< float >( GetScreenHeight() - 200 ) },
		0.2f,
		0,
		WHITE);

	DrawText(mNameOfObject.c_str(), GetScreenWidth() / 2 + (GetScreenWidth() / 2 - 50) / 2 - MeasureText(mNameOfObject.c_str(), 40) / 2, 150, 40, RED);
	DrawText(mDescription.c_str(), GetScreenWidth() / 2 + ( GetScreenWidth() / 2 - 50 ) / 2 - MeasureText(mDescription.c_str(), 30) / 2, 250, 30, BLACK);
	DrawText(mExtendedDescription.c_str(), GetScreenWidth() / 2 + (GetScreenWidth() / 2 - 50) / 2 - MeasureText(mExtendedDescription.c_str(), 25) / 2, 350, 25, GRAY);

	//inventory with equipment
	auto inventory = inventorySystem->GetContent();

	for(int i = 0; i < mButtons.size(); i++)
	{
		Button& button = mButtons[i];

		DrawRectangleRounded(button.mButtonRec, 0.2f, 0, BROWN);

		if(button.mId < inventory.size())
		{
			Equipment* equipement = inventory[button.mId];

			DrawTextureEx(equipement->GetTexture(), { button.mButtonRec.x, button.mButtonRec.y }, 0, 2, WHITE);
		}
	}
}

void GameManager::Unload()
{
	for (Equipment* equipment : inventorySystem->GetContent())
	{
		inventorySystem->RemoveFromInventory(equipment->GetID());
	}
}
