#ifndef ENEMY_H
#define ENEMY_H

#include <Box2D\Box2D.h>
#include <include\Sprite.h>

class Enemy{
public:
	Enemy(float xPos, float yPos, b2World* physicsWorld);
	~Enemy();
	void update();
	void draw();
private:
	Sprite m_sprite;
	b2Vec2 m_velocity;
	b2Body* m_body;
	b2BodyDef m_bodyDef;
	b2FixtureDef m_fixtureDef;
	b2PolygonShape m_shape;
	const int WALKING_ANIMATION_FRAMES = 9;
	SDL_Rect gSpriteClips[9];
	int frame;
	int animationUpdate;
};

#endif