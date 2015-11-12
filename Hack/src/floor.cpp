#include "include\floor.h"

Floor::Floor(b2World*wWorld, SDL_Rect pRect)
{
	// Define the ground body.
	myBodyDef.position.Set(pRect.x + pRect.w / 2, pRect.y + pRect.h / 2);
	myBodyDef.type = b2_staticBody;

	// Define the ground box shape.
	// The extents are the half-widths of the box.
	myShape.SetAsBox(pRect.w / 2 - 10, pRect.h / 2);
	myBodyFixtureDef.shape = &myShape;

	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	myBody = wWorld->CreateBody(&myBodyDef);

	// Add the ground fixture to the ground body.
	myBody->CreateFixture(&myBodyFixtureDef);
}