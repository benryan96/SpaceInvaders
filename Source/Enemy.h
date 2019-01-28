#pragma once

#include <Engine\Renderer.h>
#include <Engine\Sprite.h>
#include <string>
#include <memory>

class Enemy
{
public:
	Enemy() = default;
	~Enemy() = default;

	bool enemyInit(std::shared_ptr<ASGE::Renderer> tmp_renderer, int enemyPosY, int enemyPosX);
	void renderEnemy();
	void goLeft();
	void goRight();
	float getEnemyX();

protected:

	int downCheck;
	bool goneDownLeft = false;
	bool goneDownRight = false;
	int enemyPosX2;
	int enemyPosY2;

	std::shared_ptr<ASGE::Renderer> enemyRenderer = nullptr;
	std::unique_ptr<ASGE::Sprite> enemySprite = nullptr;
};