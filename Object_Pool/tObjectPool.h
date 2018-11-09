#pragma once
#include "FallingFactorys.h"
#include "SimpleSprites.h"
template<typename T>
class tObjectPool
{
public:
	tObjectPool();                       // default initializes the object pool
	tObjectPool(size_t initialCapacity); // initializes the pool to have a set number of objects
	~tObjectPool();                      // destroys all objects

	T* pool;
	T* free;                            // pointers to objects that can be reused
	T* used;                            // pointers to objects that are currently in use
	size_t freeCount;                   // number of objects that are free to use
	size_t usedCount;                   // number of objects that are in use

	T* retrieve();                      // returns a pointer to an object that will be used (returns null if none available)
	void recycle(T obj);                // accepts a pointer that can be used in the future

	size_t capacity();                  // returns the total number of objects that this pool can provide
};

template<typename T>
tObjectPool<T>::tObjectPool()
{
	
}

template<typename T>
tObjectPool<T>::tObjectPool(size_t initialCapacity)
{
	pool = new pool[initialCapacity];
	freecount = initialCapacity;
	usedcount = 0;
}

template<typename T>
tObjectPool<T>::~tObjectPool()
{
}

template<typename T>
T * tObjectPool<T>::retrieve()
{
	return pool[freeCount];
}

template<typename T>
void tObjectPool<T>::recycle(T obj)
{
	if (usedCount > 25) {
		return;
	}
	pool[usedCount] = obj;
	usedCount++;
	freeCount = freeCount - usedCount;
}

template<typename T>
size_t tObjectPool<T>::capacity()
{
	return size_t();
}
