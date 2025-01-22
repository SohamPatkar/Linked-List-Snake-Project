#include "../../include/Player/SnakeController.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Event/EventService.h"
#include "../../include/Element/ElementService.h"
#include "../../include/Food/FoodService.h"


namespace Player
{
	using namespace Element;
	using namespace Food;

	SnakeController::SnakeController()
	{
		single_linked_list = nullptr;

		createLinkedList();
	}

	SnakeController::~SnakeController()
	{
		destroy();
	}

	void SnakeController::spawnSnake()
	{
		for (int i = 0; i < initial_snake_length; i++) 
		{
			single_linked_list->insertNodeAtTail();     
		}
	}

	void SnakeController::setSnakeState(SnakeState state)
	{
		current_snake_state = state;
	}

	SnakeState SnakeController::getSnakeState()
	{
		return current_snake_state;
	}

	void SnakeController::initialize()
	{
		float width = Global::ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		float height = Global::ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		single_linked_list->initialize(width, height, default_position, default_direction);
	}

	void SnakeController::update()
	{	
		switch (current_snake_state)
		{
		case SnakeState::ALIVE:
			processPlayerInput();
			delayedUpdate();
			break;

		case SnakeState::DEAD:
			handleRestart();
			break;
		}
	}

	void SnakeController::render()
	{
		single_linked_list->render();
	}

	void SnakeController::delayedUpdate()
	{
		elapsed_duration += Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (elapsed_duration >= movement_frame_duration)
		{
			elapsed_duration = 0.f;
			updateSnakeDirection();
			processSnakeCollision();

			if (getSnakeState() == SnakeState::ALIVE)
			{
				moveSnake();
			}

			current_input_state = InputState::WAITING;
		}
	}

	void SnakeController::createLinkedList()
	{
		single_linked_list = new LinkedList::SingleLinkedList();
	}

	void SnakeController::destroy()
	{
		delete (single_linked_list);
	}

	void SnakeController::moveSnake()
	{
		single_linked_list->updateNodePosition();
	}

	void SnakeController::processPlayerInput()
	{
		if (current_input_state == InputState::PROCESSING)
		{
			return;
		}

		Event::EventService* event_service = Global::ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedUpArrowKey() && current_snake_direction != Direction::DOWN)
		{
			current_snake_direction = Direction::UP;
			current_input_state == InputState::PROCESSING;
		}
		else if (event_service->pressedDownArrowKey() && current_snake_direction != Direction::UP)
		{
			current_snake_direction = Direction::DOWN;
			current_input_state == InputState::PROCESSING;
		}
		else if (event_service->pressedLeftArrowKey() && current_snake_direction != Direction::RIGHT)
		{
			current_snake_direction = Direction::LEFT;
			current_input_state == InputState::PROCESSING;
		}
		else if (event_service->pressedRightArrowKey() && current_snake_direction != Direction::LEFT)
		{
			current_snake_direction = Direction::RIGHT;
			current_input_state == InputState::PROCESSING;
		}
	}

	void SnakeController::processSnakeCollision()
	{
		processBodyCollisions();
		processElementCollisions();
		processFoodCollision();
	}

	void SnakeController::processBodyCollisions()
	{
		if (single_linked_list->processNodeCollision())
		{
			setSnakeState(SnakeState::DEAD);
			Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
		}
	}

	void SnakeController::processElementCollisions()
	{
		ElementService* element_service = Global::ServiceLocator::getInstance()->getElementService();

		if (element_service->processElementCollisions(single_linked_list->getHeadNode()))
		{
			current_snake_state = SnakeState::DEAD;
			Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
		}
	}

	void SnakeController::processFoodCollision()
	{
		FoodService* food_service = Global::ServiceLocator::getInstance()->getFoodService();
		FoodType food_type;

		if (food_service->processFoodCollisions(single_linked_list->getHeadNode(), food_type))
		{
			Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);

			food_service->destroyFood();
			OnFoodCollected(food_type);
		}
	}

	void SnakeController::OnFoodCollected(FoodType food_type)
	{
		switch (food_type)
		{
		case FoodType::PIZZA:
			single_linked_list->insertNodeAtTail();
			break;

		case FoodType::BURGER:
			single_linked_list->insertNodeAtHead();
			break;

		case FoodType::CHEESE:
			single_linked_list->insertNodeAtMiddle();
			break;

		case FoodType::APPLE:
			single_linked_list->insertNodeAtHead();
			break;

		case FoodType::MANGO:
			single_linked_list->insertNodeAtMiddle();
			break;

		case FoodType::ORANGE:
			single_linked_list->insertNodeAtTail();
			break;

		case FoodType::POISION:
			single_linked_list->removeHalfNodes();
			break;

		case FoodType::ALCOHOL:
			current_snake_direction = single_linked_list->reverse();
			break;
		}
	}

	void SnakeController::handleRestart()
	{
		restart_counter += Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (restart_counter >= restart_duration)
		{
			respawnSnake();
		}
	}

	void SnakeController::reset()
	{
		current_snake_state = SnakeState::ALIVE;
		current_snake_direction = default_direction;
		elapsed_duration = 0.f;
		restart_counter = 0.f;
		current_input_state = InputState::WAITING;
	}
	
	void SnakeController::updateSnakeDirection()
	{
		single_linked_list->updateNodeDirection(current_snake_direction);
	}

	void SnakeController::respawnSnake()
	{
		single_linked_list->removeAllNodes();
		reset();
		spawnSnake();
	}

	std::vector<sf::Vector2i> SnakeController::getCurrentSnakePositionList()
	{
		return single_linked_list->getNodesPosition();
	}
}