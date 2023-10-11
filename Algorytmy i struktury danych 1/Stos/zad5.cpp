/*

Metody klasy implementującej stos:

- void push(element x) - dodaje element x na szczyt stosu,
- //element pop() - pobiera (i usuwa) element ze szczytu stosu,
- //element top() - zwraca element znajdujący się na szczycie stosu (bez usuwania),
- void makenull() - usuwa wszystkie elementy ze stosu,
- //boolean empty() - sprawdza, czy stos jest pusty.

*/

#include <iostream>

using namespace std;

template <typename T>
class PointerStack
{
public:
    struct Node
    {
        T wartosc;
        Node *wskaznik;
    };

    Node *stos;
    int dlugosc = 0;

    ~PointerStack()
    {
        while (!empty())
        {
            pop();
        }
    }

    void push(T x)
    {
        Node *temp = new Node;
        temp->wartosc = x;
        temp->wskaznik = stos;
        stos = temp;
        dlugosc++;
    }

    T pop()
    {
        if (empty())
        {
            cout << "stack is empty" << endl;
            return 0;
        }

        T wynik = stos->wartosc;
        Node *poprzedni = stos->wskaznik;
        delete stos;
        stos = poprzedni;
        dlugosc--;
        return wynik;
    }

    T top()
    {
        return stos->wartosc;
    }

    bool empty()
    {
        if (dlugosc == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void makenull()
    {
        while (stos)
        {
            Node *temp = stos->wskaznik;
            delete stos;
            stos = temp;
        }
    }

    void print()
    {
        Node *temp = stos;
        if (stos == NULL)
            cout << "stack empty";
        else
        {
            while (temp != NULL)
            {
                cout << temp->wartosc << " ";
                temp = temp->wskaznik;
            }
        }
        cout << endl;
    }
};

int main()
{
    PointerStack<int> myStack;
    cout << "#1" << endl;
    myStack.push(1);
    myStack.push(8);
    myStack.push(9);
    myStack.print();

    cout << "#2" << endl;
    int value = myStack.pop();
    cout << value << endl;
}