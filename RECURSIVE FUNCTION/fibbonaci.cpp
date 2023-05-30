#include <iostream>
using namespace std;

int fibbonaci(int angka)
{

    if (angka == 0 or angka == 1)
    {
        return angka;
    }
    else
    {
        return fibbonaci(angka - 1) + fibbonaci(angka - 2);
    }
}

int main()
{
    cout << fibbonaci(6);
    return 0;
}