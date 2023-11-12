#pragma once
#include "IDatastructure.h"

#include<iostream>

using namespace std;

template<class T>
struct node {
	T Data;
	node* left;
	node* right;
};

template<class T>
class BStree:IDatastructure {

private:
	node<T>* Root;
	int NodesCount;
	void InOrder(node<T>* root);
	void PreOrder(node<T>* root);
	void PostOrder(node<T>* root);

public:
	BStree();
	bool IsEmpty();
	T GetRoot();
	int Size();
	void Insert(T data);
	bool Search(T data);
	void InTraverse();
	void PreTraverse();
	void PostTraverse();
	void Delete(T Data);
	void Display();
};

template<class T>
BStree<T>::BStree() :Root(NULL), NodesCount(0)
{}

template<class T>
bool BStree<T>::IsEmpty()
{
	return (!NodesCount);
}

template<class T>
int BStree<T>::Size()
{
	return NodesCount;
}

template<class T>
T BStree<T>::GetRoot()
{
	return Root->Data;
}


template<class T>
bool BStree<T>::Search(T data)
{
	node<T>* current = Root;

	while (current != NULL)
	{
		if (current->Data == data)
			return 1;
		else if (current->Data > data)
			current = current->left;
		else
			current = current->right;
	}
	return 0;
}

template<class T>
void BStree<T>::Insert(T data)
{
	node<T>* NewNode = new node<T>;
	NewNode->Data = data;
	NewNode->left = NewNode->right = NULL;
	if (IsEmpty())
	{
		Root = NewNode;
	}
	else
	{
		node<T>* Current = Root;
		node<T>* Prev = Root;

		while (Current != NULL) {

			Prev = Current;

			if (Current->Data == data)
			{
				cout << data << " already exists\n";
				return;
			}
			else
			{
				if (Current->Data > data)
				{
					Current = Current->left;
				}
				else
				{
					Current = Current->right;
				}
			}
		}
		if (Prev != NULL) {

			if (Prev->Data > data)
				Prev->left = NewNode;
			else
				Prev->right = NewNode;
		}

	}
	NodesCount++;
}



template<class T>
void BStree<T>::InOrder(node<T>* root) {
	if (root != NULL)
	{
		InOrder(root->left);
		cout << root->Data << " ";
		InOrder(root->right);
	}
	return;
}

template<class T>
void BStree<T>::PreOrder(node<T>* root) {
	if (root != NULL)
	{
		cout << root->Data << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

template<class T>
void BStree<T>::PostOrder(node<T>* root) {
	if (root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->Data << " ";
	}
}

template<class T>
void BStree<T>::InTraverse()
{
	InOrder(Root);
}

template<class T>
void BStree<T>::PreTraverse()
{
	PreOrder(Root);
}

template<class T>
void BStree<T>::PostTraverse()
{
	PostOrder(Root);
}


template<class T>
void BStree<T>::Delete(T data)
{
	if (IsEmpty())
	{
		cout << "can't delete from an empty tree..\n";
		return;
	}
	//locate the data
	node<T>* current = Root;
	node<T>* prev = NULL;

	if (data == Root->Data)
	{
		node<T>* NewCurrent = Root->right;
		node<T>* prev = Root;
		while (NewCurrent->left != NULL && NewCurrent != NULL)
		{
			prev = NewCurrent;
			NewCurrent = NewCurrent->left;
		}
		prev->left = NULL;
		NewCurrent->right = Root->right;
		NewCurrent->left = Root->left;
		Root = NewCurrent;
		NodesCount--;
	}
	else
	{
		while (current != NULL)
		{
			if (current->Data == data)
				break;

			prev = current;

			if (data < current->Data)
				current = current->left;
			else
				current = current->right;
		}

		if (current == NULL)
		{
			cout << data << " not found..\n";
			return;
		}

		if (current->left == NULL && current->right == NULL)
		{
			delete current;
			if (data < prev->Data)
				prev->left = NULL;
			else
				prev->right = NULL;

			NodesCount--;
		}
		else if (current->left == NULL)
		{
			if (current->Data < prev->Data)
				prev->left = current->right;
			else
				prev->right = current->right;

			delete current;
			NodesCount--;
		}
		else if (current->right == NULL)
		{
			if (current->Data < prev->Data)
				prev->left = current->left;
			else
				prev->right = current->left;

			delete current;
			NodesCount--;
		}
		else
		{
			node<T>* NewCurrent = current->right;
			node<T>* NewPrev = NULL;

			while (NewCurrent->left != NULL && NewCurrent != NULL)
			{
				NewPrev = NewCurrent;
				NewCurrent = NewCurrent->left;
			}

			NewPrev->left = NULL;
			NewCurrent->right = current->right;
			NewCurrent->left = current->left;
			if (data < prev->Data)
				prev->left = NewCurrent;
			else
				prev->right = NewCurrent;

			delete current;
			NodesCount--;
		}

	}
}

template<class T>
void BStree<T>::Display()
{
	InTraverse();
}


