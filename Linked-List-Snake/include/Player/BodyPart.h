#pragma once
#include "../../include/UI/UIElement/ImageView.h"
#include <Graphics/GraphicService.h>

namespace Player
{
	enum class Direction;

	class BodyPart
	{
	private:
		UI::UIElement::ImageView* bodypart_image;
		sf::Vector2i grid_position;
		Direction direction;

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
		sf::Vector2i getNextPosition();
		void updatePosition();
		void destroy();

	public:
		BodyPart();
		~BodyPart();

		void initialize(float width, float height, sf::Vector2i pos, Direction dir);
		void update();
		void render();

		Direction getDirection();
		sf::Vector2i getGridPosition();

		void setBodyPartDirection(Direction direction);
		void setPosition(sf::Vector2i position);
	};
}