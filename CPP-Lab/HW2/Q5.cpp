//This is program for convert time to second.
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	string str_time;
	cout << "Please enter time that you want to convert to second : ";
	cin >> str_time;
	int colon_pos = str_time.find(':');
	int hour = atoi(str_time.substr(0, colon_pos).c_str());
	str_time = str_time.substr(colon_pos + 1);
	colon_pos = str_time.find(':');
	int min = atoi(str_time.substr(0, colon_pos).c_str());
	int sec = atoi(str_time.substr(colon_pos + 1).c_str());
	cout << hour * 3600 + min * 60 + sec << "(second)\n";
	return 0;
}