#ifndef ASSETLOADER_HPP
#define ASSETLOADER_HPP

#include <raylib.h>

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
	Texture2D textures[TOTAL_TEXTURE_COUNT];
	int loadProgress{ 0 };
	bool finishedLoading{ false };

};
#endif