#include "../../include/Handlers/InputHandler.hpp"

InputHandler::InputHandler(PlayerId& t_playerId) : playerId(t_playerId)
{
	std::cout << "InputHandler : Object Created\n";
}

InputHandler::~InputHandler()
{
	std::cout << "InputHandler : Object Destroyed\n";
}

Command InputHandler::getActiveCommand()
{
	if (IsGamepadAvailable(0)) // 1 Controller
	{
		if (gamepadDetected == false)
		{
			std::cout << "Single Player Detected\n";
			gamepadDetected = true;
		}
	}
	else if (IsGamepadAvailable(1)) // 2 Controllers
	{
		if (gamepadDetected == false)
		{
			std::cout << "Two Players Detected\n";
			gamepadDetected = true;
		}
	}

	if (IsKeyDown(KEY_UP))
	{
		std::cout << "Active Command = MOVE_UP\n";
		return CMD_MOVE_UP;
	}
	if (IsKeyDown(KEY_DOWN))
	{
		std::cout << "Active Command = MOVE_DOWN\n";
		return CMD_MOVE_DOWN;
	}
	if (IsKeyDown(KEY_LEFT))
	{
		std::cout << "Active Command = MOVE_LEFT\n";
		return CMD_MOVE_LEFT;
	}
	if (IsKeyDown(KEY_RIGHT))
	{
		std::cout << "Active Command = MOVE_RIGHT\n";
		return CMD_MOVE_RIGHT;
	}
	return CMD_NONE;
}
