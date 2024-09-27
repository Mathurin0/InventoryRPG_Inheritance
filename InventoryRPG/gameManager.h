#pragma once
#include "button.h"
#include <string>
#include <vector>

class GameManager
{
public :
	void Init();
	void Update();
	void Draw();
	void Unload();
private:
	std::string mNameOfObject = "nameOfObject";
	std::string mDescription = "My object is incredible.";
	std::string mExtendedDescription = "Specific object description";
	std::vector<Button> mButtons {};
};

