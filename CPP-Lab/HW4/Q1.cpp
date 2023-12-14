//This is program for Complex number and getting sum,subtraction and multiple of two Complex num.
#include <iostream>

using namespace std;

struct Complex
{
	double real;
	double imag;
	Complex& operator+(const Complex& b) //Over loading operator + .
	{  
		real += b.real;
		imag += b.imag;
		return *this;
	}
	Complex& operator-(const Complex& b) //Over loading operator - .
	{
		real -= b.real;
		imag -= b.imag;
		return *this;
	}
	Complex& operator*(const Complex& b)  //Over loading operator * .
	{
		double temp;
		temp = real * b.real - imag * b.imag;
		imag = real * b.imag + imag * b.real;
		real = temp;
		return *this;
	}
};

ostream& operator<<(ostream& out, const Complex& c)// over loading the out out of program for all Complex number.
{
	out << c.real;
	if (c.imag > 0)
	{
		if (c.imag == 1)
			out << '+' << 'i';
		else
			out << '+' << c.imag << 'i';
	}
	else if (c.imag < 0)
		if (c.imag == -1)
			out << '-i';
		else
			out << c.imag << 'i';

	return out;
}
unsigned int Menu()
{
	unsigned int choicemenu;
	cout << "Which one do you want ? " << endl
		<< "1.Multiple " << endl
		<< "2.Sum" << endl
		<< "3.Sub" << endl;
	cin >> choicemenu;
	system("cls");
	return choicemenu;
}
int main()
{
	int choice = Menu();
	Complex a, b;
	cout << "Plase enter the real number of a : ";
	cin >> a.real;
	cout << "Plase enter the imag number of a : ";
	cin >> a.imag;
	cout << "Plase enter the real number of b : ";
	cin >> b.real;
	cout << "Plase enter the imag number of b : ";
	cin >> b.imag;
	switch (choice)
	{
	case (1):

		cout << a * b;
		break;
	case (2):
		cout << a + b;
		break;
	case (3):
		cout << a - b;
		break;
	default:
		cout << "Your choice is not correct please try again later." << endl;
	}

	return 0;
}