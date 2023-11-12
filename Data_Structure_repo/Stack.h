#pragma once
#include "IDatastructure.h"
#include <iostream>

template<class T>
struct link {
	T Data;
	link* Next;
};

template<class T>
class Stack:IDatastructure {
private:
	int length;
	link<T>* top;
public:
	Stack();
	~Stack();
	bool IsEmpty();
	int Size();
	void Push(T data);
	void Pop();
	T Top();
	void Display();
};

template<class T>
Stack<T>::Stack() :length(0), top(nullptr) {}

template<class T>
Stack<T>::~Stack() {}

template<class T>
bool Stack<T>::IsEmpty() {
	return !length;
}

template<class T>
int Stack<T>::Size() {
	return length;
}

template<class T>
void Stack<T>::Push(T data) {
	link<T>* temp = new link<T>;

	temp->Data = data;
	temp->Next = top;
	top = temp;

	length++;
}

template<class T>
void Stack<T>::Pop() {
	if (IsEmpty()) {
		cout << "Stack is Empty...\n";
	}
	else {
		link<T>* temp = top;
		top = top->Next;
		temp->Next = nullptr;
		delete temp;
		length--;
	}
}

template<class T>
T Stack<T>::Top() {
	return top->Data;
}

template<class T>
void Stack<T>::Display() {
	link<T>* current = top;
	while (current != nullptr) {
		cout << current->Data << " ";
		current = current->Next;
	}
	cout << "\n";
}