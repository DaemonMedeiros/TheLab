#ifndef GAMEOBJECTS_HPP
#define GAMEOBJECTS_HPP

#include <iostream>
#include "../../include/Handlers/AssetHandler.hpp"
#include "../../include/Enums/PlayerId.h"
#include "../../include/Enums/Commands.h"
#include "../../include/GameObjects/Players/Player.hpp"

class GameObjects
{
public:
	GameObjects(AssetHandler* t_assetHandler, PlayerCount& t_playerCount);
	~GameObjects();

	void init();
	void update(float& t_dt);
	void draw(RenderTexture2D& t_window);

private:

	void setupPlayers();
	void unloadPlayers();

	bool objectsInitialized{ false };

	PlayerCount playerCount{SINGLE_PLAYER};
	AssetHandler* assetHandler{ nullptr };
	Player* player_one{ nullptr };
	Player* player_two{ nullptr };
};
#endif