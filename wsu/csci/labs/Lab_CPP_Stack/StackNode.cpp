#include "StackNode.h"

StackNode::StackNode()
{
	mData = '\0';
	pNext = NULL;
}
StackNode::StackNode(char newData, StackNode *newNext)
{
	mData = newData;
	pNext = newNext;
}
StackNode::~StackNode()
{
}
char StackNode::getData()
{
	return mData;
}
StackNode * StackNode::getNext()
{
	return pNext;
}
void StackNode::setData(char c)
{
	mData = c;
}
void StackNode::setNext(StackNode *newNext)
{
	pNext = newNext;
}
ostream & operator<< (ostream& output,const StackNode rhs)
{
	output << rhs.mData;
	return output;
}