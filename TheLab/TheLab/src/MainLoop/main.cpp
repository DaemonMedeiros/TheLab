#include "../../include/MainLoop/Game.hpp"
#include "../../include/AssetLoader.hpp"

int main()
{
	AssetLoader assetLoader;
	Game game(assetLoader);
	game.Run();
	return 0;
}