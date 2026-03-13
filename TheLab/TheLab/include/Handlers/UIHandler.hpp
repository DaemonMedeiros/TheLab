#ifndef UIHANDLER_HPP
#define UIHANDLER_HPP

#include <iostream>

#include "../../include/Enums/GameStates.h"
#include "../../include/Enums/Commands.h"

class UIHandler
{
public:
	UIHandler();
	~UIHandler();

	void update(double& t_dt, Command& t_command, GameState& t_gamestate);
	void draw(GameState& t_gamestate);

private:

	void setupUI(GameState& t_gamestate);
	void takedownUI(GameState& t_gamestate);

	GameState activeUI{ GS_LOADING };
};
#endif