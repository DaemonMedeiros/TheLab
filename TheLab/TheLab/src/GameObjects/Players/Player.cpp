#include "../../include/GameObjects/Players/Player.hpp"

Player::Player(PlayerId t_player_num, Texture2D& t_texture) : player_num(t_player_num), player_texture(t_texture)
{
}

Player::~Player()
{
}

void Player::init()
{

}

void Player::update(float& t_dt)
{

}

void Player::draw(RenderTexture2D& t_window)
{
	DrawTexture(player_texture, 200, 200, WHITE);
}
