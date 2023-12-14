//This is program for playing XO game.
#include <iostream>

using namespace std;


void set_cell(char t[][3], char player, int i, int j) { t[i][j] = player; }
bool can_set(char t[][3], int i, int j)
{
	if (i > 2 || i < 0 || j > 2 || j < 0 || t[i][j] != ' ')
		return false;
	else return true;
}
void print(char t[][3])
{
	cout << "_____________" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << '|' << t[i][j] << "   ";
		}
		cout << endl << "_____________" << endl;
	}
}
bool is_win(char t[][3], char p)
{
	int i, j;
	for (i = 0; i < 3; i++)
		if (t[i][0] == t[i][1] && t[i][1] == t[i][2] && t[i][2] == p)
			return true;
	for (j = 0; j < 3; j++)
		if (t[0][j] == t[1][j] && t[1][j] == t[2][j] && t[2][j] == p)
			return true;
	if (t[0][0] == t[1][1] && t[1][1] == t[2][2] && t[2][2] == p)
		return true;
	if (t[2][0] == t[1][1] && t[1][1] == t[0][2] && t[0][2] == p)
		return true;
	return false;
}

int main()
{
	char table[3][3] = { {' ',' ',' ' } , {' ',' ',' ' } , {' ',' ',' ' } }, player = 'O';
	int row, col, i = 0;
	while (i < 9)
	{
		while (true)
		{
			cout << "It's the turn of player " << player << " please enter your chose for row and colmn." << endl;
			cin >> row >> col;
			if (can_set(table, row, col))
			{
				set_cell(table, player, row, col);
				break;
			}
			else
			{
				cout << "Ths row or colmn is not correct please try again " << endl;
				print(table);
			}
		}
		print(table);
		if (is_win(table, player))
		{
			cout << "Player " << player << " won the match congaragolation ! " << endl;
			break;
		}
		system("pause");
		system("cls");
		if (player == 'O')
			player = 'X';
		else player = 'O';
		i++;
	}
	if (i == 9)
		cout << "Draw !";

	return 0;
}