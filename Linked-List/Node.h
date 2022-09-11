#pragma once

template<class T>
class Node 
{
public:
	Node();
	T data;
	Node* next;
};

template<class T>
Node<T>::Node()
{
	next = nullptr;
}
