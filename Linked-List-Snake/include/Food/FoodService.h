#pragma once
#include <SFML/Graphics.hpp>

namespace Food
{
	class FoodItem;
	enum class FoodType;

	class FoodService
	{
	private:
		FoodItem* current_food_item;

		float cell_width;
		float cell_height;

		
	public:
		FoodService();
		~FoodService();

		void initialize();
		void update();
		void render();

		void startFoodSpawning();
		void spawnFood();
		FoodItem* createFood(sf::Vector2i position, FoodType type);
		
	};
}