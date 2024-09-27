#pragma once
#include "equipment.h"
#include <vector>
#include <sstream>

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
		Texture2D image,
		string description = "",
		int buyPrice = 1,
		int sellPrice = 1,
		Rarity rarity = Common,
		float maxDurability = 1,
		bool isEquipped = false
	);
	~Tool();

	void Repairing();

	string GetExtendedDescription() override;

private:
	int mEffectiveness;
	enum ToolType mToolType;
};