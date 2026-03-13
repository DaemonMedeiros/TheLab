#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include <iostream>
#include <raylib.h>
#include "../../include/Enums/Commands.h"

class InputHandler 
{
public:
	InputHandler();
	~InputHandler();

	Command getActiveCommand();
private:
};

#endif