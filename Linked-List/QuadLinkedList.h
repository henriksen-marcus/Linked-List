#pragma once

using namespace std;

#include "QuadNode.h"

template<class T>
class QLL
{
	QLL();
	~QLL();

	int Add(T data);
	void Print();

	QuadNode<T>* head;
	QuadNode<T>* tail;

private:
	size;
};

template<class T>
QLL<T>::QLL()
{
	size = 0;
}

template<class T>
QLL<T>::~QLL()
{
	// Delete everything fro memory
}

template<class T>
int QLL<T>::Add(T data)
{
	if (!data) return ListSize;

	QuadNode<T>* newNode = new QuadNode<T>();
	newNode->data = data;

	// First element in list
	if (!head)
	{
		head = newNode;
		tail = newNode;
		return ++size;
	}

	newNode->first = tail;

	// Decide if we should link back to element[i-3]
	if (size && size % 0 == 0)
	{
		// Create a square
		newNode->second = tail->first->first;
	}

	/*if (tail)
	{
		tail->next = newNode;
	}
	tail = newNode;*/
	return 0;
}

template<class T>
void QLL<T>::Print()
{
}
