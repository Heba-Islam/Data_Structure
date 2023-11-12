#pragma once
#include <iostream>
#include "IDatastructure.h"
using namespace std;

template <class T>
class Queue : IDatastructure{
private:
	int front;
	int rear;
	int MAXSize;
	int length;
	T* arr;
public:
	Queue(int size);
	~Queue();
	void Push(T data);
	bool IsFull();
	bool IsEmpty();
	void Display();
	void Pop();
	T Front();
	T Back();
	int  Search(T data);
};

template<class T>
Queue<T>::Queue(int size) :MAXSize(size), length(0) {
	if (size <= 0)
		MAXSize = 100;
	else {

		front = 0;
		rear = MAXSize - 1;
		arr = new T[MAXSize];
	}
}

template<class T>
Queue<T>::~Queue() {
	delete[]arr;
}

template<class T>
bool Queue<T>::IsFull() {
	return length == MAXSize;
}

template<class T>
bool Queue<T>::IsEmpty() {
	return !length;
}

template<class T>
void Queue<T>::Push(T data) {
	if (IsFull()) {
		cout << "Queue is full , can't enqueue..!\n";
	}
	else {
		rear = (rear + 1) % MAXSize;
		arr[rear] = data;
		length++;
	}
}

template<class T>
void Queue<T>::Pop() {
	if (!IsEmpty()) {
		front = (front + 1) % MAXSize;
		length--;
	}
	else
		cout << "Empty Queue...No elements to pop\n";
}

template<class T>
T Queue<T>::Front() {
	return arr[front];
}

template<class T>
T Queue<T>::Back() {
	return arr[rear];
}

template<class T>
void Queue<T>::Display() {
	if (!IsEmpty()) {
		for (int i = front; i != rear; i = ((i + 1) % MAXSize)) {
			cout << arr[i] << " ";
		}
		cout << arr[rear] << endl;
	}
	else
		cout << "Empty Queue .. No elements to display\n";
}

template<class T>
int Queue<T>::Search(T data) {
	int idx = -1;
	for (int i = front; i != rear; i++) {
		if (arr[i] == data) {
			idx = i;
			break;
		}
	}
	if (arr[rear] == data) {
		idx = rear;
	}
	return idx;
}

