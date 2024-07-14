#include <iostream>
using namespace std;

#define X 2

#define Z 2

// Dynamically allocate memory for 1D Array in C++


int main()
{
    // dynamically allocate memory of size X
    int** E = new int*[X];

    int** F = new int*[X];

    int** G = new int*[X];

    // assign values to the allocated memory


    int e = 0;
    while (e < X) {
        
        E[e] = new int[Z];
        F[e] = new int[Z];
        G[e] = new int[Z];
        e++;
    }

    
    for(int i = 0; i < X; i++)
        
    


    {
        int q = 0;
        while (q < Z) {
            E[i][q] = rand() % 10;
            F[i][q] = rand() % 10;
            G[i][q] = 0;
            q++;
        }
    }


    for (int i = 0; i < X; i++)


    {
        for (int k = 0; k < Z; k++) {
            std::cout << E[i][k] << " ";


        }
        std::cout << std::endl;
    }

    cout << endl;
    for (int i = 0; i < X; i++)
    {
        int j = 0;
        while( j < Z) {

            std::cout << F[i][j] << " ";
            j++;
        }
        std::cout << std::endl;
    }
    
    for (int i = 0; i < Z; ++i) 
        
    
        for (int j = 0; j < Z; ++j) 
            
            for (int k = 0; k < Z; ++k)
            {
                G[i][j] += E[i][k] * F[k][j];
                
            }
    cout << endl;
    for (int i = 0; i < X; i++)
    {
        int j = 0;
        while (j < Z) {

            std::cout << G[i][j] << " ";
            j++;
        }
        std::cout << std::endl;
    }
    // deallocate memory


    int i = 0;
    while (i < X) {
        delete[] E[i];
        delete[] F[i];
        delete[] G[i];
        i++;
    }
    delete[] E; 
    delete[] F;
    delete[] G;
    return 0;

}