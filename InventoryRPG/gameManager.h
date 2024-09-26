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
	std::string mDescription = "nameOfObject";
	std::vector<Button> mButtons {};
};

