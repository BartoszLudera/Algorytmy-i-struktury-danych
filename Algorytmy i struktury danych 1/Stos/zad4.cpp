/*

Metody klasy implementującej stos:

- //void push(element x) - dodaje element x na szczyt stosu,
- //element pop() - pobiera (i usuwa) element ze szczytu stosu,
- //element isTop() - zwraca element znajdujący się na szczycie stosu (bez usuwania),
- //void makenull() - usuwa wszystkie elementy ze stosu,
- //boolean empty() - sprawdza, czy stos jest pusty.

*/

#include <iostream>

using namespace std;

template <typename T>
class ArrayStack
{
public:
    int capacity;
    int top;
    T *array;

    ArrayStack()
    {
        capacity = 100;
        top = 0;
        array = new T[capacity];
    }

    ~ArrayStack()
    {
        delete[] array;
    }

    bool empty()
    {
        if (top == 0)
            return true;
        else
            return false;
    }

    void push(T element)
    {
        if (top + 1 > capacity)
        {
            capacity *= 2;
            T *tempArray = new T[capacity];

            for (int i = 0; i < top; i++)
            {
                tempArray[i] = array[i];
            }
            delete[] array;
            array = tempArray;
        }

        array[top] = element;
        top += 1;
    }

    T pop()
    {
        if (empty())
        {
            return T();
        }
        top -= 1;
        return array[top];
    }

    T isTop()
    {
        if (empty())
        {
            return T();
        }
        return array[top - 1];
    }

    void makenull()
    {
        delete[] array;
        top = 0;
        capacity = 100;
        array = new T[capacity];
    }

    void print()
    {
        if (empty())
        {
            cout << "stock is empty" << endl;
        }
        else
        {
            for (int i = 0; i < top; i++)
                cout << array[i] << " ";
            cout << "\n";
        }
    }
};

int main()
{
    ArrayStack<int> myStack;
    cout << "#1" << endl;
    myStack.push(1);
    myStack.push(8);
    myStack.push(9);
    myStack.print();

    cout << "#2" << endl;
    myStack.makenull();
    myStack.print();

    cout << "#3" << endl;
    int value = myStack.pop();
    cout << value << endl;
}