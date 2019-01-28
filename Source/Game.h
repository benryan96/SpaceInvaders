#pragma once
#include <Engine/OGLGame.h>
#include <string>
#include <memory>
#include <vector>
#include <stdlib.h>
#include "Menu.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"


struct GameFont;

/**
*  Invaders Game. An OpenGL Game based on ASGE.
*/

class InvadersGame:
	public ASGE::OGLGame
{
public:
	InvadersGame();
	~InvadersGame();

	// Inherited via Game
	virtual bool run() override;
	bool shouldExit() const;
	void render();
	

	// Inherited via OGLGame
	virtual bool init();
	virtual void drawFrame();

private:
	void processGameActions(); 
	void input(int key, int action) const;

	int enemyPosX = 10;
	int enemyPosY = 10;

	int  callback_id = -1;                             /**< Input Callback ID. The callback ID assigned by the game engine. */
	bool exit = false;                                 /**< Exit boolean. If true the game loop will exit. */
	std::unique_ptr<ASGE::Sprite> sprite = nullptr;    /**< Sprite Object. The space invader sprite. */
	std::unique_ptr<Menu> menu = nullptr;
	std::unique_ptr<Player> player = nullptr;
	std::unique_ptr<Bullet> bullet = nullptr;
	//std::unique_ptr<Enemy> enemy = nullptr;
	std::vector<std::unique_ptr<Enemy>> enemy;
};

