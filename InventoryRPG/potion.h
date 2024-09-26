#pragma once
#include "equipment.h"
#include <vector>

enum EffectType {
	StrengthEffect,
	SpeedEffect,
	ResistanceEffect
};

class Potion : public Equipment
{
public:
	Potion(
		int equipmentCountEverCreated,
		float effectStrength,
		enum EffectType effectType,
		string name,
		Texture2D image,
		string description = "",
		int buyPrice = 1,
		int sellPrice = 1,
		Rarity rarity = Common,
		float maxDurability = 1,
		bool isEquipped = false
	);
	~Potion();

	void Throw();
	void Consume();

private:
	float mEffectStrength;
	enum EffectType mEffectType;
};