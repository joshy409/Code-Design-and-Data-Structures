#pragma once
template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 2;

	T* arr;                             // pointer to underlying array
	size_t arrSize = 0;                     // stores the number of elements currently used
	size_t arrCapacity = 10;                 // stores the capacity of the underlying array

public:
	tVector()					// initializes the vector's default values
	{
		arr = new T[arrCapacity];
	}                          
	~tVector()					// destroys the underlying array	
	{
		delete[] arr;
	}                        

	T* data()					// returns a pointer to the underlying array
	{
		return arr;
	}                          

	void reserve(size_t newCapacity) {   // resizes the vector to at least this many elements
		T* temp = new T[newCapacity];

		for (int i = 0; i < arrSize; i++) {
			temp[i] = arr[i];
		}

		delete[] arr;

		arr = temp;

		arrCapacity = newCapacity;
	}

	void push_back(const T &value) {     // adds an element to the end of the vector
		if (arrSize >= arrCapacity) {
			reserve(arrCapacity * GROWTH_FACTOR);
		}
		arr[arrSize] = value;
		arrSize++;
	}

	void pop_back() {                    // drops the last element of the vector
		arrSize - 1;
	}

	T& at(size_t index) {               // returns the element at the given element
		return arr[index];
	}

	size_t size() const {                // returns current number of elements
		return arrSize;
	}
	size_t capacity() const {            // returns maximum number of elements we can store
		return arrCapacity;
	}
};

