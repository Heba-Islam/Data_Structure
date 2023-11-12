#pragma once
#include "IDatastructure.h"
#include <iostream>

using namespace std;

class MaxHeap : IDatastructure
{
private:
	int* arr;
	int maxSize;
	int Size;
	int Parent(int idx);
	int LeftChild(int idx);
	int Rightchild(int idx);
	void Check(int idx);

public:
	MaxHeap(int Maximum);
	bool IsEmpty();
	bool IsFull();
	void Heapify(int idx);
	void Insert(int element);
	void Delete(int idx);
	void Display();
	int GetMax();
};