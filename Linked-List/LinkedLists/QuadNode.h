#pragma once

// Data container for use as an element inside a quad linked list. 
template<class T>
class QuadNode
{
public:
	QuadNode<T>* ptr[4];
	T data;

	QuadNode()
	{
		for (int i{}; i < 4; i++)
		{
			ptr[i] = nullptr;
		}
	}
};
