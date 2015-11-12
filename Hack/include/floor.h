#ifndef _FLOOR_H_
#define _FLOOR_H_

#include <iostream>
#include <stdio.h>

#include <SDL.h>
#include <Box2D/Box2D.h>


class Floor
{
private:
	
	b2Body* myBody;
	b2BodyDef myBodyDef;
	b2FixtureDef myBodyFixtureDef;
	b2PolygonShape myShape;

public:

	Floor(b2World*, SDL_Rect pRect);
	~Floor()
	{
		
	}
	
};
#endif
