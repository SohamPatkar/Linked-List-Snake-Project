#pragma once
#include <SFML/System/Vector2.hpp>
#include "../../include/UI/UIElement/ImageView.h"

namespace Element
{
	class Obstacle
	{
	private:
		UI::UIElement::ImageView* obstacle_image;
		sf::Vector2i grid_position;
		float cell_width;
		float cell_height;

		void initializeObstacleImage();
		

	public:
		Obstacle();
		~Obstacle();

		void initialize(sf::Vector2i grid_pos, float width, float height);
		void update();
		void render();

		sf::Vector2f getObstacleImagePosition();
		sf::Vector2i getObstaclePosition();
	};
}