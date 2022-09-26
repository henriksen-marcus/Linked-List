#pragma once

using namespace std;
#include <iostream>
#include "QuadNode.h"

class QLL_Base
{
public:
	enum direction { left, up, right, down };
};

template<class T>
class QLL : QLL_Base 
{
public:
	QLL(T data);
	~QLL();
	/// <summary>
	/// Adds a new node in the specified direction
	/// </summary>
	/// <param name="data">What the node should contain</param>
	/// <param name="dir">In  what direction to add the node</param>
	/// <param name="overwrite">If we should replace an existing node 
	/// in the specified direction, if it exists</param>
	/// <returns>The new list size</returns>
	int Add(T data, QLL_Base::direction dir, bool overwrite = false);


	void Print();



	QLL_Base::direction RevDir(QLL_Base::direction dir);

	QuadNode<T>* head;
	QuadNode<T>* cursor;

private:
	int size;
};

template<class T>
QLL<T>::QLL(T data)
{
	size = 0;
	head = new QuadNode<T>();
	head->data = data; 
	cursor = head;
}

template<class T>
QLL<T>::~QLL()
{
	// Delete everything fro memory
	if (!head) return;

}

template<class T>
int QLL<T>::Add(T data, QLL_Base::direction dir, bool overwrite)
{
	if (size >= 3)
	{
		int connections{};
		for (int i = 0; i < 4; i++)
		{
			if (cursor->ptr[i]) connections++;
		}
		if (connections < 2)
		{
			cout << "Error: Node cannot print, too far out. Prev node amount: "  << connections << " val: " << cursor->data << endl;
			return size;
		}
	}

	if (cursor->ptr[dir] == nullptr)
	{
		auto* newNode = new QuadNode<T>();

		cursor->ptr[dir] = newNode;
		newNode->data = data;
		newNode->ptr[RevDir(dir)] = cursor;
		cursor = newNode;
		size++;
	}
	else if (overwrite)
	{
		cursor->ptr[dir]->data = data;
	}
	return size;
}

template<class T>
void QLL<T>::Print()
{
	QuadNode<T>* CurrentNode;
	int i{};


		cout << head->data;
		CurrentNode = head->ptr[left];

		while (CurrentNode)
		{
			cout << CurrentNode->data << " ";

			auto* CRNode = CurrentNode->ptr[up];
			while (CRNode)
			{
				cout << CRNode->data;
				CRNode = CRNode->ptr[up];
			}

			CRNode = CurrentNode->ptr[down];
			while (CRNode)
			{
				cout << CRNode->data;
				CRNode = CRNode->ptr[down];
			}

			CurrentNode = CurrentNode->ptr[left];
		}

		CurrentNode = head->ptr[up];
		while (CurrentNode)
		{
			cout << CurrentNode->data;
			CurrentNode = CurrentNode->ptr[up];
		}

		CurrentNode = head->ptr[right];
		while (CurrentNode)
		{
			cout << CurrentNode->data << " ";

			auto* CRNode = CurrentNode->ptr[up];
			while (CRNode)
			{
				cout << CRNode->data;
				CRNode = CRNode->ptr[up];
			}

			CRNode = CurrentNode->ptr[down];
			while (CRNode)
			{
				cout << CRNode->data;
				CRNode = CRNode->ptr[down];
			}

			CurrentNode = CurrentNode->ptr[right];
		}

		CurrentNode = head->ptr[down];
		while (CurrentNode)
		{
			cout << CurrentNode->data;
			CurrentNode = CurrentNode->ptr[down];
		}

}

template<class T>
QLL_Base::direction QLL<T>::RevDir(QLL_Base::direction dir)
{
	switch (dir)
	{
	case QLL_Base::left:
		return right;
		break;
	case QLL_Base::up:
		return down;
		break;
	case QLL_Base::right:
		return left;
		break;
	case QLL_Base::down:
		return up; 
		break;
	default:
		break;
	}
}