#include "include\Play.h"

Play::Play(b2World* w, int SCREEN_WIDTH, int SCREEN_HEIGHT) :
	TIME_PER_TICK(16),
	clockInit(false)
{
	world = w;
	bullet = new Bullet(990, 210, *world);
	backGroundImage = new Sprite();
	SDL_Rect destination = { SCREEN_WIDTH / 2 ,SCREEN_HEIGHT / 2 , SCREEN_WIDTH, SCREEN_HEIGHT };
	SDL_Rect Source = { 0, 0, 969, 545 };
	backGroundImage->Init("Assets/GameBackground.png", destination, Source);
	backGroundImage->SetOffset(SDL_Point{ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 });

	tower = new Tower(*world, 1000, 200);

	EnemyManager::GetInstance()->AddEnemy(10, 10, world);
}

void Play::Init()
{
	mouseX = mouseY = 0;
}
void Play::Update()
{
	if(!clockInit)
	{
		lastTickTime = myClock.now();
		clockInit = true;
	}

	//fixed timestep
	while (myClock.now() > lastTickTime + TIME_PER_TICK) {
		lastTickTime += TIME_PER_TICK;

		tower->update(
			KeyBoardInput::GetInstance()->isKeyPressed(SDLK_LEFT),
			KeyBoardInput::GetInstance()->isKeyPressed(SDLK_RIGHT)
			);
	}
}
void Play::Draw() const
{
	Renderer::GetInstance()->ClearRenderer();

	/*Call Darw on objects here*/
	backGroundImage->Draw();
	tower->draw();
	EnemyManager::GetInstance()->Draw();
	bullet->Fire(5.0f);
	bullet->Draw();
	Renderer::GetInstance()->RenderScreen();
}

void Play::UpdateMousePos(int x, int y)
{
	mouseX = x;
	mouseY = y;
}