#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

template< class T > class List;  // forward declaration
 
template<class T> class ListNode
{
   friend class List< T >; // make List a friend
public:
   ListNode( const T &newData);  // copy constructor
   T getData() const;      // return data in the node
protected:
   T data;                 // data
   ListNode< T > *nextPtr; // next node in the list
}; 
template< class T > class List
{
public:
   List();      // constructor
   ~List();     // destructor
   void insertAtFront( const T &newData );
   void insertAtBack( const T &newData );
   bool removeFromFront( T &removedData );
   bool removeFromBack( T &removedData );
   bool isEmpty() const;
   void print() const;
protected:
   ListNode< T > *firstPtr;  // pointer to first node
   ListNode< T > *lastPtr;   // pointer to last node
 
   // Utility function to allocate a new node
   //ListNode< T > *getNewNode( const T &newData );
};
template <class T> class Stack : protected List<T>
{
public:
	Stack();
	~Stack();
	void push( const T &newData );
	bool pop( T &removedData );
	void top(T &topData);
	bool empty() const;
	void print();
};

template <class T>
Stack<T>::Stack()
{
	firstPtr = NULL;
	lastPtr = NULL;
}

template <class T>
void Stack<T>::print()
{
	print();
}

template <class T>
void Stack<T>::push(const T &newData)
{
	insertAtFront(newData);
}

template <class T>
bool Stack<T>::pop(T &removedData)
{
	return removeFromFront(removedData);
}

template <class T>
void Stack<T>::top(T &topData)
{
	topData = firstPtr->data;
}

template <class T>
bool Stack<T>::empty() const
{
	return isEmpty();
}

template <class T>
List<T>::List()
{
	firstPtr = NULL;
	lastPtr = NULL;
}

template <class T>
List<T>::~List()
{

}

template <class T>
void List<T>::insertAtFront (const T &newData)
{
	ListNode<T> *newNode = new ListNode<T>(newData);

	if(!isEmpty())
	{
		if(newNode != NULL)
		{
			newNode->nextPtr = firstPtr;
			firstPtr = newNode;
		}
	}
	else
	{
		lastPtr = newNode;
		firstPtr = newNode;
	}
}

template <class T>
void List<T>::insertAtBack (const T &newData)
{
	ListNode<T> *newNode = new ListNode<T>(newData);

	if(!isEmpty())
	{
		if(newNode != NULL)
		{
			lastPtr->nextPtr = newNode;
			lastPtr = newNode;
		}
	}
	else
	{
		lastPtr = newNode;
		firstPtr = newNode;
	}
}

template <class T>
bool List<T>::removeFromFront (T &removedData)
{
	bool success = false;
	ListNode<T> *removedNode = firstPtr;

	if(firstPtr != NULL)
	{
		success = true;
		firstPtr = firstPtr->nextPtr;
		removedData = removedNode->data;
		delete removedNode;
	}

	return success;
}

template <class T>
bool List<T>::removeFromBack (T &removedData)
{
	bool success = false;
	ListNode<T> *newLast = firstPtr;
	ListNode<T> *deleted = lastPtr;

	if(firstPtr != NULL)
	{
		success = true;

		while(newLast->nextPtr != deleted)
		{
			newLast = newLast->nextPtr;
		}
		removedData = deleted->data;
		lastPtr = newLast;
		delete deleted;
		lastPtr->nextPtr = NULL;
	}


	return success;
}

template <class T>
bool List<T>::isEmpty() const
{
	bool success = false;

	if(firstPtr == NULL)
	{
		success = true;
	}

	return success;
}

template <class T>
void List<T>::print() const
{
	ListNode<T> *cur = firstPtr;

	while(cur != NULL)
	{
		cout << cur->data << " -> ";
		cur = cur->nextPtr;
	}
	cout << endl;
}

template <class T>
ListNode<T>::ListNode (const T &newData)
{
	data = newData;
	nextPtr = NULL;
}

template <class T>
T ListNode<T>::getData() const
{
	return data;
}