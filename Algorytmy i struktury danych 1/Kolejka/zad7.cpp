/*

Metody klasy implementującej kolejkę wskaźnikową:

- void put(element x) - dodaje element do kolejki,
- element get() - pobiera (i usuwa) pierwszy element z kolejki,
- element isFront() - zwraca element znajdujący się na początku kolejki (bez usuwania),
- void makenull() - usuwa wszystkie elementy z kolejki,
- boolean empty() - sprawdza, czy kolejka jest pusta.

*/

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *link;
};

struct PointerQueue
{

    Node *front;
    Node *rear;
    Node *link;
};

class Queue
{

    PointerQueue q;
    Node *t;

public:
    Queue()
    {
        q.front = NULL;
        q.rear = NULL;
    }

    void put(int element)
    {

        t = new Node;

        t->data = element;
        t->link = NULL;

        if ((q.rear) == NULL)
        {
            q.front = t;
        }
        else
        {
            q.rear->link = t;
            q.rear = t;
        }
    }

    int isFront()
    {
        if (isEmpty())
        {
            cout << "Queue Is Empty";
            return -1;
        }
        else
        {
            int temp;
            q.front->data;
            return temp;
        }
    }

    void get()
    {

        if (isEmpty())
        {
            cout << "Queue Is Empty";
        }
        else
        {
            t = q.front;
            q.front = q.front->link;
            free(t);
        }
    }

    bool isEmpty()
    {
        if (q.front == NULL)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    void print()
    {
        if (q.front == NULL)
        {
            cout << " Queue Is Empty";
        }
        else
        {
            t = q.front;
            t->data;

            for (t = q.front; t != NULL; t = t->link)
                cout << t->data;
        }
    }
};

int main()
{
    Queue q;
    q.put(8);
    q.put(2);
    q.put(6);
    q.put(9);
    q.get();
    q.print();
}
