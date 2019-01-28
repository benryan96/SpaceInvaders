#pragma once

#include <Engine\Renderer.h>
#include <Engine\Sprite.h>
#include <string>

class Bullet
{
public:
	Bullet() = default;
	~Bullet() = default;

	bool bulletInit(std::shared_ptr<ASGE::Renderer> tmp_renderer);
	void renderBullet();
	void setBulletXPos(float playerX);

protected:

	std::shared_ptr<ASGE::Renderer> bulletRenderer = nullptr;
	std::unique_ptr<ASGE::Sprite> bulletSprite = nullptr;
};