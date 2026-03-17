#ifndef UIHANDLER_HPP
#define UIHANDLER_HPP

#include <iostream>

#include "../../include/Handlers/AssetHandler.hpp"
#include "../../include/Handlers/InputHandler.hpp"
#include "../../include/Enums/GameStates.h"

class UIHandler
{
public:
	UIHandler(AssetHandler* t_assetHandler);
	~UIHandler();

	void update(float& t_dt, GameState& t_gamestate);
	void draw(GameState& t_gamestate);

private:

	void setupUI(GameState& t_gamestate);
	void takedownUI(GameState& t_gamestate);

	AssetHandler* assetHandler{ nullptr };
	GameState activeUI{ GS_LOADING_TEXTURES };
};
#endif