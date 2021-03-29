#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std; 

struct koordinat 
{
    //Struct berisi koordinat x, y, z
    double x;
    double y;
    double z;

} tabel[8];

void inisialisasiTabel()
{
    tabel[0].x = 0;  tabel[1].x = 20;   tabel[2].x = 20;    tabel[3].x = 0;
    tabel[0].y = 0;  tabel[1].y = 0;    tabel[2].y = 0;     tabel[3].y = 0;
    tabel[0].z = 0;  tabel[1].z = 0;    tabel[2].z = 20;    tabel[3].z = 20;

    tabel[4].x = 0;  tabel[5].x = 20;   tabel[6].x = 20;    tabel[7].x = 0;
    tabel[4].y = 20; tabel[5].y = 20;   tabel[6].y = 20;    tabel[7].y = 20;
    tabel[4].z = 0;  tabel[5].z = 0;    tabel[6].z = 20;    tabel[7].z = 20;
}

void cetakKoordinat(int M)
{
    inisialisasiTabel();

    cout << "M = " << M  << "\n\n";
    cout << setw(5) << 'X' << setw(5) << 'Y' << setw(5) << 'Z' << setw(6) << "Xp" << setw(6) << "Yp";
    cout << "\n================================\n";

    for(short i = 0; i < 8; i++)
    {
        int Xp = round(tabel[i].x / (1 - (tabel[i].z / M)));
        int Yp = round(tabel[i].y / (1 - (tabel[i].z / M)));

        cout << setw(5) << tabel[i].x << setw(5) << tabel[i].y << setw(5) << tabel[i].z;
        cout << setw(6) << Xp << setw(6) << Yp << "\n";
    }
}

int main()
{
    int M;
    cout << "Masukkan nilai M: ";
    cin >> M;
    
    cetakKoordinat(M);
}