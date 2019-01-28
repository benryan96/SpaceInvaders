#include "Actions.h"
#include "Player.h"
#include "Constants.h"

bool Player::playerInit(std::shared_ptr<ASGE::Renderer> tmp_renderer)
{
	playerRenderer = tmp_renderer;

	sprite = playerRenderer->createSprite();

	sprite->position[0] = 600;
	sprite->position[1] = 615;

	if (!sprite->loadTexture("..\\..\\Resources\\Textures\\SpaceShip.png"))
	{
		return false;
	}
}

void Player::renderPlayer()
{
	if (player_state == PlayerState::IDLE)
	{
		sprite->render(playerRenderer);
	}

	if (player_state == PlayerState::MOVELEFT || sprite->position[0] >= 1170)
	{
		sprite->position[0] -= 10;
		sprite->render(playerRenderer);
	}

	if (player_state == PlayerState::MOVERIGHT || sprite->position[0] <= 10)
	{
		sprite->position[0] += 10;
		sprite->render(playerRenderer);
	}
}

float Player::getX()
{
	return sprite->position[0];
}