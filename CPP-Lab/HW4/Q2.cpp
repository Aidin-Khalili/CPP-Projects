// This is program for out put a checkerboard with # and *.
#include <iostream>

using namespace std;

int main()
{
	char a[2] = { '#','*' };
	int m, n, k = 0;
	cout << "Please enter m and n." << endl;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++, k++)
		{
			cout << a[k % 2];
		}
		cout << endl;
		k++;
	}
	return 0;
}