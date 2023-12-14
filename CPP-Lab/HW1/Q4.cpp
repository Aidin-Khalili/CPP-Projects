//This is program for compute that which 3 numbers can make triangle or no.
#include <iostream>

using namespace std;

int main()
{
	int n[3];
	cout << "We want to compute that which 3 numbers can make triangle." << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Please enter number ( " << i + 1 << " ) : ";
		cin >> n[i];
		if (n[i] <= 0)
		{
			//For incorrect number we ask again and again.
			cout << "This is an incorrect number please try again" << endl;
			i--;
			continue;
		}
		cout << endl;
	}
	if ((n[0] < n[1] + n[2]) && (n[1] < n[0] + n[2]) && (n[2] < n[0] + n[1]))
		cout << "These numbers can make triangle. " << endl;
	else cout << "These numbers can't make triangle !" << endl;
	return 0;
}