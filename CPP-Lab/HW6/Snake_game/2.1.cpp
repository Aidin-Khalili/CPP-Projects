#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <dos.h>
#include <conio.h>
#include <stdlib.h>

#define LEN 80
#define WID 25
#define MIN_SPEED 5
#define UL static_cast<char>(201)
#define H static_cast<char>(205)
#define UR static_cast<char>(187)
#define V static_cast<char>(186)
#define DL static_cast<char>(200)
#define DR static_cast<char>(188) 
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
WORD wOldColorAttrs;
HANDLE hStdout, hStdin;

enum COLORS { Black, Blue, Green, Cyan, Red, Magenta, Brown, White, Gray, Bright_Blue, Bright_Green, Bright_Cyan, Bright_Red, Bright_Magenta, Yellow, Bright_White };
int COLOR[12][2] = { Bright_White,Green, Black,Bright_White, Black,White, Blue,Brown, Black,Yellow, Yellow,Bright_Red, Black,Bright_Magenta, Yellow,Magenta, Black,Red, Yellow,Gray, Bright_Red,Blue, Gray,Black };

using namespace std;

int Rand(int min, int max) { return (rand() % (max - min)) + min; }

void Gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Set_console_color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


class Snake
{
public:
	Snake(int _x, int _y, int _speed[]) { x.push_back(_x); y.push_back(_y); speed[0] = _speed[0]; speed[1] = _speed[1]; }
	void Set_color(int _color) { color = _color; }
	void Show_snake()
	{
		Set_console_color(color);
		for (int i = 0; i < x.size() && i < y.size(); i++)
		{
			Gotoxy(x[i], y[i]);
			cout << 'O';
		}
		Gotoxy(LEN + 1, WID + 1);
	}
	int Get_head_x() { return x[0]; }
	int Get_head_y() { return y[0]; }
	void Change_speed(int a, int b) { speed[0] = a; speed[1] = b; }
	int Get_x_speed() { return speed[0]; }
	int Get_y_speed() { return speed[1]; }
	void Set_speed(int x_speed, int y_speed) { speed[0] = x_speed; speed[1] = y_speed; }
	/*void Erase_snake()
	{
		Set_console_color(0);
		for (int i = 0; i < x.size() && i < y.size(); i++)
		{
			Gotoxy(x[i], y[i]);
			cout << 'O';
		}
	}*/
	void Improve()
	{
		x.insert(x.begin(), speed[0] + x[0]);
		y.insert(y.begin(), speed[1] + y[0]);
		Set_console_color(color);
		Gotoxy(x[0], y[0]);
		cout << "O";
	}
	void Move()
	{
		if (x.size() == 1 || y.size() == 1)
		{
			Gotoxy(x[0], y[0]);
			cout << ' ';
			x[0] += speed[0];
			y[0] += speed[1];
		}
		else
		{
			Gotoxy(x[x.size() - 1], y[y.size() - 1]);
			cout << ' ';
			x.pop_back();
			y.pop_back();
			x.insert(x.begin(), speed[0] + x[0]);
			y.insert(y.begin(), speed[1] + y[0]);
		}
		Set_console_color(color);
		Gotoxy(x[0], y[0]);
		cout << 'O';
	}
	bool Clash_body()
	{
		for (int i = 1; i < x.size() && i < y.size(); i++)
			if (x[0] == x[i] && y[0] == y[i])
				return true;
		return false;
	}
private:
	int size = 1;
	int color = 0;
	vector<int> x;
	vector<int> y;
	int speed[2];
};

class Food
{
public:
	virtual void Set_color(int _color) = 0;
	int Get_x() { return x; }
	int Get_y() { return y; }
	void Change_place(int _x, int _y) { x = _x; y = _y; }
	virtual void Show_Apple() = 0;
protected:
	int x = 0;
	int y = 0;
	int color = White;
};

class Fig : public Food
{
public:
	Fig(int _x, int _y) { x = _x; y = _y; }
	void Set_color(int _color) { color = _color; }
	void Show_Apple()
	{
		Gotoxy(x, y);
		Set_console_color(color);
		cout << sambol;
	}
private:
	char sambol = 'F';
};

class Benana : public Food
{
public:
	Benana(int _x, int _y) { x = _x; y = _y; }
	void Set_color(int _color) { color = _color; }
	void Show_Apple()
	{
		Gotoxy(x, y);
		Set_console_color(color);
		cout << sambol;
	}
private:
	char sambol = 'B';
};

class Apple : public Food
{
public:
	Apple(int _x, int _y) { x = _x; y = _y; }
	void Set_color(int _color) { color = _color; }
	void Show_Apple()
	{
		Gotoxy(x, y);
		Set_console_color(color);
		cout << sambol;
	}
private:
	char sambol = 'A';
};

class Board
{
public:
	Board(int _lenght, int _width, int _x_first, int _y_first)
	{
		lenght = _lenght;
		width = _width;
		x_first = _x_first;
		y_first = _y_first;
		x_end = x_first + lenght;
		y_end = y_first + width;
	}
	int Get_first_x() { return x_first; }
	int Get_last_x() { return x_end; }
	int Get_first_y() { return y_first; }
	int Get_last_y() { return y_end; }
	void Set_color(int _color) { color = _color; }
	void Show_board()
	{
		int i, j;
		Set_console_color(color);
		Gotoxy(x_first, y_first);
		cout << UL;
		for (i = x_first; i < x_end - 1; i++)
			cout << H;
		cout << UR;
		i = x_first;
		for (j = y_first + 1; j < y_end; j++)
		{
			Gotoxy(x_first, j);
			cout << V;
			for (i = x_first; i < x_end - 1; i++)
				cout << ' ';
			cout << V;
		}
		Gotoxy(x_first, y_end);
		cout << DL;
		for (i = x_first; i < x_end - 1; i++)
			cout << H;
		wcout << DR;
		Gotoxy(x_end + 1, y_end + 1);
	}
	int Get_x_first() { return x_first; }
	int Get_y_first() { return y_first; }
private:
	int lenght;
	int width;
	int x_first;
	int y_first;
	int x_end;
	int y_end;
	int color = 0;
};

class Snake_game
{
public:
	Snake_game()
	{
		int x_snake, y_snake, speed_snake[2], x_apple, y_apple, len_board = LEN, width_board = WID, x_1st_board = 2, y_1st_board = 2;
		int x_fig, y_fig, x_benana, y_benana;
		x_apple = Rand(x_1st_board + 1, len_board + x_1st_board - 1);
		y_apple = Rand(y_1st_board + 1, width_board + y_1st_board - 1);
		x_fig = Rand(x_1st_board + 1, len_board + x_1st_board - 1);
		y_fig = Rand(y_1st_board + 1, width_board + y_1st_board - 1);
		x_benana = Rand(x_1st_board + 1, len_board + x_1st_board - 1);
		y_benana = Rand(y_1st_board + 1, width_board + y_1st_board - 1);
		speed_snake[0] = MIN_SPEED;
		speed_snake[1] = 0;
		x_snake = x_1st_board + 1;
		y_snake = y_1st_board + 1;
		snake = new Snake(x_snake, y_snake, speed_snake);
		apple = new Apple(x_apple, y_apple);
		fig = new Fig(x_fig, y_fig);
		benana = new Benana(x_benana, y_benana);
		board = new Board(len_board, width_board, x_1st_board, y_1st_board);
		Set_color_set();
	}
	~Snake_game() { delete snake; delete apple; delete board; }
	void Set_color_set()
	{
		snake->Set_color(Green);
		apple->Set_color(Red);
		benana->Set_color(Yellow);
		fig->Set_color(Cyan);
		board->Set_color(Gray);
	}

	bool Is_eaten_Apple()
	{
		if (snake->Get_head_x() == apple->Get_x() && snake->Get_head_y() == apple->Get_y())
			return true;
		else
			return false;
	}

	bool Is_eaten_Fig()
	{
		if (snake->Get_head_x() == fig->Get_x() && snake->Get_head_y() == fig->Get_y())
			return true;
		else
			return false;
	}

	bool Is_eaten_Benana()
	{
		if (snake->Get_head_x() == benana->Get_x() && snake->Get_head_y() == benana->Get_y())
			return true;
		else
			return false;
	}

	void Make_new_Apple()
	{
		int x_Apple, y_Apple;
		x_Apple = Rand(board->Get_first_x() + 1, board->Get_last_x() - 1);
		y_Apple = Rand(board->Get_first_y() + 1, board->Get_last_y() - 1);
		apple->Change_place(x_Apple, y_Apple);
		///////////////////////////////////////////////////////////////////////////////////////////////
	}
	void Make_new_Benana()
	{
		int x_Benana, y_Benana;
		while (true)
		{
			x_Benana = Rand(board->Get_first_x() + 1, board->Get_last_x() - 1);
			y_Benana = Rand(board->Get_first_y() + 1, board->Get_last_y() - 1);
			////////////////////////////////////////////////////////////////////////////if()
		}
		benana->Change_place(x_Benana, y_Benana);
	}
	void Make_new_Fig()
	{
		int x_Fig, y_Fig;
		while (true)
		{
			x_Fig = Rand(board->Get_first_x() + 1, board->Get_last_x() - 1);
			y_Fig = Rand(board->Get_first_y() + 1, board->Get_last_y() - 1);
			////////////////////////////////////////////////////////////////////////////if()
		}
		fig->Change_place(x_Fig, y_Fig);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	bool Clash_to_wall()
	{
		int x_head = snake->Get_head_x();
		int y_head = snake->Get_head_y();
		if (x_head == board->Get_first_x() || x_head == board->Get_last_x() || y_head == board->Get_first_y() || y_head == board->Get_last_y())
			return true;
		return false;
	}


	void start()
	{
		char choice;
		board->Show_board();
		snake->Show_snake();
		apple->Show_Apple();
		while (true)
		{
			Gotoxy(20, 1);
			choice = _getch();
			switch (toupper(choice))
			{
			case('W'):
			{
				snake->Change_speed(0, -1);
				break;
			}
			case('S'):
			{
				snake->Change_speed(0, 1);
				break;
			}
			case('D'): {
				snake->Change_speed(1, 0);
				break;
			}
			case('A'): {
				snake->Change_speed(-1, 0);
				break;
			}
			default:
			{
				//cout << "Please enter valid entery.";
				//break;
			}
			}
			if (Is_eaten_Apple())
			{
				score++;
				Make_new_Apple();
				snake->Improve();
			}
			else
				snake->Move();
			if (snake->Clash_body() || Clash_to_wall())
			{
				system("cls");
				Gotoxy(12, 6);
				Set_console_color(Red);
				cout << "Game over !";
				return;
			}

			apple->Show_Apple();
		}
	}

private:
	int score = 0;
	Snake* snake;
	Apple* apple;
	Board* board;
	Fig* fig;
	Benana* benana;
};


int main()
{
	Snake_game s;
	s.start();

	return 0;
}
