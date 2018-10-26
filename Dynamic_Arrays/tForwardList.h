#pragma once
template<typename T>
class tForwardList
{


public:
	template<typename T>
	struct Node
	{
		T data;                     // data for the element stored
		Node * next;                // pointer to node following this node
	};

	Node<T> * head;                    // pointer to head of linked list

	tForwardList();                 // default constructor
	~tForwardList();                // destructor

	void push_front(const T& val);  // adds element to front (i.e. head)
	void pop_front();               // removes element from front

	T& front();                     // returns the element at the head
	const T& front() const;               // returns the element at the head (const)

	void remove(const T& val);      // removes all elements equal to the given value

	bool empty() const;             // Returns true if there are no elements
	void clear();                   // Destroys every single node in the linked list
	void resize(size_t newSize);    // Resizes the linked list to contain the given number of elements
									// New elements are default-initialized
	Node<T>* first();					//returns the first node
};

template<typename T>
tForwardList<T>::tForwardList()
{
	head = NULL;
}

template<typename T>
tForwardList<T>::~tForwardList()
{
}

template<typename T>
void tForwardList<T>::push_front(const T & val)
{
	Node<T>* newNode = new Node<T>{ val, head };
	head = newNode;
	
}

template<typename T>
void tForwardList<T>::pop_front()
{
}

template<typename T>
T & tForwardList<T>::front()
{
	return head.data;
}

template<typename T>
const T & tForwardList<T>::front() const
{
	return;
}

template<typename T>
void tForwardList<T>::remove(const T & val)
{
}

template<typename T>
bool tForwardList<T>::empty() const
{
}

template<typename T>
void tForwardList<T>::clear()
{
}

template<typename T>
void tForwardList<T>::resize(size_t newSize)
{
}

template<typename T>
tForwardList<T>::Node<T> * tForwardList<T>::first()
{
	return head;
}




