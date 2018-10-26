#pragma once
#include "tVector.h"

template <typename T>
class tQueue
{
	tVector<T> vec;                       // contains the data for a queue

public:
	tQueue();                             // default initializes the queue
	tQueue(size_t count, const T& value); // constructs a queue with the given number of elements 
										  // each element is initialized by copying the given value

	void push(const T& value);            // adds an element to the top of the Queue
	void pop();                           // drops the top-most element of the Queue

	T& front();                           // returns the front-most element
	T& back();                            // returns the back-most element

	const T& front() const;                           // returns the front-most element
	const T& back() const;                            // returns the back-most element

	bool empty() const;
	size_t size() const;                  // returns current number of elements
};

template<typename T>
tQueue<T>::tQueue()
{
}

template<typename T>
tQueue<T>::tQueue(size_t count, const T & value)
{
	for (int i = 0; i < count; i++) {
		vec.push_back(value);
	}
}

template<typename T>
void tQueue<T>::push(const T & value)
{
	vec.push_back(value);
}

template<typename T>
void tQueue<T>::pop()
{
	vec.erase(0);
}

template<typename T>
T & tQueue<T>::front()
{
	return vec[0];
}

template<typename T>
T & tQueue<T>::back()
{
	return vec[vec.size() - 1];
}

template<typename T>
const T & tQueue<T>::front() const
{
	return vec[0];
}

template<typename T>
const T & tQueue<T>::back() const
{
	return vec[vec.size() - 1];
}

template<typename T>
bool tQueue<T>::empty() const
{
	return vec.empty();
}

template<typename T>
size_t tQueue<T>::size() const
{
	return vec.size();
}
