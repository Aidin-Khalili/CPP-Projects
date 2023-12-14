//This is program for find Max and Min of 20 numbers.
#include <iostream>
#define Max_num 20

using namespace std;

int main()
{
	int max = INT_MIN, min = INT_MAX;
	int n[Max_num];
	//INPUT
	for (int i = 0; i < Max_num; i++)
	{
		cout << "Please enter the " << i + 1 << "th number : ";
		cin >> n[i];
	}
	//PROCESS
	for (int i = 0; i < Max_num; i++)
	{
		if (n[i] > max)
			max = n[i];
		if (n[i] < min)
			min = n[i];
	}
	//OUTPUT
	cout << "Maximum of this number is : " << max << endl
		<< "Minimum of this number is : " << min << endl;

	return 0;
}