#include "HotDogStand.h"


static int totalHotdogSold = 0;
HotDogStand::HotDogStand(int idIn[], int numSold[])
{
	for (int i = 0; i < 5; i++)
	{
		id[i] = idIn[i];
		hotDogsSoldThatDay[i] = numSold[i];
		totalHotdogSold += numSold[i];
	}
}

void HotDogStand::justSold(int idIn)
{
	int idYes = 0;
	for(int i =0; i < 5; i++)
	{
	   if(hotDogsSoldThatDay[i] == idIn)
		{
			idYes = i;
		}
	}
	hotDogsSoldThatDay[idYes]++;
	totalHotdogSold++;
}

static int returnTotalHotdogSold()
{
	return  totalHotdogSold;
}

int HotDogStand::returnTheNumberOfHotDogsSold(int idIn)
{
	int idYes = 0;
	for(int i =0; i < 5; i++)
	{
	   if(hotDogsSoldThatDay[i] == idIn)
		{
			idYes = i;
		}
	}
	return hotDogsSoldThatDay[idYes];
}

void HotDogStand::totalHotdogSoldByAllStand()
{
	cout << "The total number of Hot Dogs sold by all stands is: " << returnTotalHotdogSold();
}


                                       