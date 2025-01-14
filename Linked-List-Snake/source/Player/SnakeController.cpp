#include "../../include/Player/SnakeController.h"

namespace Player
{
	SnakeController::SnakeController()
	{

	}

	SnakeController::~SnakeController()
	{

	}

	void SnakeController::spawnSnake()
	{

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

	}

	void SnakeController::update()
	{
		switch (current_snake_state)
		{
		case SnakeState::ALIVE:
			processPlayerInput();
			updateSnakeDirection();
			processSnakeCollision();
			moveSnake();
			break;

		case SnakeState::DEAD:
			handleRestart();
			break;
		}
	}

	void SnakeController::render()
	{

	}

	void SnakeController::moveSnake()
	{

	}

	void SnakeController::processPlayerInput()
	{

	}

	void SnakeController::processSnakeCollision()
	{

	}

	void SnakeController::handleRestart()
	{

	}

	void SnakeController::reset()
	{

	}
	
	void SnakeController::updateSnakeDirection()
	{

	}

	void SnakeController::respawnSnake()
	{

	}
}