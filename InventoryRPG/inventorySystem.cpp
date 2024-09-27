#include "inventorySystem.h"

InventorySystem::InventorySystem()
{
}

InventorySystem::~InventorySystem()
{
}

void InventorySystem::RemoveFromInventory(int id)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i]->GetID() == id) {
			UnloadTexture(inventory[i]->GetTexture());
			delete inventory[i];
			inventory.erase(inventory.begin() + i);
		}
	}
}

void InventorySystem::AddToInventory(Equipment* equipment)
{
	if (inventory.size() < 25) {
		inventory.push_back(equipment);
	}
	else {
		printf("Your inventory is full.");
	}
}

vector<Equipment*> InventorySystem::GetContent()
{
	return inventory;
}

Equipment* InventorySystem::GetInventoryItemFromID(int id)
{

	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i]->GetID() == id) {
			Equipment* equipment = inventory[i];
			return equipment;
		}
	}
}

int InventorySystem::GetInventorySize()
{
	return inventory.size();
}

int InventorySystem::GetEquipmentCountEverCreated()
{
	equipmentCountEverCreated++;
	return equipmentCountEverCreated;
}

void InventorySystem::Buying(Equipment* equipment)
{
	int buyPrice = equipment->GetBuyPrice();
	string equipmentName = equipment->GetName();

	if (moneyCount >= buyPrice) {
		moneyCount -= buyPrice;
		AddToInventory(equipment);
		std::cout << "You bought " << equipmentName << " for " << buyPrice << " and now have " << moneyCount << " coins. \n";
	}
	else {
		std::cout << "You don't have enougth money to buy " << equipmentName << ".You only have " << moneyCount << " coins \n";
	}
}

void InventorySystem::Selling(Equipment* equipment)
{
	moneyCount += equipment->GetSellPrice();
	std::cout << "You sold " << equipment->GetName() << ". You have now " << moneyCount << " coins \n";
	RemoveFromInventory(equipment->GetID());
}