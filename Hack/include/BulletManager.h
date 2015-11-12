#pragma once
#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H

#include <list>
#include "Bullet.h"

class BulletManager {
private:
	static bool instanceFlag;

	BulletManager::BulletManager() { 
	
	}
public:
	static BulletManager* BulletManager::getInstance() {

	}
	void BulletManager::Update() {

	}
	void BulletManager::add(Bullet bullet) {
		//bullets.add(new Bullet(x,y, world));
	}
	BulletManager::~BulletManager() {
		instanceFlag = false;
	}
};

#endif