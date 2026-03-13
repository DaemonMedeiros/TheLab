#ifndef GAMEOBJECTS_HPP
#define GAMEOBJECTS_HPP

#include <iostream>
#include "../include/Handlers/AssetHandler.hpp"
#include "../include/Enums/Commands.h"

class GameObjects
{
public:
	GameObjects(AssetHandler* t_assetHandler);
	~GameObjects();

	void init();
	void update(float& t_dt, Command& t_command);
	void draw();

private:

	AssetHandler* assetHandler{ nullptr };

};
#endif