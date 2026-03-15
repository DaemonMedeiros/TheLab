#include "../../include/GameObjects/GameObjects.hpp"

GameObjects::GameObjects(AssetHandler* t_assetHandler, PlayerCount& t_playerCount) : 
						 assetHandler (t_assetHandler),playerCount (t_playerCount)
{
	std::cout << "GameObjects : Object Created\n";
}

GameObjects::~GameObjects()
{
	unloadPlayers();
	std::cout << "GameObjects : Object Destroyed\n";
}

void GameObjects::init()
{
	setupPlayers();
}

void GameObjects::setupPlayers()
{
	player_one = new Player(assetHandler->getTexture("player"));
	if (playerCount == TWO_PLAYER){player_two = new Player(assetHandler->getTexture("player"));}
}

void GameObjects::unloadPlayers()
{
	delete(player_one);
	player_one = nullptr;
	if (playerCount == TWO_PLAYER) { delete(player_two); player_two = nullptr; }
}

void GameObjects::update(float& t_dt, Command& t_command)
{
	// update game objects here
}

void GameObjects::draw()
{
	// draw game objects here
}
