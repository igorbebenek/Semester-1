#include <iostream>
#include <string> 
#include <vector>
#include <ctime>
using namespace std;

int day_of_the_week(int y, int m, int d)
{
	// array with leading number of days values
	int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	int r;

	// if month is less than 3 reduce year by 1
	if (m < 3)
		y -= 1;

	r = ((y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7);

	if (r == 0)
		return 7;
	else
		return r;
}

int okresl_liczbe_dni_miesiaca(int miesiac, int rok) 
{
	if (miesiac == 1 || miesiac == 3 || miesiac == 5 || miesiac == 7 || miesiac == 8 || miesiac == 10 || miesiac == 12)
	{
		return 31;
	}
	else if (miesiac == 2 && (rok % 4 == 0))
	{
		return 29;
	}
	else if (miesiac == 2 && (rok % 4 != 0))
	{
		return 28;
	}
	else
	{
		return 30;
	}
}

void wyswietl_nazwe_miesiaca(int miesiac)
{
	vector<string> miesiace = { 
		"Styczen", "Luty", "Marzec", 
		"Kwiecien", "Maj", "Czerwiec", 
		"Lipiec", "Sierpien", "Wrzesien", 
		"Pazdziernik", "Listopad", "Grudzien"};

	cout << "\t\t\t" << miesiace[miesiac - 1] << endl;
}

void wyswietl_miesiac_kalendarza(string miesiac_kalendarza[7][7], int biezacy_dzien, vector<string> dni_swiateczne)
{
	for (int i{}; i < 7; ++i)
	{
		for (int j{}; j < 7; ++j)
		{
			bool czy_mamy_swieto = 0;
			for (string dzien : dni_swiateczne)
			{
				if (dzien == miesiac_kalendarza[i][j])
				{
					czy_mamy_swieto = 1;
				}
			}

			if (to_string(biezacy_dzien) == miesiac_kalendarza[i][j])
			{
				cout << "\t" << "\033[1;43m" << miesiac_kalendarza[i][j] << "\033[0m";
			}
			else if (j == 6 || czy_mamy_swieto == 1)
			{
				cout << "\t" << "\033[1;31m" << miesiac_kalendarza[i][j] << "\033[0m";
			}
			else
			{
				cout << "\t" << miesiac_kalendarza[i][j];
			}
		}
		cout << endl;
	}
}

vector<string> okresl_dni_swiateczne(int rok, int miesiac)
{
	vector<string> dni_swiateczne {};

	// algorytm Gaussa:
	// https://en.wikipedia.org/wiki/Date_of_Easter#Algorithms

	int a = rok % 19;
	int b = rok % 4;
	int c = rok % 7;
	int k = rok / 100;
	int p = (13 + 8 * k) / 25;
	int q = k / 4;
	int M = (15 - p + k - q) % 30;
	int N = (4 + k - q) % 7;
	int d = (19 * a + M) % 30;
	int e = (2 * b + 4 * c + 6 * d + N) % 7;

	int wielkanoc_marzec = 22 + d + e;
	int wielkanoc_kwiecien = d + e - 9;

	if (d == 28 && e == 6 && ((11 * M + 11) % 30 < 19))
	{
		wielkanoc_kwiecien = 18;
	}
	if (d == 29 && e == 6)
	{
		wielkanoc_kwiecien = 19;
	}

	int miesiac_wielkanocy { };
	int dzien_wielkanocy { };
	if (wielkanoc_marzec <= 31)
	{
		miesiac_wielkanocy = 3;
		dzien_wielkanocy = wielkanoc_marzec;
	}
	else
	{
		miesiac_wielkanocy = 4;
		dzien_wielkanocy = wielkanoc_kwiecien;
	}

	// Wielkanoc, niedziela i poniedzialek
	if (miesiac = miesiac_wielkanocy)
	{
		dni_swiateczne.push_back(to_string(dzien_wielkanocy));
		dni_swiateczne.push_back(to_string(++dzien_wielkanocy));
	}

	// Nowy rok
	// Trzech Króli
	else if (miesiac == 1)
	{
		dni_swiateczne.push_back("1");
		dni_swiateczne.push_back("6");
	}
	
	// Wielkanoc - DO ZROBIENIA!!!

	// Œwiêto Pracy i Konstytucji 3 Maja
	else if (miesiac == 5)
	{
		dni_swiateczne.push_back("1");
		dni_swiateczne.push_back("3"); 
		
	}
	//Pierwszy Dzieñ Zielonych Œwi¹tek i Bo¿e Cia³o
	else if (miesiac == 6)
	{
		dni_swiateczne.push_back("5");
		dni_swiateczne.push_back("16");
	}
	//Œwiêto Wojska Polskiego, Wniebowziêcie Najœwiêtszej Maryi Panny
	else if (miesiac == 8)
	{
		dni_swiateczne.push_back("15");
	}
	//Wszystkich Swietych i Niepodleglosci
	else if (miesiac == 11)
	{
		dni_swiateczne.push_back("1");
		dni_swiateczne.push_back("11");
	}
	//Boze Narodzenie i Drugi dzieñ Œwi¹t Bo¿ego Narodzenia
	else if (miesiac == 12)
	{
		dni_swiateczne.push_back("25");
		dni_swiateczne.push_back("26");
	}



	return dni_swiateczne;
}

int main()
{
	int rok {};
	cout << "Podaj rok: ";
	cin >> rok;
	int miesiac {};
	cout << endl << "Podaj miesiac: ";
	cin >> miesiac;
	if (miesiac < 1 || miesiac > 12)
	{
		cout << endl << "Zla liczba miesiaca";
		return -1;
	}
	cout << endl;

	wyswietl_nazwe_miesiaca(miesiac);

	string miesiac_kalendarz_2 [7][7];
	int pierwszy_dzien_miesiaca = day_of_the_week(rok, miesiac, 1);
	int dzien_miesiaca { 1 };
	int liczba_dni_miesiaca = okresl_liczbe_dni_miesiaca(miesiac, rok);

	// Generowanie miesiaca:
	for (int i = 0; i < 7; ++i)
	{
		if (i == 0)
		{
			miesiac_kalendarz_2[0][0] = "Pn";
			miesiac_kalendarz_2[0][1] = "Wt";
			miesiac_kalendarz_2[0][2] = "Sr";
			miesiac_kalendarz_2[0][3] = "Cz";
			miesiac_kalendarz_2[0][4] = "Pt";
			miesiac_kalendarz_2[0][5] = "So";
			miesiac_kalendarz_2[0][6] = "N";
		}
		else if(i == 1)
		{
			for (int j = 0; j < 7; ++j)
			{
				if (j >= pierwszy_dzien_miesiaca - 1)
				{
					miesiac_kalendarz_2[1][j] = to_string(dzien_miesiaca++) ;
				}
				else
				{
					miesiac_kalendarz_2[1][j] = " ";
				}
			}
		}
		else
		{
			for (int j = 0; j < 7; ++j)
			{
				if (dzien_miesiaca <= liczba_dni_miesiaca)
				{
					miesiac_kalendarz_2[i][j] = to_string(dzien_miesiaca++);
				}
				else
				{
					miesiac_kalendarz_2[i][j] = " ";
				}
			}
		}
	}

	time_t now = time(0);
	tm* ltm = localtime(&now);
	int biezacy_rok = 1900 + ltm->tm_year;
	int biezacy_miesiac = 1 + ltm->tm_mon;
	int biezacy_dzien = ltm->tm_mday;
	if (rok != biezacy_rok || miesiac != biezacy_miesiac)
		biezacy_dzien = 0;

	vector<string> dni_swiateczne = okresl_dni_swiateczne(rok, miesiac);
	// Jesli biezacy_dzien == 0, to funkcja wyswietl_miesiac_kalendarza nie wyswietli zadnego dnia jako dzisiejszy.
	wyswietl_miesiac_kalendarza(miesiac_kalendarz_2, biezacy_dzien, dni_swiateczne);
}