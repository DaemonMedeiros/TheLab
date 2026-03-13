#ifndef GAME_HPP
#define GAME_HPP

#include <raylib.h>
#include "../Enums/GameStates.h"
#include "../Constants/Constants.hpp"
#include "../AssetHandler.hpp"
#include "../UIHandler.hpp"
#include "../GameObjects.hpp"

class Game
{
public:
	Game();
	~Game();
	void Run();

private:
	void Init();
	void InitRenderWindow();
	void Update(float t_dt);
	void DrawRenderWindow();
	void Draw();
	void FreeResources();

	RenderTexture2D gameWindow{ 0 };
	Vector2 gameWindowScale{ 1.0f,1.0f };
	int gameScreenWidth{ SCREEN_WIDTH };
	int gameScreenHeight{ SCREEN_HEIGHT };

	AssetHandler* assetHandler { nullptr };
	UIHandler* uiHandler{ nullptr };
	GameObjects* gameObjects { nullptr };
	GameState gameState{ GS_LOADING };
};
#endif