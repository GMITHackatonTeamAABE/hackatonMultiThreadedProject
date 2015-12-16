#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(SDL_Texture* texture);
	~Player();
	void Initialize(const GameObjectParameters*) override; 
	void Render(SDL_Renderer* renderer) override;
	void Update() override;
	void CleanUp() override;

	enum Direction {
		NONE,
		NORTH,
		SOUTH,
		EAST,
		WEST
	};

	void Move(Direction dir);

private:
	Direction mDirection;
};
#endif
