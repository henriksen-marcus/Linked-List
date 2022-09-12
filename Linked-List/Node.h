#pragma once

template<class T>
class Node 
{
public:
	Node();
	T data;
	Node* next;
	Node* prev;
};

template<class T>
Node<T>::Node()
{
	next = nullptr;
	prev = nullptr;
	data = NULL;
}

