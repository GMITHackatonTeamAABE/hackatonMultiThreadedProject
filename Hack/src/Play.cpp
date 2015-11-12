#include "include\Play.h"

Play::Play(b2World* w, int SCREEN_WIDTH, int SCREEN_HEIGHT) :
	TIME_PER_TICK(16),
	clockInit(false)
{
	world = w;
<<<<<<< HEAD
	bullet = new Bullet(990, 210, *world);
=======
	//bullet = new Bullet(990, 210, world);
>>>>>>> 56725d3f403e0e074a6e6ad5f7d9e68a4dd96e42
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
	if (!clockInit)
	{
		lastTickTime = myClock.now();
		clockInit = true;
	}

	//fixed timestep
	while (myClock.now() > lastTickTime + TIME_PER_TICK) {
		lastTickTime += TIME_PER_TICK;
		world->Step(6, 3, 6);
		tower->update(
			KeyBoardInput::GetInstance()->isKeyPressed(SDLK_LEFT),
			KeyBoardInput::GetInstance()->isKeyPressed(SDLK_RIGHT)
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
<<<<<<< HEAD
	bullet->Fire(5.0f);
	bullet->Draw();
=======

	//bullet->Draw();
>>>>>>> 56725d3f403e0e074a6e6ad5f7d9e68a4dd96e42
	Renderer::GetInstance()->RenderScreen();
}

void Play::UpdateMousePos(int x, int y)
{
	mouseX = x;
	mouseY = y;
}