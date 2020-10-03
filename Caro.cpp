#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <io.h>
using namespace std;
#pragma warning(disable: 4996)

int a[3][3] = { 0 }, e[9] = { 0 };

void Player1(int x);
void Player2(int x);
void CheckCondition(int t);
void Reset();
void Win(int n);
void Draw();
void UpdateScreen();
void RefreshScreen();
int Dem(int n);

int main()
{
	int t = 0, c = 1, draw, x;

	cout << "\n\t  1  |  2  |  3\n";
	cout << "\t-----------------\n";
	cout << "\t  4  |  5  |  6\n";
	cout << "\t-----------------\n";
	cout << "\t  7  |  8  |  9\n";
	cout << "\n\n\t10. Reset\n";
	cout << "\t0. Thoat\n\n";

	while (true) {
		draw = 0;
		
		do
		{
			if (c == 0) {
				RefreshScreen();
				UpdateScreen();
			}
			do
			{
				if (t == 0) {
					cout << "\n\tNguoi choi 1:   \b\b";
				}
				else {
					cout << "\n\tNguoi choi 2:   \b\b";
				}

				scanf("%d", &x);
			} while (x > 10 || x < 0);

			if (x == 0) {
				exit(0);
			}

			if (x == 10) {
				Reset();
				t = 2;
				break;
			}

			if (e[x] == 1 && x != 10) {
				c = 0;
			}
			else if (e[x] == 0 && x != 10) {
				e[x] = 1;
				c = 1;
			}

			for (int i = 0; i < 9; i++) {
				if (e[i] != 0) {
					draw++;
				}
			}

			if (draw >= 9) {
				Draw();
				t = 2;
				break;
			}
		} while (c == 0);

		switch (t)
		{
			case 0:
			{
				Player1(x);
				CheckCondition(t);
				RefreshScreen();
				UpdateScreen();
				break;
			}
			
			case 1:
			{
				Player2(x);
				CheckCondition(t);
				RefreshScreen();
				UpdateScreen();
				break;
			}

			default:;
		}
		t++;
		t %= 2;
	}

	return 0;
}

void Player1(int x)
{
	x -= 1;
	int d = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (x > 2) {
				d = 1;
			}

			if (x > 5) {
				d = 2;
			}

			a[d][x % 3] = 1;
		}
	}
}

void Player2(int x)
{
	x -= 1;
	int d = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (x > 2) {
				d = 1;
			}

			if (x > 5) {
				d = 2;
			}

			a[d][x % 3] = 2;
		}
	}
}

void CheckCondition(int t)
{
	int n = t + 1;
	//Horizontal
	if (a[0][0] == n && a[0][1] == n && a[0][2] == n) {
		Win(n);
		return;
	}

	if (a[1][0] == n && a[1][1] == n && a[1][2] == n) {
		Win(n);
		return;
	}

	if (a[2][0] == n && a[2][1] == n && a[2][2] == n) {
		Win(n);
		return;
	}
	//Vertical
	if (a[0][0] == n && a[1][0] == n && a[2][0] == n) {
		Win(n);
		return;
	}

	if (a[0][1] == n && a[1][1] == n && a[2][1] == n) {
		Win(n);
		return;
	}

	if (a[0][2] == n && a[1][2] == n && a[2][2] == n) {
		Win(n);
		return;
	}
	//Cross
	if (a[0][0] == n && a[1][1] == n && a[2][2] == n) {
		Win(n);
		return;
	}

	if (a[0][2] == n && a[1][1] == n && a[2][0] == n) {
		Win(n);
		return;
	}
}

void Reset()
{
	int d = 0;
	RefreshScreen();
	cout << "\t  1  |  2  |  3\n";
	cout << "\t-----------------\n";
	cout << "\t  4  |  5  |  6\n";
	cout << "\t-----------------\n";
	cout << "\t  7  |  8  |  9\n";
	cout << "\n\n\t10. Reset\n";
	cout << "\t0. Thoat\n\n";

	for (int i = 0; i < 9; i++) {
		e[i] = 0;

		if (i > 2) {
			d = 1;
		}

		if (i > 5) {
			d = 2;
		}

		a[d][i % 3] = 0;
	}
}

void Win(int n)
{
	RefreshScreen();
	if (n == 1) {
		cout << "\n\t\t\t\t\t\n\t\t\t\t\t\n\tPlayer 1 Win !!!\t\t\t\n\t\t\t\t\t\n\t\t\t\t\t\n\t\t\t\t\t";
	}
	else {
		cout << "\n\t\t\t\t\t\n\t\t\t\t\t\n\tPlayer 2 Win !!!\t\t\t\n\t\t\t\t\t\n\t\t\t\t\t\n\t\t\t\t\t";
	}
	getch();
	Reset();
}

void Draw()
{
	RefreshScreen();
	cout << "\n\t\t\t\t\t\n\t\t\t\t\t\n\tDraw\t\t\t\n\t\t\t\t\t\n\t\t\t\t\t\n\t\t\t\t\t";
	getch();
	Reset();
}

void UpdateScreen()
{
	int d = 0;
	for (int i = 0; i < 9; i++) {
		if (i == 0 || i == 3 || i == 6) {
			cout << "\t";
		}

		if (a[d][i % 3] == 1) {
			cout << "  X  ";
		}
		else if (a[d][i % 3] == 2) {
			cout << "  O  ";
		}
		else {
			cout << "  " << i + 1 << "  ";
		}

		if (i == 2 || i == 5) {
			cout << "\n\t-----------------\n";
			d++;
		}
		else if (i != 8) {
			cout << "|";
		}
	}

	cout << "\n\n\n\n\n\n";
}

void RefreshScreen()
{
	COORD coord;
	coord.X = 7;
	coord.Y = 1;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	for (int i = 0; i < 3; i++) {
		for (int e = 0; e < 3; e++) {
			for (int p = 0; p < Dem(a[i][e]) + 7; p++) {
				cout << "     ";
			}
		}

		if (i < 3 - 1) {
			cout << "\n";
		}
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int Dem(int n)
{
	int d = 0;

	do
	{
		n /= 10;
		d++;
	} while (n != 0);

	return d;
}