#include "../../include/Player/BodyPart.h"
#include "../../include/Global/Config.h"

namespace Player
{
	BodyPart::BodyPart()
	{
		grid_position = sf::Vector2i(0, 0);

		createBodyPartImage();
	}

	BodyPart::~BodyPart()
	{
		destroy();
	}

	void BodyPart::initialize(float width, float height, sf::Vector2i pos, Direction dir)
	{
		bodypart_height = height;
		bodypart_width = width;
		grid_position = pos;
		direction = dir;

		initializeBodyPartImage();
	}

	void BodyPart::update()
	{

	}

	void BodyPart::render()
	{
		bodypart_image->render();
	}

	void BodyPart::createBodyPartImage()
	{
		bodypart_image = new UI::UIElement::ImageView();
	}

	void BodyPart::initializeBodyPartImage()
	{
		bodypart_image->initialize(Global::Config::snake_body_texture_path, bodypart_width, bodypart_height, static_cast<sf::Vector2f>(grid_position));
		bodypart_image->setOriginAtCentre();
	}

	sf::Vector2f BodyPart::getBodyPartScreenPosition()
	{
		return sf::Vector2f(0, 0);
	}

	void BodyPart::destroy()
	{
		delete(bodypart_image);
	}
}