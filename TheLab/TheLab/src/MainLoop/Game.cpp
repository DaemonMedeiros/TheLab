#include "../../include/MainLoop/Game.hpp"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Run()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
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
	assetHandler = new AssetHandler;
	gameObjects = new GameObjects;
	gameObjects->init();
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

void Game::Update(float t_dt)
{
	switch (gameState)
	{
		case GS_LOADING:
			assetHandler->loadTextures();
		break;
		case GS_START:
		break;
		case GS_PLAY:
			gameObjects->update();
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
		case GS_LOADING:
			assetHandler->drawLoadScreen();
		break;
		case GS_START:
		break;
		case GS_PLAY:
			gameObjects->draw();
		break;
		case GS_PAUSE:
			gameObjects->draw();
		break;
		case GS_END:
		break;
	}
}

void Game::FreeResources()
{
	assetHandler->unloadTextures();
	delete(assetHandler);
	delete(gameObjects);
	UnloadRenderTexture(gameWindow);
}
