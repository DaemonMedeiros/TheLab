#ifndef ASSETLOADER_HPP
#define ASSETLOADER_HPP

#include <raylib.h>
#include <string>

class AssetLoader
{
public:
	AssetLoader();
	~AssetLoader();

	void loadTextures();
	Texture2D& getTexture(std::string t_name);
	void unloadTextures();
	void drawLoadScreen();

private:
	Texture2D defaultTexture{ LoadTexture("./resources/textures/default.jpeg") };

	static const int TOTAL_TEXTURE_COUNT{ 10 };
	std::string textureNames[TOTAL_TEXTURE_COUNT];
	Texture2D textures[TOTAL_TEXTURE_COUNT];
	int loadProgress{ 0 };
	bool finishedLoading{ false };

};
#endif