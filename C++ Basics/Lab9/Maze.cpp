


#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

using namespace std;

using namespace std::this_thread;

using namespace std::chrono;


char n[7][7];

void skanowanie(int u, int t)
{
    char k = '*';
    int w {};
    int z1 {};
    int z2 {};
    int z3 {};
    int z4 {};


    if (n[u][t] == 'x') {


        do {
            w = 0;
            n[u][t] = k;
            int i{};
            while ( i < 7) 
            {
                int j{};
                while ( j < 7) 
                {
                    cout << n[j][i];
                    j++;
                }
                cout << endl;
                i++;
            }
            sleep_for(nanoseconds(10));
            sleep_until(system_clock::now() + seconds(1));
            system("cls");
           
                if (n[u + 1][t] == 'x')
                {
                    w += 1;
                    z1 += 1;

            }
            if (n[u - 1][t] == 'x')
            {
                w += 1; 
                z2 += 1;
            }
            if (n[u][t + 1] == 'x')
            {
                w += 1; 
                z3 += 1;
            }
            if (n[u][t - 1] == 'x')
            {
                w += 1; 
                z4 += 1;
            }

            switch (w) 
            {
            case 0:return;

            case 1:
                if (z1 == 1)
                {
                    z1 -= 1;
                    u += 1;
                }

                if (z2 == 1)
                {
                    z2 -= 1;
                    u -= 1;
                }

                if (z3 == 1)
                {
                    z3 -= 1;
                    t += 1;
                }

                if (z4 == 1)
                {
                    z4 -= 1;
                    t -= 1;
                }
                break;
            case 2:

            case 3:

                skanowanie(u + 1, t); skanowanie(u - 1, t); skanowanie(u, t + 1); skanowanie(u, t - 1);
                return;


            }


        } 
        while (w == 1);
    }







}

int main()
{
    char symbol;


    int b = 0;



    fstream plik;
    plik.open("labiryntzut.txt", ios::in);


    while (!plik.eof()) {
        int v {};
        while ( v < 7)
        {
            plik >> symbol;
            if (symbol == '1')
            {
                n[v][b] = '#';
            }
            else
            {
                n[v][b] = 'x';
            }
            v++;
        }
        b += 1;
    }
    skanowanie(1, 1);

    int i{};
    while (i < 7)
    {
        int j = 0;
        while (j < 7)
        {
            cout << n[j][i];
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}