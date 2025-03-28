#pragma once
#include "UI/UIElement/ImageView.h"
#include "Direction.h"
#include <SFML/Graphics.hpp>

namespace Player
{
	class BodyPart
	{
	private:
		UI::UIElement::ImageView* bodypart_image;
		sf::Vector2i grid_position;
		Direction direction;
		Direction previous_direction;

		float bodypart_width;
		float bodypart_height;

		void createBodyPartImage();
		void initializeBodyPartImage();
		sf::Vector2f getBodyPartScreenPosition();
		float getRotationAngle();
		sf::Vector2i getNextPositionLeft();
		sf::Vector2i getNextPositionRight();
		sf::Vector2i getNextPositionDown();
		sf::Vector2i getNextPositionUp();
		

		void destroy();

	public:
		BodyPart();
		~BodyPart();

		void initialize(float width, float height, sf::Vector2i pos, Direction dir);
		void updatePosition();
		void render();

		sf::Vector2i getNextPosition();
		sf::Vector2i getPrevPosition();
		Direction getDirection();
		Direction getPreviousDirection();
		sf::Vector2i getPosition();

		void setBodyPartDirection(Direction direction);
		void setPosition(sf::Vector2i position);
	};
}