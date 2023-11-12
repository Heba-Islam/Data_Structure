#pragma once
#include<iostream>
#include "IDatastructure.h"
using namespace std;

struct Node {
	int element;
	Node* next;
};

class HashTable :IDatastructure {
private:
	Node* arr[10];
	int Count;
public:
	HashTable();
	void Insert(int number);
	bool IsEmpty();
	bool Search(int number);
	int Size();
	void Delete(int number);
	void Display();
};






