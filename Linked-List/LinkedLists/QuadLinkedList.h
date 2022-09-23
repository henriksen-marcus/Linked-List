#pragma once

using namespace std;
#include <iostream>
#include "QuadNode.h"

class QLL_Base
{
public:
	enum direction { forward, backwards, Upwards, Downwards };
};

template<class T>
class QLL : QLL_Base 
{
public:
	QLL();
	~QLL();

	int Add(T data);
	void Print(const direction dir);

	QuadNode<T>* head;
	QuadNode<T>* tail;

private:
	int size;
};

template<class T>
QLL<T>::QLL()
{
	size = 0;
	head = nullptr;
	tail = head;
}

template<class T>
QLL<T>::~QLL()
{
	// Delete everything fro memory
}

template<class T>
int QLL<T>::Add(T data)
{
	if (!data) return size;

	QuadNode<T>* newNode = new QuadNode<T>();
	newNode->data = data;

	// First element in list
	if (!head)
	{
		head = newNode;
		tail = newNode;
		return ++size;
	}
	if (tail)
	{
		tail->right = newNode;
		newNode->left = tail;
	}
	tail = newNode;


	//newNode->first = tail;

	// Decide if we should link back to element[i-3]
	//if (size && size % 0 == 0)
	//{
	//	// Create a square
	//	//newNode->second = tail->first->first;
	//}

	/*if (tail)
	{
		tail->next = newNode;
	}
	tail = newNode;*/
	return ++size;
}

template<class T>
void QLL<T>::Print(const direction dir)
{
	QuadNode<T>* CurrentNode;
	int i{};

	switch (dir)
	{
	case forward:
		CurrentNode = head;
		while (CurrentNode)
		{
			if (i++ >= size) return;
			cout << CurrentNode->data << " ";
			CurrentNode = CurrentNode->right;
		}
		break;
	case backwards:
		CurrentNode = tail;
		while (CurrentNode)
		{
			if (i++ >= size) return;
			cout << CurrentNode->data << " ";
			CurrentNode = CurrentNode->left;
		}
		break;
	case Upwards:
		CurrentNode = tail;
		while (CurrentNode)
		{
			if (i++ >= size) return;
			cout << CurrentNode->data << " ";
			CurrentNode = CurrentNode->top;
		}

		break;
	case Downwards:
		CurrentNode = tail;
		while (CurrentNode)
		{
			if (i++ >= size) return;
			cout << CurrentNode->data << " ";
			CurrentNode = CurrentNode->bottom;
		}
		break;

	}
	
	
}
