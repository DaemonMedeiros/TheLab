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
	if (!objectsInitialized)
	{
		setupPlayers();
		std::cout << "GameObjects : Initialized\n";
		objectsInitialized = true;
	}
}

void GameObjects::setupPlayers()
{
	player_one = new Player(PLAYER_1, assetHandler->getTexture("Player"));
	if (playerCount == TWO_PLAYER){player_two = new Player(PLAYER_2, assetHandler->getTexture("Player"));}
}

void GameObjects::unloadPlayers()
{
	delete(player_one); player_one = nullptr;
	if (playerCount == TWO_PLAYER) { delete(player_two); player_two = nullptr; }
}

void GameObjects::update(float& t_dt)
{
	// update game objects here
	player_one->update(t_dt);
	if (playerCount == TWO_PLAYER) { player_two->update(t_dt); }
}

void GameObjects::draw(RenderTexture2D& t_window)
{
	// draw game objects here
	player_one->draw(t_window);
	if (playerCount == TWO_PLAYER) { player_two->draw(t_window); }
}
