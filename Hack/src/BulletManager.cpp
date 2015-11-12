#include <include\BulletManager.h>

bool BulletManager::instanceFlag = false;
BulletManager* BulletManager::instance = NULL;

BulletManager* BulletManager::getInstance() {
	if (!instanceFlag) {
		instance = new BulletManager;
		instanceFlag = true;
		return instance;
	}	
	else {
		return instance;
	}
}

void BulletManager::Update() {
	for each (Bullet* b in bullets) {
		b->Update();
	}
}

void BulletManager::Fire(float dir) {
	if (!bullets.empty()) {
		for each (Bullet* b in bullets) {
			b->Fire(dir);
		}
	}
}

void BulletManager::add(float x, float y, b2World& world) {
	bullets.push_back(new Bullet(x, y, world));
}

void BulletManager::Draw() {
	for each(Bullet* b in bullets) {
		b->Draw();
	}
}

BulletManager::~BulletManager() {
	instanceFlag = false;
}

