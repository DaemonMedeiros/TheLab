#include "../../include/GameObjects/Players/Player.hpp"

Player::Player(PlayerId t_player_num, Texture2D& t_texture) : player_num(t_player_num), player_texture(t_texture)
{
	
}

Player::~Player()
{
	delete (inputHandler);
	inputHandler = nullptr;
}

void Player::init()
{
	inputHandler = new InputHandler(player_num);
}

void Player::update(float& t_dt)
{
	activeCommand = inputHandler->getActiveCommand();
	movePlayer(t_dt);
}

void Player::draw(RenderTexture2D& t_window)
{
	DrawTexture(player_texture, (int)position.x, (int)position.y, WHITE);
}

void Player::movePlayer(float& t_dt)
{
	direction = Vector2Normalize(position);

	if (activeCommand == CMD_MOVE_UP)
	{
		//position.y = position.y + (direction.y * -speed);
		position.y -= speed;
	}
	if (activeCommand == CMD_MOVE_DOWN)
	{
		//position.y = position.y + (direction.y * speed);
		position.y += speed;
	}
	if (activeCommand == CMD_MOVE_LEFT)
	{
		//position.x = position.x + (direction.x * -speed);
		position.x -= speed;
	}
	if (activeCommand == CMD_MOVE_RIGHT)
	{
		//position.x = position.x + (direction.x * speed);
		position.x += speed;
	}
}
