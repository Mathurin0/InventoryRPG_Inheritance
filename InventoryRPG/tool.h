#pragma once
#include "equipment.h"
#include <vector>

enum ToolType {
	Axe,
	Pickaxe,
	RepairTool
};

class Tool : public Equipment
{
public:
	Tool(
		int equipmentCountEverCreated,
		int effectiveness,
		enum ToolType toolType,
		string name,
		string description = "",
		int buyPrice = 1,
		int sellPrice = 1,
		Rarity rarity = Common,
		float maxDurability = 1,
		bool isEquipped = false
	);
	~Tool();

	void Repairing();

private:
	int mEffectiveness;
	enum ToolType mToolType;
};