#include <iostream>
using namespace std;

const int DLUGOSC = 100;

char trojkaty [DLUGOSC][DLUGOSC];

void stworz_tablice_trojkatow(int poziom_max, int x, int y, int poziom) 
{
	int rozmiar = DLUGOSC / pow(2, poziom);

	// Narysuj zewnetrzny trojkat
	for (int i = 0; i < rozmiar; i++)
	{
		// Narysuj pionowa inie (x, y) do (x, y+size)
		trojkaty[y + i][x] = 1;
		// Narysuj pozioma linie (x, y+size) do (x+size, y+size)
		trojkaty[y + rozmiar - 1][x + i] = 1;
		// Narysuj diagonalna (x, y) do (x+size, y+size)
		trojkaty[y + i][x + i] = 1;
	}

	// Narysuj wewnetrzne trojkaty
	if (poziom + 1 < poziom_max)
	{
		stworz_tablice_trojkatow(poziom_max, x, y, poziom + 1);
		stworz_tablice_trojkatow(poziom_max, x, y + (rozmiar / 2), poziom + 1);
		stworz_tablice_trojkatow(poziom_max, x + (rozmiar / 2), y + (rozmiar / 2), poziom + 1);
	}
}

void wyswietl_tablice_trojkatow()
{
	for (int i = 0; i < DLUGOSC; i++) {
		for (int j = 0; j < DLUGOSC; j++)
		{
			if (trojkaty[i][j] == 0)
				cout << ' ';
			else
				cout << '*';
		}
		cout << endl;
	}
}

int main()
{
	int poziom_max {};
	cout << "Podaj poziom trojkata Sierpinskiego: ";
	cin >> poziom_max;
	if (poziom_max < 0)
	{
		cout << "Poziom nie moze byc ujemny.";
		return -1;
	}

	stworz_tablice_trojkatow(poziom_max, 0, 0, 0);

	wyswietl_tablice_trojkatow();
}