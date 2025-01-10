#include "../../include/Level/LevelView.h"
#include "../../include/Global/ServiceLocator.h"

namespace Level
{
	LevelView::LevelView()
	{
		createViews();
	}

	LevelView::~LevelView()
	{
		destroy();
	}

	void LevelView::initialize()
	{
		initializeBackground();
		initializeBorder();
		calculateGridExtents();
	}

	void LevelView::update()
	{

	}

	void LevelView::render()
	{

	}

	void LevelView::createViews()
	{
		background_rectangle = new UI::UIElement::RectangleShapeView();
		border_rectangle = new UI::UIElement::RectangleShapeView();
	}

	void LevelView::initializeBorder()
	{
		sf::RenderWindow* game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		sf::Vector2f border_size = sf::Vector2f(grid_width, grid_height);
		sf::Vector2f border_position = sf::Vector2f(border_offset_left, border_offset_top);

		border_rectangle->initialize(border_size, border_position, border_thickness,sf::Color::Transparent, border_color);
		border_rectangle->show();
	}

	void LevelView::initializeBackground()
	{
		sf::RenderWindow* game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		sf::Vector2f background_size = sf::Vector2f(game_window->getSize().x, game_window->getSize().y);

		background_rectangle->initialize(background_size, sf::Vector2f(0, 0), 0, background_color);
		background_rectangle->show();
	}

	float LevelView::getGridWidth()
	{
		return grid_width;
	}

	float LevelView::getGridHeight()
	{
		return grid_height;
	}

	void LevelView::destroy()
	{
		delete(background_rectangle);
	}
}
