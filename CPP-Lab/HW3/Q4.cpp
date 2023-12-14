//This is program for compute what day is some days later.
#include <iostream>

using namespace std;

int main()
{
	unsigned int n;
	string week[] = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
	cout << "Please enter number of the day after Sunday : ";
	cin >> n;
	n--;
	if (n > 6)
		n = n % 7;
	else if (n == -1)
		n = 6;
	cout << week[n];
	return 0;
}