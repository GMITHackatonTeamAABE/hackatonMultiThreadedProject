#include <include/Tower.h>

Tower::Tower(b2World &world, float _posX, float _posY):
	mAngle(180),
	mTURRET_OFFSET(40, 20),
	mBUILDING_OFFSET(-40, -222),
	mMAX_ANGLE(270),
	mMIN_ANGLE(150),
	posX(_posX),
	posY(_posY)
{
	mBodySprite.Init("./assets/base.png",
		SDL_Rect{ int(posX),int(posY),76,43 },
		SDL_Rect{ 0,0,76,43 }
	);

	mTurretSprite.Init("./assets/barrel.png",
		SDL_Rect{ int(posX+mTURRET_OFFSET.x),int(posY+mTURRET_OFFSET.y),49,9 },
		SDL_Rect{ 0,0,49,9 }
	);

	mBuildingSprite.Init("./assets/tower.png",
		SDL_Rect{ int(posX+mBUILDING_OFFSET.x),int(posY+mBUILDING_OFFSET.y),284,800 },
		SDL_Rect{ 0,0,284,800 }
	);

	//Box2D body creation
	mBodyDef.type = b2_staticBody;
	mBodyDef.userData = this;
	mBodyDef.position.Set(posX, posY);

	b2Vec2 points[4] = {
		b2Vec2(posX + mBUILDING_OFFSET.x, posY + mBUILDING_OFFSET.y),				//TOP LEFT
		b2Vec2(posX + mBUILDING_OFFSET.x + 284, posY + mBUILDING_OFFSET.y),			//TOP RIGHT
		b2Vec2(posX + mBUILDING_OFFSET.x + 284, posY + mBUILDING_OFFSET.y + 800),	//BOTTOM RIGHT
		b2Vec2(posX + mBUILDING_OFFSET.x, posY + mBUILDING_OFFSET.y + 800)			//BOTTOM LEFT
	};

	mShape.Set(points, 4);
	
	mFixDef.userData = this;
	mFixDef.isSensor = false;
	mFixDef.shape = &mShape;

	mBodyPtr = world.CreateBody(&mBodyDef);
	mBodyPtr->CreateFixture(&mFixDef);
}

Tower::~Tower()
{
}

void Tower::draw()
{
	mBuildingSprite.Draw();
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

//float toDegrees(float radians)
//{
//	return radians * 57.2958f;
//}
//
//void Tower::update(float timestep, float targetX, float targetY)
//{
//	targetX -= posX;
//	targetY -= posY;
//	normalize(targetX, targetY);
//	mAngle = toDegrees(acos(dotProduct(targetX, 1, targetY, 0)));
//
//	if(targetY < posY)
//	{
//		mAngle = -mAngle;
//	}
//
//	mTurretSprite.SetRotation(mAngle);
//
//	std::cout << "Angle: " << mAngle << std::endl;
//}

void Tower::update(bool angleUp, bool angleDown)
{
	if(angleUp && mAngle > mMIN_ANGLE)
	{
		mAngle--;
	} else if(angleDown && mAngle < mMAX_ANGLE)
	{
		mAngle++;
	}

	mTurretSprite.SetRotation(mAngle);
}