//This is program for calculate BMI and say what is your body mass index.
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float w = 1, h = 1, BMI;
	cout << "Please enter height (m) : ";
	while (true)
	{
		cin >> h;
		if (h <= 0)
			cout << "Envalid number please try again ." << endl;
		else break;
	}
	cout << "Please enter weight (kg) : ";
	while (true)
	{
		cin >> w;
		if (w <= 0)
			cout << "Envalid number please try again ." << endl;
		else break;
	}
	BMI = w / pow(h, 2);
	if (BMI < 30)
	{
		if (BMI > 25)
			cout << "Overweight";
		else if (BMI > 18.5)
			cout << "Nurmal";
		else cout << "Underweight";
	}
	else
	{
		if (BMI < 35)
			cout << "Obese";
		else cout << "Extremly Obese";
	}
	cout << "( BMI was : " << BMI << " )" << endl;
	return 0;
}