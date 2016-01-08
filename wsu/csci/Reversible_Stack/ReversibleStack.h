#ifndef REVERSIBLESTACK_H
#define REVERSIBLESTACK_H

#include <string>
#include <iostream>
#include <fstream>
#include "StackNode.h"

class ReversibleStack
{
public:
	ReversibleStack();
	~ReversibleStack();

	void push(int newData);
	int pop();
	bool isEmpty();
	void reverse();

	StackNode *pTop;
};

#endif