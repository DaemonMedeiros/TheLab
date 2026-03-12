#include "AssetLoader.hpp"

AssetLoader::AssetLoader()
{
}

AssetLoader::~AssetLoader()
{
}

bool AssetLoader::texturesLoaded()
{
	return finishedLoading;
}

void AssetLoader::loadTextures()
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
				// textures[0] = LoadTexture("");
				break;
			case 1:
				// textures[1] = LoadTexture("");
				break;
			case 2:
				// textures[2] = LoadTexture("");
				break;
			case 3:
				// textures[3] = LoadTexture("");
				break;
			case 4:
				// textures[4] = LoadTexture("");
				break;
			case 5:
				// textures[5] = LoadTexture("");
				break;
			case 6:
				// textures[6] = LoadTexture("");
				break;
			case 7:
				// textures[7] = LoadTexture("");
				break;
			case 8:
				// textures[8] = LoadTexture("");
				break;
			case 9:
				// textures[9] = LoadTexture("");
				break;
		}
		loadProgress++;
	}
}

void AssetLoader::drawProgressBar()
{
	DrawRectangle(200, 320, loadProgress * (560 / TOTAL_TEXTURE_COUNT), 15, GREEN);
}
