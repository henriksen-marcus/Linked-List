#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class DLL_Base
{
public:
	enum direction { forward, backwards };
};

/* Double linked list that works like an array.
 * Able to traverse back and fourth.
 */
template<class T>
class DLL : DLL_Base
{
public:
	DLL();
	// Iteratively delete all elements in the linked list.
	~DLL();

	int size() const;

	/**
	 * \param i The index to return.
	 * \return Pointer to the node at the index.
	 */
	Node<T>* At(int &i);
	
	/**
	 * \brief Adds the specified element to the end of the list.
	 * \return The new list size.
	 */
	int add(T data);
	
	/**
	 * \brief Adds the array of elements to the end of the list.
	 * \param size The size of the incoming array.
	 * \return The new list size.
	 */
	int add(T arr[], int size);

	/** \remarks If no argument is given the last element will be removed. */
	int remove(int index = size() - 1);

	int insert(T data, int index);
	int insert(Node<T>* node, int index);

	/** \brief Swaps the index of two elements. */
	void swap(int a, int b);
	
	/**
	 * \brief Prints the data of each element in the specified direction.
	 * \param dir The direction print in (start at head or tail).
	 */
	void print(direction dir);

	Node<T>* head;
	Node<T>* tail;

private:
	/**
	 * \brief The size of the list.
	 * \remarks We don't want users to be able to edit this directly
	 */
	int size_;

public:
	/** Allows for use of the standard [] array operator */
	T& operator [] (const int &i)
	{
		Node<T>* CurrentNode = head;
		int j{};
		
		while (CurrentNode && j++ != i)
			CurrentNode = CurrentNode->next;
		
		return CurrentNode->data;
	}
};

template<class T>
DLL<T>::DLL()
{
	size_ = 0;
	head = nullptr;
	tail = head;
}

template<class T>
DLL<T>::~DLL()
{
	Node<T>* CurrentNode = head;

	while (CurrentNode)
	{
		
	}
}

template <class T>
int DLL<T>::size() const
{
	return size_;
}

template <class T>
Node<T>* DLL<T>::At(int &i)
{
	Node<T>* CurrentNode = head;
	int j{};
	
	while (CurrentNode && j++ != i)
		CurrentNode = CurrentNode->next;
	
	return CurrentNode;
}

template<class T>
int DLL<T>::add(T data)
{
	if (!data) return size_;

	auto* NewNode = new Node<T>;
	NewNode->data = data;
	NewNode->next = nullptr;

	if (!head)
	{
		head = NewNode;
	}
	if (tail)
	{
		tail->next = NewNode;
		NewNode->prev = tail;
	}
	tail = NewNode;
	
	return ++size_;
}

template <class T>
int DLL<T>::add(T arr[], const int size)
{
	if (!arr || !size) return size_;
	
	// Use our existing add function for space efficiency
	for (int i{}; i < size; i++)
	{
		add(arr[i]);
	}

	/* We don't need any math here because the list size
	 * is taken care of in the add() function. */
	return size_;
}

template<class T>
int DLL<T>::remove(const int index)
{
	Node<T>* CurrentNode = head;

	// Iterate through list until we find the desired index
	for (int i{}; i < index; i++)
	{
		CurrentNode = CurrentNode->next;
	}

	// Clean up pointers
	CurrentNode->prev->next = CurrentNode->next;
	CurrentNode->next->prev = CurrentNode->prev;

	delete CurrentNode;
	return --size_;
}

/*template<class T>
int DLL<T>::insert(T data, const int index)
{
	Node<T>* CurrentNode = head;

	// Iterate through list until we find the desired index
	for (int i{}; i < index; i++)
	{
		CurrentNode = CurrentNode->next;
	}

	// Since the user only has the data, we create a node to insert
	auto* NewNode = new Node<T>();

	// Clean up pointers
	NewNode->data = data;
	NewNode->prev = CurrentNode->prev;
	NewNode->next = CurrentNode;
	CurrentNode->prev = NewNode;
	
	return ++size_;
}*/

template<class T>
int DLL<T>::insert(T data, const int index)
{
	Node<T>* IndexNode = this->At(index);
	// Since the user only has the data, we create a node to insert
	auto* NewNode = new Node<T>();

	// Clean up pointers
	NewNode->data = data;
	NewNode->prev = IndexNode->prev;
	NewNode->next = IndexNode;
	IndexNode->prev->next = NewNode;
	IndexNode->prev = NewNode;
	
	return ++size_;
}

template<class T>
int DLL<T>::insert(Node<T>* node, const int index)
{
	Node<T>* IndexNode = this->At(index);

	/* Since the user already has a node, we just work with
	 * that off the bat. */
	node->prev = IndexNode->prev;
	node->next = IndexNode;
	IndexNode->prev->next = node;
	IndexNode->prev = node;
	
	return ++size_;
}

template <class T>
void DLL<T>::swap(int a, int b)
{
	std::swap((*this)[a], (*this)[b]);
}

template<class T>
void DLL<T>::print(const direction dir)
{
	Node<T>* CurrentNode;
	int i{};

	switch (dir)
	{
	case forward:
		CurrentNode = head;
		while (CurrentNode)
		{
			if (i++ >= size_) return;
			cout << CurrentNode->data << endl;
			CurrentNode = CurrentNode->next;
		}
		break;
	case backwards:
		CurrentNode = tail;
		while (CurrentNode)
		{
			if (i++ >= size_) return;
			cout << CurrentNode->data << endl;
			CurrentNode = CurrentNode->prev;
		}
		break;
	}
}
