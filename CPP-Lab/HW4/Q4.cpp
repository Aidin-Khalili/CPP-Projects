//This is program for calculate the word of one sentence.
#include <iostream>
#include <string>

using namespace std;

int main()
{
	char delimiter[] = { ' ',':',';',',','!','.','\0','\n','\r' };//This is our delimiters and for each of them we calculate one word.
	int z = 0, l;
	string str;
	cout << "Please enter your sentece" << endl;
	cin.ignore();
	getline(cin, str);
	l = str.length();
	for (int i = 1; i <= l; i++)
		if (strchr(delimiter, str[i]) && !strrchr(delimiter, str[i - 1]))
			z++;
	cout << z;
	return 0;
}