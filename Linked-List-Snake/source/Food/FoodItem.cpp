#include "../../include/Food/FoodItem.h"
#include "../../include/Food/FoodType.h"
#include "../../include/Global/Config.h"
#include "../../include/Level/LevelView.h"

namespace Food
{
	using namespace Global;
	using namespace Level;
	using namespace UI::UIElement;

	FoodItem::FoodItem()
	{
		food_image = new ImageView();
	}

	FoodItem::~FoodItem()
	{
		delete(food_image);
	}

	sf::String FoodItem::getFoodTexturePath()
	{
		switch (food_type)
		{
		case FoodType::ALCOHOL:
			return Config::alcohol_texture_path;
			break;

		case FoodType::APPLE:
			return Config::apple_texture_path;
			break;

		case FoodType::BURGER:
			return Config::burger_texture_path;
			break;

		case FoodType::CHEESE:
			return Config::cheese_texture_path;
			break;

		case FoodType::MANGO:
			return Config::mango_texture_path;
			break;

		case FoodType::ORANGE:
			return Config::orange_texture_path;
			break;

		case FoodType::PIZZA:
			return Config::pizza_texture_path;
			break;

		case FoodType::POISION:
			return Config::poision_texture_path;
			break;
		}
	}

	sf::Vector2f FoodItem::getGridPosition()
	{
		float screen_position_x = LevelView::border_offset_left + (cell_width * grid_position.x);
		float screen_position_y = LevelView::border_offset_top + (cell_height * grid_position.y);

		return sf::Vector2f(screen_position_x, screen_position_y);
	}

	void FoodItem::initializeFoodImage()
	{
		sf::String food_texture_path = getFoodTexturePath();
		sf::Vector2f screen_position = getGridPosition();

		food_image->initialize(food_texture_path, cell_width, cell_height, screen_position);
		food_image->show();
	}

	FoodType FoodItem::getFoodType()
	{
		return food_type;
	}

	void FoodItem::initialize(sf::Vector2i grid_pos, float width, float height, FoodType type)
	{
		grid_position = grid_pos;
		cell_width = width;
		cell_height = height;
		food_type = type;

		initializeFoodImage();
	}

	void FoodItem::update()
	{

	}

	void FoodItem::render()
	{

	}
}