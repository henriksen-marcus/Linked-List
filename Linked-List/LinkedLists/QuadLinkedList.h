#pragma once

using namespace std;
#include <iostream>
#include "QuadNode.h"
#include "DoubleLinkedList.h"
#include "Sorts/mergesort.h"

class QLL_Base
{
public:
	enum direction { left, up, right, down };
};

template<class T>
class QLL : QLL_Base 
{
public:
	/**
	 * \brief Constructor, required data at initialization.
	 * \param data The data to put in the first element.
	 */
	QLL(T data);
	~QLL();

	int size() const { return size_; }
	
	/**
	 * \brief Adds a new node in the specified direction.
	 * \param data What the node should contain
	 * \param dir What direction to add the node
	 * \param overwrite If we should replace an existing
	 * node in the specified direction, if it exists
	 * \return The new list size
	 */
	int Add(T data, QLL_Base::direction dir, bool overwrite = false);

	/**
	 * \brief Deletes the element at the cursor.
	 * \remarks We cannot always straight up delete the node,
	 * as a quad linked list needs the node's pointers to traverse.
	 */
	int Remove() { cursor->data = 0; return size_; }

	/** \brief Prints the intire linked list in no particular order. */
	void Print();

	/** \brief Prints the intire linked list in a sorted manner. */
	void PrintSorted();

	/** \brief Moves the cursor in the specified direction. */
	void Move(QLL_Base::direction dir, int steps = 1);

	/** \brief Resets the cursors position back to head. */
	void Reset() { cursor = head; }

	/** \returns The opposite direction. */
	QLL_Base::direction RevDir(QLL_Base::direction dir);

	/**
	 * \brief Checks if there is an available node to
	 * connect to next to the new node.
	 * \param checkDir The direction we want to check in.
	 * \param newNodeDir The direction relative to the cursor
	 * the new node was added in.
	 * \return A pointer to the available node. nullptr if
	 * nothing is found.
	 */
	QuadNode<T>* Check(direction checkDir, direction newNodeDir);

	/** \brief Clears the console and displays an updated image of what the cursor
	 * and it's surroundings look like. */
	void PrintEnvir();

	QuadNode<T>* head;
	QuadNode<T>* cursor;

private:
	int size_;
};


template<class T>
QLL<T>::QLL(T data)
{
	size_ = 0;
	head = new QuadNode<T>();
	head->data = data; 
	cursor = head;
}


template<class T>
QLL<T>::~QLL()
{
	// Not finished
}


template<class T>
int QLL<T>::Add(T data, QLL_Base::direction dir, bool overwrite)
{
	// Is the slot we want to add to empty?
	if (cursor->ptr[dir] == nullptr)
	{
		auto* newNode = new QuadNode<T>();
		newNode->data = data;
		
		cursor->ptr[dir] = newNode;
		
		// Add pointer back to cursor
		newNode->ptr[RevDir(dir)] = cursor;

		// Look for and connect to adjacent nodes
		if (right != dir)
		{
			newNode->ptr[left] = Check(left, dir);
			if (newNode->ptr[left]) newNode->ptr[left]->ptr[right] = newNode;
		}
		if (down != dir)
		{
			newNode->ptr[up] = Check(up, dir);
			if (newNode->ptr[up]) newNode->ptr[up]->ptr[down] = newNode;
		}
		if (left != dir)
		{
			newNode->ptr[right] = Check(right, dir);
			if (newNode->ptr[right]) newNode->ptr[right]->ptr[left] = newNode;
		}
		if (up != dir)
		{
			newNode->ptr[down] = Check(down, dir);
			if (newNode->ptr[down]) newNode->ptr[down]->ptr[up] = newNode;
		}
			
		// NOTE: Did not get node adding restriction to work yet. Currently bypassing.
		// We don't want the user to keep adding thin branches out of the list. 
		if (size_ >= 3)
		{
			int connections{};
			for (int i = 0; i < 4; i++)
				// Cursor is the previous element, we are adding from it's position
				if (cursor->ptr[i]) connections++;

			// Previous element only has one connection
			if (connections < 2)
			{
				connections = 0;
				for (int i{}; i < 4; i++)
					if (newNode->ptr[i]) connections++;
				// If the previous element only has 1 connection, and the new element only ended
				// up connecting the the previous element, delete the new one. See explanation
				// at top of code block
				if (connections < 2)
				{
					cout << "Error: Node cannot print, too far out. Prev node connections: "
                    				<< connections << " Value: " << cursor->data << endl;
					delete newNode;
				}
				return size_;
			}
		}
		
		cursor = newNode;
		size_++;
	}
	// It's not empty but we want to overwrite it
	else if (overwrite)
	{
		cursor->ptr[dir]->data = data;
	}
	PrintEnvir();
	return size_;
}


template<class T>
void QLL<T>::Print()
{
	QuadNode<T>* CurrentNode;
	cout << head->data << " ";
	CurrentNode = head->ptr[left];

	while (CurrentNode)
	{
		cout << CurrentNode->data << " ";

		auto* CRNode = CurrentNode->ptr[up];
		while (CRNode)
		{
			cout << CRNode->data << " ";
			CRNode = CRNode->ptr[up];
		}

		CRNode = CurrentNode->ptr[down];
		while (CRNode)
		{
			cout << CRNode->data << " ";
			CRNode = CRNode->ptr[down];
		}

		CurrentNode = CurrentNode->ptr[left];
	}

	CurrentNode = head->ptr[up];
	while (CurrentNode)
	{
		cout << CurrentNode->data << " ";
		CurrentNode = CurrentNode->ptr[up];
	}

	CurrentNode = head->ptr[right];
	while (CurrentNode)
	{
		cout << CurrentNode->data << " ";

		auto* CRNode = CurrentNode->ptr[up];
		while (CRNode)
		{
			cout << CRNode->data << " ";
			CRNode = CRNode->ptr[up];
		}

		CRNode = CurrentNode->ptr[down];
		while (CRNode)
		{
			cout << CRNode->data << " ";
			CRNode = CRNode->ptr[down];
		}

		CurrentNode = CurrentNode->ptr[right];
	}

	CurrentNode = head->ptr[down];
	while (CurrentNode)
	{
		cout << CurrentNode->data << " ";
		CurrentNode = CurrentNode->ptr[down];
	}
}

template <class T>
void QLL<T>::PrintSorted()
{
	DLL<T> List;
	QuadNode<T>* CurrentNode;
	List.add(head->data);
	CurrentNode = head->ptr[left];

	while (CurrentNode)
	{
		List.add(CurrentNode->data);

		auto* CRNode = CurrentNode->ptr[up];
		while (CRNode)
		{
			List.add(CRNode->data);
			CRNode = CRNode->ptr[up];
		}

		CRNode = CurrentNode->ptr[down];
		while (CRNode)
		{
			List.add(CRNode->data);
			CRNode = CRNode->ptr[down];
		}

		CurrentNode = CurrentNode->ptr[left];
	}

	CurrentNode = head->ptr[up];
	while (CurrentNode)
	{
		List.add(CurrentNode->data);
		CurrentNode = CurrentNode->ptr[up];
	}

	CurrentNode = head->ptr[right];
	while (CurrentNode)
	{
		List.add(CurrentNode->data);

		auto* CRNode = CurrentNode->ptr[up];
		while (CRNode)
		{
			List.add(CRNode->data);
			CRNode = CRNode->ptr[up];
		}

		CRNode = CurrentNode->ptr[down];
		while (CRNode)
		{
			List.add(CRNode->data);
			CRNode = CRNode->ptr[down];
		}

		CurrentNode = CurrentNode->ptr[right];
	}

	CurrentNode = head->ptr[down];
	while (CurrentNode)
	{
		List.add(CurrentNode->data);
		CurrentNode = CurrentNode->ptr[down];
	}

	// Print
	mergesort(List);
	List.print(DLL_Base::forward);
}


template <class T>
void QLL<T>::Move(QLL_Base::direction dir, int steps)
{
	for (int i{}; i < steps; i++)
		if (cursor->ptr[dir]) cursor = cursor->ptr[dir];
	
	PrintEnvir();
}


template<class T>
QLL_Base::direction QLL<T>::RevDir(const QLL_Base::direction dir)
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
	}
}


template <class T>
QuadNode<T>* QLL<T>::Check(direction checkDir, direction newNodeDir)
{
	// Very hard to explain, imagine we are checking in a U shape
	if (cursor->ptr[checkDir])
		if (cursor->ptr[checkDir]->ptr[newNodeDir])
			return cursor->ptr[checkDir]->ptr[newNodeDir];
	return nullptr;	
}


template <class T>
void QLL<T>::PrintEnvir()
{
	system("cls");
	int PrintData = cursor->ptr[up] ? cursor->ptr[up]->data : -1;
	printf("%s    %d\n", PrintData == -1 ? " " : "  ", PrintData);
	printf("      ^\n");
	printf("%d <- %d -> %d\n", cursor->ptr[left] ? cursor->ptr[left]->data : -1, cursor->data,  cursor->ptr[right] ? cursor->ptr[right]->data : -1);
	printf("      v\n");
	PrintData = cursor->ptr[down] ? cursor->ptr[down]->data : -1;
	printf("%s    %d\n", PrintData == -1 ? " " : "  ", PrintData);
}
