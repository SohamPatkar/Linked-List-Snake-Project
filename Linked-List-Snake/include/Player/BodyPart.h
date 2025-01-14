#pragma once
#include "../../include/UI/UIElement/ImageView.h"
#include <Graphics/GraphicService.h>

namespace Player
{
	enum class Direction;

	class BodyPart
	{
	private:
		UI::UIElement::ImageView* body_part_image;
		sf::Vector2i grid_position;
		Direction direction;

		float bodypart_width;
		float bodypart_height;

	public:
		void initialize();
		void update();
		void render();

	};
}