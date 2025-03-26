#pragma once
#include <Graphics/GraphicService.h>
#include "./Player/Direction.h"
#include "../LinkedList/SingleLinkedList.h"
#include "../../include/Food/FoodType.h"

namespace Player
{
	using namespace Food;

	enum class InputState
	{
		WAITING,
		PROCESSING
	};

	enum class SnakeState
	{
		ALIVE,
		DEAD
	};

	enum class TimeComplexity
	{
		NONE,
		ONE,
		N,
	};

	enum class LinkedListOperations
	{
		NONE,
		INSERT_AT_HEAD,
		INSERT_AT_TAIL,
		INSERT_AT_MID,
		REMOVE_AT_HEAD,
		REMOVE_AT_TAIL,
		REMOVE_AT_MID,
		DELETE_HALF_LIST,
		REVERSE_LIST,
	};

	class SnakeController
	{
	private:
		const int initial_snake_length = 10;
		SnakeState current_snake_state;
		LinkedList::SingleLinkedList* single_linked_list;

		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::LEFT;
		const float movement_frame_duration = 0.1f;
		float elapsed_duration = 0.f;
		const float restart_duration = 2.f;
		float restart_counter = 0.f;
		InputState current_input_state;
		Direction current_snake_direction;
		TimeComplexity time_complexity;
		LinkedListOperations last_linked_list_operation;

		int player_score;

		void createLinkedList();
		void delayedUpdate();
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
		void processBodyCollisions();
		void processElementCollisions();
		void processFoodCollision();
		void OnFoodCollected(FoodType food_type);
		void handleRestart();
		void reset();
		void respawnSnake();
		void setSnakeState(SnakeState state);

		LinkedListOperations getLinkedListOperation();
		TimeComplexity getTimeComplexity();
		int getPlayerScore();
		std::vector<sf::Vector2i> getCurrentSnakePositionList();

		SnakeState getSnakeState();
	};
}