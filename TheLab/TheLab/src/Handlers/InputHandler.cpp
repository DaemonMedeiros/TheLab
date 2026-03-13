#include "../../include/Handlers/InputHandler.hpp"

InputHandler::InputHandler()
{
	std::cout << "InputHandler : Object Created\n";
}

InputHandler::~InputHandler()
{
	std::cout << "InputHandler : Object Destroyed\n";
}

Command InputHandler::getActiveCommand()
{
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
