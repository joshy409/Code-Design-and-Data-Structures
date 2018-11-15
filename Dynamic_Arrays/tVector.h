#pragma once
template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 2;
private:
	T* arr;                             // pointer to underlying array
	size_t arrSize = 0;                     // stores the number of elements currently used
	size_t arrCapacity = 10;                 // stores the capacity of the underlying array

public:
	tVector()					// initializes the vector's default values
	{
		arr = new T[arrCapacity];
	}        

	tVector(size_t newCapacity)					// initializes the vector's default values
	{
		arrCapacity = newCapacity;
		arr = new T[arrCapacity];
	}

	tVector(const tVector &vec) {  // copy constructor
		arr = new T[vec.arrCapacity];
		for (size_t i = 0; i < vec.size(); i++) {
			arr[i] = vec.arr[i];
		}
		arrSize = vec.size();
		arrCapacity = vec.capacity();
	}

	~tVector()					// destroys the underlying array	
	{
		delete[] arr;
	}                        

	T* data()					// returns a pointer to the underlying array
	{
		return arr;
	}     

	tVector& operator=(const tVector &vec) {  // ??
		reserve(vec.arrCapacity);
		for (size_t i = 0; i < vec.arrSize; i++) {
			arr[i] = vec.arr[i];
		}
		arrSize = vec.arrSize;
		return *this;
	}

	void reserve(size_t newCapacity) {   // resizes the vector to at least this many elements
		T* temp = new T[newCapacity]; // temp array with bigger size

		for (size_t i = 0; i < arrSize; i++) { // copy the original array into new array that is bigger
			temp[i] = arr[i];
		}

		delete[] arr;
		arr = temp;
		arrCapacity = newCapacity;
	}

	void push_back(const T &value) {     // adds an element to the end of the vector
		if (arrSize >= arrCapacity) {    // if the array full
			reserve((arrCapacity == 0 ? 1 : arrCapacity)  * GROWTH_FACTOR);
		}
		arr[arrSize] = value;
		arrSize++;
	}

	void pop_back() {                    // drops the last element of the vector
		arrSize -= 1;
	}


	void erase(size_t index) {
		T* temp = new T[arrCapacity];
		for (size_t i = 0; i < index; i++) { // copy the original array into new array that is bigger
			temp[i] = arr[i];
		}
		for (size_t i = index + 1; i < arrCapacity; i++) { // copy the original array into new array that is bigger
			temp[i-1] = arr[i];
		}
		delete[] arr;
		arr = temp;
		arrSize--;
	}

	T& at(size_t index) {               // returns the element at the given element
		return arr[index];
	}

	T& operator[] (size_t index) {      // returns the element at the given element
		return arr[index];
	}

	const T& operator[] (size_t index) const {
		return arr[index];
	}

	size_t size() const {                // returns current number of elements
		return arrSize;
	}
	size_t capacity() const {            // returns maximum number of elements we can store
		return arrCapacity;
	}

	void print() const {				//print out the content of the array
		for (size_t i = 0; i < arrSize; i++) {
			std::cout << arr[i] << std::endl;
		}
	}

	bool empty() const {        // Returns true if the vector contains no elements.
		return arrSize == 0;
	}

	void resize(size_t newSize) { // Resizes the vector to contain the given number of elements.
		if (newSize < arrCapacity) {
			arrSize = newSize;
		}
		else if (newSize > arrCapacity) {
			reserve(newSize);

			for (size_t i = arrSize; i < newSize; i++) { // initialize with default value
				arr[i] = 0;
			}
			arrSize = newSize;
		}

	}

	void shrink_to_fit() { // Resizes the vector's capacity to match its size.
		if (arrSize == arrCapacity) { return; }
		reserve(arrSize);
	}

	void clear() {    // Empties the vector (all elements are destroyed in this process)}
		delete[] arr;
		arrCapacity = 0;
		arr = new T[arrCapacity];
		arrSize = 0;
	}

	
};

