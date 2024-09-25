#include "tool.h"

Tool::Tool(
	int equipmentCountEverCreated, 
	int effectiveness, 
	enum ToolType toolType, 
	string name, 
	string description, 
	int buyPrice, 
	int sellPrice, 
	Rarity rarity, 
	float maxDurability, 
	bool isEquipped
	) : Equipment(
		equipmentCountEverCreated,
		name,
		WeaponItem,
		description,
		buyPrice,
		sellPrice,
		rarity,
		maxDurability,
		isEquipped
	),
	mEffectiveness(effectiveness),
	mToolType(toolType) {}

Tool::~Tool()
{
}

void Tool::Repairing()
{
	printf("You are repairing an object with an effectiveness of %i", mEffectiveness);
}
