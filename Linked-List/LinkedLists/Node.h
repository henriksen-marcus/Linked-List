#pragma once

/**
 * \brief Data container for use as an element inside a double linked list.
 * \tparam T The datatype to store.
 * \remark Strings will not work here.
 */
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

