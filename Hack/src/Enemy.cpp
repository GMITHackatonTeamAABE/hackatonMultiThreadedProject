#include <include\Enemy.h>

Enemy::Enemy(float xPos, float yPos, b2World* physicsWorld) {
	m_sprite.Init("Assets/Enemy.png",
					SDL_Rect{ (int)xPos, (int)yPos, 100, 100 },
					SDL_Rect{ 0, 0, 47, 73 });
	/*each frame is 47pixels roughly wide but spaced at 49pixel ie move src rect forward by 40 each update*/
	
	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(xPos, yPos);
	m_body = physicsWorld->CreateBody(&m_bodyDef);

	m_shape.SetAsBox(50, 50);

	m_fixtureDef.shape = &m_shape;
	m_fixtureDef.friction = 100;
	m_body->CreateFixture(&m_fixtureDef);

	m_velocity = b2Vec2(1, 0);
}

Enemy::~Enemy() {}

void Enemy::update() {
	m_sprite.SetPosition(m_body->GetPosition().x, m_body->GetPosition().y);
}

void Enemy::draw() {
	m_sprite.Draw();
}