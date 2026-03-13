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
	{ finishedLoading = true; /*std::cout << "AssetHandler : Loading Textures Complete\n"; */}
	else
	{
		switch (loadProgress)
		{
			case 0:
				textureNames[0] = "DefaultTexture";
				break;
			case 1:
				// textures[1] = LoadTexture("");
				// textureNames[1] = "";
				break;
			case 2:
				// textures[2] = LoadTexture("");
				// textureNames[2] = "";
				break;
			case 3:
				// textures[3] = LoadTexture("");
				// textureNames[3] = "";
				break;
			case 4:
				// textures[4] = LoadTexture("");
				// textureNames[4] = "";
				break;
			case 5:
				// textures[5] = LoadTexture("");
				// textureNames[5] = "";
				break;
			case 6:
				// textures[6] = LoadTexture("");
				// textureNames[6] = "";
				break;
			case 7:
				// textures[7] = LoadTexture("");
				// textureNames[7] = "";
				break;
			case 8:
				// textures[8] = LoadTexture("");
				// textureNames[8] = "";
				break;
			case 9:
				// textures[9] = LoadTexture("");
				// textureNames[9] = "";
				break;
		}
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
