#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include "../../include/Food/FoodType.h"
#include "../../include/Food/FoodItem.h"
#include "../../include/LinkedList/Node.h"

namespace Food
{
	enum FoodSpawningStatus
	{
		ACTIVE,
		IN_ACTIVE,
	};

	class FoodService
	{
	private:
		FoodItem* current_food_item;
		FoodSpawningStatus current_spawning_status;

		float cell_width;
		float cell_height;

		std::default_random_engine random_engine;
		std::random_device random_device;

		const float spawn_duration = 4.f;
		float elapsed_duration;

		
		void handleFoodSpawning();
		void updateElapsedDuration();

	public:
		FoodService();
		~FoodService();

		void initialize();
		void update();
		void render();
		void reset();
		
		void destroyFood();
		bool processFoodCollisions(LinkedList::Node* head_node, FoodType& out_food_type);
		void startFoodSpawning();
		void stopFoodSpawning();
		void spawnFood();
		bool isValidPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position);
		FoodType getRandomFoodType();
		sf::Vector2i getValidSpawnPosition();
		sf::Vector2i getRandomPosition();

		FoodItem* createFood(sf::Vector2i position, FoodType type);
	};
}