#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

string arr[3][3] = { {"7", "8", "9"}, {"4", "O", "6"}, {"1", "2", "3"} };
string arrCz[3][3] = { {" ", " ", " "}, {" ", "O", " "}, {" ", " ", " "} };
bool flagX = false;
bool flagO = false;

string x = "X";
string o = "O";
string  b, d;
string a, c;

void inFace(string a[3][3]);
void Check(string xo);
void Gamer_Ai(string ac, string db, string xo);

static const char alphanum[] = "12346789";
int stringLength = sizeof(alphanum) - 1;

char genRandom()
{
	return alphanum[rand() % stringLength];
}

int main()
{
	setlocale(LC_ALL, "rus");

	inFace(arr);
	inFace(arrCz);
	cout << endl; cout << endl; cout << endl;

	int i = 0;
	char yesNo;

	do
	{
		cout << "Введите номер ячейки. Либо введите повторно т.к. ячейка заполнена." << endl;
		cout << "Ваш ход: "; cin >> a; cout << endl;

		b = "_";

		if (a.size() > 1)
		{
			cout << " Вы ввели недопустимую цифру" << endl;
			continue;
		}
		else
		{
			Gamer_Ai(a, b, x);
			Check(x);
		}

		if (flagX == true)
		{
			break;
		}

		d = "_";

		do
		{
			srand(time(0));
			c = genRandom();

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (arrCz[i][j] == " " && c == arr[i][j])
					{
						arrCz[i][j] = o;
						d = o;
						break;
					}
				}
			}
		} while (d != o);

		Check(o);

		if (flagO == true)
		{
			break;
		}

		system("cls"); // Обновление экрана

		inFace(arr);
		inFace(arrCz);

		cout << endl; cout << endl; cout << endl;

		i++;

		if (i > 3 && flagX == false && flagO == false)
		{
			break;
		}

	} while (i < 5);

	system("cls"); // Обновление экрана

	inFace(arrCz);
	cout << endl; cout << endl; cout << endl;

	if (flagX == true)
	{
		cout << "\t ВЫ ВЫГРАЛИ " << endl; cout << endl;
	}
	else if (flagO == true)
	{
		cout << "\t ВЫГРАЛ БОТ " << endl; cout << endl;
	}
	else if (flagX == false && flagO == false)
	{
		cout << "\t НИЧЬЯ " << endl; cout << endl;
	}
	cout << endl; cout << endl;

	cout << "Если хотите сыграть еще раз введите 'Y' иначе 'N': "; cin >> yesNo; cout << endl;

	system("pause");
}

// Интерфейс

void inFace(string a[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		cout << " ";

		for (int k = 0; k < 13; k++)
		{
			cout << "_";
		}

		cout << endl;
		cout << endl;

		for (int j = 0; j < 3; j++)
		{
			cout << " " << "| " << a[i][j];
		}
		cout << " |" << endl;
	}

	cout << " ";

	for (int m = 0; m < 13; m++)
	{
		cout << "_";
	}
	cout << endl;
}

// Результат игры (проверка)

void Check(string xo)
{
	int v = 0;

	for (int i = 0; i < 3; i++)
	{
		if (arrCz[v][i] == xo && arrCz[v + 1][i] == xo && arrCz[v + 2][i] == xo)
		{
			if (xo == x)
			{
				flagX = true;
			}
			else
			{
				flagO = true;
			}
		}
		if (arrCz[i][v] == xo && arrCz[i][v + 1] == xo && arrCz[i][v + 2] == xo)
		{
			if (xo == x)
			{
				flagX = true;
			}
			else
			{
				flagO = true;
			}
		}
	}

	if (xo == o)
	{
		if (arrCz[v][v] == o && arrCz[v + 1][v + 1] == o && arrCz[v + 2][v + 2] == o) // Проверка диагональ1
		{
			flagO = true;
		}
		if (arrCz[v][v + 2] == o && arrCz[v + 1][v + 1] == o && arrCz[v + 2][v] == o) // Проверка диагональ2
		{
			flagO = true;
		}
	}
}

// Ход Игрока и ИИ

void Gamer_Ai(string ac, string db, string xo)
{
	do
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (arrCz[i][j] == " " && ac == arr[i][j])
				{
					arrCz[i][j] = xo;
					db = xo;
					break;
				}
			}
		}
	} while (db != xo);
}