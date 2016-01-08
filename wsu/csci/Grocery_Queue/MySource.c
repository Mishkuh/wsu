#include "MyHeader.h"

int main (void)
{
	int customerNumber = 1;
	int etotalTime = 0, ntotalTime = 0;
	int curTime = 0;
	int userTime = 0;
	int eArrive = 0, nArrive = 0;
	int eService = 0, nService = 0;
	Queue express;
	Queue normal;
	srand(time(NULL));

	express.pHead = NULL;
	express.pTail = NULL;
	normal.pHead = NULL;
	normal.pTail = NULL;

	//set random arrival time for first customer
	eArrive = (rand() % 5) +1;
	nArrive = (rand() % 5) +1;

	//determine how many minutes to test for
	printf("Please enter an amount of minutes you'd like to test: ");
	scanf("%d", &userTime);
	system("cls");

	for(curTime = 0; curTime < userTime; curTime++)
	{
		//if over 24 hours reset minutes
		if(curTime % 1440 == 0 && curTime != 0)
		{
			customerNumber = 1;
		}

		//if customer arrives at this time to express line add them to line
		if(curTime == eArrive)
		{
			customerArrival(&eService, &express, &customerNumber, &eArrive, &etotalTime, curTime, "express");
		}
		//if customer arrives at this time to normal line add them to line
		if(curTime == nArrive)
		{
			customerArrival(&nService, &normal, &customerNumber, &nArrive, &etotalTime, curTime, "normal");
		}

		//if theres a customer in line and their service time has come service them
		if(!isEmpty(express) && curTime == express.pHead->serviceTime)
		{
			customerServiced(&express, curTime);
		}

		//if theres a customer in line and their service time has come service them
		if(!isEmpty(normal) && curTime == normal.pHead->serviceTime)
		{
			customerServiced(&normal, curTime);
		}

		//print both lines every ten minutes
		if(((curTime % 10) == 0) && (curTime != 0))
		{
			printQ(express.pHead);
			printf("\n");
			printQ(normal.pHead);
			printf("\n");
			system("pause");
			system("cls");
		}
	}

	return 0;
}