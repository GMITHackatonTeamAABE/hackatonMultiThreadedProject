#include <include/Tower.h>

Tower::Tower(b2World &world, float posX, float posY):
	mAngle(0),
	mTURRET_OFFSET(30, 10)
{
	mBodySprite.Init("./assets/base.png",
		SDL_Rect{ int(posX),int(posY),76,43 },
		SDL_Rect{ 0,0,76,43 }
	);

	mTurretSprite.Init("./assets/barrel.png",
		SDL_Rect{ int(posX+mTURRET_OFFSET.x),int(posY+mTURRET_OFFSET.y),49,9 },
		SDL_Rect{ 0,0,49,9 }
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
	mTurretSprite.Draw();
	mBodySprite.Draw();
}

//Projectile* Tower::fire()
//{
//	//mProjectiles.push(Projectile(...));
//	//return mProjectiles.back();
//}

void Tower::projectileHit(b2Body* projectile, b2Body* other)
{
	//mProjectiles.pop();
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

float toDegrees(float radians)
{
	return radians * 57.2958f;
}

void Tower::update(float timestep, float targetX, float targetY)
{
	normalize(targetX, targetY);
	mAngle = toDegrees(acosf(dotProduct(targetX, 1, targetY, 0)));

	//mTurretSprite.setRotation(mAngle);

	std::cout << "Angle: " << mAngle << std::endl;
}