#include "equipment.h"
#include "weapon.h"
#include <iostream>

int main()
{
	Weapon weapon = Weapon(10, 2, "Sword");

	weapon.DealDamage(50);
}