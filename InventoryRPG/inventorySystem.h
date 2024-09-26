#pragma once
#include "equipment.h"
#include <vector>

class InventorySystem
{
public :
	InventorySystem();
	~InventorySystem();

	void Buying(Equipment* equipment);
	void Selling(Equipment* equipment);
	void RemoveFromInventory(int id);
	void AddToInventory(Equipment* equipment);
	vector<Equipment*> GetContent();
	Equipment* GetInventoryItemFromID(int id);
	int GetInventorySize();
	int GetEquipmentCountEverCreated();

private :
	vector<Equipment*> inventory;
	int equipmentCountEverCreated = 0;
	int moneyCount = 500;
};

extern InventorySystem* inventorySystem;