#pragma once
#include "IDatastructure.h"
#include <iostream>

using namespace std;

template <class T>
class Vector:IDatastructure {
private:
    T* Arr;
    int Capacity;
    int Size;
public:
    Vector() : Size(0), Capacity(1), Arr(new T[1])
    {}
    Vector(int size) :Size(size), Capacity(size), Arr(new T[size])
    {}
    ~Vector()
    {
        delete[] Arr;
    }
    bool IsFull();
    bool IsEmpty();
    void push(T Data);
    void push(T Data, int index);
    void pop();
    int  GetSize();
    void Display();
    T GetElement(int index);
    void Delete(int index);
    T& operator [](int index);
};

template <class T>
bool Vector<T>::IsFull() {
    return (Size == Capacity);
}

template <class T>
bool Vector<T>::IsEmpty() {
    return (!Size);
}

template <class T>
void Vector<T>::push(T Data) {
    if (IsFull()) {
        T* temp = new T[Capacity * 2];

        for (int i = 0; i < Capacity; i++) {
            temp[i] = Arr[i];
        }

        delete[] Arr;
        Capacity *= 2;
        Arr = temp;
    }

    Arr[Size] = Data;
    Size++;
}

template <class T>
void Vector<T>::push(T Data, int index) {
    if (index == Capacity) {
        push(Data);
    }
    else {
        Arr[index] = Data;
    }
}

template <class T>
void Vector<T>::pop() {
    if (IsEmpty()) {
        cout << "Vector is Empty . No elements to Delete\n";
    }
    else {
        Size--;
    }
}

template <class T>
int Vector<T>::GetSize() {
    return Size;
}

template <class T>
void Vector<T>::Display() {
    if (IsEmpty()) {
        cout << "Vector is Empty . No elements to display\n";
    }
    else {
        for (int i = 0; i < Size; i++) {
            cout << Arr[i] << " ";
        }
    }
}

template <class T>
T Vector<T>::GetElement(int index) {
    return  Arr[index];
}
template <class T>
void Vector<T>::Delete(int index) {
    if (index < Size) {
        for (int i = index; i < Size - 1; i++) {
            Arr[i] = Arr[i + 1];
        }
        Size--;
    }
    else {
        cout << "index entered is out of range .\n";
    }
}

template <class T>
T& Vector<T>:: operator[](int index) {
    return Arr[index];
}


