#include <EnemyManager.h>

bool EnemyManager::instanceFlag = false;
EnemyManager* EnemyManager::instance = NULL;

EnemyManager* EnemyManager::GetInstance() {
	if (!instanceFlag){
		instance = new EnemyManager;
		instanceFlag = true;
		return instance;
	}
	else{
		return instance;
	}
}

EnemyManager::~EnemyManager() {
	newEnemy = NULL;
}

void EnemyManager::AddEnemy(float xPos, float yPos, b2World* physicsWorld) {
	newEnemy = new Enemy(xPos, yPos, physicsWorld);
	m_enemies.push_back(newEnemy);
}

bool EnemyManager::Init() {
	return true;
}

void EnemyManager::Draw() {
	for each (Enemy* e in m_enemies) {
		e->draw();
	}
}

void EnemyManager::RemoveEnemy(Enemy* removalEnemy) {
	for each (Enemy* e in m_enemies) {
		if (removalEnemy == e) {
			m_enemies.remove(e);
			e->~Enemy();
		}
	}
}