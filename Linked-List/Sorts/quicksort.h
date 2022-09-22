#pragma once

#include <iostream>
#include "../LinkedLists/DoubleLinkedList.h"

using namespace std;

// References:
// https://www.youtube.com/watch?v=MZaf_9IZCrc
// https://www.geeksforgeeks.org/quick-sort/

/**
 * \brief Sorts a specific portion of the given list.
 * puts all lesser numbers on the left, and larger on the right.
 * \param list The linked list we are sorting.
 * \param start First index of the portion to sort.
 * \param end Last index of the portion to sort.
 * \return 
 */
template<class T>
int partition(DLL<T>& list, int start, int end)
{
	// We are only interested in the pivots value, because
	// that is our base of comparison. Pivot is always at end.
	int pivot = list[end];

	// This number will iterate when finding an element
	// that is less than the pivot. Index placeholder.
	int leftwall = start - 1;

	// Pivot is last element, only go to (end - 1)
	for (int i = start; i <= end - 1; i++)
	{
		if (list[i] < pivot)
		{
			leftwall++;
			list.swap(leftwall, i);
		}
	}
	
	// Move pivot into correct position (where leftwall is)
	list.swap(++leftwall, end);
	return leftwall;
}

template<class T>
void qs(DLL<T>& list, int start, int end)
{
	if (start >= end) return;
		
	// This index will split the array, much like merge sort.
	// Then we will perform quicksort on the two halves.
	int middle = partition(list, start, end);

	// Left half
	qs(list, start, middle - 1);

	// Right half
	qs(list, middle + 1, end);
}

/**
 * \brief Recursive sort similar to merge sort, but faster.
 * \param list The linked list to sort.
 */
template<class T>
void quicksort(DLL<T>& list)
{
	qs(list, 0, list.size() - 1);
}