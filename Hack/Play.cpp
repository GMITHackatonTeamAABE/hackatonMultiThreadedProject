#include "include\Play.h"

Play::Play(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
	backGroundImage = new Sprite();
	SDL_Rect destination = { SCREEN_WIDTH / 2 ,SCREEN_HEIGHT / 2 , SCREEN_WIDTH, SCREEN_HEIGHT };
	SDL_Rect Source = { 0, 0, 1920, 1200 };
	backGroundImage->Init("Assets/background.png", destination, Source);
	backGroundImage->SetOffset(SDL_Point{ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 });
}

void Play::Init()
{
}
void Play::Update()
{

}
void Play::Draw()
{

}