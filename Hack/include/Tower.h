#ifndef _TOWER_H
#define _TOWER_H

#include "Sprite.h"
#include <Box2D/Box2D.h>
#include <queue>

class Tower {
public:
	Tower(b2World &world, float posX, float posY);
	virtual ~Tower();

	virtual void update(bool angleUp, bool angleDown);
	virtual void draw();
	//virtual Projectile* fire();

	virtual void projectileHit(b2Body* projectile, b2Body* other);

protected:
	Sprite mBodySprite, mTurretSprite, mBuildingSprite;

	b2Body* mBodyPtr;

	double mAngle;

	const b2Vec2 mTURRET_OFFSET, mBUILDING_OFFSET;
	const double mMAX_ANGLE, mMIN_ANGLE;

	float posX, posY;

	b2PolygonShape mShape;
	b2BodyDef mBodyDef;
	b2FixtureDef mFixDef;

	//std::queue<Projectile> mProjectiles;
};
#endif