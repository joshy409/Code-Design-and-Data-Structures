#pragma once
#include "tVector.h"
template <typename T>

class tStack
{
	tVector<T> vec;                     // contains the data for a stack

public:
	tStack();                           // initializes the stack's default values

	void push(const T& value);          // adds an element to the top of the Stack
	void pop();                         // drops the top-most element of the Stack

	T& top();                           // returns the top-most element at the given element

	size_t size() const;                // returns current number of elements

	bool empty() const;

	const T& top() const;
};

template<typename T>
tStack<T>::tStack()
{
}

template<typename T>
void tStack<T>::push(const T & value)
{
	vec.push_back(value);
}

template<typename T>
 void tStack<T>::pop()
{
	 vec.pop_back();
}

template<typename T>
T & tStack<T>::top()
{
	return vec[vec.size() - 1];
}

template<typename T>
size_t tStack<T>::size() const
{
	return vec.size();
}

template<typename T>
bool tStack<T>::empty() const
{
	return vec.empty();
}

template<typename T>
const T & tStack<T>::top() const
{
	return vec[vec.size() - 1];
}
