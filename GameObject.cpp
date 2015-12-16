#include "GameObject.h"

GameObject::GameObject()
{
	DEBUG_MSG("Character Constructor");
}

GameObject::~GameObject()
{
	DEBUG_MSG("Character Destructor");
}

float GameObject::GetX() const {
	return mX;
}

void GameObject::SetX(float x)
{
	lock_guard<mutex> lock(mMutex);
	mDestination.x = mX = x;
}

float GameObject::GetY() const {
	return mY;
}

void GameObject::SetY(float y)
{
	lock_guard<mutex> lock(mMutex);
	mDestination.y = mY = y;
}
