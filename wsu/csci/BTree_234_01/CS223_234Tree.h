#pragma once

// Implement this class in this header file

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Notes about template object:
// Whatever object is used as the template type for this class must implement the following:
// - Copy constructor
// - int GetKey() function
// - string ToString() function

template <typename T>
class CS223_234Tree
{
private:
	struct Node
	{
		// A, B and C are the actual data values in the node		
		T* A;
		T* B;
		T* C;

		// Child pointers
		Node *L, *M1, *M2, *R;

		// Constructor to initialize the node with one value. The other two value 
		// pointers will be set to null and all child pointers will be set to null. 
		// The pointer given as the parameter is directly copied to A.
		Node(T* valueForA)
		{
			A = valueForA;
			B = C = NULL;
			L = M1 = M2 = R = NULL;
		}

		// Constructor to initialize the node with one value and two child pointers.
		Node(T* valueForA, Node* leftChildOfA, Node* rightChildOfA)
		{
			A = valueForA;
			L = leftChildOfA;
			M1 = rightChildOfA;

			// Everything else is NULL
			B = C = NULL;
			M2 = R = NULL;
		}

		Node(T* aVal, T* bVal, T* cVal, Node* left, Node* m1, Node* m2, Node* right)
		{
			A = aVal;
			B = bVal;
			C = cVal;
			L = left;
			M1 = m1;
			M2 = m2;
			R = right;
		}

		bool ContainsKey(int key)
		{
			if (C && C->GetKey() == key) { return true; }
			if (B && B->GetKey() == key) { return true; }
			if (A->GetKey() == key) { return true; }
			return false;
		}

		void DeleteData()
		{
			if (A) { delete A; A = NULL; }
			if (B) { delete B; B = NULL; }
			if (C) { delete C; C = NULL; }
		}

		// Returns true if all three data-value pointers, A, B, and C, are non-null, 
		// false otherwise.
		bool IsFull()
		{
			return (A != NULL && B != NULL && C != NULL);
		}

		// Returns true if all 4 child pointers are null, implying that the node is a leaf
		bool IsLeaf()
		{
			return (NULL == L && NULL == M1 && NULL == M2 && NULL == R);
		}

		int ValueCount()
		{
			if (C) { return 3; }
			else if (B) { return 2; }
			else if (A) { return 1; }

			// Should never come here
			return 0;
		}
	};

	Node* m_root;

	void DeleteTree(Node* root)
	{
		if (root)
		{
			root->DeleteData();
			DeleteTree(root->L);
			DeleteTree(root->M1);
			DeleteTree(root->M2);
			DeleteTree(root->R);
			delete root;
		}
	}

	void Display(Node* n)
	{
		if (!n) { return; }

		// There will always be an A value with a subtree to left and right of it
		Display(n->L);
		string nodeAsString = n->A->ToString();
		cout << nodeAsString << endl;
		Display(n->M1);

		// There may or may not be a B and C value
		if (n->B)
		{
			nodeAsString = n->B->ToString();
			cout << nodeAsString << endl;
			Display(n->M2);

			if (n->C)
			{
				nodeAsString = n->C->ToString();
				cout << nodeAsString << endl;
				Display(n->R);
			}
		}
	}

	// Finds and returns the node containing the minimum value in the subtree.
	Node* FindMin(Node* root)
	{
		if (root->IsLeaf())
		{
			return root;
		}

		Node* n = root->L;
		while (n->L) { n = n->L; }
		return n;
	}

#if defined(DEBUG) || defined(_DEBUG)
	bool IsTreeValid(Node* n)
	{
		if (!n) { return true; }

		// First make sure that A is non-null. This should always be true for any 
		// node in the tree.
		if (!n->A)
		{
			cout << "DEBUG: Tree error: Value A in node is null!" << endl;
			return false;
		}

		// Now make sure A < B < C within the node. If C is null then we just 
		// need to verify that A < B and if B and C are NULL then it's ok.
		if (n->C)
		{
			// B must not be NULL in this case
			if (NULL == n->B)
			{
				cout << "DEBUG: Tree error: Value C in node is non-null but B is null!" << endl;
				return false;
			}

			if (n->C->GetKey() <= n->B->GetKey())
			{
				cout << "DEBUG: Tree error: Value C in node is <= B!" << endl;
				return false;
			}
		}
		else if (n->B)
		{
			if (n->B->GetKey() <= n->A->GetKey())
			{
				cout << "DEBUG: Tree error: Value B in node is <= A!" << endl;
				return false;
			}
		}

		// Next we make sure we have non-null child pointers where appropriate.
		if (!n->IsLeaf())
		{
			if (n->C)
			{
				if (NULL == n->R)
				{
					cout << "DEBUG: Tree error: R pointer in node is NULL but value C is not!" << endl;
					return false;
				}
			}
			if (n->B)
			{
				if (NULL == n->M2)
				{
					cout << "DEBUG: Tree error: M2 pointer in node is NULL but value B is not!" << endl;
					return false;
				}
			}
			if (NULL == n->M1)
			{
				cout << "DEBUG: Tree error: M1 pointer in node (key=";
				cout << n->A->GetKey() << ") is NULL!" << endl;
				return false;
			}
			if (NULL == n->L)
			{
				cout << "DEBUG: Tree error: L pointer in node is NULL!" << endl;
				return false;
			}
		}

		// For each value in the node, the left subtree should be all less and the right 
		// subtree all greater.
		T* vals[] = { n->A, n->B, n->C };
		Node* children[] = { n->L, n->M1, n->M1, n->M2, n->M2, n->R };
		for (int i = 0; i < 3; i++)
		{
			if (NULL == vals[i]) { break; }
			int key = vals[i]->GetKey();

			// Make sure all keys in left subtree are less
			stack<Node*> nodes;
			nodes.push(children[i / 2]);
			while (!nodes.empty())
			{
				Node* temp = nodes.top();
				nodes.pop();
				if (!temp) { continue; }

				if (temp->A->GetKey() >= key)
				{
					cout << "DEBUG ERROR: Node in left subtree of key=" << key;
					cout << " has a key of " << temp->A->GetKey() << ", which is";
					cout << "greater and thus improperly structured." << endl;
					return false;
				}
				if (temp->B && temp->B->GetKey() >= key)
				{
					cout << "DEBUG ERROR: Node in left subtree of key=" << key;
					cout << " has a key of " << temp->A->GetKey() << ", which is";
					cout << "greater and thus improperly structured." << endl;
					return false;
				}
				if (temp->C && temp->C->GetKey() >= key)
				{
					cout << "DEBUG ERROR: Node in left subtree of key=" << key;
					cout << " has a key of " << temp->A->GetKey() << ", which is";
					cout << "greater and thus improperly structured." << endl;
					return false;
				}

				// Push children
				nodes.push(temp->L);
				nodes.push(temp->M1);
				nodes.push(temp->M2);
				nodes.push(temp->R);
			}

			// TODO: Right subtree - implement it on your own if you need the 
			// extra error checking
		}

		// Recurse for all children
		return (IsTreeValid(n->L) && IsTreeValid(n->M1) &&
			IsTreeValid(n->M2) && IsTreeValid(n->R));
	}
#endif

public:
	CS223_234Tree(void)
	{
		m_root = NULL;
	}

	virtual ~CS223_234Tree(void)
	{
		DeleteTree(m_root);
		m_root = NULL;
	}

	bool Add(T& toCopyAndAdd)
	{
		Node *pCur = m_root;
		if (!m_root)
		{
			//insert
			m_root = new Node(new T(toCopyAndAdd));
			return true;
		}
		while (pCur)
		{
			if (pCur->ContainsKey(toCopyAndAdd.GetKey()))
				//failed
				return false;

			else if (pCur->C)
			{
				Node *newRight = new Node(pCur->C, pCur->M2, pCur->R);
				Node *newNode = new Node(pCur->B, pCur, newRight);
				pCur->B = pCur->C = NULL;
				pCur->M2 = pCur->R = NULL;

				m_root = pCur = newNode;

				if (toCopyAndAdd.GetKey() < pCur->A->GetKey())
					//step
					pCur = pCur->L;
				else if (toCopyAndAdd.GetKey() > pCur->A->GetKey())
					//step
					pCur = pCur->M1;
				else
					//failed
					return false;
			}
			else if (pCur->A)
			{
				if (pCur->B)
				{
					if (toCopyAndAdd.GetKey() > pCur->B->GetKey())
					{
						if (pCur->M2)
						{
							if (pCur->M2->C)
							{
								pCur->C = pCur->M2->B;
								Node *newNode = new Node(pCur->M2->C, pCur->M2->M2, pCur->M2->R);
								pCur->R = newNode;
								pCur->M2->B = pCur->M2->C = NULL;
								pCur->M2->M2 = pCur->M2->R = NULL;
							}
							if (pCur->C)
							{
								if (toCopyAndAdd.GetKey() > pCur->C->GetKey())
									pCur = pCur->R;
								else if (toCopyAndAdd.GetKey() < pCur->C->GetKey())
									pCur = pCur->M2;
								else
									return false;
							}
							else
							{
								pCur = pCur->M2;
							}
						}
						else
						{
							pCur->C = new T(toCopyAndAdd);
							return true;
						}
					}
					else if (toCopyAndAdd.GetKey() < pCur->B->GetKey() && toCopyAndAdd.GetKey() > pCur->A->GetKey())
					{
						if (pCur->M1)
						{
							if (pCur->M1->C)
							{
								pCur->C = pCur->B;
								pCur->R = pCur->M2;

								pCur->B = pCur->M1->B;
								Node *newNode = new Node(pCur->M1->C, pCur->M1->M2, pCur->M1->R);
								pCur->M2 = newNode;
								pCur->M1->B = pCur->M1->C = NULL;
								pCur->M1->M2 = pCur->M1->R = NULL;
							}
							if (pCur->B)
							{
								if (toCopyAndAdd.GetKey() < pCur->B->GetKey())
									pCur = pCur->M1;
								else if (toCopyAndAdd.GetKey() > pCur->B->GetKey())
									pCur = pCur->M2;
								else
									return false;
							}
						}
						else
						{
							if (pCur->A && !pCur->B)
							{
								pCur->B = new T(toCopyAndAdd);
							}
							else if(pCur->A && pCur->B)
							{
								pCur->C = pCur->B;
								pCur->B = new T(toCopyAndAdd);
							}
						}
					}
					else if (toCopyAndAdd.GetKey() < pCur->A->GetKey())
					{
						if (pCur->L)
						{
							if (pCur->L->C)
							{
								pCur->C = pCur->B;
								pCur->B = pCur->A;
								pCur->A = pCur->L->B;
								Node *newNode = new Node(pCur->L->C, pCur->L->M2, pCur->L->R);
								pCur->R = pCur->M2;
								pCur->M2 = pCur->M1;
								pCur->M1 = newNode;
								pCur->L->B = pCur->L->C = NULL;
								pCur->L->M2 = pCur->L->R = NULL;
							}
							if (toCopyAndAdd.GetKey() > pCur->A->GetKey())
								pCur = pCur->M1;
							else if (toCopyAndAdd.GetKey() < pCur->A->GetKey())
								pCur = pCur->L;
							else
								return false;
						}
						else
						{
							pCur->C = pCur->B;
							pCur->B = pCur->A;
							pCur->A = new T(toCopyAndAdd);
							return true;
						}
					}
					else
						return false;
				}
				else if (toCopyAndAdd.GetKey() < pCur->A->GetKey())
				{
					if (pCur->L)
					{
						if (pCur->L->C)
						{
							pCur->B = pCur->A;
							pCur->A = pCur->L->B;
							Node *newNode = new Node(pCur->L->C, pCur->L->M2, pCur->L->R);
							pCur->M2 = pCur->M1;
							pCur->M1 = newNode;
							pCur->L->B = pCur->L->C = NULL;
							pCur->L->M2 = pCur->L->R = NULL;
						}

						if (toCopyAndAdd.GetKey() > pCur->A->GetKey())
							pCur = pCur->M1;
						else if (toCopyAndAdd.GetKey() < pCur->A->GetKey())
							pCur = pCur->L;
						else
							return false;
					}
					else
					{
						pCur->C = pCur->B;
						pCur->B = pCur->A;
						pCur->A = new T(toCopyAndAdd);
						return true;
					}
				}
				else if (toCopyAndAdd.GetKey() > pCur->A->GetKey())
				{
					if (pCur->M1)
					{
						if (pCur->M1->C)
						{
							pCur->B = pCur->M1->B;
							Node *newNode = new Node(pCur->M1->C, pCur->M1->M2, pCur->M1->R);
							pCur->M2 = newNode;
							pCur->M1->B = pCur->M1->C = NULL;
							pCur->M1->M2 = pCur->M1->R = NULL;
						}
						if (pCur->B)
						{
							if (toCopyAndAdd.GetKey() < pCur->B->GetKey())
								pCur = pCur->M1;
							else if (toCopyAndAdd.GetKey() > pCur->B->GetKey())
								pCur = pCur->M2;
							else
								return false;
						}
						else
						{
							pCur = pCur->M1;
						}
					}
					else if (pCur->B)
					{
						pCur->C = pCur->B;
						pCur->B = new T(toCopyAndAdd);
						return true;
					}
					else
					{
						pCur->B = new T(toCopyAndAdd);
						return true;
					}
				}
				else
					return false;
			}
			else
			{
				return false;
			}
		}
	}

	void Display(ostream& outstream)
	{
		if (!m_root)
		{
			outstream << "(tree is empty)";
		}
		Display(m_root);
	}

	void DisplayLevelKeys(ostream& outstream)
	{
		if (!m_root)
		{
			outstream << "(tree is empty, no levels to display)";
			return;
		}

		struct NodeLevel
		{
			Node* node;
			int level;
			NodeLevel(Node* n, int l) { node = n; level = l; }
		};

		queue<NodeLevel> nodes;
		nodes.push(NodeLevel(m_root, 0));
		int maxLevel = 0;
		while (!nodes.empty())
		{
			NodeLevel nl = nodes.front();
			nodes.pop();
			Node* n = nl.node;
			if (nl.level > maxLevel)
			{
				outstream << endl;
				maxLevel = nl.level;
			}

			outstream << "< " << n->A->GetKey() << " ";
			if (n->B) { outstream << n->B->GetKey() << " "; }
			if (n->C) { outstream << n->C->GetKey() << " "; }
			outstream << ">";

			// Enqueue children
			if (n->L) { nodes.push(NodeLevel(n->L, nl.level + 1)); }
			if (n->M1) { nodes.push(NodeLevel(n->M1, nl.level + 1)); }
			if (n->M2) { nodes.push(NodeLevel(n->M2, nl.level + 1)); }
			if (n->R) { nodes.push(NodeLevel(n->R, nl.level + 1)); }
		}
		outstream << endl;
	}

	T* Find(int key)
	{
		// You must implement this function to return the value for the object 
		// with the associated key. Return NULL if no such object exists in 
		// the tree.
		Node * pCur = this->m_root;

		while (pCur)
		{
			if (pCur->A && key == pCur->A->GetKey())
				return pCur->A;
			else if (pCur->A && key < pCur->A->GetKey())
				pCur = pCur->L;
			else if (pCur->B && key == pCur->B->GetKey())
				return pCur->B;
			else if (pCur->B && key < pCur->B->GetKey())
				pCur = pCur->M1;
			else if (pCur->C && key == pCur->C->GetKey())
				return pCur->C;
			else if (pCur->C && key < pCur->C->GetKey())
				pCur = pCur->M2;
			else if (pCur->C && key > pCur->C->GetKey())
				pCur = pCur->R;
		}

		return NULL;
	}

	T* GetMin()
	{
		if (!m_root) { return NULL; }
		Node* n = FindMin(m_root);
		return n->A;
	}

#if defined(DEBUG) || defined(_DEBUG)
	bool IsTreeValid()
	{
		return IsTreeValid(m_root);
	}
#endif

	bool Remove(int key)
	{
		Node* pCur = m_root;
		Node* pTemp;

		if (!m_root) { return false; }

		while (pCur)
		{
			// has three students
			if (pCur->A && pCur->B && pCur->C)
			{
				if (key == pCur->C->GetKey()) // Operations on C if key == C.key
				{
					if (!pCur->R)
					{
						pCur->C = NULL;
					}
					else
					{
						Node *replace = FindMin(pCur->R);
						Student *temp = replace->A;
						Remove(replace->A->GetKey());
						pCur->C = temp;
					}
					return true;
				}
				else if (key == pCur->B->GetKey()) // Performs operations on B is key == B.key()
				{
					if (!pCur->M2)
					{
						pCur->B = pCur->C;
						pCur->C = NULL;
					}
					else
					{
						Node *replace = FindMin(pCur->M2);
						Student *temp = replace->A;
						Remove(replace->A->GetKey());
						pCur->B = temp;
					}
					return true;
				}
				else if (key == pCur->A->GetKey()) // performs operations on A if key == A.key()
				{
					if (!pCur->M1)
					{
						pCur->A = pCur->B;
						pCur->B = pCur->C;
						pCur->C = NULL;
					}
					else
					{
						Node *replace = FindMin(pCur->M1);
						Student *temp = replace->A;
						Remove(replace->A->GetKey());
						pCur->A = temp;
					}
					return true;
				}
				else if (!pCur->L)
				{
					return false;
				}

				//greater than student C (move to R)
				else if (key > pCur->C->GetKey())
				{
					//R has only one student
					if (!pCur->R->B)
					{
						//sibling has only one student
						//fuze current and children (M2, R)
						if (!pCur->M2->B)
						{
							pCur->M2->C = pCur->R->A;
							pCur->M2->B = pCur->C;
							pCur->M2->M2 = pCur->R->L;
							pCur->M2->R = pCur->R->M1;
							pCur->R->A = pCur->C = NULL;
							pCur->R->L = pCur->R->M1 = NULL;

							// step
							pCur = pCur->M2;
						}
						//multiple students
						//rotate using M2->C
						else if (pCur->M2->C)
						{
							pCur->R->B = pCur->R->A;
							pCur->R->M2 = pCur->R->M1;
							pCur->R->M1 = pCur->R->L;
							pCur->R->A = pCur->C;
							pCur->R->L = pCur->M2->R;
							pCur->C = pCur->M2->C;

							pCur->M2->C = NULL;
							pCur->M2->R = NULL;

							//step
							pCur = pCur->R;
						}
						//multiple students
						//Rotate using M2->B
						else
						{
							pCur->R->B = pCur->R->A;
							pCur->R->M2 = pCur->R->M1;
							pCur->R->M1 = pCur->R->L;
							pCur->R->A = pCur->C;
							pCur->R->L = pCur->M2->M2;
							pCur->C = pCur->M2->B;

							pCur->M2->B = NULL;
							pCur->M2->M2 = NULL;

							//step
							pCur = pCur->R;
						}
					}
					//R has more than one student
					else
					{
						//step
						pCur = pCur->R;
					}
				}
					//move to the right of B
				else if (key > pCur->B->GetKey() && key < pCur->C->GetKey())
				{
					//M2 has only one student
					if (!pCur->M2->B)
					{
						// sibling has only one child
						// fuse current with children
						if (!pCur->M1->B)
						{
							pCur->M1->C = pCur->M2->A;
							pCur->M1->B = pCur->B;
							pCur->M1->M2 = pCur->M2->L;
							pCur->M1->R = pCur->M2->M1;

							pCur->B = pCur->C;
							pCur->M2 = pCur->R;

							pCur->C = NULL;
							pCur->R = NULL;

							//step
							pCur = pCur->M1;
						}
						//sibling has three students
						//rotate C
						else if (pCur->M1->C)
						{
							pCur->M2->B = pCur->M2->A;
							pCur->M2->M2 = pCur->M2->M1;
							pCur->M2->M1 = pCur->M1->L;
							pCur->M2->A = pCur->B;
							pCur->B = pCur->M1->C;
							pCur->M2->L = pCur->M1->R;

							pCur->M1->R = NULL;
							pCur->M1->C = NULL;

							//step
							pCur = pCur->M2;
						}
						//sibling has two students
						//rotate B
						else
						{
							pCur->M2->B = pCur->M2->A;
							pCur->M2->M2 = pCur->M2->M1;
							pCur->M2->M1 = pCur->M1->L;
							pCur->M2->A = pCur->B;
							pCur->B = pCur->M1->B;
							pCur->M2->L = pCur->M1->M2;

							pCur->M1->M2 = NULL;
							pCur->M1->B = NULL;

							//step
							pCur = pCur->M2;
						}
					}
					else
					{
						pCur = pCur->M2;
					}
				}
				//between A and B (M1)
				else if (key > pCur->A->GetKey() && key < pCur->B->GetKey())
				{
					//only one student
					if (!pCur->M1->B)
					{
						//right child has one student
						if (!pCur->M2->B)
						{
							//left has only one student
							//fuze cur with m1 and m2
							if (!pCur->L->B)
							{
								pCur->M1->C = pCur->M2->A;
								pCur->M1->B = pCur->B;
								pCur->M1->M2 = pCur->M2->L;
								pCur->M1->R = pCur->M2->M1;

								pCur->B = pCur->C;
								pCur->M2 = pCur->R;

								pCur->R = NULL;
								pCur->C = NULL;
							}
							//left has more than one student
							//rotate C
							else if (pCur->L->C)
							{
								pCur->M1->B = pCur->M1->A;
								pCur->M1->M2 = pCur->M1->M1;
								pCur->M1->M1 = pCur->M1->L;
								pCur->M1->L = pCur->L->R;
								pCur->M1->A = pCur->A;
								pCur->A = pCur->L->C;

								pCur->L->C = NULL;
								pCur->L->R = NULL;
							}
							//left has more than one student
							//rotate B
							else
							{
								pCur->M1->B = pCur->M1->A;
								pCur->M1->M2 = pCur->M1->M1;
								pCur->M1->M1 = pCur->M1->L;
								pCur->M1->L = pCur->L->M2;
								pCur->M1->A = pCur->A;
								pCur->A = pCur->L->B;

								pCur->L->B = NULL;
								pCur->L->M2 = NULL;
							}
						}
						//right child has more than one student
						else
						{
							//rotate
							if (pCur->M2->C)
							{
								pCur->M1->B = pCur->B;
								pCur->B = pCur->M2->A;
								pCur->M2->A = pCur->M2->B;
								pCur->M2->B = pCur->M2->C;
								pCur->M1->M2 = pCur->M2->L;
								pCur->M2->L = pCur->M2->M1;
								pCur->M2->M1 = pCur->M2->M2;
								pCur->M2->M2 = pCur->M2->R;

								pCur->M2->C = NULL;
								pCur->M2->R = NULL;

								//step
								pCur = pCur->M1;
							}
							//left has more than one student
							//rotate B
							else
							{
								pCur->M1->B = pCur->B;
								pCur->B = pCur->M2->A;
								pCur->M2->A = pCur->M2->B;
								pCur->M1->M2 = pCur->M2->L;
								pCur->M2->L = pCur->M2->M1;
								pCur->M2->M1 = pCur->M2->M2;

								pCur->M2->B = NULL;
								pCur->M2->M2 = NULL;

								//step
								pCur = pCur->M1;
							}
						}
					}
					else
					{
						//step
						pCur = pCur->M1;
					}
				}
				//left of A
				else if (key < pCur->A->GetKey())
				{
					if (!pCur->L->B)
					{
						if (!pCur->M1->B)
						{
							pCur->L->B = pCur->A;
							pCur->L->C = pCur->M1->A;
							pCur->A = pCur->B;
							pCur->B = pCur->C;
							pCur->M2 = pCur->R;
							pCur->M1 = pCur->M2;

							pCur->R = NULL;
							pCur->C = NULL;

							//step
							pCur = pCur->L;
						}
						//more than one student
						//rotate
						else if (pCur->M1->C)
						{
							pCur->L->B = pCur->A;
							pCur->A = pCur->M1->A;
							pCur->M1->A = pCur->M1->B;
							pCur->M1->B = pCur->M1->C;
							pCur->L->M2 = pCur->M1->L;
							pCur->M1->L = pCur->M1->M1;
							pCur->M1->M1 = pCur->M1->M2;
							pCur->M1->M2 = pCur->M1->R;

							pCur->M1->C = NULL;
							pCur->M1->R = NULL;

							//step
							pCur = pCur->L;
						}
						//left has more than one student
						//rotate B
						else
						{
							pCur->L->B = pCur->A;
							pCur->A = pCur->M1->A;
							pCur->M1->A = pCur->M1->B;
							pCur->L->M2 = pCur->M1->L;
							pCur->M1->L = pCur->M1->M1;
							pCur->M1->M1 = pCur->M1->M2;

							pCur->M1->B = NULL;
							pCur->M1->M2 = NULL;

							//step
							pCur = pCur->L;
						}
					}
					else
					{
						pCur = pCur->L;
					}
				}
			}
			//has two students
			else if (pCur->A && pCur->B && !pCur->C)
			{
				if (key == pCur->B->GetKey()) // Performs operations on B is key == B.key()
				{
					if (!pCur->M2)
					{
						pCur->B = pCur->C;
						pCur->C = NULL;
					}
					else
					{
						Node *replace = FindMin(pCur->M2);
						Student *temp = replace->A;
						Remove(replace->A->GetKey());
						pCur->B = temp;
					}
					return true;
				}
				else if (key == pCur->A->GetKey()) // performs operations on A if key == A.key()
				{
					if (!pCur->M1)
					{
						pCur->A = pCur->B;
						pCur->B = pCur->C;
						pCur->C = NULL;
					}
					else
					{
						Node *replace = FindMin(pCur->M1);
						Student *temp = replace->A;
						Remove(replace->A->GetKey());
						pCur->A = temp;
					}
					return true;
				}
				else if (!pCur->L)
				{
					return false;
				}
				//move to the right of B
				else if (key > pCur->B->GetKey())
				{
					//M2 has only one student
					if (!pCur->M2->B)
					{
						// sibling has only one child
						// fuse current with children
						if (!pCur->M1->B)
						{
							pCur->M1->C = pCur->M2->A;
							pCur->M1->B = pCur->B;
							pCur->M1->M2 = pCur->M2->L;
							pCur->M1->R = pCur->M2->M1;

							pCur->M2->A = pCur->B = NULL;
							pCur->M2->L = pCur->M2->M1 = NULL;

							//step
							pCur = pCur->M1;
						}
						//sibling has three students
						//rotate C
						else if (pCur->M1->C)
						{
							pCur->M2->B = pCur->M2->A;
							pCur->M2->M2 = pCur->M2->M1;
							pCur->M2->M1 = pCur->M1->L;
							pCur->M2->A = pCur->B;
							pCur->B = pCur->M1->C;
							pCur->M2->L = pCur->M1->R;

							pCur->M1->R = NULL;
							pCur->M1->C = NULL;

							//step
							pCur = pCur->M2;
						}
						//sibling has two students
						//rotate B
						else
						{
							pCur->M2->B = pCur->M2->A;
							pCur->M2->M2 = pCur->M2->M1;
							pCur->M2->M1 = pCur->M1->L;
							pCur->M2->A = pCur->B;
							pCur->B = pCur->M1->B;
							pCur->M2->L = pCur->M1->M2;

							pCur->M1->M2 = NULL;
							pCur->M1->B = NULL;

							//step
							pCur = pCur->M2;
						}
					}
					else
					{
						pCur = pCur->M2;
					}
				}
				//between A and B (M1)
				else if (key > pCur->A->GetKey() && key < pCur->B->GetKey())
				{
					//only one student
					if (!pCur->M1->B)
					{
						//right child has one student
						if (!pCur->M2->B)
						{
							//left has only one student
							//fuze cur with m1 and m2
							if (!pCur->L->B)
							{
								pCur->M1->C = pCur->M2->A;
								pCur->M1->B = pCur->B;
								pCur->M1->M2 = pCur->M2->L;
								pCur->M1->R = pCur->M2->M1;

								pCur->M2->M1 = pCur->M2->L = NULL;
								pCur->B = pCur->M2->A = NULL;
							}
							//left has more than one student
							//rotate C
							else if (pCur->L->C)
							{
								pCur->M1->B = pCur->M1->A;
								pCur->M1->M2 = pCur->M1->M1;
								pCur->M1->M1 = pCur->M1->L;
								pCur->M1->L = pCur->L->R;
								pCur->M1->A = pCur->A;
								pCur->A = pCur->L->C;

								pCur->L->C = NULL;
								pCur->L->R = NULL;
							}
							//left has more than one student
							//rotate B
							else
							{
								pCur->M1->B = pCur->M1->A;
								pCur->M1->M2 = pCur->M1->M1;
								pCur->M1->M1 = pCur->M1->L;
								pCur->M1->L = pCur->L->M2;
								pCur->M1->A = pCur->A;
								pCur->A = pCur->L->B;

								pCur->L->B = NULL;
								pCur->L->M2 = NULL;
							}
						}
						//right child has more than one student
						else
						{
							if (pCur->M2->C)
							{
								pCur->M1->B = pCur->B;
								pCur->B = pCur->M2->A;
								pCur->M2->A = pCur->M2->B;
								pCur->M2->B = pCur->M2->C;
								pCur->M1->M2 = pCur->M2->L;
								pCur->M2->L = pCur->M2->M1;
								pCur->M2->M1 = pCur->M2->M2;
								pCur->M2->M2 = pCur->M2->R;

								pCur->M2->C = NULL;
								pCur->M2->R = NULL;

								//step
								pCur = pCur->M1;
							}
							//left has more than one student
							//rotate B
							else
							{
								pCur->M1->B = pCur->B;
								pCur->B = pCur->M2->A;
								pCur->M2->A = pCur->M2->B;
								pCur->M1->M2 = pCur->M2->L;
								pCur->M2->L = pCur->M2->M1;
								pCur->M2->M1 = pCur->M2->M2;

								pCur->M2->B = NULL;
								pCur->M2->M2 = NULL;

								//step
								pCur = pCur->M1;
							}
						}
					}
					else
					{
						//step
						pCur = pCur->M1;
					}
				}
				//left of A
				else if (key < pCur->A->GetKey())
				{
					if (!pCur->L->B)
					{
						if (!pCur->M1->B)
						{
							pCur->L->B = pCur->A;
							pCur->L->C = pCur->M1->A;
							pCur->A = pCur->B;
							pCur->M1 = pCur->M2;

							pCur->M2 = NULL;
							pCur->B = NULL;

							//step
							pCur = pCur->L;
						}
						else if (pCur->M1->C)
						{
							pCur->L->B = pCur->A;
							pCur->A = pCur->M1->A;
							pCur->M1->A = pCur->M1->B;
							pCur->M1->B = pCur->M1->C;
							pCur->L->M2 = pCur->M1->L;
							pCur->M1->L = pCur->M1->M1;
							pCur->M1->M1 = pCur->M1->M2;
							pCur->M1->M2 = pCur->M1->R;

							pCur->M1->C = NULL;
							pCur->M1->R = NULL;

							//step
							pCur = pCur->L;
						}
						//left has more than one student
						//rotate B
						else
						{
							pCur->L->B = pCur->A;
							pCur->A = pCur->M1->A;
							pCur->M1->A = pCur->M1->B;
							pCur->L->M2 = pCur->M1->L;
							pCur->M1->L = pCur->M1->M1;
							pCur->M1->M1 = pCur->M1->M2;

							pCur->M1->B = NULL;
							pCur->M1->M2 = NULL;

							//step
							pCur = pCur->L;
						}
					}
					else
					{
						pCur = pCur->L;
					}
				}
			}
			// has only one student
			else if (pCur->A && !pCur->B && !pCur->C)
			{
				if (key == pCur->A->GetKey()) // performs operations on A if key == A.key()
				{
					if (!pCur->M1)
					{
						pCur->A = pCur->B;
						pCur->B = pCur->C;
						pCur->C = NULL;
					}
					else
					{
						Node *replace = FindMin(pCur->M1);
						Student *temp = replace->A;
						Remove(replace->A->GetKey());
						pCur->A = temp;
					}
					return true;
				}
				// has children (not a leaf)
				if (pCur->L && pCur->M1)
				{
					//children have only one student
					//Fuse current with those children
					if (!pCur->L->B && !pCur->M1->B)
					{
						Student *temp = pCur->L->A;

						pCur->L->B = pCur->A;
						pCur->L->M2 = pCur->M1->L;
						pCur->L->C = pCur->M1->A;
						pCur->L->R = pCur->M1->M1;

						m_root = pCur->L;

						pCur->A = pCur->M1->A = NULL;
						pCur->M1->L = pCur->M1->M1 = NULL;
						pCur = NULL;

						pCur = m_root;
					}
				}
			}
		}
		return false;
	}
};

