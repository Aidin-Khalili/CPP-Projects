/// This is program for gussing the number.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int guess_num, num_of_guess = 1, rand_num, max_limited;
	// We can ask to undrestand what's the max limit of number.
	cout << "Please determine the max limit of number : " << endl;
	cin >> max_limited;
	srand(time(0));
	rand_num = (rand() % max_limited) + 1;
	cout << "Enter your guess : " << endl;
	while (true)
	{
		cin >> guess_num;
		if (guess_num < rand_num)
			cout << "go over " << endl;
		else if (guess_num > rand_num)
			cout << "go under !" << endl;
		else
		{
			cout << "You win !" << endl;
			break;
		}
		num_of_guess++;
	}
	//In next line we say how many gusses did you do.
	cout << "The number of guesses is : " << num_of_guess;
	return 0;
}