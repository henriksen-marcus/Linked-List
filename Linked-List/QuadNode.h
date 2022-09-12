#pragma once

#include <iostream>

template<class T>
class QuadNode
{
public:
	QuadNode* first, second, third, fourth;
	T data;

	QuadNode()
	{
		first = nullptr;
		second = nullptr;
		thrid = nullptr;
		fourth = nullptr;
		
	}
};
