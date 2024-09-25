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
			inventory[i]->~Equipment();
			inventory.erase(inventory.begin() + i);
		}
	}
}

void InventorySystem::AddToInventory(Equipment* equipment)
{
	inventory.push_back(equipment);
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
		printf("You buyed %s for %i \n", equipmentName.c_str(), buyPrice);
	}
	else {
		printf("You don't have enougth money to buy %s. You only have %i coins \n", equipmentName.c_str(), moneyCount);
	}
}

void InventorySystem::Selling(Equipment* equipment)
{
	moneyCount += equipment->GetSellPrice();
	RemoveFromInventory(equipment->GetID());
	printf("You sell %s. You have now %i coins \n", equipment->GetName().c_str(), moneyCount);
}