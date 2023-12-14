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


class Animal
{
public:
	virtual void Set_color(int _color) = 0;
	virtual void Show() = 0;
	int Get_head_x() { return x[0]; }
	int Get_head_y() { return y[0]; }
	vector<int> Get_all_x() { return x; }
	vector<int> Get_all_y() { return y; }
	void Change_speed(int a, int b) { speed[0] = a; speed[1] = b; }
	int Get_x_speed() { return speed[0]; }
	int Get_y_speed() { return speed[1]; }
	void Set_speed(int x_speed, int y_speed) { speed[0] = x_speed; speed[1] = y_speed; }
	virtual void Move() = 0;
protected:
	int size = 1;
	int color = 0;
	vector<int> x;
	vector<int> y;
	int speed[2];

};

class Urchin : public Animal
{
public:
	Urchin(int _x, int _y, int _speed[]) { x.push_back(_x); y.push_back(_y); speed[0] = _speed[0]; speed[1] = _speed[1]; }
	void Set_color(int _color) { color = _color; }
	void Show()
	{
		Set_console_color(color);
		Gotoxy(x[0], y[0]);
		cout << 'U';
	}
	void Move()
	{
		Gotoxy(x[0], y[0]);
		cout << ' ';
		x[0] += speed[0];
		y[0] += speed[1];
		Set_console_color(color);
		Gotoxy(x[0], y[0]);
		cout << 'U';
	}
};
class Snake : public Animal
{
public:
	Snake(int _x, int _y, int _speed[]) { x.push_back(_x); y.push_back(_y); speed[0] = _speed[0]; speed[1] = _speed[1]; }
	void Set_color(int _color) { color = _color; }
	void Show()
	{
		Set_console_color(color);
		for (int i = 0; i < x.size() && i < y.size(); i++)
		{
			Gotoxy(x[i], y[i]);
			cout << 'O';
		}
	}
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

};

class Food
{
public:
	virtual void Set_color(int _color) = 0;
	int Get_x() { return x; }
	int Get_y() { return y; }
	void Change_place(int _x, int _y) { x = _x; y = _y; }
	virtual void Show() = 0;
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
	void Show()
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
	void Show()
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
	void Show()
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
	void Show()
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
		int x_fig, y_fig, x_benana, y_benana, x_urchin, y_urchin, speed_urchin[2];
		x_apple = Rand(x_1st_board + 1, len_board + x_1st_board - 1);
		y_apple = Rand(y_1st_board + 1, width_board + y_1st_board - 1);
		x_fig = Rand(x_1st_board + 1, len_board + x_1st_board - 1);
		y_fig = Rand(y_1st_board + 1, width_board + y_1st_board - 1);
		x_benana = Rand(x_1st_board + 1, len_board + x_1st_board - 1);
		y_benana = Rand(y_1st_board + 1, width_board + y_1st_board - 1);
		speed_snake[0] = 1;
		speed_snake[1] = 0;
		x_snake = x_1st_board + 1;
		y_snake = y_1st_board + 1;
		speed_urchin[0] = -1;
		speed_urchin[1] = 0;
		x_urchin = (len_board + x_1st_board) / 2;
		y_urchin = (width_board + y_1st_board) / 2;
		snake = new Snake(x_snake, y_snake, speed_snake);
		urchin = new Urchin(x_urchin, y_urchin, speed_urchin);
		apple = new Apple(x_apple, y_apple);
		fig = new Fig(x_fig, y_fig);
		benana = new Benana(x_benana, y_benana);
		board = new Board(len_board, width_board, x_1st_board, y_1st_board);
		Set_color_set();
	}
	~Snake_game() { delete snake; delete urchin; delete benana; delete fig; delete apple; delete board; }
	void Set_color_set()
	{
		snake->Set_color(Green);
		urchin->Set_color(Gray);
		apple->Set_color(Red);
		benana->Set_color(Yellow);
		fig->Set_color(Cyan);
		board->Set_color(White);
	}
	bool Is_eaten_food(Food* food , Animal* animal)
	{
		if (animal->Get_head_x() == food->Get_x() && animal->Get_head_y() == food->Get_y())
			return true;
		else
			return false;
	}
	void Make_new_coordinates(Food* food)
	{
		int x, y;
		//while (true)
		{
			x = Rand(board->Get_first_x() + 1, board->Get_last_x() - 1);
			y = Rand(board->Get_first_y() + 1, board->Get_last_y() - 1);
			////////////////////////////////////////////////////////////////////////////if()
		}
		food->Change_place(x, y);
	}
	bool Clash_to_urchin()
	{
		vector<int> xs_snake = snake->Get_all_x();
		vector<int> ys_snake = snake->Get_all_y();
		int x_urchin = urchin->Get_head_x();
		int y_urchin = urchin->Get_head_y();
		for (int i = 0; i < xs_snake.size(); i++)
		{
			if (xs_snake[i] == x_urchin && ys_snake[i] == y_urchin)
				return true;
		}
		return false;
	}
	bool Clash_to_each_foods(Animal* animal)
	{
		int x_head = animal->Get_head_x();
		int y_head = animal->Get_head_y();
		int x_speed = animal->Get_x_speed();
		int y_speed = animal->Get_y_speed();
		if (x_head + x_speed == board->Get_first_x() || x_head + x_speed == board->Get_last_x() || y_head + y_speed == board->Get_first_y() || y_head + y_speed == board->Get_last_y())
			return true;
		if (x_head + x_speed == apple->Get_x())
		{
			if (y_head + y_speed == apple->Get_y())
				return true;
		}
		if (x_head + x_speed == benana->Get_x())
		{
			if (y_head + y_speed == benana->Get_y())
				return true;
		}
		if (x_head + x_speed == fig->Get_x())
		{
			if (y_head + y_speed == fig->Get_y())
				return true;
		}
		return false;
		///////////////////////////////////////////////////////////////////////////////////////////////////////
	}

	bool Clash_to_wall(Animal* animal)
	{
		int x_head = animal->Get_head_x();
		int y_head = animal->Get_head_y();
		if (x_head == board->Get_first_x() || x_head == board->Get_last_x() || y_head == board->Get_first_y() || y_head == board->Get_last_y())
			return true;
		return false;
	}

	bool Is_eating_food()
	{
		bool ate = false;
		if (Is_eaten_food(apple , snake))
		{
			score++;
			Make_new_coordinates(apple);
			snake->Improve();
			ate = true;
		}
		if (Is_eaten_food(benana , snake))
		{
			score += 2;
			Make_new_coordinates(benana);
			snake->Improve();
			snake->Improve();
			ate = true;
		}
		if (Is_eaten_food(fig , snake))
		{
			score--;
			Make_new_coordinates(fig);
		///////////////////////////////////////////////////////////////////
			ate = true;
		}
		return ate;
	}

	void Show_score()
	{
		Gotoxy(10, 1);
		Set_console_color(Bright_Blue);
		cout << "Score : " << score << "    " ;
	}

	void Move_urchin()
	{
		int rand_num;
		while (true)
		{
			rand_num = Rand(0, 4);
			urchin->Change_speed(speed[0][rand_num], speed[1][rand_num]);
			
			//if (!Is_eaten_food(apple, urchin) && !Is_eaten_food(benana, urchin) && !Is_eaten_food(fig, urchin) && !Clash_to_wall(urchin))
			if(!Clash_to_each_foods(urchin))
			{
				urchin->Move();
				break;
			}
		}
		
	}

	void start()
	{
		char choice;
		board->Show();
		snake->Show();
		urchin->Show();
		apple->Show();
		benana->Show();
		fig->Show();
		while (true)
		{
			Show_score();
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
			case('D'): 
			{
				snake->Change_speed(1, 0);
				break;
			}
			case('A'):
			{
				snake->Change_speed(-1, 0);
				break;
			}
			}
			Move_urchin();
			if (!Is_eating_food())
				snake->Move();
			if (snake->Clash_body() || Clash_to_wall(snake) || score < 0 || Clash_to_urchin())
			{
				system("cls");
				Gotoxy(12, 6);
				Set_console_color(Red);
				cout << "Game over !";
				return;
			}
			apple->Show();
			benana->Show();
			fig->Show();

		}
	}

private:
	int score = 0;
	Snake* snake;
	Urchin* urchin;
	Apple* apple;
	Board* board;
	Fig* fig;
	Benana* benana;
	int speed[2][4] = { 0,1 , 0,-1 , 1,0 , -1,0 };
};


int main()
{
	Snake_game s;
	s.start();

	return 0;
}
