#pragma once
#include <iostream>
#include "Node.h"

// References:
// https://github.com/Taheri-meisam/SingleLinkedList_ex/blob/master/SingleLinkedList_ex/SingleLinkedList_ex.cpp

using namespace std;

template<class T>
class SLL
{
public:
	SLL();

	//int Size();
	int Add(T data);
	void Print();

	Node<T>* head;
	Node<T>* tail;

private:
	int size;
};

template<class T>
SLL<T>::SLL()
{
	size = 0;
	head = tail;
}

//template<class T>
//SLL<T>::~SLL()
//{
//	return 0;
//}

//template<class T>
//int SLL<T>::Size()
//{
//	return 0;
//}

template<class T>
int SLL<T>::Add(T data)
{
	if (!data) return ListSize;

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
	}
	tail = newNode;

	// Head can also store data, put it 
	// there if the list is empty.
	/*if (!head->data)
	{
		head->data = data;
		return ++ListSize;
	}
	else if (!tail->data)
	{
		tail->data = data;
		return ++ListSize;
	}*/

	

	//if (FirstTimeAdd)
	//{
	//	FirstTimeAdd = false;
	//	// Insert in middle
	//	head->next = newNode;
	//	tail = newNode;
	//}
	//else 
	//{
		/*tail->next = newNode;
		tail = newNode;*/
	//}
	
	return ++ListSize;
}

template<class T>
void SLL<T>::Print()
{
	Node<T>* CurrentNode = head;
	while (CurrentNode)
	{
		cout << CurrentNode->data << endl;
		CurrentNode = CurrentNode->next;
	}
}