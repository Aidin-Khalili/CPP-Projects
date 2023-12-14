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

class Mouse
{
public:
	Mouse(int _x, int _y) { x = _x; y = _y; }
	void Set_color(int _color) { color = _color; }
	int Get_x() { return x; }
	int Get_y() { return y; }
	void Change_place(int _x ,int _y ) { x = _x; y = _y; }
	void Show_mouse()
	{
		Gotoxy(x, y);
		Set_console_color(color);
		cout << 'X';
	}

private:
	int x;
	int y;
	int color = 0;
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
		for (j = y_first + 1; j < y_end ; j++)
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
		int x_snake, y_snake, speed_snake[2], x_mouse, y_mouse, len_board = LEN, width_board = WID, x_1st_board = 2, y_1st_board = 2;
		x_mouse = Rand(x_1st_board + 1, len_board + x_1st_board - 1);
		y_mouse = Rand(y_1st_board + 1, width_board + y_1st_board - 1);
		speed_snake[0] = MIN_SPEED;
		speed_snake[1] = 0;
		x_snake = x_1st_board + 1;
		y_snake = y_1st_board + 1;
		snake = new Snake(x_snake, y_snake, speed_snake);
		mouse = new Mouse(x_mouse, y_mouse);
		board = new Board(len_board, width_board, x_1st_board, y_1st_board);
		Set_color_set();
	}
	~Snake_game() { delete snake; delete mouse; delete board; }
	void Set_color_set()
	{
		snake->Set_color(13);
		mouse->Set_color(3);
		board->Set_color(5);
	}

	bool Is_eaten_mouse()
	{
		if (snake->Get_head_x() == mouse->Get_x() && snake->Get_head_y() == mouse->Get_y())
			return true;
		else
			return false;
	}

	void Make_new_mouse()
	{
		int x_mouse, y_mouse;
		x_mouse = Rand(board->Get_first_x() + 1,board->Get_last_x() - 1);
		y_mouse = Rand(board->Get_first_y() + 1, board->Get_last_y() - 1);
		mouse->Change_place(x_mouse,y_mouse);
	}

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
		mouse->Show_mouse();
		Gotoxy(20, 1);
		while (true)
		{
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
				if (Is_eaten_mouse())
				{
					score++;
					Make_new_mouse();
					snake->Improve();
				}
				else
					snake->Move();
				if (snake->Clash_body() || Clash_to_wall())
				{
					system("cls");
					Gotoxy(12, 6);
					Set_console_color(10);
					cout << "Game over !";
					return;
				}
				
				mouse->Show_mouse();
		}
	}

private:
	int score = 0;
	Snake* snake;
	Mouse* mouse;
	Board* board;
};


int main()
{
	Snake_game s;
	s.start();

	return 0;
}
