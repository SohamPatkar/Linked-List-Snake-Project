#pragma once
#include <SFML/Graphics.hpp>
#include <random>

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

		std::default_random_engine random_engine;
		std::random_device random_device;

	public:
		FoodService();
		~FoodService();

		void initialize();
		void update();
		void render();

		void startFoodSpawning();
		void spawnFood();
		bool isValidPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position);
		FoodType getRandomFoodType();
		sf::Vector2i getValidSpawnPosition();
		sf::Vector2i getRandomPosition();
		FoodItem* createFood(sf::Vector2i position, FoodType type);
		
	};
}