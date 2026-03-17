#include "../../include/Handlers/GameStateHandler.hpp"

GameStateHandler::GameStateHandler()
{
	
}

GameStateHandler::~GameStateHandler()
{
}

GameState GameStateHandler::updateGameState(float& t_dt)
{
	// Temporary Dev Tools ------------------------------------------------------------------
	if (IsKeyPressed(KEY_ONE)) {
		 std::cout << "GameState : GS_LOADING_TEXTURES\n"; return GS_LOADING_TEXTURES;}
	if (IsKeyPressed(KEY_TWO)) {
		 std::cout << "GameState : GS_START_MENU\n"; return GS_START_MENU; }
	if (IsKeyPressed(KEY_THREE)) {
		std::cout << "GameState : GS_INIT_OBJECTS\n"; return GS_INIT_OBJECTS; }
	if (IsKeyPressed(KEY_FOUR)) {
		std::cout << "GameState : GS_PLAY\n"; return GS_PLAY; }
	if (IsKeyPressed(KEY_FIVE)) {
		std::cout << "GameState : GS_PAUSE\n"; return GS_PAUSE; }
	if (IsKeyPressed(KEY_SIX)) {
		std::cout << "GameState : GS_END\n"; return GS_END; }
	// --------------------------------------------------------------------------------------
}
