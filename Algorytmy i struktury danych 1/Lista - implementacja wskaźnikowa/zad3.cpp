/*

Metody klasy reprezentującej listę dwukierunkową*:

		//void Insert(element x, cell * p); // wstawia element x na pozycję next komórki o wskaźniku p
										  // (lub w przypadku pustej listy tworzy komórkę z elementem x w miejscu głowy listy)
		//void Delete(cell * p); // usuwa komórkę z pozycji next komórki o wskaźniku p
		//cell * Locate(element x); // zwraca wskaźnik do pierwszej komórki z elementem x
		//cell * First(); // zwraca wskaźnik do pierwszej komórki na liście
		//cell * Next(cell * p); // zwraca wskaźnik do kolejnej komórki po komórce o wskaźniku p
		//cell * Previous(cell * p); // zwraca wskaźnik do komórki poprzedzającej komórkę o wskaźniku p
		//cell * Last(); // zwraca wskaźnik do ostatniej komórki na liście
		//void print(); // wyświetla wszystkie elementy listy

*/

#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	T data;
	Node *next;
	Node *prev;
};

template <typename T>
class DoublyLinkedList
{
public:
	Node<T> *head;
	Node<T> *prev;

	DoublyLinkedList()
	{
		head = NULL;
		prev = NULL;
	}

	T First()
	{
		Node<T> *temp = head;
		return 1;
	}

	T Last()
	{
		Node<T> *temp = head;
		int counter = 0;
		while (temp != NULL)
		{
			temp = temp->next;
			counter++;
		}
		return counter + 1;
	}

	T Next(int position)
	{
		if (position < 1 || position > Last())
		{
			cout << "\nposition should be >= 1 or <= " << Last() - 1;
			return -1;
		}
		else
		{
			return position + 1;
		}
	}

	T Previous(int position)
	{
		if (position < 1 || position > Last())
		{
			cout << "\nposition should be >= 2 or <= " << Last();
			return -1;
		}
		else
		{
			return position - 1;
		}
	}

	void Insert(T newElement, int position)
	{
		Node<T> *newNode = new Node<T>();

		newNode->data = newElement;
		newNode->next = NULL;
		newNode->prev = NULL;

		if (position < 1)
		{
			cout << "\nposition should be >= 1.";
		}
		else if (position == 1)
		{

			newNode->next = head;
			//head->prev = newNode;
			head = newNode;
		}
		else
		{

			Node<T> *temp = head;
			for (int i = 1; i < position - 1; i++)
			{
				if (temp != NULL)
				{
					temp = temp->next;
				}
			}

			if (temp != NULL)
			{
				newNode->next = temp->next;
				newNode->prev = temp;
				temp->next = newNode;
				if (newNode->next != NULL)
					newNode->next->prev = newNode;
			}
			else
			{
				cout << "\nThe previous node is null.";
			}
		}
	}

	T Locate(int searchValue)
	{
		Node<T> *temp = head;
		int found = 0;
		int i = 0;

		if (temp != NULL)
		{
			while (temp != NULL)
			{
				i++;
				if (temp->data == searchValue)
				{
					found++;
					break;
				}
				temp = temp->next;
			}
			if (found == 1)
			{
				return i;
			}
			else
			{
				return Last();
			}
		}
		else
		{
			return Last();
		}
	}

	void Delete(int position)
	{
		if (position < 1)
		{
			cout << "\nposition should be >= 1.";
		}
		else if (position == 1 && head != NULL)
		{
			Node<T> *nodeToDelete = head;
			head = head->next;
			free(nodeToDelete);
			if (head != NULL)
				head->prev = NULL;
		}
		else
		{
			Node<T> *temp = head;
			for (int i = 1; i < position - 1; i++)
			{
				if (temp != NULL)
				{
					temp = temp->next;
				}
			}
			if (temp != NULL && temp->next != NULL)
			{
				Node<T> *nodeToDelete = temp->next;
				temp->next = temp->next->next;
				if (temp->next->next != NULL)
					temp->next->next->prev = temp->next;
				free(nodeToDelete);
			}
			else
			{
				cout << "\nThe node is already null.";
			}
		}
	}

	void print()
	{
		Node<T> *temp = head;
		if (temp != NULL)
		{
			cout << "The list contains: ";
			while (temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
		else
		{
			cout << "The list is empty.\n";
		}
	}
};

int main()
{
	DoublyLinkedList<int> MyList;

	MyList.Insert(2312, 1);
	MyList.print();

	MyList.Insert(32, 1);
	MyList.print();

	MyList.Insert(3423, 3);
	MyList.print();

	MyList.Insert(888, MyList.First());
	MyList.print();

	MyList.Insert(222, MyList.Last());
	MyList.print();

	MyList.Insert(69, 4);

	MyList.Insert(420, MyList.Last());
	MyList.print();

	MyList.Insert(20, MyList.Next(3));
	MyList.print();

	MyList.Delete(MyList.Locate(32));
	MyList.print();
}
