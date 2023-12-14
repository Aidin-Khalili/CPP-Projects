//This is program for finding the divisor of one number.
#include <iostream>
#include <vector>
using namespace std;

int find_divisor(int n, vector <int>& a)
{
	int num = 0;
	for (int i = 1; i < n + 1; i++)
		if (n % i == 0)
		{
			a.push_back(i);
			num++;
		}
	return num;
}
int main()
{
	int n, num_div;
	vector <int> v; //Use vector for have dynamic array.
	cout << "Please enter number that you want to calculate its divisors : ";
	cin >> n;
	num_div = find_divisor(n, v);
	for (int i = 0; i < num_div; i++)
		cout << v[i] << ' ';
	cout << endl;
	return 0;
}