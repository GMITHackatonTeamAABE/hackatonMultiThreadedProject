#include "include\Play.h"

Play::Play(b2World* w, int SCREEN_WIDTH, int SCREEN_HEIGHT) :
	TIME_PER_TICK(8),
	clockInit(false)
{
	world = w;
	backGroundImage = new Sprite();
	SDL_Rect destination = { SCREEN_WIDTH / 2 ,SCREEN_HEIGHT / 2 , SCREEN_WIDTH, SCREEN_HEIGHT };
	SDL_Rect Source = { 0, 0, 969, 545 };
	backGroundImage->Init("Assets/GameBackground.png", destination, Source);
	backGroundImage->SetOffset(SDL_Point{ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 });

	tower = new Tower(world, 1000, 300);
	floor = new Floor(world, SDL_Rect{0,SCREEN_HEIGHT,SCREEN_WIDTH,10});
	EnemyManager::GetInstance()->AddEnemy(10, 10, world);
}

void Play::Init()
{
	mouseX = mouseY = 0;
}
void Play::Update()
{
	if (!clockInit)
	{
		lastTickTime = myClock.now();
		clockInit = true;
	}

	//fixed timestep
	while (myClock.now() > lastTickTime + TIME_PER_TICK) {
		lastTickTime += TIME_PER_TICK;
		world->Step(1.0f/60.0f, 2, 4);
		tower->update(
			KeyBoardInput::GetInstance()->isKeyPressed(SDLK_LEFT),
			KeyBoardInput::GetInstance()->isKeyPressed(SDLK_RIGHT),
			KeyBoardInput::GetInstance()->isKeyPressed(SDLK_SPACE)
			);
		EnemyManager::GetInstance()->Update();
	}
}
void Play::Draw() const
{
	Renderer::GetInstance()->ClearRenderer();

	/*Call Draw on objects here*/
	backGroundImage->Draw();
	tower->draw();
	EnemyManager::GetInstance()->Draw();

	Renderer::GetInstance()->RenderScreen();
}

void Play::UpdateMousePos(int x, int y)
{
	mouseX = x;
	mouseY = y;
}