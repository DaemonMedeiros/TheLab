#ifndef GAMESTATEHANDLER_HPP
#define GAMESTATEHANDLER_HPP

#include <iostream>
#include <raylib.h>
#include "../Enums/GameStates.h"

class GameStateHandler
{
public:
	GameStateHandler();
	~GameStateHandler();

	GameState updateGameState(float& t_dt);

private:

};
#endif