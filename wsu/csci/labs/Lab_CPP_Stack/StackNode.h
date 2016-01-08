#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;

class Stack;

class StackNode
{
public:
	StackNode();
	StackNode(char newData, StackNode *newNext);
	~StackNode();

	char getData();
	StackNode * getNext();

	void setData(char c);
	void setNext(StackNode *newNext);

	friend ostream & operator<< (ostream& output,const StackNode sn);
	friend class Stack;

private:
	char mData;
	StackNode *pNext;
};

class Stack
{
public:
	Stack();
	~Stack();
	void push(char c);
	char pop();
	char peek();
	bool isEmpty();

	friend ostream& operator<< (ostream& output, const Stack& s);

private:
	StackNode *top;
	int size;
};