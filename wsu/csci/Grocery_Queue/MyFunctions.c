#include "MyHeader.h"

/*
	Function: makeNode()
	Date Created: 10-6-14
	Date Last Modified:  10-6-14
	Description: makes a new node
	Input Parameters: values to assign to new node
	Returns: node pointer storing new values
*/
QNode *makeNode(int custNo, int serviceTime, int totalTime)
{
	QNode * pMem = NULL;

	pMem = (QNode *) malloc (sizeof(QNode));

	//if able to allocate memory assign values
	if(pMem != NULL)
	{
		pMem->customerNumber = custNo;
		pMem->serviceTime = serviceTime;
		pMem->totalTime = totalTime;
		pMem->pNext = NULL;
	}

	return pMem;
}
/*
	Function: enqueue
	Date Created: 10-6-14
	Date Last Modified:  10-6-14
	Description: adds a node to end of queue
	Input Parameters: queue, and values to assign to node
	Returns: void
*/
void enqueue(Queue *q, int customerNumber, int serviceTime, int totalTime)
{
	QNode *pMem = NULL;

	//make a node to add to queue
	pMem = makeNode(customerNumber, serviceTime,totalTime);

	//if no items in queue
	if(q->pHead == NULL)
	{
		q->pHead = pMem;
	}
	//add item to back of queue and update new tail
	pMem->pNext = q->pTail;
	q->pTail = pMem;
}
/*
	Function: dequeue()
	Date Created: 10-6-14
	Date Last Modified:  10-6-14
	Description: removes nodes from a queue
	Input Parameters: q, pointers to hold values
	Returns: void
*/
void dequeue(Queue *q, int *customerNumber, int *serviceTime, int *totalTime)
{
	QNode *pTemp = NULL;
	pTemp = (QNode *) malloc(sizeof(QNode));

	pTemp =	q->pHead;

	//if able to allocate pTemp and set to head set values
	if(pTemp != NULL)
	{
		*customerNumber = pTemp->customerNumber;
		*serviceTime = pTemp->serviceTime;
		*totalTime = pTemp->totalTime;

		//if only one item
		if(q->pHead == q->pTail)
		{
			q->pTail = NULL;
		}

		//set head to next
		q->pHead = q->pHead->pNext;

		free(pTemp);
	}
}
/*
	Function: customerArrival()
	Date Created: 10-6-14
	Date Last Modified:  10-6-14
	Description: adds customer to a line and updates times
	Input Parameters: times to modify, line to add to, and name of the line
	Returns: void
*/
void customerArrival(int *serviceTime, Queue *line, int *customerNumber, int *arrivalTime, int *totalTime, int curTime, char *curLine)
{
	//update service time and total time with random number 
	*serviceTime = ((rand() %5)+1) + curTime;
	*totalTime += *serviceTime;

	//alert user customer arrived
	printf("Customer %d has arrived to %s line at %d minutes\n", *customerNumber, curLine, *arrivalTime);
	system("pause");
	system("cls");

	//put customer in line
	enqueue(line, *customerNumber, *serviceTime, *totalTime);

	//set new arrival time for next customer and update customer number
	*arrivalTime = ((rand() %5)+1) + curTime;
	*customerNumber = (*customerNumber + 1);
}
/*
	Function: customerServiced()
	Date Created: 10-6-14
	Date Last Modified:  10-6-14
	Description: services a customer and removes them from line
	Input Parameters: line to service, current time
	Returns: void
*/
void customerServiced(Queue *line, int curTime)
{
	int tempCustomerNumber = 0, tempServiceTime = 0, tempTotalTime = 0;

	//if the customers has been serviced remove them from line
	dequeue(line, &tempCustomerNumber, &tempServiceTime, &tempTotalTime);

	//alert user
	printf("Customer %d has been helped after %d minutes\n", tempCustomerNumber, tempServiceTime);
	system("pause");
	system("cls");
}
/*
	Function: printQ()
	Date Created: 10-6-14
	Date Last Modified:  10-6-14
	Description: prints items in a line
	Input Parameters: line to print
	Returns: void
*/
void printQ(QNode *line)
{
	if(line == NULL)
	{
		printf("end");
	}
	else
	{
		printf("customer %d-->", line->customerNumber);
		printQ(line->pNext);
	}
}
/*
	Function: isEmpty()
	Date Created: 10-6-14
	Date Last Modified:  10-6-14
	Description: determines if a line is empty
	Input Parameters: line to check
	Returns: 1 if empty 0 if not
*/
int isEmpty(Queue line)
{
	int result = 0;

	if(line.pHead == NULL)
	{result = 1;}
	
	return result;
}
