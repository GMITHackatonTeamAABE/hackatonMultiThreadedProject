#include "include\Button.h"


Button::Button(){
}
void Button::Init(SDL_Rect pos, std::string path){
	rect = pos;
	SDL_Rect tempSRC{0,0,400,300};
	m_sprite = new Sprite();
	m_sprite->Init(path, pos, tempSRC);
}
bool Button::IsClicked(int x , int y){

	if (rect.x + rect.w > x && rect.x < x && rect.y + rect.h > y && rect.y < y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Button::Draw(){
	m_sprite->Draw();
}
