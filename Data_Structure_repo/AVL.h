#pragma once
#include "IDatastructure.h"

#include <iostream>

using namespace std;

template<class T>
struct node {
	T Data;
	node* right;
	node* left;
	int Height;
};

template<class T>
class AVL:IDatastructure {
private:
	node<T>* Root;
	int height(node<T>* Node);
	int BalanceFactor(node<T>* Node);
	void InOrder(node<T>* root);
	void PreOrder(node<T>* root);
	void PostOrder(node<T>* root);
	node<T>* InsertNode(node<T>* Node, T data);
	node<T>* RightRotate(node<T>* Node);
	node<T>* LeftRotate(node<T>* Node);
	node<T>* DeleteNode(node<T>* Node, T data);
public:
	AVL();
	bool IsEmpty();
	void Insert(T data);
	T GetRoot();
	void InTraverse();
	void PreTraverse();
	void PostTraverse();
	void Delete(T data);
	void Display();
};

template<class T>
AVL<T>::AVL()
{
	Root = NULL;
}

template<class T>
bool AVL<T>::IsEmpty()
{
	return Root == NULL;
}

template<class T>
int AVL<T>::height(node<T>* Node) {
	if (Node != NULL)
		return Node->Height;
	else
		return 0;
}

template<class T>
int AVL<T>::BalanceFactor(node<T>* Node) {
	if (Node == NULL)
		return 0;
	else
		return (height(Node->left) - height(Node->right));
}

template<class T>
T AVL<T>::GetRoot()
{
	if (Root != NULL)
		return Root->Data;
	else
		cout << "Tree is Empty..\n";
	return(-1);

}

template<class T>
void AVL<T>::InOrder(node<T>* root) {
	if (root != NULL)
	{
		InOrder(root->left);
		cout << root->Data << " ";
		InOrder(root->right);
	}
	return;
}

template<class T>
void AVL<T>::PreOrder(node<T>* root) {
	if (root != NULL)
	{
		cout << root->Data << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

template<class T>
void AVL<T>::PostOrder(node<T>* root) {
	if (root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->Data << " ";
	}
}

template<class T>
void AVL<T>::InTraverse()
{
	InOrder(Root);
}

template<class T>
void AVL<T>::PreTraverse()
{
	PreOrder(Root);
}

template<class T>
void AVL<T>::PostTraverse()
{
	PostOrder(Root);
}

template<class T>
node<T>* AVL<T>::RightRotate(node<T>* Node)
{
	node<T>* x = Node->left;
	node<T>* T2 = x->right;

	x->right = Node;
	Node->left = T2;

	Node->Height = max(height(Node->left), height(Node->right) + 1);
	x->Height = max(height(x->left), height(x->right) + 1);

	return x;
}

template<class T>
node<T>* AVL<T>::LeftRotate(node<T>* Node)
{
	node<T>* x = Node->right;
	node<T>* T2 = x->left;

	x->left = Node;
	Node->right = T2;

	Node->Height = max(height(Node->left), height(Node->right) + 1);
	x->Height = max(height(x->left), height(x->right) + 1);

	return x;
}

template<class T>
node<T>* AVL<T>::InsertNode(node<T>* Node, T data)
{
	node<T>* NewNode = new node<T>;
	NewNode->Data = data;
	NewNode->left = NewNode->right = NULL;
	NewNode->Height = 1;

	if (Node == NULL)
		return NewNode;

	if (data < Node->Data)
		Node->left = InsertNode(Node->left, data);
	else if (data > Node->Data)
		Node->right = InsertNode(Node->right, data);
	else
	{
		cout << "this value already exists..\n";
		return Node;
	}

	Node->Height = 1 + max(height(Node->left), height(Node->right));

	if (BalanceFactor(Node) > 1 && data < Node->left->Data)
		return RightRotate(Node);

	if (BalanceFactor(Node) < -1 && data > Node->right->Data)
		return LeftRotate(Node);

	if (BalanceFactor(Node) > 1 && data < Node->left->Data)
	{
		Node->left = LeftRotate(Node->left);
		return RightRotate(Node);
	}

	if (BalanceFactor(Node) < -1 && data < Node->right->Data)
	{
		Node->right = RightRotate(Node->right);
		return LeftRotate(Node);
	}

	return Node;
}

template<class T>
void AVL<T>::Insert(T data)
{
	Root = InsertNode(Root, data);
}

template<class T>
node<T>* AVL<T>::DeleteNode(node<T>* Node, T data) {
	if (Node == NULL)
		return Node;

	if (data < Node->Data)
		Node->left = DeleteNode(Node->left, data);
	else if (data > Node->Data)
		Node->right = DeleteNode(Node->right, data);
	else {
		if (Node->left == NULL) {
			node<T>* temp = Node->right;
			delete Node;
			return temp;
		}
		else if (Node->right == NULL) {
			node<T>* temp = Node->left;
			delete Node;
			return temp;
		}
		else {
			node<T>* temp = Node->right;
			while (temp->left != NULL) {
				temp = temp->left;
			}
			Node->Data = temp->Data;
			Node->right = DeleteNode(Node->right, temp->Data);
		}
	}

	if (Node == NULL)
		return Node;

	Node->Height = 1 + max(height(Node->left), height(Node->right));

	if (BalanceFactor(Node) > 1 && BalanceFactor(Node->left) >= 0)
		return RightRotate(Node);

	if (BalanceFactor(Node) > 1 && BalanceFactor(Node->left) < 0) {
		Node->left = LeftRotate(Node->left);
		return RightRotate(Node);
	}

	if (BalanceFactor(Node) < -1 && BalanceFactor(Node->right) <= 0)
		return LeftRotate(Node);

	if (BalanceFactor(Node) < -1 && BalanceFactor(Node->right) > 0) {
		Node->right = RightRotate(Node->right);
		return LeftRotate(Node);
	}

	return Node;
}

template<class T>
void AVL<T>::Delete(T data)
{
	Root = DeleteNode(Root, data);
}

template<class T>
void AVL<T>::Display()
{
	InTraverse();
}





