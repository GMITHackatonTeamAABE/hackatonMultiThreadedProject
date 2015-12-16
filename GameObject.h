#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <iostream>
#include "Debug.h"
#include "GameObjectParameters.h"

#include <SDL.h>
#include <mutex>
#include <atomic>

using namespace std;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	virtual void Initialize(const GameObjectParameters*) = 0; 
	virtual void Render(SDL_Renderer* renderer) = 0;
	virtual void Update() = 0;
	virtual void CleanUp() = 0;
	float GetX() const;
	void SetX(float);
	float GetY() const;
	void SetY(float);
protected:
	atomic<float> mX, mY;
	SDL_Texture* mTexture;
	SDL_Rect mSource, mDestination;

	mutex mMutex;
};
#endif
