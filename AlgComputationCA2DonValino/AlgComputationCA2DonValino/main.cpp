#include <string>
#include <iostream>
#include "CityBST.h"
#include "City.h"
#include <utility>      // std::pair, std::make_pair
#include <ctime>
#include <chrono>

using namespace std;

// References:
// cplusplus. 2017. clock. [ONLINE] Available at: http://www.cplusplus.com/reference/ctime/clock/. [Accessed 7 April 2017].
// cplusplus. 2017. std::pair. [ONLINE] Available at: http://www.cplusplus.com/reference/utility/pair/. [Accessed 25 April 2017].
// carlduke. 2015.How can I measure CPU time and wall clock time on both Linux/Windows? [ONLINE] Available at: http://stackoverflow.com/questions/17432502/how-can-i-measure-cpu-time-and-wall-clock-time-on-both-linux-windows. [Accessed 25 April 2017].

int main()
{

	// Integer Values to measure running-time statistics
	int start_seconds_cpu;
	int stop_seconds_cpu;

	// Instance Of CityBST Binary Search Tree
	CityBST tree;

	// Insertion To The Tree /////////////////////////////////////////////////////////////////////////////////////////

	// Ireland
	std::pair <double, string> longtitudeIn;
	longtitudeIn.first = 3.0;
	longtitudeIn.second = "N";

	std::pair <double, string> latitudeIn;
	latitudeIn.first = 18.0;
	latitudeIn.second = "E";

	City c1("Dublin", longtitudeIn, latitudeIn, 10000,12);

	// Philippines
	longtitudeIn.first = 13.0;
	longtitudeIn.second = "S";

	latitudeIn.first = 28.0;
	latitudeIn.second = "E";
	City c2("Manila", longtitudeIn, latitudeIn, 10000, 12);

	// Mexico
	longtitudeIn.first = 13.0;
	longtitudeIn.second = "S";

	latitudeIn.first = 26.0;
	latitudeIn.second = "E";
	City c3("Zacatecas", longtitudeIn, latitudeIn, 10000, 12);

	// Adding To The Tree
	tree.add(c1);
	tree.add(c2);
	tree.add(c3);

	// Mexico
	longtitudeIn.first = 123.0;
	longtitudeIn.second = "S";

	latitudeIn.first = 226.0;
	latitudeIn.second = "E";
	City c6("Zacatecas", longtitudeIn, latitudeIn, 10000, 12);

	// Collecting Running-time statistics for Adding a new node to the Tree

	start_seconds_cpu = clock(); // Returns the processor time consumed by the program. // CPU
	auto start_seconds_wall_add = std::chrono::system_clock::now(); // Wall

	// Tested for adding the third node to the tree
	tree.add(c6);

	// stop timer
	stop_seconds_cpu = clock();
	std::chrono::duration<double> stop_seconds_wall_add = (std::chrono::system_clock::now() - start_seconds_wall_add);
	std::cout << std::endl << std::endl << "Adding To The Tree Executed In CPU Clock: " << (stop_seconds_cpu - start_seconds_cpu) / double(CLOCKS_PER_SEC) << "s\n" << std::endl; // CLOCKS_PER_SEC =  The value returned is expressed in clock ticks, which are units of time of a constant but system - specific length
	std::cout << "Adding To The Tree Executed In Wall Clock: " << stop_seconds_wall_add.count() << "s\n" << std::endl;


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////









	// Testing to ensure that you can't insert two sities within the same coordinates / location
	// USA
	longtitudeIn.first = 13.0;
	longtitudeIn.second = "S";

	latitudeIn.first = 26.0;
	latitudeIn.second = "E";
	City c4("Orange County", longtitudeIn, latitudeIn, 10000, 12);
	tree.add(c4);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////










	// Collecting Running-time statistics for Checking if a city with a particular name exist in the Binary Search Tree

	start_seconds_cpu = clock(); // Returns the processor time consumed by the program.
	auto start_seconds_wall_find = std::chrono::system_clock::now(); // Wall

	// Check if a city with a particular name exist in the Binary Search Tree
	if (tree.find("Manila") == true)
	{
		cout << "The City: ''Manila'' exist" << endl << endl;
	}
	else
	{
		cout << "The City: ''Manila'' does not exist" << endl << endl;
	}

	// stop timer
	stop_seconds_cpu = clock();
	std::chrono::duration<double> stop_seconds_wall_find = (std::chrono::system_clock::now() - start_seconds_wall_find);
	std::cout << std::endl << std::endl << "Checking if a city with a particular name exist Executed In CPU Clock: " << (stop_seconds_cpu - start_seconds_cpu) / double(CLOCKS_PER_SEC) << "s\n" << std::endl; // CLOCKS_PER_SEC =  The value returned is expressed in clock ticks, which are units of time of a constant but system - specific length
	std::cout << "Checking if a city with a particular name exist Executed In Wall Clock: " << stop_seconds_wall_find.count() << "s\n" << std::endl;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////












	// Deleting a node
	std::pair <double, string> longtitudeManila;
	longtitudeManila.first = 27.0;
	longtitudeManila.second = "E";

	std::pair <double, string> latitudeManila;
	latitudeManila.first = 12.0;
	latitudeManila.second = "S";

	// Wrong location but right name
	tree.deleteNode("Manila", longtitudeManila, latitudeManila);

	// Collecting Running-time statistics for deleting a node in the Binary Search Tree

	start_seconds_cpu = clock(); // Returns the processor time consumed by the program.
	auto start_seconds_wall_delete = std::chrono::system_clock::now(); // Wall

	// Right location and name
	longtitudeManila.first = 28.0;
	longtitudeManila.second = "E";

	latitudeManila.first = 13.0;
	latitudeManila.second = "S";
	tree.deleteNode("Manila", longtitudeManila, latitudeManila); 
	

	// stop timer
	stop_seconds_cpu = clock();
	std::chrono::duration<double> stop_seconds_wall_delete = (std::chrono::system_clock::now() - start_seconds_wall_delete);
	std::cout << std::endl << std::endl << "Deleting a node in the Binary Search Tree Executed In CPU Clock: " << (stop_seconds_cpu - start_seconds_cpu) / double(CLOCKS_PER_SEC) << "s\n" << std::endl; // CLOCKS_PER_SEC =  The value returned is expressed in clock ticks, which are units of time of a constant but system - specific length
	std::cout << "Deleting a node in the Binary Search Tree Executed In Wall Clock: " << stop_seconds_wall_delete.count() << "s\n" << std::endl;

	cout << "City: ''Manila'' Deleted" << endl << endl;

	// City ''Manila'' no longer exist in the Binary Search Tree
	if (tree.find("Manila") != true)
	{
		cout << "The City: ''Manila'' does not exist" << endl << endl;
	}










	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Collecting Running-time statistics for Checking The Height Of The Tree

	start_seconds_cpu = clock();  // Returns the processor time consumed by the program.
	auto start_seconds_wall_height = std::chrono::system_clock::now(); // Wall

	// Checking The Height Of The Tree
	cout << "Height Of The Tree: " << tree.height() << endl << endl;

	// stop timer
	stop_seconds_cpu = clock();
	std::chrono::duration<double> stop_seconds_wall_height = (std::chrono::system_clock::now() - start_seconds_wall_height);
	std::cout << std::endl << std::endl << "Checking The Height Of The Tree Executed In CPU Clock: " << (stop_seconds_cpu - start_seconds_cpu) / double(CLOCKS_PER_SEC) << "s\n" << std::endl; // CLOCKS_PER_SEC =  The value returned is expressed in clock ticks, which are units of time of a constant but system - specific length
	std::cout << "Checking The Height Of The Tree Executed In Wall Clock: " << stop_seconds_wall_height.count() << "s\n" << std::endl;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////











	// Traversals

	// Collecting Running-time statistics for Pre-Order traversal

	start_seconds_cpu = clock(); // Returns the processor time consumed by the program.
	auto start_seconds_wall_Pre_Order = std::chrono::system_clock::now(); // Wall

	// Pre-Order traversal
	cout << "////////////////////////////////////////////////////" << endl;
	cout << "Pre-Order traversal: " << endl;
	tree.preOrder();
	cout << "////////////////////////////////////////////////////" << endl;


	// stop timer
	stop_seconds_cpu = clock();
	std::chrono::duration<double> stop_seconds_wall_Pre_Order = (std::chrono::system_clock::now() - start_seconds_wall_Pre_Order);
	std::cout << std::endl << std::endl << "Pre-Order traversal Executed In CPU Clock: " << (stop_seconds_cpu - start_seconds_cpu) / double(CLOCKS_PER_SEC) << "s\n" << std::endl; // CLOCKS_PER_SEC =  The value returned is expressed in clock ticks, which are units of time of a constant but system - specific length
	std::cout << "Pre-Order traversal Executed In Wall Clock: " << stop_seconds_wall_Pre_Order.count() << "s\n" << std::endl;

	// Collecting Running-time statistics for In-Order traversal

	start_seconds_cpu = clock(); // Returns the processor time consumed by the program.
	auto start_seconds_wall_In_Order = std::chrono::system_clock::now(); // Wall

	// In-Order traversal
	cout << "////////////////////////////////////////////////////" << endl;
	cout << "In-Order traversal: " << endl;
	tree.inOrder();
	cout << "////////////////////////////////////////////////////" << endl;


	// stop timer
	stop_seconds_cpu = clock();
	std::chrono::duration<double> stop_seconds_wall_In_Order = (std::chrono::system_clock::now() - start_seconds_wall_In_Order);
	std::cout << std::endl << std::endl << "In-Order traversal Executed In CPU Clock: " << (stop_seconds_cpu - start_seconds_cpu) / double(CLOCKS_PER_SEC) << "s\n" << std::endl; // CLOCKS_PER_SEC =  The value returned is expressed in clock ticks, which are units of time of a constant but system - specific length
	std::cout << "In-Order traversal Executed In Wall Clock: " << stop_seconds_wall_In_Order.count() << "s\n" << std::endl;

	// Collecting Running-time statistics for  Post-Order traversal

	start_seconds_cpu = clock(); // Returns the processor time consumed by the program.
	auto start_seconds_wall_Post_Order = std::chrono::system_clock::now(); // Wall

	// Post-Order traversal
	cout << "////////////////////////////////////////////////////" << endl;
	cout << "Post-Order traversal: " << endl;
	tree.postOrder();
	cout << "////////////////////////////////////////////////////" << endl;


	// stop timer
	stop_seconds_cpu = clock();
	std::chrono::duration<double> stop_seconds_wall_Post_Order = (std::chrono::system_clock::now() - start_seconds_wall_Post_Order);
	std::cout << std::endl << std::endl << "Post-Order traversal Executed In CPU Clock: " << (stop_seconds_cpu - start_seconds_cpu) / double(CLOCKS_PER_SEC) << "s\n" << std::endl; // CLOCKS_PER_SEC =  The value returned is expressed in clock ticks, which are units of time of a constant but system - specific length
	std::cout << "Post-Order traversal Executed In Wall Clock: " << stop_seconds_wall_Post_Order.count() << "s\n" << std::endl;








	cout << "////////////////////////////////////////////////////" << endl;
	cout << "Print All Nodes Within A Given Distance: " << endl;

	std::pair <double, string> minlongtitudeIn;
	minlongtitudeIn.first = 10;
	std::pair <double, string> maxlongtitudeIn;
	maxlongtitudeIn.first = 30;

	// Minimum latitude exceeds the latitude of the city Dublin. Therefore Dublin is not printed. Only the city of Mexico - Zacatecas is printed
	std::pair <double, string> minlatitudeIn;
	minlatitudeIn.first = 10;
	std::pair <double, string> maxlatitudeIn;
	maxlatitudeIn.first = 30;

	// Collecting Running-time statistics for Printing All Records Within A Given Distance

	start_seconds_cpu = clock();  // Returns the processor time consumed by the program.
	auto start_seconds_wall_printByDistance = std::chrono::system_clock::now(); // Wall

	tree.printAllRecordsWithinAGivenDistance(minlongtitudeIn, minlatitudeIn, maxlongtitudeIn, maxlatitudeIn);

	// stop timer
	stop_seconds_cpu = clock();
	std::chrono::duration<double> stop_seconds_wall_printByDistance = (std::chrono::system_clock::now() - start_seconds_wall_printByDistance);
	std::cout << std::endl << std::endl << "Printing All Records Within A Given Distance Executed In CPU Clock: " << (stop_seconds_cpu - start_seconds_cpu) / double(CLOCKS_PER_SEC) << "s\n" << std::endl; // CLOCKS_PER_SEC =  The value returned is expressed in clock ticks, which are units of time of a constant but system - specific length
	std::cout << "Printing All Records Within A Given Distance Executed In Wall Clock: " << stop_seconds_wall_printByDistance.count() << "s\n" << std::endl;

	system("pause");
	return 0;
}