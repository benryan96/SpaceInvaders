#include "Actions.h"

/**< Queued Game Action. The next action to be processed as determined by user input. */
std::atomic<GameAction> game_action = GameAction::NONE;
std::atomic<MenuState> menu_action = MenuState::START_SELECTED;
std::atomic<GameState> game_state = GameState::MENU;
std::atomic<PlayerState> player_state = PlayerState::IDLE;
std::atomic<BulletState> bullet_state = BulletState::IDLE;
std::atomic<EnemyState> enemy_state = EnemyState::GORIGHT;
std::atomic<EnemyTransitionState> enemy_trans_state = EnemyTransitionState::WASRIGHT;