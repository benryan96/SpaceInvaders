#pragma once

#include <Engine\Renderer.h>
#include <Engine\Sprite.h>
#include <string>

class Player
{
public:

	Player() = default;
	~Player() = default;

	bool playerInit(std::shared_ptr<ASGE::Renderer> tmp_renderer);
	void renderPlayer();
	float getX();

protected:
	std::shared_ptr<ASGE::Renderer> playerRenderer = nullptr;
	std::shared_ptr<ASGE::Sprite> sprite = nullptr;
};