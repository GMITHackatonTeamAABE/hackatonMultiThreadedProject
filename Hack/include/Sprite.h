#ifndef SPRITE_H
#define SPRITE_H

#include <iostream> 
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Renderer.h"


class Sprite
{
public :
	Sprite();
	void Init(std::string imagePath, SDL_Rect destination, SDL_Rect source);
	void SetPosition(float x, float y);
	void SetWidth(float w);
	void SetHeight(float h);
	void SetDestinationRect(SDL_Rect destination);
	void SetSourceRect(SDL_Rect source);
	void SetOffset(SDL_Point offset);/*offset is relative width and height of the sprite not the texture */
	void SetRotation(double rot);
	void Draw();

protected:
	SDL_Texture* loadTexture(std::string path, SDL_Renderer*);
	SDL_Texture* myTexture;
	SDL_Point m_offset;
	SDL_Rect m_Destrination, m_Source;
	double rotation;
};
#endif