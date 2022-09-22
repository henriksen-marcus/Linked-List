#pragma once

#include <iostream>
#include "../LinkedLists/DoubleLinkedList.h"

/**
 * \brief Sorting algorithm similar to bubble sort
 * but more efficient.
 * \param list The linked list to sort.
 */
template<class T>
void selectionsort(DLL<T>& list)
{
	for (int i{}; i < list.size(); i++)
	{
		int smallestNumber = list[i];
		int index{};
		for (int k{ i + 1 }; k < list.size(); k++)
		{
			if (list[k] < smallestNumber)
			{
				smallestNumber = list[k];
				index = k;
			}
		}
		if (index != 0) list.swap(i, index); 
	}
}
