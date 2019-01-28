#include "Enemy.h"
#include "Actions.h"
#include "Player.h"
#include "Constants.h"

bool Enemy::enemyInit(std::shared_ptr<ASGE::Renderer> tmp_renderer, int enemyPosX, int enemyPosY)
{
	enemyRenderer = tmp_renderer;

	enemySprite = enemyRenderer->createSprite(); 

	enemySprite->position[0] = enemyPosX;
	enemySprite->position[1] = enemyPosY;

	enemyPosX2 = enemyPosX;
	enemyPosY2 = enemyPosY;

	if (!enemySprite->loadTexture("..\\..\\Resources\\Textures\\Enemy.png"))
	{
		return false;
	}
}

void Enemy::renderEnemy()
{ 
	//bool have I gone down, initally no (do this in the .h
	enemySprite->render(enemyRenderer);
	if (enemy_state == EnemyState::GORIGHT)
	{
		goRight();
			if (enemySprite->position[0] >= 1170 && goneDownRight == false /* and have I gone down already*/)
			{
				enemy_state = EnemyState::GODOWN;
				
				goneDownRight = true;
			}
			
		//Now I have NOT gone down
	}

	else if (enemy_state == EnemyState::GOLEFT)
	{
		goLeft();
			if (enemySprite->position[0] <= 10 && goneDownLeft == false /* and have I gone down already*/)
			{
				enemy_state = EnemyState::GODOWN;
				
				goneDownLeft = true;
			}
		
		//Now I have NOT gone down
	}
	
	else if (enemy_state == EnemyState::GODOWN)
	{
		
		
		//goneDown = true;
		if (downCheck < 20)
		{	
			//enemySprite->render(enemyRenderer);
			enemySprite->position[1] += 30;
			downCheck += 10;
		}
		else if (goneDownLeft == true)
		{
			enemy_state = EnemyState::GORIGHT;
			goneDownRight = false;
			downCheck = 0;
		}
		else if (goneDownRight == true)
		{
			enemy_state = EnemyState::GOLEFT;
			goneDownLeft = false;
			downCheck = 0;
		}
		//Now I HAVE gone down
		
		//if (enemySprite->position[0] <= 9 /*&& /*goneDown == true*/ /* and have I gone down already*/)
		//{
		//	enemy_state = EnemyState::GORIGHT;
		//}
		//if (enemySprite->position[0] >= 1170 /*&& /*goneDown == true*//* and have I gone down already*/)
		//{
		//	enemy_state = EnemyState::GOLEFT;
		//}
		//enemy_state = EnemyState::GOLEFT;

	}
}

void Enemy::goLeft()
{
	enemySprite->position[0] -= 10;
	//enemySprite->render(enemyRenderer);
}

void Enemy::goRight()
{
	enemySprite->position[0] += 10;
	//enemySprite->render(enemyRenderer);
	/*if (enemyPosX2)
	{

	}*/

}

float Enemy::getEnemyX()
{
	return enemySprite->position[0];
}