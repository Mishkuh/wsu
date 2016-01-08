// Cpt S 223 Homework  - AVL Tree Implementation
// Implement the Add and Remove functions for the AVL tree
// Remember the rules for each node in an AVL tree:
// 1. Entire left subtree is less (same as BST)
// 2. Entire right subtree is greater (same as BST)
// 3. abs(DepthOfLeftSubtree - DepthOfRightSubtree) <= 1

#include "AVLTree.h"

using namespace std;

AVLTree::Node::Node(int dataValue, Node* parent)
{
	Data = dataValue;
	Left = Right = NULL;
	Parent = parent;
}

// Deletes a child of this node and sets the appropriate child pointer to 
// NULL. The child must be the immediate left or right child of this node.
bool AVLTree::Node::DeleteChild(Node* child)
{
	return ReplaceAndDeleteChild(child, NULL);
}

bool AVLTree::Node::ReplaceAndDeleteChild(Node* child, Node* newChild)
{
	if (child == Left)
	{
		if (Left) { delete Left; }
		Left = newChild;
	}
	else if (child == Right)
	{
		if (Right) { delete Right; }
		Right = newChild;
	}
	else
	{
		// It's not a child of this node
		return false;
	}
	return true;
}

AVLTree::AVLTree(void)
{
	m_root = NULL;
}

AVLTree::~AVLTree(void)
{
	DeleteTree(m_root);
	m_root = NULL;
}

// Should return false if the value already exists in the tree or if memory 
// for a new node could not be allocated.
bool AVLTree::Add(int dataValue)
{
	// Implement this function
	// Add the node and balance the tree to obey AVL rules
}

// Adds all nodes, including null ones, that reside on the specified level. The 
// level number is 0-based. Since null nodes are included, this function always 
// adds exactly 2^level nodes to the queue. This is intended to be a helpful 
// utility function for the tree displaying function, which wants information 
// about everything on a level so it can compute spacing for a nice display.
void AVLTree::AddAllNodesOnLevel(int level, std::queue<Node*>& theQ)
{
	// Just return if level value is invalid
	if (level < 0)
	{
		return;
	}
	
	// Count the number of levels in the tree
	int lc = CountLevels();
	
	if (0 == level)
	{
		theQ.push(m_root);
	}
	else if (level >= lc)
	{
		// This means that we want nodes from a level that doesn't exist in the 
		// tree. So we just add 2^level null nodes to the queue.
		int count = 1 << level;
		while (count--)
		{
			theQ.push(NULL);
		}
	}
	else
	{
		// By no means is this the most efficient way to do this, but get the list of 
		// nodes for the previous level and just add their children.
		queue<Node*> prevLevel;
		AddAllNodesOnLevel(level - 1, prevLevel);

		while (!prevLevel.empty())
		{
			Node* parent = prevLevel.front();
			prevLevel.pop();

			// If the parent node is non-null, enqueue both children, otherwise enqueue 
			// 2 null children
			if (parent)
			{
				theQ.push(parent->Left);
				theQ.push(parent->Right);
			}
			else
			{
				theQ.push(NULL);
				theQ.push(NULL);
			}
		}
	}
}

// Utility function to compute the number of digits in the string representation of 
// the specified number in base-10.
int AVLTree::CountDigits(int decimalValue)
{
	if (0 == decimalValue)
	{
		return 1;
	}

	int count = (decimalValue < 0) ? 1 : 0;
	while (decimalValue)
	{
		count++;
		decimalValue /= 10;
	}
	return count;
}

// Returns the number of levels in the tree. A tree with no contents (null root) will have 
// zero levels. A tree with just the root and no children has 1 level. For all other cases 
// the number of levels must be counted. There is a linear-time algorithm for this.
int AVLTree::CountLevels()
{
	return CountLevels(m_root);
}

int AVLTree::CountLevels(Node* n)
{
	if (NULL == n)
	{
		return 0;
	}

	int leftLevels = CountLevels(n->Left);
	int rightLevels = CountLevels(n->Right);
	return 1 + ((leftLevels > rightLevels) ? leftLevels : rightLevels);
}

void AVLTree::DeleteTree(Node* root)
{
	if (root)
	{
		DeleteTree(root->Left);
		DeleteTree(root->Right);
		delete root;
	}
}

void AVLTree::DisplayContents(Node* node, ostream& outputStream)
{
	/*
	if (node)
	{
		DisplayContents(node->Left, outputStream);
		
		// Display the numerical value for this node
		outputStream << node->Data << " ";
		
		// Display the entire right subtree
		DisplayContents(node->Right, outputStream);
	}
	*/

	// Non-recusive version
	stack<Node*> nodes;
	while (true)
	{
		while (true)
		{
			if (!node) { break; }
		
			if (node->Left)
			{
				nodes.push(node);
				node = node->Left;
				continue;
			}

			outputStream << node->Data << " ";
			node = node->Right;
		}
		if (nodes.empty()) { break; }
		else
		{
			node = nodes.top();
			nodes.pop();
			outputStream << node->Data << " ";
			node = node->Right;
		}
	}
}

void AVLTree::DisplayContents(ostream& outputStream)
{
	outputStream << "BST Contents: ";
	DisplayContents(m_root, outputStream);
	outputStream << endl;
}

void AVLTree::DisplayLevels(std::ostream& outputStream)
{
	if (NULL == m_root)
	{
		outputStream << "(tree is empty)" << endl;
		return;
	}

	int lc = CountLevels();
	outputStream << "Tree with " << lc << " levels:" << endl;

	struct NodeLevel
	{
		Node* N;
		int Level;

		NodeLevel(Node* n, int lvl)
		{
			N = n;
			Level = lvl;
		}
	};

	bool worst = false;
	bool secondWorst = false;

	if (worst) // Worst display mode
	{
		queue<NodeLevel> nodes;
		nodes.push(NodeLevel(m_root, 0));
		int maxlevel = 0;
		while (!nodes.empty())
		{
			NodeLevel nl = nodes.front();
			nodes.pop();

			// See if we've hit a new level
			if (nl.Level > maxlevel)
			{
				outputStream << endl;
				maxlevel = nl.Level;
			}

			if (nl.N)
			{
				// Display the node's data and then enqueue children
				outputStream << nl.N->Data << " ";
				nodes.push(NodeLevel(nl.N->Left, nl.Level + 1));
				nodes.push(NodeLevel(nl.N->Right, nl.Level + 1));
			}
		}
	}
	else if (secondWorst) // Second worst display mode
	{
		for (int i = 0; i < CountLevels(); i++)
		{
			queue<Node*> theQ;
			AddAllNodesOnLevel(i, theQ);
			while (!theQ.empty())
			{
				Node* temp = theQ.front();
				theQ.pop();
				if (temp)
				{
					outputStream << temp->Data << " ";
				}
				else
				{
					outputStream << "{0} ";
				}
			}

			outputStream << endl;
		}
	}
	else // Smart display mode
	{
		// First find the maximum value in the tree and compute the number of digits
		// Note that we're assuming all positive numbers
		int max = GetMax();
		int charsPerNum = CountDigits(max);
		// We want at least one space after each number but also since rounding stuff 
		// gets weird we want a little extra padding
		charsPerNum+=2;
		// We display null values as "{0} " so we need at least 4 digits
		if (charsPerNum < 4) { charsPerNum = 4; }

		// Count the levels in the tree and then calculate how many characters will be 
		// needed to display the bottommost level.
		int lc = CountLevels();
		int charsOnLast = charsPerNum * (1 << (lc - 1));
		
		// Now loop through the rows and display them
		for (int i = 0; i < lc; i++)
		{
			queue<Node*> theQ;
			AddAllNodesOnLevel(i, theQ);

			float spacesBetweenNumCenters = (float)charsOnLast / (float)theQ.size();
			float numCenter = spacesBetweenNumCenters / 2.0f;
			int charAt = 0;
			
			while (!theQ.empty())
			{
				Node* temp = theQ.front();
				theQ.pop();
				int digitsForThisOne;
				if (temp)
				{
					digitsForThisOne = CountDigits(temp->Data);
				}
				else
				{
					digitsForThisOne = 3;
				}

				// Put right amount of spacing before this symbol
				int spaceCount = (int)(numCenter - (float)charAt - ((float)digitsForThisOne / 2.0f));
				if (spaceCount < 0)
				{
					bool breakhere = true;
				}
				if (spaceCount < 1) { spaceCount = 1; }
				DisplaySpaces(spaceCount, outputStream);

				// Display the number or symbol and update charAt and numCenter
				if (temp)
				{
					outputStream << temp->Data;
				}
				else
				{
					outputStream << "{0}";
				}
				charAt += spaceCount + digitsForThisOne;
				numCenter += spacesBetweenNumCenters;
			}

			outputStream << endl;
		}
	}
}

void AVLTree::DisplaySpaces(int spaceCount, ostream& outputStream)
{
	while (spaceCount--)
	{
		outputStream << " ";
	}
}

// Gets the maximum value in the tree. Returns 0 if the tree is empty.
int AVLTree::GetMax()
{
	if (m_root)
	{
		Node* n = m_root;
		while (n->Right)
		{
			n = n->Right;
		}
		return n->Data;
	}
	return 0;
}

bool AVLTree::IsEmpty()
{
	return (NULL == m_root);
}

// Returns true if the value was found and removed, false if it was not found
bool AVLTree::Remove(int dataValue)
{
	if (!m_root)
	{
		return false;
	}

	// Implement (the rest of) this function
	// Balance the tree after removal so that it obeys AVL rules
}
