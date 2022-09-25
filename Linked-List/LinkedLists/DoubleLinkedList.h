#pragma once
#include <iostream>
#include <vcruntime_startup.h>

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

	int size() { return size_; }

	/**
	 * \param i The index to return.
	 * \return Pointer to the node at the index.
	 * \remarks Pointer safety: If the given index exceeds the
	 * list size, the tail will be returned.
	 */
	Node<T>* at(const int &i);
	
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
	int add(T arr[], const int& size);

	/**
	 * \brief Adds the specified element to the start of the list.
	 * \return The new list size.
	 */
	int addFront(T data) { return insert(data, 0); }

	int addFront(T arr[], const int& size);
	

	/**
	 * \brief Deletes the element at given index and cleans up pointers.
	 * \remarks If no argument is given the last element will be removed.
	 */
	int remove(const int& index = -1);

	/**
	 * \brief Deletes the last element in the list.
	 * \return The new list size;
	 */
	int pop() { return remove(); }

	/**
	 * \brief Deletes the first element in the list.
	 * \return The new list size.
	 */
	int popFront() { return remove(0); }

	/**
	 * \brief Inserts a node with the given data into the specifed index.
	 * Moves the node at the index one slot to the right.
	 * \return The new list size.
	 * \remarks Cannot perform the same action as add(). Will always
	 * move the current element at the given index.
	 */
	int insert(T data, const int& index);

	/**
	* \brief Inserts the given node into the specified index.
	* Moves the node at the index one slot to the right.
	* \return The new list size.
	* \remarks Cannot perform the same action as add(). Will always
	* move the current element at the given index.
	*/
	int insert(Node<T>* node, const int& index);

	/** \brief Swaps the value of two elements. */
	void swap(int& a, int& b);
	
	/**
	 * \brief Prints the data of each element in the specified direction.
	 * \param dir The direction to print in (start at head or tail).
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
	int index_;
	Node<T>* cursor_;

	int diff(int& a, int& b) { return abs(a - b); }

public:
	/** Allows for use of the standard [] array operator */
	T& operator [] (const int &i)
	{
		if (i <)
		
		Node<T>* CurrentNode = head;
		cursor_ = head;
		index_ = 0;
		int j{};
		
		while (CurrentNode && j++ != i)
		{
			CurrentNode = CurrentNode->next;
			cursor_ = CurrentNode;
			index_ = j;
		}
			
		
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
		CurrentNode = CurrentNode->next;
		delete CurrentNode->prev;
	}
	delete CurrentNode;
}

template <class T>
Node<T>* DLL<T>::at(const int &i)
{
	Node<T>* CurrentNode = head;
	int j{};
	
	while (CurrentNode && j++ != i)
		CurrentNode = CurrentNode->next;

	if (CurrentNode) return CurrentNode;
	return tail;
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
int DLL<T>::add(T arr[], const int &size)
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

template <class T>
int DLL<T>::addFront(T arr[], const int& size)
{
	// We iterate backwards to insert the array in the
	// correct order
	for (int i = size; i >= 0; i--)
	{
		insert(arr[i], 0);
	}
	return size_;
}

template<class T>
int DLL<T>::remove(const int& index)
{
	if (index >= size_) return size_;
	
	// Delete last element if no argument is given
	if (index == -1 || index == size_ - 1)
	{
		tail = tail->prev;
		delete tail->next;
		return --size_;
	}
	
	Node<T>* CurrentNode = head;

	// Iterate through list until we find the desired index
	for (int i{}; i < index; i++)
	{
		CurrentNode = CurrentNode->next;
	}

	// Clean up pointers
	if (CurrentNode->prev) CurrentNode->prev->next = CurrentNode->next;
	CurrentNode->next->prev = CurrentNode->prev;
	
	delete CurrentNode;
	return --size_;
}

template<class T>
int DLL<T>::insert(T data, const int &index)
{
	Node<T>* IndexNode = this->at(index);
	// Since the user only has the data, we create a node to insert
	auto* NewNode = new Node<T>();
	
	// Prep new node
	NewNode->data = data;
	NewNode->next = IndexNode;
	
	// Clean up pointers
	// Incase the indexnode is the head, we check for nullptr on prev
	if (IndexNode->prev)
	{
		NewNode->prev = IndexNode->prev;
		IndexNode->prev->next = NewNode;
		IndexNode->prev = NewNode;
	} else
	{
		head = NewNode;
	}
	
	return ++size_;
}

template<class T>
int DLL<T>::insert(Node<T>* node, const int& index)
{
	Node<T>* IndexNode = this->at(index);

	// Since the user already has a node, we just work with
	// that off the bat. 
	node->next = IndexNode;

	// Clean up pointers
	// Incase the indexnode is the head, we check for nullptr on prev
	if (IndexNode->prev)
	{
		node->prev = IndexNode->prev;
		IndexNode->prev->next = node;
		IndexNode->prev = node;
	} else
	{
		head = node;
	}
	
	return ++size_;
}

template <class T>
void DLL<T>::swap(int& a, int& b)
{
	std::swap((*this)[a], (*this)[b]);
}

template<class T>
void DLL<T>::print(const direction dir)
{
	Node<T>* CurrentNode;
	int i{};
	cout << "[ ";
	switch (dir)
	{
	case forward:
		CurrentNode = head;
		while (CurrentNode)
		{
			if (i++ >= size_) return;
			cout << CurrentNode->data << " ";
			CurrentNode = CurrentNode->next;
		}
		break;
	case backwards:
		CurrentNode = tail;
		while (CurrentNode)
		{
			if (i++ >= size_) return;
			cout << CurrentNode->data << " ";
			CurrentNode = CurrentNode->prev;
		}
		break;
	}
	cout << "]" << endl;
}
