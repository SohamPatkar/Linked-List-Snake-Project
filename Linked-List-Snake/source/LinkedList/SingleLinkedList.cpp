#include "../../include/LinkedList/SingleLinkedList.h"
#include "../../include/LinkedList/Node.h"

namespace LinkedList
{
	SingleLinkedList::SingleLinkedList()
	{
		head_node = nullptr;
	}

	SingleLinkedList::~SingleLinkedList() = default;

	Node* SingleLinkedList::createNode()
	{
		return new Node();
	}

	void SingleLinkedList::createHeadNode()
	{
		head_node = createNode();
		head_node->body_part.initialize(node_width,node_height,default_position,default_direction);
		return;
	}

	void SingleLinkedList::initialize(float width, float height, sf::Vector2i position, Player::Direction direction)
	{
		node_width = width;
		node_height = height;
		default_position = position;
		default_direction = direction;
	}

	void SingleLinkedList::render()
	{
		head_node->body_part.render();
	}
}