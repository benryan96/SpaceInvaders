#include "Game.h"
#include "Actions.h"
#include "Constants.h"
#include "GameFont.h"

#include <Engine/Input.h>
#include <Engine/Keys.h>
#include <Engine/Sprite.h>

/**
*   @brief   Default Constructor.
*/
InvadersGame::InvadersGame()
{

}


/**
*   @brief   Destructor.
*   @details Remove any non-managed memory and callbacks.
*/
InvadersGame::~InvadersGame()
{
	this->inputs->unregisterCallback(callback_id);
}


/**
*   @brief   Initialises the game.
*   @details The game window is created and all assets required to
			 run the game are loaded. The input callback should also
			 be set in the initialise function. 
*   @return  True if the game initialised correctly.
*/
bool InvadersGame::init()
{
	width = WINDOW_WIDTH;
	height = WINDOW_HEIGHT;
	if (!initAPI())
	{
		return false;
	}

	renderer->setWindowTitle("Invaders - Exercise 1");
	renderer->setClearColour(ASGE::COLOURS::BLACK);
	toggleFPS();

	// input callback function
	callback_id = this->inputs->addCallbackFnc(&InvadersGame::input, this);
	
	// load fonts we need
	GameFont::fonts[0] = new GameFont(
		renderer->loadFont("..\\..\\Resources\\Fonts\\Comic.ttf", 42), "default", 42);

	renderer->setFont(GameFont::fonts[0]->id);
	renderer->renderText("Space Invaders", 420, 200, 1.0, ASGE::COLOURS::DARKORANGE);
	
	menu = std::make_unique<Menu>();
	menu->menuInit(renderer);

	player = std::make_unique<Player>();
	player->playerInit(renderer);

	bullet = std::make_unique<Bullet>();
	bullet->bulletInit(renderer);

	/*enemy = std::make_unique<Enemy>();
	enemy->enemyInit(renderer);*/

	for (int i = 0; i < 55; i++)
	{
		enemy.push_back(std::make_unique<Enemy>());
		if (i > 1)
		{
			if (i % 11 == 0)
			{
				enemyPosX += 55;
				enemyPosY = 25;
			}
		}
		enemy[i]->enemyInit(renderer, enemyPosY, enemyPosX);
		enemyPosY += 50;
	}

	if (GameFont::fonts[0]->id == -1)
	{
		return false;
	}

	// load space invader sprite
	sprite = renderer->createSprite();


	return true;
}


/**
*   @brief   The main game loop. 
*   @details The main loop should be responsible for updating the game
			 and rendering the current scene. Runs until the shouldExit
			 signal is received.
*   @return  True if the game ran correctly. 
*/
bool InvadersGame::run()
{
	while (!shouldExit())
	{
		processGameActions();
		render();
	}

	return true;
}


/**
*   @brief   Should the game exit?
*   @details Has the renderer terminated or the game requesting to exit?
*   @return  True if the game should exit
*/
bool InvadersGame::shouldExit() const
{
	return (renderer->exit() || this->exit);
}


/**
*   @brief   Renders the scene
*   @details Prepares the renderer subsystem before drawing the 
			 current frame. Once the current frame is has finished
			 the buffers are swapped accordingly and the image shown.
*   @return  void
*/
void InvadersGame::render()
{
	beginFrame();
	drawFrame();
	endFrame();
}


/**
*   @brief   Renderers the contents for this frame 
*   @details All game objects that need rendering should be done
			 in this function, as it ensures they are completed
			 before the buffers are swapped.
*   @return  void
*/
void InvadersGame::drawFrame()
{
	if (game_state == GameState::MENU)
	{
		menu->renderMenu();		
	}
	if (game_state == GameState::GAME)
	{
		player->renderPlayer();
 		if (bullet_state == BulletState::SHOOT)
		{
			if (!bullet)
			{
				bullet = std::make_unique<Bullet>();
				bullet->bulletInit(renderer);
			}

			bullet->setBulletXPos(player->getX());

			bullet->renderBullet();
		}

		if (bullet_state == BulletState::END)
		{
			bullet.reset();
			bullet_state = BulletState::IDLE;
		}

		/*if (enemyPosX == 1170)
		{
			enemy_state = EnemyState::GODOWN;
		}*/

		for (int i = 0; i < 55; i++)
		{
			if (enemy[i])
			{
				enemy[i]->renderEnemy();
				/*if (enemy[i]->getEnemyX() >= 1170)
				{
					enemy_state = EnemyState::GORIGHT;
				}
				if (enemy[i]->getEnemyX() <= 9)
				{
					enemy_state = EnemyState::GOLEFT;
				}*/
			}
			
		}
		/*if (enemyPosX >= 1170)
		{
			enemy_state = EnemyState::GORIGHT;
		}
		if (enemyPosX <= 9)
		{
			enemy_state = EnemyState::GOLEFT;
		}*/
		
		//Render Enemy
		//Render Barriers
	}
	if (game_state == GameState::OPTIONS)
	{

	}

	sprite->render(renderer);
}


/**
*   @brief   Processes any key inputs and translates them to a GameAction
*   @details This function is added as a callback to handle the game's 
			 input. Key presseses are translated in to GameActions which 
			 are then processed by the main game loop.
*   @param   key is the key the action relates to
*   @param   action whether the key was released or pressed
*   @return  void
*/
void InvadersGame::input(int key, int action) const
{
	if (action == ASGE::KEYS::KEY_PRESSED)
	{
		if (key == ASGE::KEYS::KEY_ESCAPE)
		{
			game_action = GameAction::EXIT;
		}

		//Menu Navigations

		if (game_state == GameState::MENU)
		{
			if (key == ASGE::KEYS::KEY_S)
			{
				if (menu_action == MenuState::START_SELECTED)
				{
					menu_action = MenuState::OPTIONS_SELECTED;
					return;
				}
				if (menu_action == MenuState::OPTIONS_SELECTED)
				{
					menu_action = MenuState::EXIT_SELECTED;
					return;
				}
				if (menu_action == MenuState::EXIT_SELECTED)
				{
					menu_action = MenuState::START_SELECTED;
					return;
				}
			}
			if (key == ASGE::KEYS::KEY_W)
			{
				if (menu_action == MenuState::START_SELECTED)
				{
					menu_action = MenuState::EXIT_SELECTED;
					return;
				}
				if (menu_action == MenuState::EXIT_SELECTED)
				{
					menu_action = MenuState::OPTIONS_SELECTED;
					return;
				}
				if (menu_action == MenuState::OPTIONS_SELECTED)
				{
					menu_action = MenuState::START_SELECTED;
					return;
				}
			}
			if (key == ASGE::KEYS::KEY_ENTER)
			{
				if (menu_action == MenuState::START_SELECTED)
				{
					game_state = GameState::GAME;
					return;
				}
				if (menu_action == MenuState::OPTIONS_SELECTED)
				{
					game_state = GameState::OPTIONS;
					return;
				}
				if (menu_action == MenuState::EXIT_SELECTED)
				{
					game_action = GameAction::EXIT;
				}
			}
		}

		//Player Action
		if (game_state == GameState::GAME)
		{
			if (key == ASGE::KEYS::KEY_A)
			{
				player_state = PlayerState::MOVELEFT;
			}
			if (key == ASGE::KEYS::KEY_D)
			{
				player_state = PlayerState::MOVERIGHT;
			}
			if (key == ASGE::KEYS::KEY_P)
			{
				player_state = PlayerState::PAUSE;
			}
			if (key == ASGE::KEYS::KEY_SPACE)
			{
				bullet_state = BulletState::SHOOT;
			}
		}
	}
	if (action == ASGE::KEYS::KEY_RELEASED && key == ASGE::KEYS::KEY_A)
	{
		player_state = PlayerState::IDLE;
	}
	if (action == ASGE::KEYS::KEY_RELEASED && key == ASGE::KEYS::KEY_D)
	{
		player_state = PlayerState::IDLE;
	}
}


/**
*   @brief   Processes the next game action
*   @details Uses the game action that was a direct result of 
*            user input. It allows input to processed in a different
             thread and the game actions performed in the main thread. 
*   @return  void
*/
void InvadersGame::processGameActions()
{
	if (game_action == GameAction::EXIT)
	{
		this->exit = true;
	}
	
	game_action = GameAction::NONE;
}
