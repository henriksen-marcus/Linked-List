#pragma once

#include <iostream>
#include "../LinkedLists/DoubleLinkedList.h"

/**
 * \brief Stacks two lists together like a deck of cards. Sorts the items in correct order.
 * \param list The original list.
 * \param start The first index of the left half.
 * \param middle The middle of the section, left inclusive.
 * \param end The last index of the right half.
 */
template<class T>
void merge(DLL<T>& list, int start, int middle, int end)
{
	// Size of left temp array
	int size1 = middle - start + 1;
	// Size of right temp array
	int size2 = end - middle;

	// Init temp arrays 
	T* leftarr = new T[size1];
	T* rightarr = new T[size2];

	// Copy over data to temp lists, to use in comparisons
	for (int i{}; i < size1; i++) { leftarr[i] = list[start + i]; }
	for (int i{}; i < size2; i++) { rightarr[i] = list[middle + 1 + i]; }

	int index0 = start, index1{}, index2{};

	// Run no more iterations than the smallest list size (avoid going out of range)
	// index0 = index of original (to-be merged) list
	while (index1 < size1 && index2 < size2)
	{
		if (leftarr[index1] < rightarr[index2])		// Always push the smallest number in
		{											// the two lists to the leftmost position
			list[index0] = leftarr[index1];			// in the original list
			index1++;
		}
		else {
			list[index0] = rightarr[index2];
			index2++;
		}
		index0++;
	}

	// Copy over leftovers
	if (index1 < size1)
	{
		for (index1; index1 < size1; index1++, index0++)
		{
			list[index0] = leftarr[index1];
		}
	}

	if (index2 < size2)
	{
		for (index2; index2 < size2; index2++, index0++)
		{
			list[index0] = rightarr[index2];
		}
	}

	// Clear memory
	delete[] leftarr;
	delete[] rightarr;
}


template<class T>
void mergesort(DLL<T>& list, int start, int end)
{
	// Ensures we stop splitting when we reach an array size of one
	if (start < end)
	{
		int middle = (start + end) / 2;

		mergesort(list, start, middle); // Left
		mergesort(list, middle + 1, end); // Right
		merge(list, start, middle, end);
	}
}


template<class T>
void mergesort(DLL<T>& list)
{
	mergesort(list, 0, list.size() - 1);
}