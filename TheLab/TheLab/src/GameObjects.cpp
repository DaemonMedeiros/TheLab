#include "../include/GameObjects.hpp"

GameObjects::GameObjects()
{
	std::cout << "GameObjects : Object Created\n";
}

GameObjects::~GameObjects()
{
	std::cout << "GameObjects : Object Destroyed\n";
}

void GameObjects::init()
{
	// initialize set up for game objects here
}

void GameObjects::update(double t_dt, Command& t_command)
{
	// update game objects here
}

void GameObjects::draw()
{
	// draw game objects here
}
