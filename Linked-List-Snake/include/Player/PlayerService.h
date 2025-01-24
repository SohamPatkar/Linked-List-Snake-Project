#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Level/LevelConfig.h"

namespace Player
{
	class SnakeController;
	enum class LinkedListOperations;
	enum class TimeComplexity;

	class PlayerService
	{
	private:
		SnakeController* snake_controller;

		void createController();
		void destroy();
	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();

		LinkedListOperations getLinkedListOperation();
		TimeComplexity getTimeComplexity();
		int getPlayerScore();
		std::vector<sf::Vector2i> getCurrentSnakePositionList();

		void spawnPlayer(Level::LinkedListType level_type);
	};
}