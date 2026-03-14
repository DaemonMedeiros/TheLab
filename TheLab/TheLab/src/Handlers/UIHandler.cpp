#include "../../include/Handlers/UIHandler.hpp"

UIHandler::UIHandler(AssetHandler* t_assetHandler) : assetHandler(t_assetHandler)
{
	setupUI(activeUI);
	std::cout << "UIHandler : Object Created\n";
}

UIHandler::~UIHandler()
{
	std::cout << "UIHandler : Object Destroyed\n";
}

void UIHandler::update(float& t_dt, Command& t_command, GameState& t_gamestate)
{
	if (t_gamestate != activeUI)
	{
		takedownUI(t_gamestate);
		activeUI = t_gamestate;
		setupUI(t_gamestate);
	}
	else
	{
		switch (t_gamestate)
		{
			case GS_LOADING_TEXTURES:
				break;
			case GS_START_MENU:
				break;
			case GS_INIT_OBJECTS:
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
		case GS_LOADING_TEXTURES:
			break;
		case GS_START_MENU:
			break;
		case GS_INIT_OBJECTS:
			break;
		case GS_PLAY:
			break;
		case GS_PAUSE:
			break;
		case GS_END:
			break;
	}
}

void UIHandler::setupUI(GameState& t_gamestate)
{
	switch (t_gamestate)
	{
		case GS_LOADING_TEXTURES:
			break;
		case GS_START_MENU:
			break;
		case GS_INIT_OBJECTS:
			break;
		case GS_PLAY:
			break;
		case GS_PAUSE:
			break;
		case GS_END:
			break;
	}
}

void UIHandler::takedownUI(GameState& t_gamestate)
{
	switch (t_gamestate)
	{
		case GS_LOADING_TEXTURES:
			break;
		case GS_START_MENU:
			break;
		case GS_INIT_OBJECTS:
			break;
		case GS_PLAY:
			break;
		case GS_PAUSE:
			break;
		case GS_END:
			break;
	}
}
