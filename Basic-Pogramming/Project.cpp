#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <dos.h>
#include <windows.h>
#include <wincon.h>
#include <fstream>
char menuChoice;
HANDLE hStdout, hStdin;
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
WORD wOldColorAttrs;
#pragma warning(disable : 4996)
#define Max 63
using namespace std;
char STR[Max+1] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";
int Code[Max];
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
 

int Find(char str[], char ch)
{
	int i;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == ch)
			return i;
	}
	return 0;
}


int coding(char Msg[],char Key[])
{
	int x , y , z , d , i , j , L;
	gotoxy(35,8);
	SetConsoleTextAttribute(hStdout,12);
	cout << "Please Enter a String(Msg) and press Enter : ";
	SetConsoleTextAttribute(hStdout,124);
	cin.ignore();
	cin.getline(Msg,Max);
	gotoxy(35,9);
	SetConsoleTextAttribute(hStdout,12);
	cout << "Please Enter KEY String and press Enter:";
	SetConsoleTextAttribute(hStdout,124);
	cin.getline(Key,Max);
	SetConsoleTextAttribute(hStdout,12);
	gotoxy(35,11);
	cout << "Code string is : ";
	SetConsoleTextAttribute(hStdout,124);
	L = strlen(Key);
	j = L;
	for (i = 0; Msg[i] != '\0'; i++) {
		x = Find(STR,Msg[i]);
		if (j >= L-1)
			j = 0;
		else
			j++;
		y = Find(STR, Key[j]);
		z = Code[x] + Code[y];
		d = 0;
		if (z >= Max) {
			d = 1;
			z = z - Max;
		}
		cout <<  STR[z] << d;
	}
	cout << "\n";
	return 0;
}


int decoding(char Msg[], char Key[])
{
	int x , y , z , L , j , t;
	gotoxy(35,8);
	SetConsoleTextAttribute(hStdout,12);
	cout << "Please Enter Msg(Coded) String and press Enter : ";
	SetConsoleTextAttribute(hStdout,124);
	cin.ignore();
	cin.getline(Msg, Max);
	gotoxy(35,9);
	SetConsoleTextAttribute(hStdout,12);
	cout << "Please Enter Key String and press Enter : ";
	SetConsoleTextAttribute(hStdout,124);
	cin.getline(Key, Max);
	SetConsoleTextAttribute(hStdout,12);
	gotoxy(35, 11);
	cout << "Decode string is : ";
	SetConsoleTextAttribute(hStdout,124);
	L = strlen(Key);
	j = L;
	for (t = 0 ; Msg[t] != '\0' ; t+=2)
	{
		if ( j >= (L - 1) )
			j = 0;
		else
			j++;
		z = Msg[t + 1]-'0';
		x = Find(STR,Msg[t]);		
		y = Find(STR,Key[j]);
		z = x - 1 - Code[y] + (Max * z);
		cout << STR[z] ;
	}
	cout << "\n";
	return 0;
}


int FileDeCode(char Msg[], char Key[])
{
	int   i , z , x , y , L , j;
	char xx , yy;
	fstream inFile("h:/output.txt", std::ios::in);
	fstream outFile("h:/output2.txt", std::ios::out);
	char buffer[256];
	gotoxy(33,8);
	SetConsoleTextAttribute(hStdout,12);
	cout << "Please source file in h:/output.txt and then Press 'Y': ";
	SetConsoleTextAttribute(hStdout,124);
	cin >> xx;
	if (xx != 'y' && xx != 'Y')
		return 0;
	gotoxy(35,9);
	SetConsoleTextAttribute(hStdout,12);
	cout << "Please Enter KEY String and press Enter : ";
	SetConsoleTextAttribute(hStdout,124);
	cin.ignore();
	cin.getline(Key, Max);
	//inFile.open("h:/output.txt",ios::in);
	if (!inFile) 
	{
		cerr << "Can't open input file from' h:/output.txt '" << endl;
		return -1;
	}
	//outFile.open("h:/output2.txt", ios::out);
	if (!outFile) {
		cerr << "Can't open output file from ' h:/output2.txt '" << endl;
		return -2;
	}
	i = 0;
	L = strlen(Key);
	j = L;
	inFile.getline(buffer, 256);
	while ((!inFile.eof()) && (buffer[i] != '\0')) {
		for (i = 0; (!inFile.eof()) && (buffer[i] != '\0'); i = i + 2) {
			if (buffer[i] == '\0')
				break;
			xx = buffer[i];
			yy = buffer[i + 1];
			z = yy - '0';
			x = Find(STR, xx);
			if (j >= L - 1)
				j = 0;
			else
				j++;
			y = Find(STR, Key[j]);
			z = x - 1 - Code[y] + (Max * z);
			cout    << STR[z];
			outFile << STR[z];
		}
		outFile << "\n";
		inFile.getline(buffer, 256);
	}
	inFile.close();
	outFile.close();
	return 0;
}
int FileCode(char Msg[] , char Key[])
{
	int   i , z , x , y , j , L;
	char xx;
	fstream inFile("h:/input.txt", std::ios::in);
	fstream outFile("h:/output.txt", std::ios::out);
	char buffer[256];
	gotoxy(33,8);
	SetConsoleTextAttribute(hStdout,12);
	cout << "Please source file in h:/Input.txt and then Press Y:";
	SetConsoleTextAttribute(hStdout,124);
	cin >> xx;
	if (xx != 'y' && xx != 'Y')
		return 0;
	gotoxy(35,9);
	SetConsoleTextAttribute(hStdout,12);
	cout << "Please Enter KEY String and press Enter:";
	SetConsoleTextAttribute(hStdout,124);
	cin >> Key;
	//inFile.open("h:/input.txt", ios::in);
	if (!inFile) {
		cerr << "Can't open input file " << "h:/input.txt" << endl;
		return -1;
	}
	//outFile.open("h:/output.txt", ios::out);

	if (!outFile) {
		cerr << "Can't open output file " << "h:/output.txt" << endl;
		return -2;
	}
	L = strlen(Key);
	j = L;
	inFile.getline(buffer, 256);
	while ((!inFile.eof()) && (buffer[0] != '\0')) {
		for (i = 0; (!inFile.eof()) && (buffer[i] != '\0'); i++) {
			if (buffer[i] == '\0')
				break;
			xx = buffer[i];
			x = Find(STR, xx);
			if (j >= L - 1)
				j = 0;
			else
				j++;
			y = Find(STR, Key[j]);
			z = Code[x] + Code[y];
			if (z >= Max) {
				z = z - Max;
				outFile << STR[z] << "1" ;
				cout << STR[z] << "1";
			              }
			else {
				outFile << STR[z] << "0";
				cout << STR[z] << "0";
			}
		}
		outFile << "\n";
		inFile.getline(buffer, 256);
	}
	inFile.close();
	outFile.close();
	return 0;
}

int Input() {
	SetConsoleTextAttribute(hStdout, wOldColorAttrs);
	SetConsoleTextAttribute(hStdout,0);
	system("cls");
	SetConsoleTextAttribute(hStdout,12);
	gotoxy(35,7);
	cout << "* * * * * * * * * * * *";
	gotoxy(35,8);
	SetConsoleTextAttribute(hStdout,12);
	cout << "* ";
	SetConsoleTextAttribute(hStdout,78);
	cout << "Enter your Choice : ";
	SetConsoleTextAttribute(hStdout,12);
	cout << "* ";
	gotoxy(35,9);
	cout << "*                     *";
	gotoxy(35,10);
	SetConsoleTextAttribute(hStdout,12);
	cout << "* (C)";
	SetConsoleTextAttribute(hStdout,14);
	cout << "ode a string     ";
	SetConsoleTextAttribute(hStdout,12);
	cout << "*";
	gotoxy(35,11);
	SetConsoleTextAttribute(hStdout,12);
	cout << "* (D)";
	SetConsoleTextAttribute(hStdout,14);
	cout << "ecode a string   ";
	SetConsoleTextAttribute(hStdout,12);
	cout << "*";
	gotoxy(35,12);
	cout << "* (F)";
	SetConsoleTextAttribute(hStdout,14);
	cout << "ile code         ";
	SetConsoleTextAttribute(hStdout,12);
	cout << "*";
	gotoxy(35,13);
	cout << "* (R)";
	SetConsoleTextAttribute(hStdout,14);
	cout << "estore           ";
	SetConsoleTextAttribute(hStdout,12);
	cout << "*";
	gotoxy(35,14);
	cout << "* (Q)";
	SetConsoleTextAttribute(hStdout,14);
	cout << "uit              ";
	SetConsoleTextAttribute(hStdout,12);
	cout << "*";
	gotoxy(35,15);
	cout << "*                     *";
	gotoxy(35,16);
	SetConsoleTextAttribute(hStdout,12);
	cout << "* * * * * * * * * * * *";
	gotoxy(56,8);
	SetConsoleTextAttribute(hStdout,124);
	cin >> menuChoice;
	SetConsoleTextAttribute(hStdout,FOREGROUND_RED);
	return menuChoice;
}

int main() {
	int  i;
	char Msg[101],Key[101];
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
	for (i = 0; i < Max; i++) {
		Code[i] = i + 1;
	}	
	do
	{
		menuChoice = Input();
		switch (menuChoice){
		case'C':
		case'c':{
		    	//call to process function user code from console
			    system("CLS");
		    	coding(Msg, Key);
				break;
				}
		case'D':
		case'd':{
				//call to process function display decode for user 
				system("CLS");
				decoding(Msg, Key);
				break;
    			}
		case'Q':
		case'q':{
			    // Bye Bye
            	system("CLS");
				gotoxy(40,10);
				SetConsoleTextAttribute(hStdout,252);
				cout << "Thanks ! Nice to meet you ;) " << endl;
				SetConsoleTextAttribute(hStdout,wOldColorAttrs);
				break;
				}
		case'F':
		case'f':{
			     //call to process function code  file form user 
		    	system("CLS");
				FileCode(Msg,Key);
				cout << "\nFile output is h:/output.txt" << endl;
			    break;
				}
		case'R':
		case'r':{
			    //call to process function Decode  file form user 
		    	system("CLS");
				FileDeCode(Msg,Key);
				cout << "\nFile output is h:/output2.txt" << endl;
			    break;
		        }
		default:
			{
				system("CLS");
				gotoxy(40,10);
				SetConsoleTextAttribute(hStdout,252);
				cout << "Wrong! Enter Correct Please try again " << endl;
				SetConsoleTextAttribute(hStdout,wOldColorAttrs);
			}
		}
		cout << "\n";
		system("Pause");
	} while (menuChoice != 'q' && menuChoice != 'Q');
	return 0;
}