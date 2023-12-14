//This is program for calculate least common multiple of 2 numbers.
#include <iostream>

using namespace std;

int main()
{
	int a, b, max;
	cout << "Please enter your 2 numbers that you want to calculate their least common multiple " << endl;
	cin >> a >> b;
	if (a > b) max = a;
	else max = b;
	for (max; (max % a != 0 || max % b != 0); max++);//Calaulate least common multiple
	cout << "This is the least common multiple  of " << a << " and " << b << " : " << max;

	return 0;
}