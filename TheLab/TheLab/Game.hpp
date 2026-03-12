#ifndef GAME_HPP
#define GAME_HPP

#include <raylib.h>
#include "Constants.hpp"

class Game
{
public:
	Game();
	~Game();
	void Run();

private:
	void Init();
	void Update(float t_dt);
	void ScaleAndRenderWindow();
	void Draw();

	RenderTexture2D appWindow{ 0 };
	Vector2 appWindowScale{ 1.0f,1.0f };
	int gameScreenWidth{ SCREEN_WIDTH };
	int gameScreenHeight{ SCREEN_HEIGHT };

};
#endif