#ifndef STACKNODE_H
#define STACKNODE_H

#include <string>
#include <iostream>
#include <fstream>

class StackNode
{
public:
	StackNode(int newData);
	~StackNode();

	int data;
	StackNode *pNext;
};

#endif