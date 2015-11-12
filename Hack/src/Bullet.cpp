#include <include/Bullet.h>

Bullet::Bullet(float x, float y, b2World* world, float dir, float power) {
	m_position.x = x;
	m_position.y = y;
	SDL_Rect src = { 0,0, 100,100 };

	//load the sprite
	spriteRect = { int(m_position.x),(int)m_position.y, 10,10 };
	sprite = new Sprite();
	sprite->Init("Assets/bulletTemp.png", spriteRect, src);

	//create the box2d body
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.userData = this;
	bodyDef.position.x = m_position.x;
	bodyDef.position.y = m_position.y;
	
	b2FixtureDef fixDef;
	b2PolygonShape shape;
	shape.SetAsBox(10, 10);
	fixDef.isSensor = true;
	fixDef.shape = &shape;

	bulletBody = world->CreateBody(&bodyDef);

	dir *= 0.017f;	//degrees to radians
	//launch the bullet
	bulletBody->SetLinearVelocity(b2Vec2(cos(dir) * power, sin(dir) * power));
}

void Bullet::Update() {
	sprite->SetPosition(bulletBody->GetPosition().x, bulletBody->GetPosition().y);
	sprite->SetRotation(bulletBody->GetAngle());
	//sprite->SetDestinationRect(spriteRect);
}

bool Bullet::CheckCollision(SDL_Rect* rect) {
	
	return false;
}

//void Bullet::Fire(float dir, float power) {
//	fire = true;
//	
//	bulletBody->ApplyForceToCenter(b2Vec2(cosf(dir) * power, sinf(dir) * power), true);
//}

void Bullet::Draw() const
{
	sprite->Draw();
}

Bullet::~Bullet() {
	delete sprite;
}