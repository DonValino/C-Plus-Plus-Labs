//TASK1
/*#include <iostream>
using namespace std;

int myFirstFunctionConvertion(double ounce, double ton)
{
	double tonanswer = 0, boxAnswer = 0;
	tonanswer = ounce / ton;
	cout << "The weight of the package of cereal in ton is " << tonanswer << "\n";
	boxAnswer = ton / ounce;
	cout << "The number of boxes needed to fill a ton is:" << boxAnswer;


	return 0;
}

int main()
{
	double ounce = 0;
	double ton = 35273.92;

	cout << "Enter the weight of the cereal in once.\n";
	cin >> ounce;

	myFirstFunctionConvertion(ounce, ton);


	return 0;
}*/


//TASK2
/*#include <iostream>
using namespace std;


int main()
{
	double amountToKillMouse = 0;
	double weightOfMouse = 0;
	double weightGoal = 0;
	double const dietSodaArtificialSweetenerpercentage = 0.001;
	double answer = 0;

	cout << "Enter the amount of artificial sweeterner to kill a mice.\n";
	cin >> amountToKillMouse;

	cout << "Enter the weight of the mouse.\n";
	cin >> weightOfMouse;

	cout << "Enter the weight of the dieter's weight goal.\n";
	cin >> weightGoal;

	answer = (weightGoal / weightOfMouse) * amountToKillMouse;
	answer = answer * dietSodaArtificialSweetenerpercentage;

	cout << "The amount of Artificial Sweetener needed to kill the friend is" << answer;

	return 0;
}*/



//TASK 3
/*#include <iostream>
#include <string>
using namespace std;


int main()
{
	int numOfHoursWorked = 0;
	double hourlyWorkedRate = 0;
	double answer = 0;
	char s = 'y';
	bool test = true;

	while (test == true)
	{
		cout << "Enter the amount of hours worked.\n";
		cin >> numOfHoursWorked;

		cout << "Enter the hourly work rate.\n";
		cin >> hourlyWorkedRate;

		if (numOfHoursWorked > 40)
		{
			double const overTimePay = hourlyWorkedRate * 1.5;
			int numHoursOvertime = numOfHoursWorked - 40;
			answer = (40 * hourlyWorkedRate) + (numHoursOvertime * overTimePay);
		}
		else{
			answer = (numOfHoursWorked * hourlyWorkedRate);
		}

		cout << "The Gross Pay is: " << answer << "\n";
		cout << "Do you require an additional service?.\n";
		cout << "Enter Y or N?.";
		cin >> s;
		if (s == 'N')
		{
			test = false;
			cout << s;
		}
		else if (s == 'n')
		{
			test = false;
		}
		else
		{
			test = true;
		}


	}
	system("pause");
	return 0;

}*/


//TASK 4
/*#include <iostream>
#include <string>
#include <fstream> 
using namespace std;


int main()
{
	double const increaseRetroactive = 7.6;
	double increase = 0;
	double addSalary = 0;
	double salary = 1;
	double monthlySalary = 0;
	char s[] = "Hello";

	fstream textfile;
	textfile.open("H:\\LAB1C++\\Project3\\employeeRecord.txt", std::ifstream::in);
	while (!textfile.eof())
	{
		textfile >> salary;
		cout << salary;
	}

	textfile.close();
	increase = (salary / 100) * increaseRetroactive;
	salary = salary + increase;
	monthlySalary = salary / 12;

	std::ofstream ofs("H:\\LAB1C++\\Project3\\employeeRecord.txt", std::ofstream::out);

	ofs << "Salary: " << salary << "\nMonthly Salary: " << monthlySalary << "\nBack-Pay: " << increase;

	ofs.close();
	cout << "\n";
	system("pause");
	return 0;

}*/



/*Task 5
https://www.youtube.com/watch?v=Z-AkRgvBeTk
http ://stackoverflow.com/questions/4108313/how-do-i-find-the-length-of-an-array

#include <iostream>
#include <string>
#include <fstream> 
	using namespace std;


	  int main()
	  {
		  double const increaseRetroactive = 7.6;
		  double increase = 0;
		  double addSalary = 0;
		  double salary = 1;
		  double monthlySalary = 0;
		  char s[] = "Hello";
		  int numLine = 0;
		  double num[] = { 0, 0, 0, 0, 0, 0, 0 };
		  double totalAmountBackPay = 0;


		  fstream textfile;
		  std::string line;
		  int numEmployee = 0;
		  textfile.open("C:\\Users\\Jake\\\Desktop\\employeeRecord.txt", std::ifstream::in);
		  while (!textfile.eof())
		  {
			  int i = 0;
			  textfile >> salary;
			  num[i] = salary;
			  cout << salary;
			  i++;
		  }

		  textfile.close();

		  increase = (salary / 100) * increaseRetroactive;
		  salary = salary + increase;
		  monthlySalary = salary / 12;

		  std::ofstream ofs("C:\\Users\\Jake\\\Desktop\\employeeRecord.txt", std::ofstream::out);

		  ofs << "Name:   " << "Salary:   " << "Monthly Salary:   " << "Back-Pay:   " << "\nJake    " << salary << "          " << monthlySalary << "           " << increase << "   \n" << "Number of employee in text file : " << (numLine) << "\nTotol amount of back-pay: ";
		  ofs.close();

		  int numLines = 0;
		  ifstream in("C:\\Users\\Jake\\\Desktop\\employeeRecord.txt");
		  std::string unused;
		  while (std::getline(in, unused))
			  ++numLines;

		  cout << "LINE:" << numLines;
		  double numLeght = (sizeof(num) / sizeof(*num));
		  for (int i = 0; i < numLeght; i++)
		  {
			  cout << "Hello There Buddy";
			  totalAmountBackPay += (num[i] / 100) * increaseRetroactive;
		  }
		  ofs.open("C:\\Users\\Jake\\\Desktop\\employeeRecord.txt", std::ofstream::out);

		  ofs << "Name:   " << "Salary:   " << "Monthly Salary:   " << "Back-Pay:   " << "\nJake    " << salary << "          " << monthlySalary << "           " << increase << "   \n" << "\nNumber of employee in text file : " << (numLines - 3) << "\nTotol amount of back-pay: " << totalAmountBackPay;
		  ofs.close();

		  cout << "\n";
		  system("pause");
		  return 0;

	  }*/