//This is program for calculate subtraction of 2 times.
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


int convert_to_second(string str_time)
{

	int colon_pos = str_time.find(':');
	int hour = atoi(str_time.substr(0, colon_pos).c_str());
	str_time = str_time.substr(colon_pos + 1);
	colon_pos = str_time.find(':');
	int min = atoi(str_time.substr(0, colon_pos).c_str());
	int sec = atoi(str_time.substr(colon_pos + 1).c_str());
	return hour * 3600 + min * 60 + sec;
}

int main()
{
	string str_time;
	int t1, t2, subtraction, hour, min, sec;
	cout << "Please enter first time (hour:minute:second) : ";
	cin >> str_time;
	t1 = convert_to_second(str_time);
	cout << "Please enter second time (hour:minute:second) : ";
	cin >> str_time;
	t2 = convert_to_second(str_time);
	subtraction = abs(t2 - t1);
	hour = subtraction / 3600;
	min = (subtraction % 3600) / 60;
	sec = subtraction % 60;
	if (t2 >= t1)
		cout << "t(2) - t(1) = ";
	else if (t1 > t2)
		cout << "t(1) - t(2) = ";
	cout << subtraction << "(second) or "
		<< hour << ':' << min << ':' << sec << endl;
	return 0;
}