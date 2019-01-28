#include "Menu.h"
#include "Actions.h"
#include "GameFont.h"

bool Menu::menuInit(std::shared_ptr<ASGE::Renderer> tmp_renderer)
{

	menuRenderer = tmp_renderer;

	sprite = menuRenderer->createSprite();
	sprite->position[0] = 700;
	sprite->position[1] = 250;
	if (!sprite->loadTexture("..\\..\\Resources\Textures\Invader.jpg"))
	{
		return false;
	}
}


void Menu::renderMenu()
{
	
	menuRenderer->setFont(GameFont::fonts[0]->id);
	menuRenderer->renderText("Space Invaders", 420, 200, 1.0, ASGE::COLOURS::DARKORANGE);
	//menu
	if (menu_action == MenuState::START_SELECTED)
	{
		menuRenderer->renderText("Start", 420, 300, 1.0, ASGE::COLOURS::ANTIQUEWHITE);
		menuRenderer->renderText("Options", 420, 340, 1.0, ASGE::COLOURS::DARKORANGE);
		menuRenderer->renderText("Exit", 420, 380, 1.0, ASGE::COLOURS::DARKORANGE);
	}

	if (menu_action == MenuState::OPTIONS_SELECTED)
	{
		menuRenderer->renderText("Start", 420, 300, 1.0, ASGE::COLOURS::DARKORANGE);
		menuRenderer->renderText("Options", 420, 340, 1.0, ASGE::COLOURS::ANTIQUEWHITE);
		menuRenderer->renderText("Exit", 420, 380, 1.0, ASGE::COLOURS::DARKORANGE);
	}

	if (menu_action == MenuState::EXIT_SELECTED)
	{
		menuRenderer->renderText("Start", 420, 300, 1.0, ASGE::COLOURS::DARKORANGE);
		menuRenderer->renderText("Options", 420, 340, 1.0, ASGE::COLOURS::DARKORANGE);
		menuRenderer->renderText("Exit", 420, 380, 1.0, ASGE::COLOURS::ANTIQUEWHITE);
	}
}

