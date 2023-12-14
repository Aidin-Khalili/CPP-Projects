// This is program for computing the routation of rubic cube and make some scramble rubics.
#include<iostream>
#include <stdlib.h>
#include <string>
#include<conio.h>
#include<dos.h>
#include<windows.h>
#include<wincon.h>
#include<fstream>
#include <ctime>
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
WORD wOldColorAttrs;
#pragma warning(disable : 4996)
typedef int MATRIX[3][3];
using namespace std;
MATRIX F, R, U, L, D, B;
HANDLE hStdout, hStdin;
char menuChoice;
int colorID[6] = { 32,64,241,224,192,144 };
char  Oper[13] = { "FfRrUuBbLlDd" };
string Operation;


void RotationF(MATRIX RR, MATRIX DD, MATRIX LL, MATRIX UU, char way)
{
	// We use tHis function for rotation front matrixes of rubic.
	// If we enter capital char it rotations lowercase and if small char rotations upercase.
	int t1, t2, t3;
	if (way == '+')
	{
		t1 = RR[0][0];
		t2 = RR[1][0];
		t3 = RR[2][0];
		RR[0][0] = UU[2][0];
		RR[1][0] = UU[2][1];
		RR[2][0] = UU[2][2];
		UU[2][0] = LL[0][2];
		UU[2][1] = LL[1][2];
		UU[2][2] = LL[2][2];
		LL[0][2] = DD[0][0];
		LL[1][2] = DD[0][1];
		LL[2][2] = DD[0][2];
		DD[0][0] = t1;
		DD[0][1] = t2;
		DD[0][2] = t3;
	}
	else {
		t1 = RR[0][0];
		t2 = RR[1][0];
		t3 = RR[2][0];
		RR[0][0] = DD[0][0];
		RR[1][0] = DD[0][1];
		RR[2][0] = DD[0][2];
		DD[0][0] = LL[0][2];
		DD[0][1] = LL[1][2];
		DD[0][2] = LL[2][2];
		LL[0][2] = UU[2][0];
		LL[1][2] = UU[2][1];
		LL[2][2] = UU[2][2];
		UU[2][0] = t1;
		UU[2][1] = t2;
		UU[2][2] = t3;
	}

}


void RotationR(MATRIX RR, MATRIX DD, MATRIX LL, MATRIX UU, char way)
{
	// We use tHis function for rotation right matrixes of rubic.
	// If we enter capital char it rotations lowercase and if small char rotations upercase.
	int t1, t2, t3;
	if (way == '+')
	{
		t1 = RR[0][0];
		t2 = RR[1][0];
		t3 = RR[2][0];
		RR[0][0] = UU[0][2];
		RR[1][0] = UU[1][2];
		RR[2][0] = UU[2][2];
		UU[0][2] = LL[0][2];
		UU[1][2] = LL[1][2];
		UU[2][2] = LL[2][2];
		LL[0][2] = DD[0][2];
		LL[1][2] = DD[1][2];
		LL[2][2] = DD[2][2];
		DD[0][2] = t1;
		DD[1][2] = t2;
		DD[2][2] = t3;
	}
	else {
		t1 = RR[0][0];
		t2 = RR[1][0];
		t3 = RR[2][0];
		RR[0][0] = DD[0][2];
		RR[1][0] = DD[1][2];
		RR[2][0] = DD[2][2];
		DD[0][2] = LL[0][2];
		DD[1][2] = LL[1][2];
		DD[2][2] = LL[2][2];
		LL[0][2] = UU[0][2];
		LL[1][2] = UU[1][2];
		LL[2][2] = UU[2][2];
		UU[0][2] = t1;
		UU[1][2] = t2;
		UU[2][2] = t3;
	}
}
void RotationU(MATRIX RR, MATRIX FF, MATRIX LL, MATRIX BB, char way)
{
	int t1, t2, t3;
	if (way == '+')
	{
		// We use tHis function for rotation up matrixes of rubic.
		// If we enter capital char it rotations lowercase and if small char rotations upercase.
		t1 = RR[0][0];
		t2 = RR[0][1];
		t3 = RR[0][2];
		RR[0][0] = BB[0][0];
		RR[0][1] = BB[0][1];
		RR[0][2] = BB[0][2];
		BB[0][0] = LL[0][0];
		BB[0][1] = LL[0][1];
		BB[0][2] = LL[0][2];
		LL[0][0] = FF[0][0];
		LL[0][1] = FF[0][1];
		LL[0][2] = FF[0][2];
		FF[0][0] = t1;
		FF[0][1] = t2;
		FF[0][2] = t3;
	}
	else {
		t1 = RR[0][0];
		t2 = RR[0][1];
		t3 = RR[0][2];
		RR[0][0] = FF[0][0];
		RR[0][1] = FF[0][1];
		RR[0][2] = FF[0][2];
		FF[0][0] = LL[0][0];
		FF[0][1] = LL[0][1];
		FF[0][2] = LL[0][2];
		LL[0][0] = BB[0][0];
		LL[0][1] = BB[0][1];
		LL[0][2] = BB[0][2];
		BB[0][0] = t1;
		BB[0][1] = t2;
		BB[0][2] = t3;
	}

}

void RotationB(MATRIX LL, MATRIX DD, MATRIX RR, MATRIX UU, char way)
{
	// We use tHis function for rotation back matrixes of rubic.
	// If we enter capital char it rotations lowercase and if small char rotations upercase.
	int t1, t2, t3;
	if (way == '+')
	{
		t1 = LL[0][0];
		t2 = LL[1][0];
		t3 = LL[2][0];
		LL[0][0] = DD[2][0];
		LL[1][0] = DD[2][1];
		LL[2][0] = DD[2][2];
		DD[2][0] = RR[0][2];
		DD[2][1] = RR[1][2];
		DD[2][2] = RR[2][2];
		RR[0][2] = UU[0][0];
		RR[1][2] = UU[0][1];
		RR[2][2] = UU[0][2];
		UU[0][0] = t1;
		UU[0][1] = t2;
		UU[0][2] = t3;
	}
	else {
		t1 = LL[0][0];
		t2 = LL[1][0];
		t3 = LL[2][0];
		LL[0][0] = UU[0][0];
		LL[1][0] = UU[0][1];
		LL[2][0] = UU[0][2];
		UU[0][0] = RR[0][2];
		UU[0][1] = RR[1][2];
		UU[0][2] = RR[2][2];
		RR[0][2] = DD[2][0];
		RR[1][2] = DD[2][1];
		RR[2][2] = DD[2][2];
		DD[2][0] = t1;
		DD[2][1] = t2;
		DD[2][2] = t3;
	}

}

void RotationL(MATRIX FF, MATRIX DD, MATRIX BB, MATRIX UU, char way)
{
	// We use tHis function for rotation left matrixes of rubic.
	// If we enter capital char it rotations lowercase and if small char rotations upercase.
	int t1, t2, t3;
	if (way == '+')
	{
		t1 = FF[0][0];
		t2 = FF[1][0];
		t3 = FF[2][0];
		FF[0][0] = UU[0][0];
		FF[1][0] = UU[1][0];
		FF[2][0] = UU[2][0];
		UU[0][0] = BB[0][2];
		UU[1][0] = BB[1][2];
		UU[2][0] = BB[2][2];
		BB[0][2] = DD[0][0];
		BB[1][2] = DD[1][0];
		BB[2][2] = DD[2][0];
		DD[0][0] = t1;
		DD[1][0] = t2;
		DD[2][0] = t3;
	}
	else {
		t1 = FF[0][0];
		t2 = FF[1][0];
		t3 = FF[2][0];
		FF[0][0] = DD[0][0];
		FF[1][0] = DD[1][0];
		FF[2][0] = DD[2][0];
		DD[0][0] = BB[0][2];
		DD[1][0] = BB[1][2];
		DD[2][0] = BB[2][2];
		BB[0][2] = UU[0][0];
		BB[1][2] = UU[1][0];
		BB[2][2] = UU[2][0];
		UU[0][0] = t1;
		UU[1][0] = t2;
		UU[2][0] = t3;
	}
}
void RotationD(MATRIX RR, MATRIX FF, MATRIX LL, MATRIX BB, char way)
{
	// We use tHis function for rotation down matrixes of rubic.
	// If we enter capital char it rotations lowercase and if small char rotations upercase.
	int t1, t2, t3;
	if (way == '+')
	{

		t1 = RR[2][0];
		t2 = RR[2][1];
		t3 = RR[2][2];
		RR[2][0] = BB[2][0];
		RR[2][1] = BB[2][1];
		RR[2][2] = BB[2][2];
		BB[2][0] = LL[2][0];
		BB[2][1] = LL[2][1];
		BB[2][2] = LL[2][2];
		LL[2][0] = FF[2][0];
		LL[2][1] = FF[2][1];
		LL[2][2] = FF[2][2];
		FF[2][0] = t1;
		FF[2][1] = t2;
		FF[2][2] = t3;
	}
	else {
		t1 = RR[2][0];
		t2 = RR[2][1];
		t3 = RR[2][2];
		RR[2][0] = FF[2][0];
		RR[2][1] = FF[2][1];
		RR[2][2] = FF[2][2];
		FF[2][0] = LL[2][0];
		FF[2][1] = LL[2][1];
		FF[2][2] = LL[2][2];
		LL[2][0] = BB[2][0];
		LL[2][1] = BB[2][1];
		LL[2][2] = BB[2][2];
		BB[2][0] = t1;
		BB[2][1] = t2;
		BB[2][2] = t3;
	}

}


void Rotation(MATRIX M, char way)
{
	// We use tHis function for rotation a matrix of rubic (internal).
	// If we enter capital char it rotations lowercase and if small char rotations upercase.
	int temp;
	if (way == '+')
	{
		temp = M[0][2];
		M[0][2] = M[0][1];
		M[0][1] = M[0][0];
		M[0][0] = M[1][0];
		M[1][0] = M[2][0];
		M[2][0] = M[2][1];
		M[2][1] = M[2][2];
		M[2][2] = M[1][2];
		M[1][2] = temp;
	}
	else
	{
		temp = M[0][2];
		M[0][2] = M[1][2];
		M[1][2] = M[2][2];
		M[2][2] = M[2][1];
		M[2][1] = M[2][0];
		M[2][0] = M[1][0];
		M[1][0] = M[0][0];
		M[0][0] = M[0][1];
		M[0][1] = temp;
	}


}
void gotoxy(int x, int y)
{
	// We use this function to move to the espeshial x and y on the display.
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Play(MATRIX M, int COL, int ROW)
{
	// We use this function to color and right digit in the black screan.
	int i, j;
	for (i = 0; i < 3; i++) {
		gotoxy(COL, ROW);
		for (j = 0; j < 3; j++) {
			SetConsoleTextAttribute(hStdout, colorID[M[i][j]]);
			cout << "[" << M[i][j] << "]" ;
		}
		ROW = ROW + 1;
	}
}
			

void DISPLAY(int Row)
{
	// We use this to display all matrixes.
	Play(U, 20, 7+Row);
	Play(L, 10, 11 + Row);
	Play(F, 20, 11 + Row);
	Play(R, 30, 11 + Row);
	Play(B, 40, 11 + Row);
	Play(D, 20, 15 + Row);
}
void SET(MATRIX M, int color)
{
	// We use this function to color the digit.
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			M[i][j] = color;
}

int Input() 
// This is menu choice and it returns choices.
// If we enter capital char it rotations lowercase and if small char rotations upercase.  
{
	SetConsoleTextAttribute(hStdout, wOldColorAttrs);

	SetConsoleTextAttribute(hStdout, 0);	
	SetConsoleTextAttribute(hStdout, 12);
	gotoxy(65, 5);
	cout << "* * * * * * * * * * * * * * * * * *";
	gotoxy(65, 6);
	cout << "*";
	SetConsoleTextAttribute(hStdout, 0);
	SetConsoleTextAttribute(hStdout, 2);
	cout << "Capital Letter= Clockwise";
	SetConsoleTextAttribute(hStdout, 0);
	SetConsoleTextAttribute(hStdout, 12);
	gotoxy(92, 6);
	SetConsoleTextAttribute(hStdout, 0);
	SetConsoleTextAttribute(hStdout, 12);
	cout << "       *";
	gotoxy(65, 7);
	cout << "*";
	SetConsoleTextAttribute(hStdout, 0);
	SetConsoleTextAttribute(hStdout, 2);
	cout << "Small=Counter Clockwise Rotation";
	SetConsoleTextAttribute(hStdout, 0);
	SetConsoleTextAttribute(hStdout, 12);
	cout << " *";
	gotoxy(65, 8);
	SetConsoleTextAttribute(hStdout, 12);
	cout << "* ";
	SetConsoleTextAttribute(hStdout, 78);
	cout << "Enter your Choice: ";
	SetConsoleTextAttribute(hStdout, 12);
	cout << "             *";
	gotoxy(65, 9);
	SetConsoleTextAttribute(hStdout, 12);
	cout << "* (F)";
	SetConsoleTextAttribute(hStdout, 14);
	cout << "ront                       ";
	SetConsoleTextAttribute(hStdout, 12);
	cout << "  *";
	gotoxy(65, 10);
	SetConsoleTextAttribute(hStdout, 12);
	cout << "* (R)";
	SetConsoleTextAttribute(hStdout, 14);
	cout << "right                      ";
	SetConsoleTextAttribute(hStdout, 12);
	cout << "  *";
	gotoxy(65, 11);
	SetConsoleTextAttribute(hStdout, 12);
	cout << "* (U)";
	SetConsoleTextAttribute(hStdout, 14);
	cout << "p                          ";
	SetConsoleTextAttribute(hStdout, 12);
	cout << "  *";
	gotoxy(65, 12);
	cout << "* (D)";
	SetConsoleTextAttribute(hStdout, 14);
	cout << "own                        ";
	SetConsoleTextAttribute(hStdout, 12);
	cout << "  *";
	SetConsoleTextAttribute(hStdout, 12);
	gotoxy(65, 13);
	cout << "* (L)";
	SetConsoleTextAttribute(hStdout, 14);
	cout << "eft                        ";
	SetConsoleTextAttribute(hStdout, 12);
	cout << "  *";
	gotoxy(65, 14);	
	cout << "* (B)";
	SetConsoleTextAttribute(hStdout, 14);
	cout << "ack                        ";
	SetConsoleTextAttribute(hStdout, 12);
	cout << "  *";
	gotoxy(65, 15);
	cout << "* (S)";
	SetConsoleTextAttribute(hStdout, 14);
	cout << "cramble                    ";
	SetConsoleTextAttribute(hStdout, 12);
	cout << "  *";
	gotoxy(65, 16);
	cout << "* (Q)";
	SetConsoleTextAttribute(hStdout, 14);
	cout << "uit                        ";
	SetConsoleTextAttribute(hStdout, 12);
	cout << "  *";
	gotoxy(65, 17);
	cout << "*                                 *";
	gotoxy(65, 18);
	SetConsoleTextAttribute(hStdout, 12);
	cout << "* * * * * * * * * * * * * * * * * *";
	gotoxy(85, 8);
	SetConsoleTextAttribute(hStdout, 124);
	cin >> menuChoice;
	SetConsoleTextAttribute(hStdout, FOREGROUND_RED);
	return menuChoice;
}
int Rand(int x)
{
	///We use this function for telling us some random numbers.
	if (x <= 0)
		return 0;
	return (rand()%x);
}
void Scramble() 
{
	// We use this function to make scramble rubic.
	int i, j,k;
	SetConsoleTextAttribute(hStdout, 12);
	gotoxy(65, 19);
	cout << "Please enter the number of rotation : ";
	gotoxy(65, 20);
	cout << "--->> ";
	cin >> j;
	gotoxy(73, 20);
	cout << "<<---  ";
	Operation = "";
	for (i = 0; i < j; i++) {
		k = Rand(12);
		cout << Oper[k] <<" ";
		Operation += Oper[k];
	}
	for (i = 0; i < j; i++) {
		switch (Operation[i]) {
		case'F':
			Rotation(F, '-');
			RotationF(R, D, L, U, '-');
			DISPLAY(12);
			break;
		case'f':
			Rotation(F, '+');
			RotationF(R, D, L, U, '+');
			DISPLAY(12);
			break;
		case'R':
			Rotation(R, '-');
			RotationR(B, D, F, U, '-');
			DISPLAY(12);
			break;
		case'r':
			Rotation(R, '+');
			RotationR(B, D, F, U, '+');
			DISPLAY(12);
			break;
		case'U':
			Rotation(U, '-');
			RotationU(R, F, L, B, '-');
			DISPLAY(12);
			break;
		case'u':
			Rotation(U, '+');
			RotationU(R, F, L, B, '+');
			DISPLAY(12);
			break;
		case'L':
			Rotation(L, '-');
			RotationL(F, D, B, U, '-');
			DISPLAY(12);
			break;
		case'l':
			Rotation(L, '+');
			RotationL(F, D, B, U, '+');
			DISPLAY(12);
			break;
		case'D':
			Rotation(D, '-');
			RotationD(R, F, L, B, '-');
			DISPLAY(12);
			break;
		case'd':
			Rotation(D, '+');
			RotationD(R, F, L, B, '+');
			DISPLAY(12);
			break;
		case'B':
			Rotation(B, '-');
			RotationB(L, D, R, U, '-');
			DISPLAY(12);
			break;
		case'b':
			Rotation(B, '+');
			RotationB(L, D, R, U, '+');
			DISPLAY(12);
			break;
		default:
			break;
		}
		DISPLAY(12);
	}
	SET(F, 0);
	SET(R, 1);
	SET(U, 2);
	SET(D, 3);
	SET(L, 4);
	SET(B, 5);
	DISPLAY(-4);

}
int main()
{

	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
	SetConsoleTextAttribute(hStdout, 12);
	system("cls");
	int i, j, k, l;
	srand(std::time(0));
	SET(F, 0);
	SET(R, 1);
	SET(U, 2);
	SET(D, 3);
	SET(L, 4);
	SET(B, 5);
	DISPLAY(-4);
	do
	{
		menuChoice = Input();
		switch (menuChoice) {
		case'F':
			Rotation(F,'-');
			RotationF(R ,D , L, U,'-');
			DISPLAY(-4);			
			break;
		case'f': 
			Rotation(F, '+');
			RotationF(R, D, L, U, '+'); 
			DISPLAY(-4);			
			break;
		case'R':
			Rotation(R, '-');
			RotationR(B, D, F, U, '-');
			DISPLAY(-4);
			break;
		case'r': 
			Rotation(R, '+');
			RotationR(B, D, F, U, '+');
			DISPLAY(-4);
			break;
		case'U':
			Rotation(U, '-');
			RotationU(R, F, L, B, '-');
			DISPLAY(-4);
			break;
		case'u': 
			Rotation(U, '+');
			RotationU(R, F, L, B, '+');
			DISPLAY(-4);
			break;
		case'L':
			Rotation(L, '-');
			RotationL(F, D, B, U, '-');
			DISPLAY(-4);
			break;
		case'l': 
			Rotation(L, '+');
			RotationL(F, D, B, U, '+');
			DISPLAY(-4);
			break;			   
		case'D':
			Rotation(D, '-');
			RotationD(R, F, L, B, '-');
			DISPLAY(-4);
			break;
		case'd':
			Rotation(D, '+');
			RotationD(R, F, L, B, '+');
			DISPLAY(-4);
			break;			   
		case'B':
			Rotation(B, '-');
			RotationB(L, D, R, U, '-');
			DISPLAY(-4);
			break;
		case'b': 
			Rotation(B, '+');
			RotationB(L, D, R, U, '+');
			DISPLAY(-4);
			break;
		case'S':
		case's':
			Scramble();
			break;
		case'Q':
		case'q': 
			// Bye Bye
			system("CLS");
			gotoxy(40, 10);
			SetConsoleTextAttribute(hStdout, 252);
			cout << "Thanks ! Have good time ;) " << endl;
			SetConsoleTextAttribute(hStdout, wOldColorAttrs);
		    break;
		default:
			break;
		}
	} while (menuChoice != 'q' && menuChoice != 'Q');

	return 0;
}