#pragma once

// Data container for use as an element inside a quad linked list. 
template<class T>
class QuadNode
{
public:
	QuadNode* top,* right,* bottom,* left;
	T data;

	QuadNode()
	{
		top = nullptr;
		right = nullptr;
		bottom = nullptr;
		left = nullptr;
	}
};
