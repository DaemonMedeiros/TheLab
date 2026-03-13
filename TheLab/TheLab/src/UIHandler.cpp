#include "../include/UIHandler.hpp"

UIHandler::UIHandler()
{
	std::cout << "UIHandler : Object Created\n";
}

UIHandler::~UIHandler()
{
	std::cout << "UIHandler : Object Destroyed\n";
}

void UIHandler::update(double& t_dt, Command& t_command, GameState& t_gamestate)
{
	if (t_gamestate != activeUI)
	{
		exitUIState(t_gamestate);
		activeUI = t_gamestate;
		enterUIState(t_gamestate);
	}
	else
	{
		switch (t_gamestate)
		{
			case GS_LOADING:
				break;
			case GS_START:
				break;
			case GS_PLAY:
				break;
			case GS_PAUSE:
				break;
			case GS_END:
				break;
		}
	}
}

void UIHandler::draw(GameState& t_gamestate)
{
	switch (t_gamestate)
	{
		case GS_LOADING:
			break;
		case GS_START:
			break;
		case GS_PLAY:
			break;
		case GS_PAUSE:
			break;
		case GS_END:
			break;
	}
}

void UIHandler::exitUIState(GameState& t_gamestate)
{
	switch (t_gamestate)
	{
		case GS_LOADING:
			break;
		case GS_START:
			break;
		case GS_PLAY:
			break;
		case GS_PAUSE:
			break;
		case GS_END:
			break;
	}
}

void UIHandler::enterUIState(GameState& t_gamestate)
{
	switch (t_gamestate)
	{
		case GS_LOADING:
			break;
		case GS_START:
			break;
		case GS_PLAY:
			break;
		case GS_PAUSE:
			break;
		case GS_END:
			break;
	}
}
