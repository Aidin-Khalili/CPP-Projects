//This is program for binary search as digit numbers and if it requeird , we will sort the numbers.
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(vector <int> n, int buf, int min, int max)
{
	//This is function for binary search and it is recurtion.
	int mid = (min + max) / 2;
	if (max == min || min == mid)
		return -1;
	if (n[mid] == buf)
		return mid + 1;
	else if (buf > n[mid])
		return binary_search(n, buf, mid+1, max);
	else return binary_search(n, buf, min, mid-1);
}
bool is_sorted(vector <int> a, int n)
{
	//This is function that can computing the vector of number is sorted or no.
	int i = 0, j = 0;
	for (i; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (a[i] > a[j])
				return false;
	return true;
}

int main()
{
	int n, i, num;
	char menochoice = 'v', m;
	vector <int> a;
	cout << "Please enter the number : ";
	cin >> n; //Input the number of digits.
	for (i = 0; i < n; i++)
	{
		cout << "Please enter the (" << i + 1 << "th) number : ";
		cin >> num;
		a.push_back(num);//Enter the digits on vcetor.
	}
	if (is_sorted(a, n) == false)
	{
		//If the numbers are not sorted , we should sort it and then search on them.
		system("cls");
		cout << "Your numbers are not sorted but we sort them for you !" << endl << "These are your numbers : ";
		sort(a.begin(), a.end());
		for (i = 0; i < n; i++)
			cout << a[i] << " ";//Display the sorted digits. 
	}
	cout << endl <<"Please enter your search number : ";
	cin >> num;
	cout << "The result of searching is : " <<binary_search(a, num, 0, n) ;
	return 0;
}