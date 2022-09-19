#pragma once

#include <iostream>

template<class T>
class QuadNode
{
public:
	QuadNode* top, right, bottom, left;
	T data;

	QuadNode()
	{
		// Link to previous element
		first = nullptr;
		// Link to next element
		second = nullptr;
		thrid = nullptr;
		fourth = nullptr;
	}
};
