#ifndef GAMEOBJECTS_HPP
#define GAMEOBJECTS_HPP

#include <iostream>
#include "../include/Enums/Commands.h"

class GameObjects
{
public:
	GameObjects();
	~GameObjects();

	void init();
	void update(double t_dt, Command& t_command);
	void draw();

private:


};
#endif