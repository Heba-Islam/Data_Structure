#include "MaxHeap.h"
MaxHeap::MaxHeap(int Max) :maxSize(Max), Size(0)
{
	arr = new int[Max];
}

int MaxHeap::Parent(int idx)
{
	int p = (idx - 1) / 2;
	return p;
}

int MaxHeap::LeftChild(int idx)
{
	int lchild = (idx * 2 + 1);
	return lchild;
}

int MaxHeap::Rightchild(int idx)
{
	int rchild = (idx * 2 + 2);
	return rchild;
}

bool MaxHeap::IsEmpty()
{
	return !Size;
}

bool MaxHeap::IsFull()
{
	return Size == maxSize;
}

void MaxHeap::Heapify(int idx)
{
	int left = LeftChild(idx), right = Rightchild(idx), Max = idx;

	if (left < Size && arr[left] > arr[idx])
		Max = left;
	if (right < Size && arr[right] > arr[Max])
		Max = right;
	if (Max != idx) {
		swap(arr[idx], arr[Max]);
		Heapify(Max);
	}

}

void MaxHeap::Check(int idx)
{
	while (idx != 0 && arr[Parent(idx)] < arr[idx]) {
		swap(arr[idx], arr[Parent(idx)]);
		idx = Parent(idx);
	}
}

void MaxHeap::Insert(int element)
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

void MaxHeap::Delete(int idx)
{
	arr[idx] = INT_MAX;
	Check(idx);

	if (Size <= 1)
	{
		Size--;
		return;
	}

	arr[0] = arr[--Size];
	Heapify(0);

}

void MaxHeap::Display()
{
	for (int i = 0; i < Size; i++) {
		cout << arr[i] << " ";
	}
}

int MaxHeap::GetMax()
{
	return arr[0];
}