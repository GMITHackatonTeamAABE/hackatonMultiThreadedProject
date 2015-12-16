#include "Player.h"

Player::Player(SDL_Texture* texture)
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
	//DEBUG_MSG("Player Updating");
	switch (mDirection)
	{
	case NORTH:
		SetY(GetY() - 0.01f);
		break;
	case SOUTH:
		SetY(GetY() + 0.01f);
		break;
	case EAST:
		SetX(GetX() + 0.01f);
		break;
	case WEST:
		SetX(GetX() - 0.01f);
		break;

	case NONE:
	default:
		break;
	}
}

void Player::CleanUp()
{
	DEBUG_MSG("Cleaning Up Player");
}

void Player::Move(Direction dir) {
	mDirection = dir;
}
