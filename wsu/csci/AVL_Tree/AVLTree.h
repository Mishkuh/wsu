// As usual, you can add new functions and member variables 
// in this file, but don't delete what's already declared.
#pragma once

#include <iostream>
#include <queue>
#include <stack>

class AVLTree
{
private:
	struct Node
	{
		int Data;
		Node* Left;
		Node* Right;
		Node* Parent;

		Node(int dataValue, Node* parent);
		bool DeleteChild(Node* child);
		bool ReplaceAndDeleteChild(Node* child, Node* newChild);
	};

	// Pointer to the root node of the binary search tree
	// If this is null it implies that the tree is empty
	Node* m_root;

	void AddAllNodesOnLevel(int level, std::queue<Node*>& theQ);

	static int CountDigits(int decimalValue);

	int CountLevels(Node* n);

	void DeleteTree(Node* n);

	void DisplayContents(Node* node, std::ostream& outputStream);

	void DisplaySpaces(int spaceCount, std::ostream& outputStream);

public:
	AVLTree(void);
	~AVLTree(void);

	// Should return false if the value already exists in the tree or if memory 
	// for a new node could not be allocated.
	bool Add(int dataValue);

	int CountLevels();

	void DisplayContents(std::ostream& outputStream);

	void DisplayLevels(std::ostream& outputStream);

	// Gets the maximum value in the tree. Returns 0 if the tree is empty.
	int GetMax();

	bool IsEmpty();

	// Returns true if the value was found and removed, false if it was not found
	bool Remove(int dataValue);
};

