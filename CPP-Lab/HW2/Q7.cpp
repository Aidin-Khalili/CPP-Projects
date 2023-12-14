//This is program for make some random number and save them in array and after that subtraction to 5.
#include <iostream>
#include <cstdlib>
#include <ctime>

#define Max_num 20

using namespace std;
int main()
{
	int n[20];
	srand(time(0));
	cout << "For the first : ";
	for (int i = 0; i < Max_num; i++)
	{
		n[i] = rand() % 100; // make random number from limited of 0 up to 99.
		cout << n[i] << ' ';
	}
	cout << endl << "And The last : ";
	for (int i = 0; i < Max_num; i++)
	{
		n[i] -= 5;
		cout << n[i] << ' ';
	}
	return 0;
}