//This is program for calculate the number is prime or no.
#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int n)
{
	int Sqrt = sqrt(n);
	for (int i = 2; i <= Sqrt; i++)
		if (n % i == 0)
			return false;
	return true;
}

int main()
{
	int n;
	cout << "Please enter your number that you want undrestand it's prime or no " << endl;
	cin >> n;
	if (is_prime(n))
		cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}