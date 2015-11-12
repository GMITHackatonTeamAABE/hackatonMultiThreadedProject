#include <include\GameStateController.h>

bool GameStateController::instanceFlag = false;
GameStateController* GameStateController::instance = NULL;

GameStateController* GameStateController::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new GameStateController;
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}

void GameStateController::SetGameState(int g) { GameState = g; }
int GameStateController::getGameState() { return GameState; }