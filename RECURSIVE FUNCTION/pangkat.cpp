#include <iostream>
using namespace std;

// int pangkat(int nilai, int pangkat)
// {
//     int hasil = nilai;
//     for (int i = 1; i < pangkat; i++)
//     {
//         hasil = nilai * hasil;
//     }
//     return hasil;
// }

int pangkatrekursif(int angka, int pangkat)
{
    if (pangkat == 1)
    {
        return angka;
    }
    else
    {
        return angka * pangkatrekursif(angka, (pangkat - 1));
    }
}

int main()
{
    cout << pangkatrekursif(5, 2);

    cin.get();
    return 0;
}