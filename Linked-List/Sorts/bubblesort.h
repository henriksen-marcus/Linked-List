#pragma once

#include <iostream>
#include "../LinkedLists/DoubleLinkedList.h"

using namespace std;

/**
 * \brief Simple but slow sorting algorithm.
 * \param list The linked list to sort.
 */
template<class T>
void bubblesort(DLL<T>& list)
{
    bool swapped = true;

    /* We check if there has been a swap in the current pass,
     * if not we know the list is sorted. */
    while (swapped)
    {
        swapped = false;
        for (int i{}; i < list.size() - 1; i++)
        {
            if (list[i] > list[i + 1]) // Compare size of element i and the next element
            {
                list.swap(i, i + 1);
                swapped = true;
            }
        }
    }
}
