#ifndef _TOWER_H
#define _TOWER_H

#include "Sprite.h"
#include <Box2D/Box2D.h>
#include <include/Bullet.h>
#include <vector>
#include "include\SoundManager.h"

class Tower {
public:
	Tower(b2World *world, float posX, float posY);
	virtual ~Tower();

	virtual void update(bool angleUp, bool angleDown, bool fire);
	virtual void draw();
	//virtual Projectile* fire();

	virtual void projectileHit(b2Body* projectile, b2Body* other);

protected:
	Sprite mBodySprite, mTurretSprite, mBuildingSprite;

	b2Body* mBodyPtr;

	double mAngle;

	const b2Vec2 mTURRET_OFFSET, mBUILDING_OFFSET;
	const double mMAX_ANGLE, mMIN_ANGLE;
	const float mPOWER;

	float posX, posY;
	b2Vec2 barrelOrigin;
	float barrelLength;

	b2PolygonShape mShape;
	b2BodyDef mBodyDef;
	b2FixtureDef mFixDef;

	bool fired;

	std::vector<Bullet*> mBullets;

	b2World* worldPtr;
};
#endif