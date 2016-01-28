#include "Player.h"

Player::Player(SDL_Texture* texture) :
instructions(),
semaphore(SDL_CreateSemaphore(0)),
UP(0x01),
RIGHT(0x10),
DOWN(0x02),
LEFT(0x20),
awake(true)
{
	DEBUG_MSG("Constructing Player");
	mTexture = texture;
	mDestination = mSource = SDL_Rect{ 0, 0, 32, 32 };
}

Player::~Player()
{
	DEBUG_MSG("Destructing Player");
}

void Player::Initialize(const GameObjectParameters* params)
{
	DEBUG_MSG("Player Initializing");
	SetX(params->GetX());
	SetY(params->GetY());
}

void Player::Render(SDL_Renderer* renderer)
{
	//DEBUG_MSG("Player Drawing");
	SDL_RenderCopy(renderer, mTexture, &mSource, &mDestination);
}

void Player::Update()
{
	if (awake) {
		SDL_SemWait(semaphore);	//wait for semaphore to be positive
		DEBUG_MSG("sem");
		unsigned char direction;	//direction to travel in
		{
			//lock_guard<mutex> lock(mMutex);	//lock (scoped) mutex for std::list manipulation
			_ASSERT(instructions.size() > 0);	//if we're here it means the semaphore is positive, so the size of the list should also be positive
			direction = *instructions.begin();
			instructions.pop_front();
		}

		//check if we should move vertically
		if (direction & UP) {
			SetY(GetY() - 5.f);
		}
		else if (direction & DOWN) {
			SetY(GetY() + 5.f);
		}

		//check if we should move horizontally
		if (direction & LEFT) {
			SetX(GetX() - 5.f);
		}
		else if (direction & RIGHT) {
			SetX(GetX() + 5.f);
		}

		//printf("X: %f, Y: %f", GetX(), GetY());
	}

}

void Player::CleanUp()
{
	DEBUG_MSG("Cleaning Up Player");
}

void Player::Sleep() {
	awake = false;
}

void Player::Wake() {
	awake = true;
}

bool Player::IsAwake() const {
	return awake;
}

void Player::Instruct(const unsigned char direction) {
	//lock_guard<mutex> lock(mMutex);	//lock (scoped) mutex for std::list manipulation
	instructions.push_back(direction);
	SDL_SemPost(semaphore);	//increment semaphore because we pushed a new direction into the instruction list
}


