#include "include\Bullet.h"

Bullet::Bullet(float x, float y, b2World& world) {
	m_position.x = x;
	m_position.y = y;
	SDL_Rect src = { 0,0, 100,100 };
	spriteRect = { int(m_position.x),(int)m_position.y, 10,10 };
	sprite = new Sprite();
	sprite->Init("Assets/bulletTemp.png", spriteRect, src);

	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.userData = this;
	bodyDef.position.x = m_position.x;
	bodyDef.position.y = m_position.y;

	bulletBody = world.CreateBody(&bodyDef);
}

void Bullet::Update() {
	sprite->SetPosition(bulletBody->GetPosition().x, bulletBody->GetPosition().y);
	sprite->SetDestinationRect(spriteRect);

}

void Bullet::setPosition(float x, float y) {
	m_position.x = x;
	m_position.y = y;
}

bool Bullet::CheckCollision(SDL_Rect* rect) {
	
	return false;
}

void Bullet::Fire(float dir) {
	fire = true;
	// apply force
}

void Bullet::Draw() { // sprite.Draw();
	if (fire)
		sprite->Draw();
	else {}
}

Bullet::~Bullet() {
	delete sprite;
}