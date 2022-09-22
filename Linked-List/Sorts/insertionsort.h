#pragma once

#include <iostream>
#include "../LinkedLists/DoubleLinkedList.h"

using namespace std;

template <class T>
void insertionsort (DLL<T>& list)
{
	for (int i{}; i < list.size() - 1; i++)
	{
		if (list[i] > list[i + 1])
		{
			list.swap(i, i + 1);

			// Continue pushing the swapped number back until it's in the right position
			for (int k = i; k > 0; k--)
			{
				if (list[k] > list[k - 1]) break;
				else list.swap(k, k - 1);
			}
		}
	}
	cout << "Insertion Sort: list is sorted." << endl;
}

