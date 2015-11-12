#pragma comment(lib, "Box2D.lib")

#include <SDL.h>			//SDL
#include <SDL_ttf.h>
#include <string>
#include <chrono>
#include <Box2D/Box2D.h>
#include <include\Renderer.h>
#include <include\Sprite.h>
#include <include\KeyBoardInput.h>
#include <include/Tower.h>

//Screen dimension constants
const int SCREEN_WIDTH = 1248;			//SDL
const int SCREEN_HEIGHT = 704;			//SDL
										//gamestates
const int MENU = 0, PLAY = 1, PAUSE = 2, GAMEOVER = 3;
int gameState;




Sprite* backGroundImage;
Tower* tower;

int mouseX, mouseY;
std::chrono::steady_clock myClock;
chrono::time_point<chrono::steady_clock> lastTickTime, lastFrameTime;
const auto TIME_PER_TICK = chrono::milliseconds(16);


void Init();
void DrawGame();
void DrawMenu();
void UpdateGame();
bool UpdateMenu(SDL_Event e);
void Reset();
void ClearPointers();


int wmain()
{
	gameState = MENU;
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//SDL
#pragma region SDL STUFF
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Create Renderer for the Window
			if (!Renderer::GetInstance()->Init(window, SCREEN_WIDTH, SCREEN_HEIGHT))
			{
				return 0;
			}

			bool quit = false;
			Init();




			SDL_Event e;
			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0) {
					KeyBoardInput::GetInstance()->updateKeyboard(e);
					switch (e.type)
					{
					case SDL_QUIT:
						quit = true;
						break;
					case SDL_MOUSEMOTION:
						mouseX = e.motion.x;
						mouseY = e.motion.y;
						std::cout << "X: " << mouseX << "\tY: " << mouseY << std::endl;
						break;
					}
				}

				//controls gameState added in game menu feature
				switch (gameState)
				{
				case MENU:
					//updateMenu
					quit = UpdateMenu(e);
					//draw menu
					DrawMenu();

					break;
				case PLAY:
					UpdateGame();
					DrawGame();
					break;
				}//end switch

				 // Escape button
				if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_ESCAPE))
				{
					quit = true;
				}
				else if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_RETURN))
				{
					gameState = PLAY;
				}

			}//end while wuit
		}//end else
	}//end else

	ClearPointers();
	return 0;
}

void Init()
{
	b2World world = b2World(b2Vec2_zero);

	gameState = MENU;
	backGroundImage = new Sprite();
	SDL_Rect destination = { SCREEN_WIDTH/2 ,SCREEN_HEIGHT/2 , SCREEN_WIDTH, SCREEN_HEIGHT };
	SDL_Rect Source = { 0, 0, 1240, 720 };
	backGroundImage->Init("Assets/menu.png", destination, Source);
	backGroundImage->SetOffset(SDL_Point{ SCREEN_WIDTH/2,SCREEN_HEIGHT/2});

	tower = new Tower(world, 100, 100);

	lastTickTime = lastFrameTime = myClock.now();
}
void DrawGame()
{
	Renderer::GetInstance()->ClearRenderer();

	/*Call Darw on objects here*/
	tower->draw();

	Renderer::GetInstance()->RenderScreen();
}
void DrawMenu()
{
	Renderer::GetInstance()->ClearRenderer();

	/*Call Darw on objects here*/
	backGroundImage->Draw();
	

	Renderer::GetInstance()->RenderScreen();
}
bool UpdateMenu(SDL_Event e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN) {
		//If the left mouse button was pressed
		if (e.button.button == SDL_BUTTON_LEFT) {
			//Get the mouse offsets
			int mouse_x = e.button.x;
			int mouse_y = e.button.y;
			//SDL_Log("Mouse Button 1 (left) is pressed. x = " + x );
			/*std::cout << "Mouse Button 1 (left) is pressed. x = " << mouse_x << ", y = " << mouse_y << std::endl;
			if (playButton.IsClicked(mouse_x, mouse_y)) {
				gameState = PLAY;
			}
			else if (exitButton.IsClicked(mouse_x, mouse_y)) {
				return true; 
			}*/
		}
	}
	return false;
}
void UpdateGame()
{
	//fixed timestep
	while (myClock.now() > lastTickTime + TIME_PER_TICK) {
		lastTickTime += TIME_PER_TICK;

		tower->update(1.0f,
			KeyBoardInput::GetInstance()->isKeyPressed(SDLK_LEFT),
			KeyBoardInput::GetInstance()->isKeyPressed(SDLK_RIGHT)
			);
	}
}
void Reset()
{

}
void ClearPointers()
{
	delete backGroundImage;
	delete tower;
}