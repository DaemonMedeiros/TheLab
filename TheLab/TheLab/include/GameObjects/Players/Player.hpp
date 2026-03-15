#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <raylib.h>
#include <raymath.h>
#include "../Enums/Commands.h"
#include "../Enums/PlayerId.h"
#include "../Handlers/InputHandler.hpp"

class Player
{
public:
	Player(PlayerId t_player_num, Texture2D& t_texture);
	~Player();

	void init();
	void update(float& t_dt);
	void draw(RenderTexture2D& t_window);

private:

	void movePlayer(float& t_dt);

	PlayerId player_num;
	InputHandler* inputHandler{nullptr};
	Command activeCommand{CMD_NONE};
	Texture2D player_texture;

	Vector2 position{200.0f,200.0f};
	Vector2 direction{ 0.0f,0.0f };
	int speed = 5;
};
#endif