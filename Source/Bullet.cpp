#include "Actions.h"
#include "Player.h"
#include "Constants.h"
#include "Bullet.h"


bool Bullet::bulletInit(std::shared_ptr<ASGE::Renderer> tmp_renderer)
{
	bulletRenderer = tmp_renderer;

	bulletSprite = bulletRenderer->createSprite();

	bulletSprite->position[1] = 590;

	if (!bulletSprite->loadTexture("..\\..\\Resources\\Textures\\Projectile.png"))
	{
		return false;
	}
}

void Bullet::renderBullet()
{
	if (bullet_state == BulletState::SHOOT)
	{
		bulletSprite->render(bulletRenderer);
		bulletSprite->position[1] -= 20;
	}
	if (bulletSprite->position[1] <= 0)
	{
		bullet_state = BulletState::END;
	}
}

void Bullet::setBulletXPos(float playerX)
{
	if (bulletSprite->position[1] >= 590)
	{
		float playerX2 = playerX + 35;
		bulletSprite->position[0] = playerX2;
	}
}
