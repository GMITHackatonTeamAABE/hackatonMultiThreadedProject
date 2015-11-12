#include "include\Play.h"

Play::Play(b2World* w, int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
	world = w;
	bullet = new Bullet(180, 110, world);
	backGroundImage = new Sprite();
	SDL_Rect destination = { SCREEN_WIDTH / 2 ,SCREEN_HEIGHT / 2 , SCREEN_WIDTH, SCREEN_HEIGHT };
	SDL_Rect Source = { 0, 0, 1920, 1200 };
	backGroundImage->Init("Assets/background.png", destination, Source);
	backGroundImage->SetOffset(SDL_Point{ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 });
	tower = new Tower(*world, 100, 100);

}

void Play::Init()
{
}
void Play::Update()
{
	tower->update(1.0f, 0, 1);
}
void Play::Draw()
{
	Renderer::GetInstance()->ClearRenderer();

	/*Call Darw on objects here*/
	backGroundImage->Draw();
	tower->draw();

	bullet->Draw();
	Renderer::GetInstance()->RenderScreen();
}