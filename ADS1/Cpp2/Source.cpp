#include <iostream>
#include <string>
#include <fstream> 
using namespace std;


int main()
{
	double euro = 0;
	int totalAmountOfChocolate = 0;
	int totalAmountOfLeftOverCoupons = 0;

	cout << "Enter the money to buy chocolate.Each chocolate is €1 each";
	cin >> euro;

	for (int i = 0; i<euro; i++)
	{
		if (euro > 7)
		{
			totalAmountOfChocolate = (int)((euro / 7) + euro);
			totalAmountOfLeftOverCoupons = (euro - (7 * ((int)((euro / 7))))) + ((int)((euro / 7)));
			while (totalAmountOfLeftOverCoupons > 7)
			{
				totalAmountOfChocolate += (int)(totalAmountOfLeftOverCoupons / 7);
				totalAmountOfLeftOverCoupons = totalAmountOfLeftOverCoupons - (7 * ((int)(totalAmountOfLeftOverCoupons / 7)));
			}
		}
	}
	cout << totalAmountOfChocolate;
	cout << "\n" << totalAmountOfLeftOverCoupons;
	cout << "\n";
	system("pause");
	return 0;

}