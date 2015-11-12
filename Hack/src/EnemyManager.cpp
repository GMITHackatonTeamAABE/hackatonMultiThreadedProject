#include <include/EnemyManager.h>

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
	
}

void EnemyManager::AddEnemy(float xPos, float yPos, b2World* physicsWorld) {
	
	m_enemies.push_back(new Enemy(xPos, yPos, physicsWorld));
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

void EnemyManager::Update() {
	for each (Enemy* e in m_enemies) {
		e->update();
	}
}