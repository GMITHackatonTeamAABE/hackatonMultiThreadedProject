#ifndef PLAYER_H
#define PLAYER_H

#include <list>
#include "GameObject.h"

typedef const unsigned char Direction;	//bitfield

class Player : public GameObject
{
public:
	Player(SDL_Texture* texture);
	~Player();
	void Initialize(const GameObjectParameters*) override; 
	void Render(SDL_Renderer* renderer) override;
	void Update() override;
	void CleanUp() override;

	void Sleep();
	void Wake();
	bool IsAwake() const;
	atomic<bool> awake;

	const Direction UP, DOWN, LEFT, RIGHT;

	void Instruct(Direction direction);

private:
	list<Direction> instructions;
	SDL_sem* semaphore;
};
#endif
