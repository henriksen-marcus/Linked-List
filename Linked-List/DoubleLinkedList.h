#pragma once
#include <iostream>
#include "Node.h"

// References:
// https://github.com/Taheri-meisam/SingleLinkedList_ex/blob/master/SingleLinkedList_ex/SingleLinkedList_ex.cpp

using namespace std;

template<class T>
class DLL
{
public:
	DLL();
	~DLL();

	int Size();
	int Add(T data);
	int Remove(int index);
	int Insert(T data, int index);
	int Insert(Node<T>* node, int index);
	void Print();

	Node<T>* head;
	Node<T>* tail;

private:
	int size;
};

template<class T>
DLL<T>::DLL()
{
	size = 0;
	head = tail;
}

template<class T>
DLL<T>::~DLL()
{
	return;
}

//template<class T>
//int DLL<T>::Size()
//{
//	return 0;
//}

template<class T>
int DLL<T>::Add(T data)
{
	if (!data) return size;

	Node<T>* newNode = new Node<T>;
	newNode->data = data;
	newNode->next = nullptr;

	if (!head)
	{
		head = newNode;
	}
	if (tail)
	{
		tail->next = newNode;
		newNode->prev = tail;
	}
	tail = newNode;
	
	return ++size;
}

template<class T>
int DLL<T>::Remove(int index)
{
	Node<T>* CurrentNode = head;

	for (int i{}; i < index; i++)
	{
		CurrentNode = CurrentNode->next;
	}

	CurrentNode->prev->next = CurrentNode->next;
	CurrentNode->next->prev = CurrentNode->prev;

	delete CurrentNode;
	return --size;
}

template<class T>
int DLL<T>::Insert(T data, int index)
{
	Node<T>* CurrentNode = head;

	for (int i{}; i < index; i++)
	{
		CurrentNode = CurrentNode->next;
	}

	Node<T>* NewNode = new Node<T>();

	NewNode->data = data;
	NewNode->prev = CurrentNode->prev;
	NewNode->next = CurrentNode;

	CurrentNode->prev = NewNode;
	
	return ++size;
}

template<class T>
int DLL<T>::Insert(Node<T>* node, int index)
{
	cout << "We got em bois!" << endl;

	Node<T>* CurrentNode = head;

	for (int i{}; i < index; i++)
	{
		CurrentNode = CurrentNode->next;
	}

	node->prev = CurrentNode->prev;
	node->next = CurrentNode;

	CurrentNode->prev = node;
	return ++size;
}

template<class T>
void DLL<T>::Print()
{
	/*Node<T>* CurrentNode = head;
	while (CurrentNode)
	{
		cout << CurrentNode->data << endl;
		CurrentNode = CurrentNode->next;
	}*/

	Node<T>* CurrentNode = tail;

	while (CurrentNode)
	{
		cout << CurrentNode->data << endl;
		CurrentNode = CurrentNode->prev;
	}
}