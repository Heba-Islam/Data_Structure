#pragma once
#include "IDatastructure.h"
#include <iostream>

using namespace std;

template<class T>
struct Link {
	T Data;
	Link* Next;
};

template<class T>
class LinkedList : IDatastructure{
private:
	Link<T>* Head;
	Link<T>* Tail;
	int length;
public:
	LinkedList() {
		Head = NULL;
		Tail = NULL;
		length = 0;
	}

	int GetSize();
	bool IsEmpty();
	void InsertFront(T element);
	void InsertBack(T data);
	void Display();
	void Insert(int pos, T data);
	void PopFront();
	void PopBack();
	void Erase(T data);
	void EraseAt(int pos);
	void Reverse();
	int  Search(T data);
	T GetElementAt(int location);
};


template <class T>
int LinkedList<T>::GetSize() {
	return length;
}

template <class T>
bool LinkedList<T>::IsEmpty() {
	return length == 0;
}

template<class T>
void LinkedList<T>::InsertFront(T element) {
	Link<T>* NewLink = new Link<T>;
	NewLink->Data = element;
	if (length == 0) {
		Head = Tail = NewLink;
		NewLink->Next = NULL;
	}
	else {
		NewLink->Next = Head;
		Head = NewLink;
	}
	length++;
}

template <class T>
void LinkedList<T>::InsertBack(T data) {
	Link<T>* NewLink = new Link<T>;
	NewLink->Data = data;
	if (length == 0) {
		Head = Tail = NewLink;
		NewLink->Next = NULL;
	}
	else {
		Tail->Next = NewLink;
		NewLink->Next = NULL;
		Tail = NewLink;
	}
	length++;
}


template <class T>
void LinkedList<T>::Insert(int pos, T data) {
	if (pos < 0 || pos > length)
	{
		cout << "Out of range ...! Enter a pos between 0 and " << length - 1 << "\n";
	}
	else {
		if (!pos) {
			InsertFront(data);
		}
		else if (pos == length - 1) {
			InsertBack(data);
		}
		else {
			Link<T>* cur = Head;
			for (int i = 0; i < pos - 1; i++) {
				cur = cur->Next;
			}
			Link<T>* NewLink = new Link<T>;
			NewLink->Next = cur->Next;
			NewLink->Data = data;
			cur->Next = NewLink;

			length++;
		}
	}
}

template<class T>
void LinkedList<T>::Display() {
	Link<T>* Current = Head;
	while (Current != NULL) {
		cout << Current->Data << " ";
		Current = Current->Next;
	}
}

template<class T>
void LinkedList<T>::PopFront() {
	if (!IsEmpty()) {
		Link<T>* cur = Head;
		Head = Head->Next;
		delete cur;
		length--;
	}
	else {
		cout << "List is Empty .. \n";
	}

}


template <class T>
void LinkedList<T>::PopBack() {
	if (!IsEmpty()) {

		Link<T>* Current = Head->Next;
		Link<T>* Prev = Head;

		while (Current != Tail) {
			Prev = Current;
			Current = Current->Next;
		}

		delete Current;
		Prev->Next = NULL;
		Tail = Prev;
		length--;
	}
	else {
		cout << "Empty List!...\n";
	}
}

template <class T>
void LinkedList<T>::Erase(T data) {
	if (data == Head->Data) {
		PopFront();
	}
	else if (data == Tail->Data) {
		PopBack();
	}
	else {

		Link<T>* Current = Head->Next;
		Link<T>* Prev = Head;

		while (Current != NULL) {
			if (Current->Data == data) {
				break;
			}
			Prev = Current;
			Current = Current->Next;
		}
		if (Current == NULL) {
			cout << "Data not found\n";
		}
		else {
			Prev->Next = Current->Next;
			delete Current;
			length--;
		}
	}

}

template <class T>
void LinkedList<T>::EraseAt(int pos) {
	if (pos < 2) {
		PopFront();
	}
	else if (pos == length) {
		PopBack();
	}
	else {
		if (pos<0 && pos>length) {
			cout << "Out of range... Enter a position from 1 to " << length << "\n";
		}
		else {
			Link<T>* Current = Head->Next;
			Link<T>* Prev = Head;
			for (int i = 1; i < pos; i++) {
				Prev = Current;
				Current = Current->Next;
			}
			Prev->Next = Current->Next;
			delete Current;
			length--;
		}
	}
}

template<class T>
void LinkedList<T>::Reverse() {
	Link<T>* Current = Head;
	Link<T>* Prev = NULL;
	Link<T>* next = Head->Next;
	while (next != NULL) {
		next = Current->Next;
		Current->Next = Prev;
		Prev = Current;
		Current = next;
	}
	Head = Prev;
}

template<class T>
int LinkedList<T>::Search(T data) {
	Link<T>* NewLink = Head;
	int location = 0;
	while (NewLink != NULL) {
		if (NewLink->Data == data) {
			return location;
		}
		location++;
		NewLink = NewLink->Next;
	}
	return -1;
}

template<class T>
T LinkedList<T>::GetElementAt(int location) {

	Link<T>* NewLink = Head;
	for (int i = 0; i < location; i++) {
		NewLink = NewLink->Next;
	}
	return NewLink->Data;

}
