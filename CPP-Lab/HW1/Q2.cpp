/// This is the program for do some math computing .
#include <iostream>
#include <cmath>

using namespace std;
int Menu();
float Mul(int a, int b) { return a * b; }
float Div(int a, int b) { return a / b; }
float Add(int a, int b) { return a + b; }
float Sub(int a, int b) { return a - b; }
float Sqrt(int a) { return sqrt(a); }
float Sin(float a) { a *= 0.0174532925; return sin(a); }
float Cos(float a) { a *= 0.0174532925; return cos(a); }
float Log(float a) { return log10(a); }
int main()
{
	int choice_menu = 0, a, b;
	float c;

	while (choice_menu != 9)
	{
		choice_menu = Menu();
		switch (choice_menu)
		{
		case(1):
			cout << "Please enter your numbers : ";
			cin >> a >> b;
			cout << "This the sum of " << a << " and " << b << " : " << Add(a, b) << endl;
			break;
		case(2):
			cout << "Please enter your numbers : ";
			cin >> a >> b;
			cout << "This the subtraction of " << a << " and " << b << " : " << Sub(a, b) << endl;
			break;
		case(3):
			cout << "Please enter your numbers : ";
			cin >> a >> b;
			cout << "This the multiple of " << a << " and " << b << " : " << Mul(a, b) << endl;
			break;
		case(4):
			cout << "Please enter your numbers : ";
			cin >> a >> b;
			cout << "This the divition of " << a << " and " << b << " : " << Div(a, b) << endl;
			break;
		case(5):
			cout << "Please enter your number : ";
			cin >> a;
			cout << "This the sqrt of " << a << " : " << Sqrt(a) << endl;
			break;
		case(6):
			cout << "Please enter your number(degree) : ";
			cin >> c;
			cout << "This the sin of " << c << "(dgree) : " << Sin(c) << endl;
			break;
		case(7):
			cout << "Please enter your number(dgree) : ";
			cin >> c;
			cout << "This the cos of " << c << "(dgree) : " << Cos(c) << endl;
			break;
		case(8):
			cout << "Please enter your number : ";
			cin >> c;
			cout << "This the log of " << c << " : " << Log(c) << endl;
			break;
		case(9):
			cout << " Have good time ;) " << endl;
			break;
		default:
			cout << "Your choice number is not correct please try again " << endl;
		}
		system("pause");
		system("cls");
	}

	return 0;
}
int Menu()
{
	int choice;
	cout << "Which one do you whant : " << endl
		<< "1.Calculate sum of two number" << endl
		<< "2.Calculate subtraction of two number" << endl
		<< "3.Calculate multiple of two number" << endl
		<< "4.Calculate divition of two number" << endl
		<< "5.Calculate sqrt " << endl
		<< "6.Calculate sin " << endl
		<< "7.Calculate cos " << endl
		<< "8.Calculate log" << endl
		<< "9.Exit" << endl;
	cin >> choice;
	return choice;
}

