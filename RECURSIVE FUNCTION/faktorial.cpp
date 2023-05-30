#include <iostream>
using namespace std;

int faktorial(int angka)
{
    if (angka <= 1)
    {
        return angka;
    }
    else
    {
        return angka * faktorial(angka - 1);
    }
}

int main()
{

    cout << faktorial(4);

    return 0;
}