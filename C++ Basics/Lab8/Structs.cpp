#include <iostream>
#include <fstream>
#include<string>
using namespace std;
struct student {
    string imie;
    string nazwisko;
    int numer_indeksu;

};

int main() {


    cout << "1.Zapis w pliku" << endl;
    cout << "2.Odczyt pliku" << endl;
    cout << "3.Usuniecie z pliku" << endl;
    cout << "4.Wylacz Program" << endl;

    int wybor;
    cin >> wybor;

    switch (wybor) {
    case 1: {
        cout << "Podaj liczbe studentow: " << endl;
        int n;
        cin >> n;

        student* nowy_student = new student[n];
        for (int i = 0; i < n; i++) {
            cout << "Podaj imie studenta: " << endl;
            cin >> nowy_student[i].imie;
            cout << "Podaj nazwisko studenta: " << endl;
            cin >> nowy_student[i].nazwisko;
            cout << "Podaj numer albumu Studenta: " << endl;
            cin >> nowy_student[i].numer_indeksu;
        }
        fstream plik;
        plik.open("Spis Studentow.txt", ios::out | ios::app);

        for (int j = 0; j < n; j++) {
            plik << nowy_student[j].imie << endl;
            plik << nowy_student[j].nazwisko << endl;
            plik << nowy_student[j].numer_indeksu << endl;
        }
        plik.close();
        delete[] nowy_student;
        break;


    }

    case 2: {
        fstream plik;
        plik.open("Spis Studentow.txt", ios::in);
        if (plik.good() == false) {
            cout << "Plik nie istnieje" << endl;
            exit(0);
        }
        string linia;
        while (getline(plik, linia)) {
            cout << linia << endl;

        }
        plik.close();
        break;
    } case 3: {
        remove("Spis Studentow.txt");

        cout << "Usuniety poprawnie" << endl;
        break;
    }
    case 4: {
        exit(0);
    }
    default: {
        cout << "Wybierz odpowiedz poprawną" << endl;
        cin >> wybor;

        cout << endl;

    }
    }
    return 0;
}