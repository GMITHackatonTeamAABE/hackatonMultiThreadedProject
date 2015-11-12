#include "include\Menu.h"

Menu::Menu(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
	backGroundImage = new Sprite();
	SDL_Rect destination = { SCREEN_WIDTH / 2 ,SCREEN_HEIGHT / 2 , SCREEN_WIDTH, SCREEN_HEIGHT };
	SDL_Rect Source = { 0, 0, 1920, 1200 };
	backGroundImage->Init("Assets/background.png", destination, Source);
	backGroundImage->SetOffset(SDL_Point{ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 });
	destination = { SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 4 - 150, 400, 300 };
	playButton.Init(destination, "Assets/PlayButton.png");
	destination = { SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 4 * 3 - 150, 400, 300 };
	exitButton.Init(destination, "Assets/ExitButton.png");
}

void Menu::Init()
{
}
bool Menu::Update(SDL_Event e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN) {
		//If the left mouse button was pressed
		if (e.button.button == SDL_BUTTON_LEFT) {
			//Get the mouse offsets
			int mouse_x = e.button.x;
			int mouse_y = e.button.y;
			std::cout << "Mouse Button 1 (left) is pressed. x = " << mouse_x << ", y = " << mouse_y << std::endl;
			if (playButton.IsClicked(mouse_x, mouse_y)) {
				GameStateController::GetInstance()->SetGameState(GameStateController::PLAY);
			}
			else if (exitButton.IsClicked(mouse_x, mouse_y)) {
				return true;
			}
		}
	}
	return false;
}
void Menu::Draw()
{
	Renderer::GetInstance()->ClearRenderer();
	/*Call Darw on objects here*/
	backGroundImage->Draw();
	playButton.Draw();
	exitButton.Draw();

	Renderer::GetInstance()->RenderScreen();
}