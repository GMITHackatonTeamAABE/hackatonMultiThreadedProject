#include "include\Bullet.h"

void Bullet::Update(float dir) {// b2Vec2 dir

}
void Bullet::CreateBody() {

}
bool Bullet::CheckLife() {
	return true;
}

bool Bullet::CheckCollision(SDL_Rect* rect) {
	return false;
}

void Bullet::Draw() { // sprite.Draw();
	sprite->Draw();
}

Bullet::~Bullet() {

}