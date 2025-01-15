#pragma once
#include <Graphics/GraphicService.h>
#include "../include/Player/Direction.h"

namespace LinkedList
{
	struct Node;

	class SingleLinkedList
	{
	private:
		Node* head_node;
		float node_width;
		float node_height;
		sf::Vector2i default_position;
		Player::Direction default_direction;

		Node* createNode();

	public:
		SingleLinkedList();
		~SingleLinkedList();
		void initialize(float width, float height, sf::Vector2i position, Player::Direction direction);
		void render();
	};
}