#ifndef GAME_HPP
#define GAME_HPP

#include <raylib.h>

#include "../Constants/Constants.hpp"

#include "../Enums/GameStates.h"
#include "../Enums/PlayerId.h"

#include "../Handlers/GameStateHandler.hpp"
#include "../Handlers/AssetHandler.hpp"
#include "../Handlers/InputHandler.hpp"
#include "../Handlers/UIHandler.hpp"

#include "../GameObjects/GameObjects.hpp"

#include "../Utilities/Observer.hpp"

class Game
{
public:
	Game();
	~Game();
	void Run();

private:
	void Init();
	void InitRenderWindow();
	void Update(float& t_dt);
	void DrawRenderWindow();
	void Draw();
	void FreeResources();

	RenderTexture2D gameWindow{ 0 };
	Vector2 gameWindowScale{ 1.0f,1.0f };
	int gameScreenWidth{ SCREEN_WIDTH };
	int gameScreenHeight{ SCREEN_HEIGHT };

	GameState gameState{ GS_LOADING_TEXTURES };
	PlayerCount playerCount{ SINGLE_PLAYER };

	GameStateHandler* gameStateHandler{ nullptr };
	AssetHandler* assetHandler { nullptr };
	UIHandler* uiHandler{ nullptr };

	GameObjects* gameObjects{ nullptr };
};
#endif