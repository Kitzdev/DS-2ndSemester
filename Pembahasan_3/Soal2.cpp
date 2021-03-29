#include <iostream>
using namespace std;

void inisialisasiMatriksSoal(int matriksSoal[][5])
{
    matriksSoal[0][0] = 1;  
    matriksSoal[0][1] = 0;  
    matriksSoal[0][2] = 0;  
    matriksSoal[0][3] = 0;
    matriksSoal[0][4] = 0;

    matriksSoal[1][0] = 0;  
    matriksSoal[1][1] = 1;  
    matriksSoal[1][2] = 0;  
    matriksSoal[1][3] = 0;
    matriksSoal[1][4] = 0;

    matriksSoal[2][0] = 0;  
    matriksSoal[2][1] = 0;  
    matriksSoal[2][2] = 1;  
    matriksSoal[2][3] = 0;
    matriksSoal[2][4] = 0;

    matriksSoal[3][0] = 0;  
    matriksSoal[3][1] = 0;  
    matriksSoal[3][2] = 0;  
    matriksSoal[3][3] = 1;
    matriksSoal[3][4] = 0;

    matriksSoal[4][0] = 0;  
    matriksSoal[4][1] = 0;  
    matriksSoal[4][2] = 0;  
    matriksSoal[4][3] = 0;
    matriksSoal[4][4] = 1;
}

int main()
{
    int matriksInput[5][5];
    int matriksSoal[5][5];
    int matriksHasil[5][5];
    int container;
    inisialisasiMatriksSoal(matriksSoal);

    for(short i = 0; i < 5; i++)
    {
        for(short j = 0; j < 5; j++)
        {
            cout << "Masukkan nilai matriks baris ke-" << i + 1 << " kolom ke-" << j + 1<< " : ";
            cin >> matriksInput[i][j]; 
        }
    }
    
    cout << "\nMatriks inputan: \n";

    for(short i = 0; i < 5; i++)
    {
        for(short j = 0; j < 5; j++)
        {
            cout << matriksInput[i][j] << " ";
        }

        cout << "\n";
    }

    cout << "\nMatriks soal: \n";

    for(short i = 0; i < 5; i++)
    {
        for(short j = 0; j < 5; j++)
        {
            cout << matriksSoal[i][j] << " ";
        }

        cout << "\n";
    }

    for(short i = 0; i < 5; i++)
    {
        for(short j = 0; j < 5; j++)
        {
            container = 0;

            for(short k = 0; k < 5; k++)
            {
                container += matriksInput[i][k] * matriksSoal[k][j];
            }
            
            matriksHasil[i][j] = container;
        }
    }

    cout << "\nHasil perkalian dua buah matriks: \n";

    for(short i = 0; i < 5; i++)
    {
        for(short j = 0; j < 5; j++)
        {
            cout << matriksHasil[i][j] << " ";
        }

        cout << "\n";
    }
}