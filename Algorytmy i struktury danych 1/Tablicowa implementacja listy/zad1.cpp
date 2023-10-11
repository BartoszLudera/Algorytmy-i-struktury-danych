/*
POLECENIE:

Tablicowa implementacja listy

First() - zwraca pozycję elementu pierwszego -(indeks 0).
END() - zwraca pozycję za ostatnim elementem (czyli last+1).
Next(p) -zwraca indeks następnego elementu po p (czyli p+1): -jeśli istnieje element następny, to zwróć jego indeks -jeśli nie istnieje element następny, to zwróć -1.
Previous(p) - zwraca indeks poprzedniego elementu w stosunku do p (czyli p-1) -jeśli istnieje element poprzedni, to zwróć jego indeks -jeśli nie istnieje element poprzedni, to zwróć -1.
Insert(x,p) - wstawia x do komórki o numerze p ( o ile się da): -sprawdź, czy jest miejsce w tablicy -sprawdź, czy pozycja p jest poprawna -przesuń elementy w tablicy, aby komórka p była pusta -wstaw x do komórki p -zwiększ last -zwróć true gdy operacja wstawiania się powiedzie, false wpp.
Delete(p) - usuwa element z komórki o numerze p: -sprawdź, czy pozycja p jest poprawna -przesuń elementy w "górę" tablicy -zmniejsz last -zwróć true gdy operacja usuwania się powiedzie, false wpp.
Locate(x) - zwraca pozycję elementu x w liście (indeks komórki), jeśli x występuje w tablicy. -zwraca END() (pozycję za ostatnim elementem) gdy x nie występuje w tablicy.
Retrieve(p) - zwraca wskaźnik elementu znajdującego się w liście na pozycji p(w komórce p), jeśli pozycja p jest poprawna - zwraca nullptr w przeciwnym przypadku.

*/

#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

const int _maxlengthOfArray = 100;

template <typename T>
class ArrayList
{
public:
    int _counter;
    int _lastElementsOfArray;
    T _elements[_maxlengthOfArray];

    int First() // zwraca pozycję elementu pierwszego -(indeks 0).
    {
        return 0;
    }

    int End() // zwraca pozycję za ostatnim elementem (czyli last+1).
    {
        return _lastElementsOfArray + 1;
    }

    int Next(int p) // zwraca indeks następnego elementu po p (czyli p+1)
    {
        if (p < End())
        {
            return p + 1;
        }
        else
        {
            cout << "WRONG OPERATION" << endl;
            return -1;
        }
    }

    int Previous(int p) // zwraca indeks poprzedniego elementu w stosunku do p (czyli p-1)
    {
        if ((p <= First()) || (p > End()))
        {
            cout << "WRONG OPERATION" << endl;
            return -1;
        }
        else
        {
            return (p - 1);
        }
    }

    bool Insert(T x, int p) // wstawia x do komórki o numerze p ( o ile się da): -sprawdź, czy jest miejsce w tablicy
                            //-sprawdź, czy pozycja p jest poprawna -przesuń elementy w tablicy, aby komórka p była pusta
                            //-wstaw x do komórki p -zwiększ last -zwróć true gdy operacja wstawiania się powiedzie, false wpp.
    {
        if ((p < 0) || (p > End()))
            return false;

        if (p == End())
        {
            _elements[p] = x;
            _lastElementsOfArray = _lastElementsOfArray + 1;
            return true;
        }
        if (p < End())
        {
            for (int k = End(); k > p; k--)
            {
                _elements[k] = _elements[k - 1];
            }
            _elements[p] = x;
            _lastElementsOfArray = _lastElementsOfArray + 1;
            return true;
        }
        return false;
    }

    T Retrieve(int p) // zwraca wskaźnik elementu znajdującego się w liście na pozycji p(w komórce p),
                      // jeśli pozycja p jest poprawna - zwraca nullptr w przeciwnym przypadku.
    {
        if ((p >= 0) || p <= End())
        {
            return _elements[p];
        }
        else
        {
            return NULL; // nullptr jest błędne dlatego zastosowałem NULL
        }
    }

    bool Delete(int p) // usuwa element z komórki o numerze p: -sprawdź, czy pozycja p jest poprawna -przesuń elementy w "górę" tablicy
                       //-zmniejsz last -zwróć true gdy operacja usuwania się powiedzie, false wpp.
    {
        if (p > End() - 1)
            return false;

        while (p < End() - 1)
        {
            _elements[p] = _elements[p + 1];
            p++;
        }
        _lastElementsOfArray--;
        return false;
    }

    int Locate(T x) // zwraca pozycję elementu x w liście (indeks komórki), jeśli x występuje w tablicy. -zwraca END()
                    //(pozycję za ostatnim elementem) gdy x nie występuje w tablicy.
    {
        for (int i = 0; i < End(); i++)
            if (_elements[i] == x)
                return i;
        return End();
    }

    void print() // function printing value of arraylist
    {
        int i = First();
        while (i != End())
        {
            cout << Retrieve(i) << " ";
            i = Next(i);
        }
        cout << endl;
    }
};

int main()
{
    ArrayList<string> _arrayList;

    cout << "#1" << endl;
    _arrayList._lastElementsOfArray = -1;       // make arraylist empty and clean without it arraylist is starting from 0
    _arrayList.Insert("a", _arrayList.First()); // using Insert
    _arrayList.print();

    cout << "#2" << endl;
    _arrayList.Insert("b", _arrayList.First()); // using First, End, Insert
    _arrayList.Insert("c", _arrayList.End());
    _arrayList.print();

    cout << "#3" << endl;
    _arrayList.Delete(_arrayList.Locate("a"));
    _arrayList.print();

    cout << "#4" << endl;
    _arrayList.Insert("arbuz", _arrayList.Previous(_arrayList.End()));
    _arrayList.print();
}