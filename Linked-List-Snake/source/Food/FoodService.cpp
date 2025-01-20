#include "../../include/Food/FoodService.h"
#include "../../include/Food/FoodItem.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Food/FoodType.h"

namespace Food
{
	using namespace Global;

	FoodService::FoodService()
	{
		current_food_item = nullptr;
	}

	FoodService::~FoodService()
	{
		if (current_food_item) 
		{
			delete(current_food_item);
		}
	}

	void FoodService::initialize()
	{

	}

	void FoodService::update()
	{
		if (current_food_item)
		{
			current_food_item->update();
		}
	}

	void FoodService::render()
	{
		if (current_food_item)
		{
			current_food_item->render();
		}
	}

	void FoodService::startFoodSpawning()
	{
		float cell_width = ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		float cell_height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		spawnFood();
	}

	FoodItem* FoodService::createFood(sf::Vector2i position, FoodType type)
	{
		FoodItem* food = new FoodItem();
		food->initialize(position, cell_width, cell_height, type);
		return food;
	}

	void FoodService::spawnFood()
	{
		current_food_item = createFood(sf::Vector2i(4, 6), FoodType::BURGER);
	}

}