#include "include\Bullet.h"

Bullet::Bullet(float x, float y, b2World* World) {
	world = World;
	m_position.x = x;
	m_position.y = y;
	SDL_Rect src = { 0,0, 100,100 };
	spriteRect = { int(m_position.x),(int)m_position.y, 10,10 };
	sprite = new Sprite();
	sprite->Init("Assets/bulletTemp.png", spriteRect, src);
}

void Bullet::Update(float dir) {
	sprite->SetPosition(m_position.x, m_position.y);
	sprite->SetDestinationRect(spriteRect);
}

void Bullet::CreateBody() {
	
}

/*bool Bullet::CheckLife() {
	return true;
}*/

bool Bullet::CheckCollision(SDL_Rect* rect) {
	
	return false;
}

void Bullet::Fire(float dir) {
	
}

void Bullet::Draw() { // sprite.Draw();
	sprite->Draw();
}

Bullet::~Bullet() {
	delete sprite;
}