// /*

// Metody klasy implementującej kolejkę tablicową (z tablicą cykliczną):

// - //void put(element x) - dodaje element do kolejki,
// - //element get() - pobiera (i usuwa) pierwszy element z kolejki,
// - //element isFront() - zwraca element znajdujący się na początku kolejki (bez usuwania),
// - //void makenull() - usuwa wszystkie elementy z kolejki,
// - //boolean empty() - sprawdza, czy kolejka jest pusta.

// */

#include <iostream>

using namespace std;

template <typename T>
class Queue
{
public:
    T *array;
    int capacity;
    int front;
    int rear;
    int count;

    Queue()
    {
        capacity = 10;
        array = new T[capacity];
        front = -1;
        rear = -1;
    }
    ~Queue()
    {
        delete[] array;
    }

    bool empty()
    {
        if (front == -1)
            return 1;
        else
            return 0;
    }

    bool full()
    {
        if (front == 0 && rear == capacity - 1)
        {
            return true;
        }
        if (front == rear + 1)
        {
            return true;
        }
        return false;
    }

    void makenull()
    {
        delete[] array;
        capacity = 10;
        front = -1;
        rear = -1;
        array = new T[capacity];
    }

    void put(T element)
    {
        if (full())
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear = (rear + 1) % capacity;
            array[rear] = element;
        }
    }

    T get()
    {
        T element;
        if (empty())
        {
            cout << "Queue is empty!" << endl;
            return T();
        }
        else
        {
            element = array[front];
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % capacity;
            }
            return (element);
        }
    }

    T isFront()
    {
        if (empty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return array[front + 1];
    }

    void print()
    {
        if (empty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            for (int i = 0; i <= rear; i++)
                cout << array[i] << " ";
            cout << endl;
        }
    }
};

int main()
{
    Queue<string> q;

    cout << "#1" << endl;
    q.put("bitcoin");
    q.print();

    cout << "#2" << endl;
    q.get();
    q.print();

    cout << "#3" << endl;
    q.makenull();
    q.put("etherium");
    q.put("luna");
    q.print();

    cout << "#4" << endl;
    q.put(q.get());
    q.print();
}
