#include "HashTable.h"

HashTable::HashTable()
{
	for (int i = 0; i < 10; i++)
	{
		arr[i] = new Node;
		arr[i]->element = -1;
		arr[i]->next = NULL;
	}
	Count = 0;
}

bool HashTable::IsEmpty()
{
	return (!Count);
}

int HashTable::Size()
{
	return Count;
}

void HashTable::Insert(int number)
{
	int idx = number % 10;

	Node* newNode = new Node;

	newNode->element = number;
	newNode->next = NULL;

	if (arr[idx]->element == -1)
	{
		arr[idx] = newNode;
	}
	else
	{
		Node* current = arr[idx];
		Node* prev = arr[idx];

		while (current != NULL)
		{
			prev = current;
			current = current->next;
		}

		prev->next = newNode;
		Count++;
	}

}

void HashTable::Delete(int number)
{
	int idx = number % 10;
	Node* current = arr[idx];
	Node* prev = NULL;

	if (arr[idx]->element == number)
	{
		arr[idx] = arr[idx]->next;
	}

	else
	{
		while (current != NULL && current->element != number)
		{
			prev = current;
			current = current->next;
		}

		if (current == NULL)
		{
			cout << "element not found..\n";
			return;
		}

		prev->next = current->next;
		delete current;
	}

	Count--;
}

bool HashTable::Search(int number)
{
	int idx = number % 10;
	if (arr[idx]->element == -1)
	{
		return 0;
	}
	else
	{
		if (arr[idx]->element == number)
			return 1;

		Node* current = arr[idx];
		while (current != NULL && current->element != number)
		{
			current = current->next;
		}
		if (current == NULL)
		{
			return 0;
		}
		else
			return 1;
	}
}

void HashTable::Display()
{
	for (int i = 0; i < 10; i++) {

		if (arr[i]->element > -1)
		{
			Node* current = arr[i];

			while (current != NULL)
			{
				cout << current->element << " ";
				current = current->next;
			}
			cout << "\n";
		}

	}
}