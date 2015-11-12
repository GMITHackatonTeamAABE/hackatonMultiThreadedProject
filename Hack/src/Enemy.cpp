#include <include\Enemy.h>

Enemy::Enemy(float xPos, float yPos, b2World* physicsWorld) {
	m_sprite.Init("Assets/Enemy.png",
					SDL_Rect{ (int)xPos, (int)yPos, 100, 100 },
					SDL_Rect{ 0, 0, 47, 73 });
	m_sprite.SetOffset(SDL_Point{ 50,50 });
	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(xPos, yPos);
	m_body = physicsWorld->CreateBody(&m_bodyDef);

	m_shape.SetAsBox(50, 50);

	m_fixtureDef.shape = &m_shape;
	m_fixtureDef.friction = 0;
	m_body->CreateFixture(&m_fixtureDef);

	m_velocity = b2Vec2(100, 0);

	frame = 0;
	gSpriteClips[WALKING_ANIMATION_FRAMES];
	animationUpdate = 0;

	//Set sprite clips
	gSpriteClips[0] = { 3, 0, 42, 70 };
	gSpriteClips[1] = { 53, 0, 42, 70 };
	gSpriteClips[2] = { 103, 0, 37, 70 };
	gSpriteClips[3] = { 145, 0, 49, 70 };
	gSpriteClips[4] = { 198, 0, 41, 70 };
	gSpriteClips[5] = { 245, 0, 43, 70 };
	gSpriteClips[6] = { 290, 0, 48, 70 };
	gSpriteClips[7] = { 346, 0, 41, 70 };
	gSpriteClips[8] = { 392, 0, 39, 70 };
}

Enemy::~Enemy() {}

void Enemy::update() {
	m_body->SetLinearVelocity(b2Vec2(m_velocity.x ,m_body->GetLinearVelocity().y));
	m_sprite.SetPosition(m_body->GetPosition().x, m_body->GetPosition().y);

	animationUpdate++;
	if (animationUpdate % 10 == 0)
	{
		++frame;
		m_sprite.SetSourceRect(gSpriteClips[frame]);
	}
	//Cycle animation
	if (frame == WALKING_ANIMATION_FRAMES)
	{
		frame = 0;
		m_sprite.SetSourceRect(gSpriteClips[frame]);
	}
}

void Enemy::draw() {
	m_sprite.Draw();
}

bool Enemy::checkCollisions() {
	for (b2ContactEdge* edge = m_body->GetContactList(); edge; edge = edge->next) {
		b2Fixture* a = edge->contact->GetFixtureA();
		b2Fixture* b = edge->contact->GetFixtureB();

		if (a->IsSensor() || b->IsSensor()) {
			return true;
		}
	}
	return false;
}