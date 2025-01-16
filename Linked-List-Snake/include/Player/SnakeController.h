#pragma once
#include <Graphics/GraphicService.h>
#include "./Player/Direction.h"
#include "../LinkedList/SingleLinkedList.h"

namespace Player
{
	enum class SnakeState
	{
		ALIVE,
		DEAD
	};

	class SnakeController
	{
	private:
		const int initial_snake_length = 10;
		SnakeState current_snake_state;
		LinkedList::SingleLinkedList* single_linked_list;

		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;
		Direction current_snake_direction;

		void createLinkedList();
		void destroy();

	public:
		SnakeController();
		~SnakeController();
		
		void initialize();
		void update();
		void render();

		void spawnSnake();
		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void handleRestart();
		void reset();
		void respawnSnake();
		void setSnakeState(SnakeState state);

		SnakeState getSnakeState();
	};
}