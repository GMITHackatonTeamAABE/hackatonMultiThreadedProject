#include "include\Play.h"

Play::Play(b2World* w, int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
	world = w;
	backGroundImage = new Sprite();
	SDL_Rect destination = { SCREEN_WIDTH / 2 ,SCREEN_HEIGHT / 2 , SCREEN_WIDTH, SCREEN_HEIGHT };
	SDL_Rect Source = { 0, 0, 969, 545 };
	backGroundImage->Init("Assets/GameBackground.png", destination, Source);
	backGroundImage->SetOffset(SDL_Point{ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 });
	tower = new Tower(*world, 100, 100);
	EnemyManager::GetInstance()->AddEnemy(10, 10, world);
}

void Play::Init(){
}

void Play::Update(){
	tower->update(1.0f, 0, 1);
	world->Step(60,30,60);
}

void Play::Draw(){
	Renderer::GetInstance()->ClearRenderer();

	/*Call Draw on objects here*/
	backGroundImage->Draw();
	tower->draw();
	EnemyManager::GetInstance()->Draw();

	Renderer::GetInstance()->RenderScreen();
}