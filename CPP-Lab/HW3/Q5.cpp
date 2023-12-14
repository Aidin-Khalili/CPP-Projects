//This is program for write all indivisible number of 2 numbers.
#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cout << "Please enter n , m : ";
	cin >> n >> m;
	for (int i = 1; i <= 80; i++)
	{
		if (i % n != 0 && i % m != 0)
			cout << i << ' ';
	}
	return 0;
}