
//This program for calculate GCD of 2 numbers.
#include <iostream>

using namespace std;

int main()
{
	int a, b, n, m;
	cout << "Please enter your 2 numbers that you want to make their gcd " << endl;
	cin >> a >> b;
	n = a, m = b;
	for (; a != b; )
		if (a > b)
			a -= b;
		else
			b -= a;
	cout << "This is the gcd of " << n << " and " << m << " : " << a;

	return 0;
}