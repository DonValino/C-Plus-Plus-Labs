#include <cstdlib>
#include <iostream>
#include "HotDogStand.h"
using namespace std;

int main(int argc, char *argv[])
{
	static int totalSold = 0;
	int id[5];
	int numberOfHotDogsSold[5];
	bool whileStillWantAdd = true;
	bool whileStillViewTotal = true;
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter The Id for Hot Dog Stand: " << (i + 1) << "\n";
		cin >> id[i];
		cout << "Enter The number of hot dogs sold by Hot Dog Stand: " << (i + 1) << "\n";
		cin >> numberOfHotDogsSold[i];
	}
	HotDogStand hotdog(id, numberOfHotDogsSold);

	while (whileStillWantAdd)
	{
		cout << "Enter the id of the Hotdog stand that sold a hotdog\n";
		int id = 0;
		cin >> id;
		hotdog.justSold(id);
		cout << "Item Sold\n";
		char f = 'a';
		cout << "Finish? Type 'y'. Otherwise type any other letters";
		cin >> f;
		if (f == 'y')
		{
			whileStillWantAdd = false;
		}
	}

	while (whileStillViewTotal)
	{
		cout << "Enter the id of the Hotdog stand you wish to view the total\n";
		int id = 0;
		cin >> id;
		cout << "Total for hot dog stand " << id << " is: " << hotdog.returnTheNumberOfHotDogsSold(id) << "\n";
		hotdog.totalHotdogSoldByAllStand();
		cout << "\nFinish? Type 'y'. Otherwise type any other letters\n";
		char f = 'a';
		cin >> f;
		if (f == 'y')
		{
			whileStillViewTotal = false;
		}
	}
 


	system("PAUSE");
	return EXIT_SUCCESS;
}


