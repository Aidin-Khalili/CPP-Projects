//This is program for checking the array of number is sorted or no.
#include <iostream>
#include <vector>
using namespace std;
bool is_sorted_asc(vector<int> v)
{
	int i, j, x = v.size();
	for (i = 0; i < x - 1; i++)
		for (j = i + 1; j < x; j++)
			if (v[i] >= v[j])
				return false;
	return true;
}
bool is_sorted_des(vector<int> v)//This is function to diagnosis the array of number is sorted des or no.
{
	int i, j, x = v.size();
	for (i = 0; i < x - 1; i++)
		for (j = i + 1; j < x; j++)
			if (v[i] <= v[j])
				return false;
	return true;
}

int main()
{
	int n, i;
	vector <int> v;
	cout << "Please enter number of your array : ";
	cin >> n;
	v.resize(n);
	for (i = 0; i < n; i++)
	{
		cout << "Please enter the " << i + 1 << "th of your array : ";
		cin >> v[i];
	}
	if (is_sorted_asc(v) || is_sorted_des(v))
		cout << "It\'s sorted. " << endl;
	else cout << "It isn\'t sorted. " << endl;
	return 0;
}