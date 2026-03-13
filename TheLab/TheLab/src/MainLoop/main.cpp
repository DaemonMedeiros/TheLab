#include <cstdlib>
#include <ctime>

#include "../../include/MainLoop/Game.hpp"

int main()
{
	srand(time(NULL));
	Game game;
	game.Run();
	return 0;
}