//This is program for make random number without repeated.
#include <iostream>
#include <vector>
#include <ctime>
#define Max_ran 20

using namespace std;

bool Is_repeated(vector <int> a, int n)
{
	for (int i = 0; i < a.size(); i++)
		if (a[i] == n)
			return false;
	return true;
}

int main()
{
	vector <int> v;
	int n, i , rand_num;
	cout << "Please enter n for make random array : ";
	cin >> n;
	srand(time(0));
	rand_num = (rand() % Max_ran) + 1;
	for (i = 0; i < n; i++)
	{
		while (!Is_repeated(v, rand_num))
			rand_num = (rand() % Max_ran) + 1;
		v.push_back(rand_num);
		cout << v[i] << ' ';
	}

	return 0;
}