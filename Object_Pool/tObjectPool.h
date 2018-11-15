#pragma once
#include "FallingFactorys.h"
#include "SimpleSprites.h"
#include "algorithm"
#include <vector>

template<typename T>
class tObjectPool
{
public:
	tObjectPool();                       // default initializes the object pool
	~tObjectPool();                      // destroys all objects

	std::vector<T> pool;                            // all objects stored in the pool
	std::vector<bool> free;                     // indicates whether an object is available

	T retrieve();                      // returns a pointer to an object that will be used (returns null if none available)
	void recycle(T obj);               // accepts a pointer that can be used in the future

	size_t capacity();                  // returns the total number of objects that this pool can provide
};

template<typename T>
tObjectPool<T>::tObjectPool()
{
	for (int i = 0; i < 20; i++) {
		free.push_back(false);
	}
}

template<typename T>
tObjectPool<T>::~tObjectPool()
{
}

template<typename T>
T  tObjectPool<T>::retrieve()
{
	for (int i = 0; i < pool.size(); i++) {
		if (free[i] == false) {
			free[i] = true;
			return pool[i];
		}
	}
	return NULL;
}

template<typename T>
void tObjectPool<T>::recycle(T obj)
{
	auto temp = std::find(pool.begin(), pool.end(), obj);
	free[std::distance(pool.begin(), temp)] = false;
}

template<typename T>
size_t tObjectPool<T>::capacity()
{
	return pool.size();
}


