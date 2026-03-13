#ifndef UIHANDLER_HPP
#define UIHANDLER_HPP

#include <iostream>

#include "../include/Enums/GameStates.h"
#include "../include/Enums/Commands.h"

class UIHandler
{
public:
	UIHandler();
	~UIHandler();

	void update(double& t_dt, Command& t_command, GameState& t_gamestate);
	void draw(GameState& t_gamestate);

private:

	void exitUIState(GameState& t_gamestate);
	void enterUIState(GameState& t_gamestate);

	GameState activeUI;
};
#endif