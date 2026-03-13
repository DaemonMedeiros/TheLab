#include <cstdlib>
#include <ctime>

#include "../../include/MainLoop/Game.hpp"
#include "../../include/AssetLoader.hpp"

int main()
{
	srand(time(nullptr));
	Game game;
	game.Run();
	return 0;
}