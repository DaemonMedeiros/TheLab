#include "../include/AssetHandler.hpp"

AssetHandler::AssetHandler()
{
	for (int i = 0; i < TOTAL_TEXTURE_COUNT; i++) { textures[i] = defaultTexture; }
	loadProgress++;
}

AssetHandler::~AssetHandler()
{
}

void AssetHandler::loadTextures()
{
	if (loadProgress == TOTAL_TEXTURE_COUNT)
	{
		finishedLoading = true;
	}
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
	for (int i = 0; i < TOTAL_TEXTURE_COUNT; i++){UnloadTexture(textures[i]);}
}

void AssetHandler::drawLoadScreen()
{
	DrawRectangle(200, 320, loadProgress * (560 / TOTAL_TEXTURE_COUNT), 15, GREEN);
}
