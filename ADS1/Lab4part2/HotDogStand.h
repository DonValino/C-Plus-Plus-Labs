#include <iostream>
using namespace std;

class HotDogStand
{
private:
	int id[5];
	int hotDogsSoldThatDay[5];
public:
	HotDogStand(int idIn[5], int numSold[5]);
	void justSold(int idIn);
	int returnTheNumberOfHotDogsSold(int idIn);
	void totalHotdogSoldByAllStand();

};
