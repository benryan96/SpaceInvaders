#pragma once
#include <Engine\Renderer.h>
#include <Engine\Sprite.h>
#include <string>

class Menu 
{
public:
	void renderMenu();
	bool menuInit(std::shared_ptr<ASGE::Renderer> tmp_renderer);
private:
	std::shared_ptr<ASGE::Renderer> menuRenderer = nullptr;
	std::unique_ptr<ASGE::Sprite> sprite = nullptr;
};