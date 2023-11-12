#pragma once
#include "IDatastructure.h"

#include <iostream>

using namespace std;

template<class T>
struct link {
	T Data;
	link* Next;
};

template<class T>
class LinkQueue {
private:
	link<T>* front;
	link<T>* rear;
	int length;
public:
	LinkQueue();
	~LinkQueue();
	bool IsEmpty();
	int Size();
	void Push(T data);
	void Pop();
	T Front();
	T Back();
	void Display();
	int Search(T data);
};

template<class T>
LinkQueue<T>::LinkQueue() : length(0), front(NULL), rear(NULL)
{}

template<class T>
LinkQueue<T>::~LinkQueue() {
	link<T>* current = front;
	while (current != NULL) {
		current = front;
		front = front->Next;
		delete front;
	}
}

template<class T>
bool LinkQueue<T>::IsEmpty() {
	return !length;
}

template<class T>
int LinkQueue<T>::Size() {
	return length;
}

template<class T>
void LinkQueue<T>::Push(T data) {
	link<T>* NewLink = new link<T>;
	NewLink->Data = data;

	if (!IsEmpty()) {
		NewLink->Next = NULL;
		rear->Next = NewLink;
		rear = NewLink;
	}
	else {
		front = rear = NewLink;
		NewLink->Next = NULL;
	}

	length++;
}

template<class T>
void LinkQueue<T>::Pop() {
	if (IsEmpty()) {
		cout << "Empty Queue...\n";
	}
	else {
		if (length > 1) {

			link<T>* current = front;
			front = front->Next;
			delete current;
		}
		else {
			delete front;
			front = rear = NULL;
		}
		length--;
	}
}

template<class T>
T LinkQueue<T>::Front() {
	if (!IsEmpty())
	{
		return front->Data;
	}
	else {
		cout << "Empty Queue..\n";
	}
}

template<class T>
T LinkQueue<T>::Back() {
	if (!IsEmpty())
	{
		return rear->Data;
	}
	else {
		cout << "Empty Queue..\n";
	}
}

template<class T>
void LinkQueue<T>::Display() {
	link<T>* current = front;
	while (current != NULL) {
		cout << current->Data << " ";
		current = current->Next;
	}
	cout << endl;
}

template<class T>
int LinkQueue<T>::Search(T data) {
	int pos = -1;
	link<T>* current = front;
	bool found = 0;
	while (current != NULL) {
		pos++;
		if (current->Data == data) {
			found = 1;
			return pos;
		}
		current = current->Next;
	}
	if (!found) {
		return -1;
	}
}

