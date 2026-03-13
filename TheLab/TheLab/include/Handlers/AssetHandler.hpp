#ifndef ASSETHANDLER_HPP
#define ASSETHANDLER_HPP

#include <raylib.h>
#include <iostream>

class AssetHandler
{
public:
	AssetHandler();
	~AssetHandler();

	void loadTextures();
	Texture2D& getTexture(std::string t_name);
	void unloadTextures();
	void drawLoadScreen();

private:
	Texture2D defaultTexture{ LoadTexture("./resources/textures/default.jpeg") };

	void loadScreenTextures();

	static const int TOTAL_TEXTURE_COUNT{ 25 };
	std::string textureNames[TOTAL_TEXTURE_COUNT];
	Texture2D textures[TOTAL_TEXTURE_COUNT];
	int loadProgress{ 0 };
	bool finishedLoading{ false };

};
#endif