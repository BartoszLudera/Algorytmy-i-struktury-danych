/*

Proszę zaprojektować i zaimplementować tablicę z haszowaniem dla liczb naturalnych. Należy użyć funkcji skrótu zwracającej resztę z dzielenia przez pojemność
tablicy oraz adresowania otwartego z funkcją przyrostu p(i) = i, gdzie i jest kolejnym numerem próby wstawienia.

Komponenty tablicy haszującej z adresowaniem otwartym:

- tablica z danymi,
- funkcja dodająca elementy do tablicy (Insert),
- funkcja szukająca danego elementu w tablicy (Search),
- funkcja usuwająca element o zadanym indeksie,
- funkcja skrótu,
- funkcja przyrostu.

*/

#include <iostream>
#include <list>

using namespace std;

class Hash
{
public:
    int capacity = 7;
    list<int> *table;

    Hash()
    {
        table = new list<int>[capacity];
    }

    int hashFunction(int x)
    {
        return (x % capacity);
    }

    void insertItem(int key)
    {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteItem(int key)
    {
        int index = hashFunction(key);

        list<int>::iterator i;
        for (i = table[index].begin();
             i != table[index].end(); i++)
        {
            if (*i == key)
                break;
        }

        if (i != table[index].end())
            table[index].erase(i);
    }

    bool searchItem(int key)
    {
        int index = hashFunction(key);

        list<int>::iterator i;
        for (i = table[index].begin();
             i != table[index].end(); i++)
        {
            if (*i == key)
                break;
        }

        if (i != table[index].end())
        {return true;}
        else
        {return false;}
    }

    void displayHash()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << i;
            for (auto x : table[i])
                cout << " => " << x;
            cout << endl;
        }
    }
};

int main()
{
    int a[] = {1, 4, 7, 8, 15}; // input data
    int n = sizeof(a) / sizeof(a[0]);

    Hash h;

    for (int i = 0; i < n; i++) // insert items to table
    {
        h.insertItem(a[i]);
    }

    h.deleteItem(4);
    h.displayHash();

    int e=8;
    if(h.searchItem(e)==true)
    {
        cout<<"Elemnet "<<e<<" is in table"<<endl;
    }
    else
    {
        cout<<"Elemnet "<<e<<" isn't in table"<<endl;
    }
}
