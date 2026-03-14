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
		std::cout << "Gamepad 1 Detected\n";
		float leftStickX = GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_X);
		float leftStickY = GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_Y);
		float rightStickX = GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_RIGHT_X);
		float rightStickY = GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_RIGHT_Y);
		float leftTrigger = GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_TRIGGER);
		float rightTrigger = GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_RIGHT_TRIGGER);

		if (leftStickX > -leftStickDeadzoneX && leftStickX < leftStickDeadzoneX) leftStickX = 0.0f;
		if (leftStickY > -leftStickDeadzoneY && leftStickY < leftStickDeadzoneY) leftStickY = 0.0f;
		if (rightStickX > -rightStickDeadzoneX && rightStickX < rightStickDeadzoneX) rightStickX = 0.0f;
		if (rightStickY > -rightStickDeadzoneY && rightStickY < rightStickDeadzoneY) rightStickY = 0.0f;
		if (leftTrigger < leftTriggerDeadzone) leftTrigger = -1.0f;
		if (rightTrigger < rightTriggerDeadzone) rightTrigger = -1.0f;
	}
	if (IsGamepadAvailable(1)) // 2 Controllers
	{
		std::cout << "Gamepad 1 Detected\n";
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
