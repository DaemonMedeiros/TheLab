#include "../../include/MainLoop/Game.hpp"

Game::Game()
{
	std::cout << "Game : Object Created\n";
}

Game::~Game()
{
	std::cout << "Game : Object Destroyed\n";
}

void Game::Run()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT); // Vsync and Anti-aliasing
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib Template");
	InitRenderWindow();
	Init();
	while (!WindowShouldClose())
	{
		float deltaTime = GetFrameTime();
		Update(deltaTime);
		DrawRenderWindow();
	}
	FreeResources();
	CloseWindow();
}

void Game::Init()
{
	gameStateHandler = new GameStateHandler;
	assetHandler = new AssetHandler;
	uiHandler = new UIHandler (assetHandler);
	gameObjects = new GameObjects(assetHandler, playerCount);
}

void Game::InitRenderWindow()
{
	SetWindowMinSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	gameWindow = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);
	SetTextureFilter(gameWindow.texture, TEXTURE_FILTER_BILINEAR);
	SetTargetFPS(TARGET_FPS);
}

void Game::DrawRenderWindow()
{
	gameWindowScale = { (float)GetScreenWidth() / gameScreenWidth, (float)GetScreenHeight() / gameScreenHeight };
	BeginTextureMode(gameWindow);
	ClearBackground(RAYWHITE);
	// ----
		Draw();
	// ----
	EndTextureMode();
	BeginDrawing();
	ClearBackground(BLACK);
	DrawTexturePro(gameWindow.texture,
		{ 0.0f, 0.0f, (float)gameWindow.texture.width, (float)-gameWindow.texture.height },
		{ (GetScreenWidth() - ((float)gameScreenWidth * gameWindowScale.x)) * 0.5f, (GetScreenHeight() - ((float)gameScreenHeight * gameWindowScale.y)) * 0.5f,
		(float)gameScreenWidth * gameWindowScale.x, (float)gameScreenHeight * gameWindowScale.y }, { 0.0f, 0.0f }, 0.0f, WHITE);
	EndDrawing();
}

void Game::Update(float& t_dt)
{
	//gameState = gameStateHandler->updateGameState(t_dt);
	uiHandler->update(t_dt, gameState);
	
	switch (gameState)
	{
		case GS_LOADING_TEXTURES:
			assetHandler->loadTextures();
		break;
		case GS_START_MENU:
			break;
		case GS_INIT_OBJECTS:
			gameObjects->init();
			break;
		case GS_PLAY:
			gameObjects->update(t_dt);
		break;
		case GS_PAUSE:
		break;
		case GS_END:
		break;
	}
}

void Game::Draw()
{
	switch (gameState)
	{
		case GS_LOADING_TEXTURES:
			assetHandler->drawLoadScreen();
		break;
		case GS_START_MENU:
			break;
		case GS_INIT_OBJECTS:
			break;
		case GS_PLAY:
			gameObjects->draw(gameWindow);
		break;
		case GS_PAUSE:
			gameObjects->draw(gameWindow);
		break;
		case GS_END:
		break;
	}
}

void Game::FreeResources()
{
	assetHandler->unloadTextures();
	delete(assetHandler);
	delete(uiHandler);
	delete(gameStateHandler);
	delete(gameObjects);
	UnloadRenderTexture(gameWindow);
}
