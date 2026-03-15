#include "../../include/Handlers/AssetHandler.hpp"

AssetHandler::AssetHandler()
{
	std::cout << "GameObjects : Object Created\n";
	for (int i = 0; i < TOTAL_TEXTURE_COUNT; i++) { textures[i] = defaultTexture; }
}

AssetHandler::~AssetHandler()
{
	std::cout << "AssetHandler : Object Destroyed\n";
}

void AssetHandler::loadTextures()
{
	if (loadProgress == 0) { std::cout << "AssetHandler : Loading Textures\n"; }
	if (loadProgress == TOTAL_TEXTURE_COUNT) 
	{ 
		if (!finishedLoading)
		{
			finishedLoading = true; 
			std::cout << "AssetHandler : Loading Textures Complete\n";
		}
	}
	else
	{
		loadScreenTextures();
		loadPlayerTextures();
		loadProgress++;
	}
}

Texture2D& AssetHandler::getTexture(std::string t_name)
{
	for (int i = 0; i < TOTAL_TEXTURE_COUNT; i++)
	{
		if (t_name == textureNames[i])
		{
			return textures[i];
		}
	}
	return defaultTexture;
}

void AssetHandler::unloadTextures()
{
	std::cout << "AssetHandler : Unloading Textures\n";
	for (int i = 0; i < TOTAL_TEXTURE_COUNT; i++){UnloadTexture(textures[i]);}
	std::cout << "AssetHandler : Textures Unloaded\n";
}

void AssetHandler::drawLoadScreen()
{
	DrawRectangle(200, 320, loadProgress * (560 / TOTAL_TEXTURE_COUNT), 15, GREEN);
}

void AssetHandler::loadScreenTextures()
{
	switch (loadProgress)
	{
	case 0:
		textureNames[0] = "DefaultTexture";
		break;
	case 1:
		textures[1] = LoadTexture("./resources/textures/placeholders/screens/1_LoadingTextures_PH.jpg");
		textureNames[1] = "LoadingTextures";
		break;
	case 2:
		textures[2] = LoadTexture("./resources/textures/placeholders/screens/2_InitObjects_PH.jpg");
		textureNames[2] = "InitObjects";
		break;
	case 3:
		textures[3] = LoadTexture("./resources/textures/placeholders/screens/3_StartMenu_PH.jpg");
		textureNames[3] = "StartMenu";
		break;
	case 4:
		textures[4] = LoadTexture("./resources/textures/placeholders/screens/4_Gameplay_PH.jpg");
		textureNames[4] = "Gameplay";
		break;
	case 5:
		textures[5] = LoadTexture("./resources/textures/placeholders/screens/5_Pause_PH.jpg");
		textureNames[5] = "Pause";
		break;
	case 6:
		textures[6] = LoadTexture("./resources/textures/placeholders/screens/6_Settings_PH.jpg");
		textureNames[6] = "Settings";
		break;
	case 7:
		textures[7] = LoadTexture("./resources/textures/placeholders/screens/7_GameEnd_PH.jpg");
		textureNames[7] = "GameEnd";
		break;
	case 8:
		textures[8] = LoadTexture("./resources/textures/placeholders/screens/8_Credits_PH.jpg");
		textureNames[8] = "Credits";
		break;
	}
}

void AssetHandler::loadPlayerTextures()
{
	switch (loadProgress)
	{
	case 9:
		textures[9] = LoadTexture("./resources/textures/placeholders/players/Player_PH.jpeg");
		textureNames[9] = "Player";
		break;
	}
}
