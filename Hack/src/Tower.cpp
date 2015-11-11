#include <include/Tower.h>

Tower::Tower(b2World &world, float posX, float posY):
	mAngle(0)
{
	mBodySprite.Init("path/to/bodyImage",
		SDL_Rect{ int(posX),int(posY),100,100 },
		SDL_Rect{ 0,0,100,100 }
	);

	mTurretSprite.Init("path/to/turretImage",
		SDL_Rect{ int(posX),int(posY),100,100 },
		SDL_Rect{ 0,0,100,100 }
	);

	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.userData = this;
	bodyDef.position.x = posX;
	bodyDef.position.y = posY;

	mBodyPtr = world.CreateBody(&bodyDef);
}

Tower::~Tower()
{
}

void Tower::draw()
{
	mBodySprite.Draw();
	mTurretSprite.Draw();
}

Projectile* Tower::fire()
{
	//mProjectiles.push(Projectile(...));
	//return mProjectiles.back();
}

void Tower::projectileHit(b2Body* projectile, b2Body* other)
{
	mProjectiles.pop();
}

float dotProduct(float aX, float bX, float aY, float bY)
{
	return (aX * bX) + (aY * bY);
}

void normalize(float& x, float& y)
{
	float length = sqrtf(powf(x, 2) + powf(y, 2));
	x /= length;
	y /= length;
}

void Tower::update(float timestep, float targetX, float targetY)
{
	normalize(targetX, targetY);
	mAngle = acosf(dotProduct(targetX, 1, targetY, 0));

	//mTurretSprite.setRotation(mAngle);
}