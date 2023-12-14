//This is program for convert cm to inch
#include <iostream>

using namespace std;

int main()
{
	float  n;
	cout << "Please enter number that you whant to change it's unit ( cm -> inch ) : ";
	cin >> n;
	n *= 0.39370079;
	cout << "This is your answer : " << n << "(inch)";
	return 0;
}