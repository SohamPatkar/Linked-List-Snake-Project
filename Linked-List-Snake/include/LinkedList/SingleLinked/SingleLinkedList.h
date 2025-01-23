#pragma once
#include <Graphics/GraphicService.h>
#include "../include/Player/Direction.h"
#include "LinkedList/LinkedList.h"
#include <vector>

namespace LinkedList
{
	namespace SingleLinked
	{
		using namespace Player;

		struct SingleNode;

		class SingleLinkedList : public LinkedList
		{
		protected:
			virtual Node* createNode() override;

		public:
			SingleLinkedList();
			~SingleLinkedList();


			void insertNodeAtTail() override;
			void insertNodeAtHead() override;
			void insertNodeAtMiddle() override;
			void insertNodeAtIndex(int index);

			void shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);

			void removeNodeAtTail() override;
			void removeNodeAtHead() override;
			void removeNodeAtMiddle() override;
			void removeNodeAt(int index) override;
			void removeNodeAtIndex(int index);
			void removeAllNodes() override;
			void removeHalfNodes() override;

			void shiftNodesAfterRemoval(Node* cur_node);

			Direction reverse() override;
			void reverseNodeDirections();
		};
	}	
}