#pragma once
#include "Node.h"

using namespace std;

class Queue 
{
public:
	Node<int>* head;
	Node<int>* tail;
	int size;

	Queue() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	void add(int data)
	{
		Node<int>* newNode = new Node<int>();
		newNode->data = data;
		newNode->next = nullptr;
		newNode->prev = nullptr;

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
		size++;
	}

	void Print()
	{
		Node<int>* CurrentNode = head;
		while (CurrentNode)
		{
			cout << CurrentNode->data << endl;
			CurrentNode = CurrentNode->next;
		}
	}

	void RemoveFirst() {
		Node<int>* p = head;
		if (!p) {
			cout << "Queue is Empty!" << endl;
			return;
		}
		head = head->next;
		p->next = nullptr;
		delete p;
		//p->previous = nullptr;
	}
};