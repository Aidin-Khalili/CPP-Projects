//This is proram for dicing up to get non 6.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int dice_num = 6, i = 0;
	srand(time(0));
	cout << "This is proram for dicing up to get non 6." << endl;
	system("pause");
	while (dice_num == 6)
	{
		dice_num = rand() % 6 + 1;
		cout << "The " << i + 1 << "st chance :" << dice_num << endl;
		system("pause");
	}

	return 0;
}