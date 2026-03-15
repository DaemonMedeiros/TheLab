#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../Enums/Commands.h"
#include "../Enums/PlayerId.h"
#include "../Handlers/AssetHandler.hpp"
#include "../Handlers/InputHandler.hpp"

class Player
{
public:
	Player(Texture2D& t_texture);
	~Player();
private:

	Texture2D texture;
};
#endif