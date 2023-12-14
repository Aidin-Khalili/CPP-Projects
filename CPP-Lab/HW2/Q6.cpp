//This is program for convert time from second to hour , minute and second.
#include <iostream>

#define Max_num 20

using namespace std;
int main()
{
	int t, sec, min, hour;
	cout << "Please enter time in second : ";
	cin >> t;
	hour = t / 3600;
	min = (t % 3600) / 60;
	sec = t - hour * 3600 - min * 60;
	cout << "It\'s :" << endl << hour << ':' << min << ':' << sec;
	return 0;
}