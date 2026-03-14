#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include <iostream>
#include <raylib.h>
#include "../Constants/Constants.hpp"
#include "../../include/Enums/Commands.h"
#include "../../include/Enums/PlayerID.h"

#define XBOX_ALIAS_1 "xbox"

class InputHandler 
{
public:
	InputHandler(PlayerId& t_playerId);
	~InputHandler();

	Command getActiveCommand();
private:

    const float leftStickDeadzoneX{ 0.1f };
    const float leftStickDeadzoneY{ 0.1f };
    const float rightStickDeadzoneX{ 0.1f };
    const float rightStickDeadzoneY{ 0.1f };
    const float leftTriggerDeadzone{ -0.9f };
    const float rightTriggerDeadzone{ -0.9f };

    int gamepad{0};

    PlayerId playerId{ PLAYER_1 };
};

#endif