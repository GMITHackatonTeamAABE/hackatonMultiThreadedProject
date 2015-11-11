#ifndef _TOWER_H
#define _TOWER_H

#include "Sprite.h"
#include <Box2D/Box2D.h>
#include <queue>

class Projectile;

class Tower {
public:
	Tower(b2World &world, float posX, float posY);
	virtual ~Tower();

	virtual void update(float timestep, float targetX, float targetY);
	virtual void draw();
	virtual Projectile* fire();

	virtual void projectileHit(b2Body* projectile, b2Body* other);

protected:
	Sprite mBodySprite, mTurretSprite;

	b2Body* mBodyPtr;

	float mAngle;

	std::queue<Projectile> mProjectiles;
};
#endif