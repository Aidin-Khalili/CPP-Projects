#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <iomanip>
#include <vector>

#define LEN 80
#define WID 25
#define MIN_SPEED 5
#define UL static_cast<char>(201)
#define H static_cast<char>(205)
#define UR static_cast<char>(187)
#define V static_cast<char>(186)
#define DL static_cast<char>(200)
#define DR static_cast<char>(188) 
#define XX 80
#define YY 25
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
		Set_color(color);
		for (int i = 0; i < x.size()  && i < y.size(); i++)
		{
			Gotoxy(x[i], y[i]);
			cout << 'o';
		}
	}
private:
	int size = 1;
	int color;
	vector<int> x;
	vector<int> y;
	int speed[2] ;
};

class Mouse
{
public:
	Mouse(int _x, int _y) { x = _x; y = _y; }
	void Set_color(int _color) { color = _color; }
	void Show_mouse()
	{
		Gotoxy(x, y);
		Set_color(color);
		cout << 'O';
	}
private:
	int x;
	int y;
	int color;
};

class Board 
{
public:
	Board(int _lenght,int _width , int _x_first, int _y_first)
	{ 
		lenght = _lenght;
		width = _width; 
		x_first = _x_first;
		y_first = _y_first;
		x_end = x_first + lenght;
		y_end = y_first + width;
	}
	void Show_board()
	{
		int i , j;
		Gotoxy(x_first, y_first);
		cout << UL;
		for (i = x_first; i < x_end - 1; i++)
			cout << H;
		cout << UR;
		i = x_first;
		for (j = y_first + 1; j < y_end - 1; j++)
		{
			Gotoxy(i, j);
			cout << V;
			for (i = x_first; i < x_end - 1; i++)
				cout << ' ';
			cout << V;
		}
		Gotoxy(x_end, y_end);
		cout << DL;
		for (i = x_first; i < x_end - 1; i++)
			cout << H;
		wcout << DR;

		/*
		int i, j;
		Gotoxy(x_first, y_first);
		cout << UL;
		for (i = 1; i < x_end - 1; i++)
			cout << H;
		cout << UR ;
		Gotoxy(x_first, y_first + 1);
		for (i = 1; i < YY - 1; i++) {
			cout << V;
			for (j = 1; j < XX - 1; j++)
				cout << " ";
			cout << V << "\n";
		}
		cout << DL;
		for (i = 1; i < XX - 1; i++)
			cout << H;
		cout << DR << "\n";
		cout << setw(5) << 178 << right << setw(4) << static_cast<char>(178);
		*/

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
};

class Snake_game
{
public:
	Snake_game()
	{
		int x_snake, y_snake, speed_snake[2], x_mouse, y_mouse, len_board, width_board, x_1st_board, y_1st_board;
		x_1st_board = 5;
		y_1st_board = 5;
		len_board = LEN;
		width_board = WID;
		x_mouse = Rand(x_1st_board, len_board + x_1st_board);
		y_mouse = Rand(y_1st_board, width_board + y_1st_board);
		speed_snake[0] = MIN_SPEED;
		speed_snake[1] = 0;
		x_snake = x_1st_board;
		y_snake = y_1st_board;
		snake = new Snake(x_snake, y_snake, speed_snake);
		mouse = new Mouse(x_mouse, y_mouse);
		board = new Board(len_board, width_board, x_1st_board, y_1st_board);
	}
	~Snake_game() { delete snake; delete mouse; delete board; }


private:
	Snake *snake;
	Mouse *mouse;
	Board *board;
};


int main()
{
	/*
	int i, j;
	cout  << UL;
	for (i = 1; i < XX - 1; i++)
		cout << H;
	cout <<  UR << "\n";
	for (i = 1; i < YY - 1; i++) {
		cout  << V;
		for (j = 1; j < XX - 1; j++)
			cout << " ";
		cout << V << "\n";
	}
	cout <<  DL;
	for (i = 1; i < XX - 1; i++)
		cout << H;
	cout <<  DR << "\n";
	*/





	//cout << setw(5) << 178 << right << setw(4) << static_cast<char>(178);
	//wstring wideString = L"فارسی";
	//wcout  << wideString ;
	Board b(LEN, WID, 5, 5);

		

	b.Show_board();
	
	return 0;
}
