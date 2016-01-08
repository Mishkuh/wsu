#include "StackNode.h"

StackNode::StackNode(int newData)
{
	data = newData;
	pNext = NULL;
}

StackNode::~StackNode(){}