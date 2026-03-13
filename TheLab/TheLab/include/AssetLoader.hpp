#ifndef ASSETLOADER_HPP
#define ASSETLOADER_HPP

#include <raylib.h>
#include <string>

class AssetLoader
{
public:
	AssetLoader();
	~AssetLoader();

	bool texturesLoaded();
	void loadTextures();
	void drawProgressBar();

private:
	static const int TOTAL_TEXTURE_COUNT{ 10 };

	std::string textureNames[TOTAL_TEXTURE_COUNT];
	Texture2D defaultTexture{ LoadTexture("../resources/texture/default.jpeg") };
	Texture2D textures[TOTAL_TEXTURE_COUNT];
	int loadProgress{ 0 };
	bool finishedLoading{ false };

};
#endif