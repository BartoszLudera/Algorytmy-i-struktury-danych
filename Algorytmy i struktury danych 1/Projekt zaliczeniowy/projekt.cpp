/*
POLECENIE: Proszę zaimplementować obsługę wielomianów na bazie tablic. Działania na wielomianach: dodawanie, odejmowanie, mnożenie, obliczanie wartości wielomianu (algorytm Hornera).

autor: Bartosz Ludera
*/

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

void multiplication()
{
    int sWx, sPx, valueLen;
    int *wWx, *wPx, *value;

    cout << "Podaj stopien wielomianu W(x): ";
    cin >> sWx;
    sWx++;

    cout << "Podaj stopien wielomianu P(x): ";
    cin >> sPx;
    sPx++;

    valueLen = sWx + sPx;

    value = new int[valueLen];
    wWx = new int[valueLen];
    wPx = new int[valueLen];

    cout << "Wspolczynniki wielomianu W(x): " << endl;
    for (int i = 0; i < sWx; i++)
    {
        cin >> wWx[i];
    }

    cout << "Wspolczynniki wielomianu P(x): " << endl;
    for (int i = 0; i < sPx; i++)
    {
        cin >> wPx[i];
    }

    for (int k = sWx; k <= valueLen; k++)
        wWx[k] = 0;
    for (int u = sPx; u <= valueLen; u++)
        wPx[u] = 0;

    for (int i = 0; i <= valueLen; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            value[i] += wWx[i - j] * wPx[j];
        }
    }

    cout << "Wynik wspolczynnikow: " << endl;
    for (int v = 0; v < valueLen - 1; v++)
    {
        cout << value[v] << ", ";
    }
    cout << endl;
}

void hornerAlgoritm()
{
    int sWx, argument, value;

    cout << "Podaj stopien wielomianu W(x): ";
    cin >> sWx;
    sWx++;

    int *wWx = new int[sWx];

    cout << "Podaj wspolczynniki wielomianu W(x): " << endl;
    for (int i = 0; i < sWx; i++)
    {
        cin >> wWx[i];
    }

    cout << "Podaj argument do obliczenia wartosci wielomainu: ";
    cin >> argument;

    value = wWx[0];

    for (int i = 1; i <= sWx; i++)
    {
        value = value * argument + wWx[i];
    }

    cout << "Wartosc wielomianu = " << value << endl;
}

void addOrSubstract(bool _isAdding)
{
    bool isReverse;
    int roznica, roznica2, sWx, sPx;
    int *wWx;
    int *wPx;

    cout << "Podaj stopien wielomianu W(x): ";
    cin >> sWx;
    sWx++;

    cout << "Podaj stopien wielomianu P(x): ";
    cin >> sPx;
    sPx++;

    if (sWx < sPx)
    {
        int temp;
        temp = sWx;
        sWx = sPx;
        sPx = temp;
        isReverse = true;
    }
    else if (sWx >= sPx)
    {
        isReverse = false;
    }

    if (sPx == sWx)
    {
        wWx = new int[sWx];

        wPx = new int[sPx];

        cout << "wspolczynniki wielomianu W(x): " << endl;
        for (int i = 0; i < sWx; i++)
        {
            cin >> wWx[i];
        }

        cout << "wspolczynniki wielomianu P(x): " << endl;
        for (int i = 0; i < sPx; i++)
        {
            cin >> wPx[i];
        }
    }
    else if (sWx > sPx)
    {
        roznica = sWx - sPx;
        wWx = new int[sWx];

        wPx = new int[sWx];

        if (isReverse)
        {
            cout << "wspolczynniki wielomianu W(x): " << endl;
            roznica2 = roznica;
            for (int i = 0; i < roznica; i++)
            {
                wPx[i] = 0;
            }
            for (int i = roznica2; i < sWx; i++)
            {
                cin >> wPx[i];
            }

            cout << "wspolczynniki wielomianu P(x): " << endl;
            for (int i = 0; i < sWx; i++)
            {
                cin >> wWx[i];
            }
        }
        else
        {
            cout << "wspolczynniki wielomianu W(x): " << endl;
            for (int i = 0; i < sWx; i++)
            {
                cin >> wWx[i];
            }
            cout << "wspolczynniki wielomianu P(x): " << endl;
            roznica2 = roznica;
            for (int i = 0; i < roznica; i++)
            {
                wPx[i] = 0;
            }
            for (int i = roznica2; i < sWx; i++)
            {
                cin >> wPx[i];
            }
        }
    }
    cout << "Wynik wspolczynnikow: " << endl;
    for (int i = 0; i < sWx; i++)
    {
        if (_isAdding)
            cout << wWx[i] + wPx[i];
        else
            cout << wWx[i] - wPx[i];
        cout << ", ";
    }
    cout << endl;
}

int main()
{
    while (true)
    {
        int wybor, argument;

        cout << "1. Dodawanie" << endl;
        cout << "2. Odejmowanie" << endl;
        cout << "3. Mnożenie" << endl;
        cout << "4. Oblicz wartosc wielomianu (algorytm Hornera)" << endl;
        cout << "5. Wyjdz" << endl;
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor)
        {
        case 1:
        {
            addOrSubstract(true);
        }
        break;
        case 2:
        {
            addOrSubstract(false);
        }
        break;
        case 3:
        {
            multiplication();
        }
        break;
        case 4:
        {
            hornerAlgoritm();
        }
        break;
        case 5:
        {
            exit(0);
        }
        break;

        default:
            cout << "Nie ma takiej opcji w menu!";
            exit(0);
        }
        cout << endl;
        cout << endl;
    }
}
