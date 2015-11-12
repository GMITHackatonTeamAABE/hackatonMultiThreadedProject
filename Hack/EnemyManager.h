#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <include\Enemy.h>
#include <list>

class EnemyManager {
public:
	static EnemyManager* GetInstance();
	~EnemyManager();
	bool Init();
	void Draw();
	void AddEnemy(float xPos, float yPos, b2World* physicsWorld);
	void RemoveEnemy(Enemy* removalEnemy);
private:
	EnemyManager::EnemyManager() {}
	static EnemyManager* instance;
	static bool instanceFlag;
	std::list<Enemy*> m_enemies;
	
};

#endif