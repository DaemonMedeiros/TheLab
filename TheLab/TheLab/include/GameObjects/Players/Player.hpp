#ifndef PLAYER_HPP
#define PLAYER_HPP

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

	PlayerId player_num;
	Texture2D player_texture;

	Vector2 position{0.0f,0.0f};
};
#endif