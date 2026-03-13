#include "../../include/MainLoop/Game.hpp"

Game::Game(AssetLoader& t_assetLoader) : assetLoader(t_assetLoader)
{
}

Game::~Game()
{
}

void Game::Run()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib Template");
	SetWindowMinSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	SetTargetFPS(TARGET_FPS);
	Init();

	while (!WindowShouldClose())
	{
		float deltaTime = GetFrameTime();
		if (!texturesLoaded)
		{
			assetLoader.loadTextures();
		}
		else
		{
			Update(deltaTime);
		}
		ScaleAndRenderWindow();
	}
	CloseWindow();
}

void Game::Init()
{
	appWindow = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);
	SetTextureFilter(appWindow.texture, TEXTURE_FILTER_BILINEAR);
	appWindowScale = { (float)GetScreenWidth() / gameScreenWidth, (float)GetScreenHeight() / gameScreenHeight };

	gameObjects.init();
}

void Game::ScaleAndRenderWindow()
{
	BeginTextureMode(appWindow);
	ClearBackground(RAYWHITE);
	// ----
	if (!texturesLoaded)
	{
		assetLoader.drawProgressBar();
	}
	else
	{
		Draw();
	}
	// ----
	EndTextureMode();
	BeginDrawing();
	ClearBackground(BLACK);
	DrawTexturePro(appWindow.texture,
		{ 0.0f, 0.0f, (float)appWindow.texture.width, (float)-appWindow.texture.height },
		{ (GetScreenWidth() - ((float)gameScreenWidth * appWindowScale.x)) * 0.5f, (GetScreenHeight() - ((float)gameScreenHeight * appWindowScale.y)) * 0.5f,
		(float)gameScreenWidth * appWindowScale.x, (float)gameScreenHeight * appWindowScale.y }, { 0.0f, 0.0f }, 0.0f, WHITE);
	EndDrawing();
}

void Game::Update(float t_dt)
{
	
	appWindowScale = { (float)GetScreenWidth() / gameScreenWidth, (float)GetScreenHeight() / gameScreenHeight };
	gameObjects.update();
}

void Game::Draw()
{
	gameObjects.draw();
}