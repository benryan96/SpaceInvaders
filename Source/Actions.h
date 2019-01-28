#pragma once
#include <string>
#include <atomic>

/** @file Actions.h
    @brief   Actions file defines a thread safe game action
    @details GameActions are stored here as well as a thread safe  
             GameAction variable, which has external linkage. 
*/


/** @enum GameAction
*   @brief is a strongly typed enum class representing the next game action
*/
enum class GameAction
{
	INVALID = -1,  /**< is a non-valid game action */
	NONE    =  0,  /**< means no outstanding action to process */
	EXIT           /**< signals the intention to exit the game */
};

enum class MenuState
{
	START_SELECTED,
	OPTIONS_SELECTED,
	EXIT_SELECTED
};

enum class GameState
{
	MENU,
	GAME,
	OPTIONS
};

enum class PlayerState
{
	IDLE,
	MOVERIGHT,
	MOVELEFT,
	PAUSE
};

enum class BulletState
{
	END,
	IDLE,
	SHOOT
};

enum class EnemyState
{
	GORIGHT,
	GOLEFT,
	GODOWN,
	SHOOT
};

enum class EnemyTransitionState
{
	WASRIGHT,
	WASLEFT
};

extern std::atomic<PlayerState> player_state;
extern std::atomic<GameAction> game_action;
extern std::atomic<MenuState> menu_action;
extern std::atomic<GameState> game_state;
extern std::atomic<BulletState> bullet_state;
extern std::atomic<EnemyState> enemy_state;
extern std::atomic<EnemyTransitionState> enemy_trans_state;