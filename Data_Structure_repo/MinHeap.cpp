#include "MinHeap.h"

MinHeap::MinHeap(int Max) :maxSize(Max), Size(0)
{
	arr = new int[Max];
}

int MinHeap::Parent(int idx)
{
	int p = (idx - 1) / 2;
	return p;
}

int MinHeap::LeftChild(int idx)
{
	int lchild = (idx * 2 + 1);
	return lchild;
}

int MinHeap::Rightchild(int idx)
{
	int rchild = (idx * 2 + 2);
	return rchild;
}

bool MinHeap::IsEmpty()
{
	return !Size;
}

bool MinHeap::IsFull()
{
	return Size == maxSize;
}

void MinHeap::Heapify(int idx)
{
	int left = LeftChild(idx), right = Rightchild(idx), Mini = idx;

	if (left < Size && arr[left] < arr[idx])
		Mini = left;
	if (right < Size && arr[right] < arr[Mini])
		Mini = right;
	if (Mini != idx) {
		swap(arr[idx], arr[Mini]);
		Heapify(Mini);
	}

}

void MinHeap::Check(int idx)
{
	while (idx != 0 && arr[Parent(idx)] > arr[idx]) {
		swap(arr[idx], arr[Parent(idx)]);
		idx = Parent(idx);
	}
}

void MinHeap::Insert(int element)
{
	if (IsEmpty())
	{
		arr[0] = element;
		Size++;
		return;
	}
	if (IsFull())
	{
		cout << "Heap is full : could not insert..\n";
		return;
	}

	arr[Size] = element;
	Check(Size);
	Size++;

}

void MinHeap::Delete(int idx)
{
	arr[idx] = INT_MIN;
	Check(idx);

	if (Size <= 1)
	{
		Size--;
		return;
	}

	arr[0] = arr[--Size];
	Heapify(0);

}

void MinHeap::Display()
{
	for (int i = 0; i < Size; i++) {
		cout << arr[i] << " ";
	}
}

int MinHeap::GetMin()
{
	return arr[0];
}
