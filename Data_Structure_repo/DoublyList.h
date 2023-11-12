#pragma once
#include "IDatastructure.h"
#include <iostream>
using namespace std;

template <class T>
struct link {
	T Data;
	link* Next;
	link* Prev;
};

template<class T>
class DoublyList : IDatastructure {
private:
	link<T>* Head;
	link<T>* Tail;
	int length;
public:
	DoublyList();
	int Size();
	bool IsEmpty();
	void InsertFront(T data);
	void InsertBack(T data);
	void Insert(int pos, T data);
	void PopFront();
	void PopBack();
	void EraseAt(int pos);
	void Erase(T element);
	void Display();
	T GetElementAt(int pos);
	int search(T data);
};

template <class T>
DoublyList<T>::DoublyList() : Head(NULL), Tail(NULL), length(0)
{	}

template <class T>
int DoublyList<T>::Size() {
	return length;
}

template <class T>
bool DoublyList<T>::IsEmpty() {
	return !length;
}

template <class T>
void DoublyList<T>::InsertFront(T data) {

	link<T>* NewLink = new link<T>;
	NewLink->Data = data;

	if (IsEmpty()) {
		Head = Tail = NewLink;
		NewLink->Prev = NULL;
		NewLink->Next = NULL;
	}
	else {
		NewLink->Next = Head;
		NewLink->Prev = NULL;
		Head = NewLink;
	}

	length++;
}

template <class T>
void DoublyList<T>::InsertBack(T data) {

	link<T>* NewLink = new link<T>;
	NewLink->Data = data;

	if (IsEmpty()) {
		Head = Tail = NewLink;
		NewLink->Prev = NULL;
		NewLink->Next = NULL;
	}
	else {
		NewLink->Next = NULL;
		NewLink->Prev = Tail;
		Tail->Next = NewLink;
		Tail = NewLink;
	}

	length++;
}

template<class T>
void DoublyList<T>::Insert(int pos, T data) {
	if (pos < 0 || pos > length)
	{
		cout << "Out of range ...! Enter a position between 0 and " << length - 1 << "\n";
	}
	else {
		if (pos == 0) {
			InsertFront(data);
		}
		else if (pos == length - 1) {
			InsertBack(data);
		}
		else {
			link<T>* NewLink = new link<T>;
			link<T>* current = Head;
			NewLink->Data = data;
			for (int i = 0; i < pos - 1; i++) {
				current = current->Next;
			}
			NewLink->Next = current->Next;
			NewLink->Prev = current;
			current->Next->Prev = NewLink;
			current->Next = NewLink;

			length++;
		}


	}
}

template<class T>
void DoublyList<T>::PopFront() {
	if (IsEmpty()) {
		cout << "Empty list ... No elements to delete\n";
	}
	else if (Size() == 1) {
		delete Head;
		Head = Tail = NULL;
		length--;
	}
	else {
		link<T>* Temp = Head;
		Head = Head->Next;
		Head->Prev = NULL;
		delete Temp;
		length--;
	}

}

template<class T>
void DoublyList<T>::PopBack() {
	if (IsEmpty()) {
		cout << "Empty list ... No elements to delete\n";
	}
	else if (Size() == 1) {
		delete Head;
		Head = NULL;
		Tail = NULL;
		length--;
	}
	else {
		link<T>* Temp = Tail;
		Tail = Tail->Prev;
		Tail->Next = NULL;
		delete Temp;
		length--;
	}


}

template<class T>
void DoublyList<T>::EraseAt(int pos) {
	if (pos == 0) {
		PopFront();
	}
	else if (pos == Size() - 1) {
		PopBack();
	}
	else {
		if (pos < 0 || pos >= length) {
			cout << "Out of bounds...\n";
		}
		else {

			link<T>* Current = Head->Next;
			for (int i = 1; i < pos; i++) {
				Current = Current->Next;
			}

			Current->Next->Prev = Current->Prev;
			Current->Prev->Next = Current->Next;
			delete Current;
			length--;
		}

	}
}

template<class T>
void DoublyList<T>::Erase(T element) {

	link<T>* Current = Head;

	while (Current != NULL) {
		if (Current->Data == element) {
			break;
		}
		Current = Current->Next;
	}
	if (Current == NULL) {
		cout << "Element not found\n";
	}
	else {
		Current->Next->Prev = Current->Prev;
		Current->Prev->Next = Current->Next;
		delete Current;
		Current--;
	}
}


template<class T>
void DoublyList<T>::Display() {
	link<T>* Current = Head;
	while (Current != NULL) {
		cout << Current->Data << " ";
		Current = Current->Next;
	}
	cout << "\n";
}

template<class T>
T DoublyList<T>::GetElementAt(int pos) {
	link<T>* Current = Head;
	for (int i = 0; i < pos; i++) {
		Current = Current->Next;
	}
	return Current->Data;
}

template<class T>
int DoublyList<T>::search(T data) {
	link<T>* Current = Head;
	int loc = 0;
	while (Current != NULL) {
		if (Current->Data == data) {
			return loc;
		}
		Current = Current->Next;
		loc++;
	}
}

