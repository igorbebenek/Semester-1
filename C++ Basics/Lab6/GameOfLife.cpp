#include <iostream>
#include  <conio.h>
#include   <cstdlib>
#include   <windows.h>
#include  <time.h>

using namespace std;
void cords(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
int main()
{
    int c, a, matrix[83][60], gra_o_zycie[83][60];
    int live;
    srand(time(NULL));
    for (a = 0; a <= 79; a++)
        for (c = 0; c <= 55; c++)
        {
            matrix[a][c] = 0;
            if (a > 1 && a < 78 && c>1 && c < 55)
                if (rand() % 6 == 1)
                {

                    matrix[a][c] = 1;
                    cout << 'x' << endl;
                }

        }
    while (1)
    {
        for (a = 2; a <= 77; a++)
            for (c = 2; c <= 54; c++)
            {
                cords(a, c);
                if (matrix[a][c])
                    cout << "x";
                else cout << " ";

            }


        for (a = 2; a <= 77; a++)
            for (c = 2; c <= 54; c++)
            {
                gra_o_zycie[a][c] = matrix[a][c];
                live = matrix[a - 1][c - 1] + matrix[a][c - 1] + matrix[a + 1][c - 1] + matrix[a - 1][c] + matrix[a + 1][c] + matrix[a - 1][c + 1] + matrix[a][c + 1] + matrix[a + 1][c + 1];
                if (matrix[a][c] == 1)
                {
                    if (live < 2 || live>3)
                    {
                        gra_o_zycie[a][c] = 0;
                    }
                    else
                    {
                        gra_o_zycie[a][c] = 1;
                    }
                }
                else
                {
                    if (live == 3) gra_o_zycie[a][c] = 1;
                }
            }

        for (a = 2; a <= 77; a++)
            for (c = 2; c <= 54; c++)
                matrix[a][c] = gra_o_zycie[a][c];

        Sleep(50);
    }
    return 0;
}
