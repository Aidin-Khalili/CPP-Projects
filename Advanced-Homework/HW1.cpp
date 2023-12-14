#include <iostream>
using namespace std;
int menu()
{
	int chooseanswer = 0;
	system("cls");
	cout << "Choose the number of data type ..." << endl;
	cout << "1.Charector" << endl;
	cout << "2.Short integer" << endl;
	cout << "3.Integer" << endl;
	cout << "4.Long long integer" << endl;
	cout << "5.Signed integer" << endl;
	cout << "6.Unsigned integer" << endl;
	cout << "7.Bool" << endl;
	cout << "8.Float" << endl;
	cout << "9.Double" << endl;
	cout << "10.Long double" << endl;
	cout << "11.Quit" << endl;
	cin >> chooseanswer;
	if ((chooseanswer > 11) || (chooseanswer < 1))
		return -1;
	return chooseanswer;
}
void Char()
{
	cout << "This is the size of char : " << sizeof(char) << endl ;
	cout << "This is the Min number of char : " << CHAR_MIN << endl;
	cout << "This is the Max number of char : " << CHAR_MAX << endl;
	system("pause");
}
void Short_int()
{
	cout << "This is the size of Short integer : " << sizeof(short int) << endl;
	cout << "This is the Min number of Short integer : " << SHRT_MIN << endl;
	cout << "This is the Max number of Short integer : " << SHRT_MAX << endl;
	system("pause");
}
void Int()
{
	cout << "This is the size of integer : " << sizeof(int) << endl;
	cout << "This is the Min number of integer : " << INT_MIN << endl;
	cout << "This is the Max number of integer : " << INT_MAX << endl;
	system("pause");
}
void Long_long_int()
{
	cout << "This is the size of long long integer : " << sizeof(long long int) << endl;
	cout << "This is the Min number of long long integer : " << LLONG_MIN << endl;
	cout << "This is the Max number of long long integer : " << LLONG_MAX << endl;
	system("pause");
}
void Signed_int()
{
	cout << "This is the size of signed integer : " << sizeof(signed int) << endl;
	cout << "This is the Min number of signed integer : " << INT_MIN << endl;
	cout << "This is the Max number of signed integer : " << INT_MAX << endl;
	system("pause");
}
void Unsigned_int()
{
	cout << "This is the size of Unsigned integer : " << sizeof(unsigned int) << endl;
	cout << "This is the Min number of Unsigned integer : " << '0' << endl;
	cout << "This is the Max number of Unsigned integer : " << UINT_MAX << endl;
	system("pause");
}
void Bool()
{
	cout << "This is the size of bool : " << sizeof(bool) << endl;
	cout << "This is the Min number of bool : " << '0' << endl;
	cout << "This is the Max number of bool : " << '1' << endl;
	system("pause");
}
void Float()
{
	cout << "This is the size of float : " << sizeof(float) << endl;
	cout << "This is the Min number of float : " <<FLT_MIN << endl;
	cout << "This is the Max number of float : " << FLT_MAX << endl;
	system("pause");
}
void Double()
{
	cout << "This is the size of double : " << sizeof(double) << endl;
	cout << "This is the Min number of double : " << DBL_MIN << endl;
	cout << "This is the Max number of double : " << DBL_MAX << endl;
	system("pause");
}
void Long_double()
{
	cout << "This is the size of long double : " << sizeof(long double) << endl;
	cout << "This is the Min number of long double : " << LDBL_MIN << endl;
	cout << "This is the Max number of long double : " << LDBL_MAX << endl;
	system("pause");
}

int main()
{
	int a = 0;
	do{
		a=menu();
		system("cls");
		switch (a)
		{
		case(1):
			Char();
			break;
		case (2):
			Short_int();
			break;
		case (3):
			Int();
			break;
		case (4):
			Long_long_int();
			break;
		case (5):
			Signed_int();
			break;
		case(6):
			Unsigned_int();
			break;
		case (7):
			Bool();
			break;
		case (8):
			Float();
			break;
		case (9):
			Double();
			break;
		case (10):
			Long_double();
			break;
		case (-1):
			cout << "The number you have choosen is not correct please try again ...";
		}
	}while (a != 11);
	cout << "Have good time ;)"<< endl ;
	system("pause");
	return 0;
}
