/*
	Michael Wiens
	PA_04
	Benjamin Cheung
	Oct 8th, 2014
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct qNode
{
	int customerNumber;
	int serviceTime;
	int totalTime;
	struct qNode *pNext;
}QNode;

typedef struct queue
{
	QNode *pHead;
	QNode *pTail;
}Queue;

void enqueue(Queue *q, int customerNumber, int serviceTime, int totalTime);
void dequeue(Queue *q, int *customerNumber, int *serviceTime, int *totalTime);
void customerArrival(int *serviceTime, Queue *line, int *customerNumber, int *arrivalTime, int *totalTime, int curTime, char *curLine);
void customerServiced(Queue *line, int curTime);
void printQ(QNode *line);
int isEmpty(Queue line);