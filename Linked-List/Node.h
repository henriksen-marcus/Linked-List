#pragma once

// Data container for use as an element inside a double linked list. 
template<class T>
class Node 
{
public:
	T data;
	Node* next;
	Node* prev;

	Node()
	{
		next = nullptr;
		prev = nullptr;
		data = NULL;
	}
};

