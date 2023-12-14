//This is the program for hangman game.
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int make_rand_num(int max);//The function that make random number between 0 and max.
string make_guess_hangman(string str[], int a);
bool is_same_char(char s, char c);
void print(string s);

int main()
{
	string str[] = { "apple","orange","bread","phone","computer","human","book","cake","pizza","desk","pen","watch","lamp","soccer" };
	string guess;
	int rand_num, i, max_guess;
	char g;
	bool choice = 1;
	cout << "Get ready to guess one vocab." << endl;
	system("pause");
	srand(time(0));
	while (choice)
	{
		system("cls");
		rand_num = make_rand_num(sizeof(str) / sizeof(string));
		guess = make_guess_hangman(str, rand_num);
		max_guess = 2.5 * guess.length();
		print(guess);
		for (i = 0; i < max_guess; i++)
		{
			cin >> g;
			for (int j = 0; j < guess.length(); j++)
				if (is_same_char(str[rand_num][j], g))
					guess[j] = tolower(g);
			print(guess);
			if (str[rand_num] == guess)
			{
				cout << "You win !" << endl;
				break;
			}
		}
		if (i == max_guess)
			cout << "Sorry you have " << max_guess << " guesses , "
			<< "and you couldn\'t guess it." << endl
			<< "It was : " << str[rand_num] << endl;
		cout << "Do you want to play again or no ? (1 = yes and 0 = no )" << endl;
		cin >> choice;
		if (choice != 0 || choice != 1)
			choice = 0;
	}
	system("cls");
	cout << "Have good time :D" << endl;
	return 0;
}
int make_rand_num(int max)
{
	int ran;
	ran = (rand() % max);
	return ran;
}
string make_guess_hangman(string str[], int ran)
{
	string q;
	int len;
	len = str[ran].length();
	for (int i = 0; i < len; i++)
		q += '_';
	return q;

}
bool is_same_char(char s, char c)
{
	char a[2] = { toupper(c),tolower(c) };
	if (s == a[0] || s == a[1])
		return true;
	else return false;
}
void print(string s)
{
	int len = s.length();
	for (int i = 0; i < len; i++)
		cout << s[i] << ' ';
	cout << endl;
}