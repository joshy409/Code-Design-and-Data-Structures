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
	tForwardList(const tForwardList& other);            // copy-constructor

	tForwardList<T>& operator=(const tForwardList &rhs);   // copy-assignment

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

	//TODO: iterators
	class iterator
	{
	public:
		
		Node<T> * cur;						// current node being operated upon

		bool operator==(const iterator& rhs) const; // returns true if the iterator points to the same node
		bool operator!=(const iterator& rhs) const; // returns false if the iterator does not point to the same node
		T& operator*() const;                       // returns a reference to the element pointed to by the current node
		iterator& operator++();                     // pre-increment (returns a reference to this iterator after it is incremented)
		iterator operator+(int);                   // post-increment (returns an iterator to current node while incrementing the existing iterator)
		
	};
	iterator begin();
	iterator end();
};


template<typename T>
tForwardList<T>::tForwardList()
{
	//initialize head to nullpointer
	head = nullptr;
	
}

template<typename T>
tForwardList<T>::~tForwardList()
{ 
	this->clear();
}

template<typename T>
tForwardList<T>::tForwardList(const tForwardList & other)
{
	//copy
	Node<T>* copyNode = other.head;
	head = new Node<T>{ other.head->data, nullptr }; //deep
	Node<T>* temp = head;
	copyNode = copyNode->next;
	while (copyNode != nullptr) {
		Node<T>* copy = new Node<T>{ copyNode->data, nullptr }; //deep
		head->next = copy;
		head = copy;
		copyNode = copyNode->next;
	}
	head = temp;
}

template<typename T>
tForwardList<T> & tForwardList<T>::operator=(const tForwardList & rhs)
{
	//clears the original list 
	this->clear();

	//copy
	Node<T>* copyNode = rhs.head;
	head = new Node<T>{ rhs.head->data, nullptr }; //deep
	Node<T>* temp = head;
	copyNode = copyNode->next;
	while (copyNode != nullptr) {
		Node<T>* copy = new Node<T>{ copyNode->data, nullptr }; //deep
		head->next = copy;
		head = copy;
		copyNode = copyNode->next;
	}
	head = temp;
	return *this;
}

template<typename T>
void tForwardList<T>::push_front(const T & val)
{
	//create the new node in the front and make the new node the head
	Node<T>* newNode = new Node<T>{ val, head };
	head = newNode;
}

template<typename T>
void tForwardList<T>::pop_front()
{
	//move the head over to the next node and delete the original head
	Node<T>* temp = head;
	head = head->next;
	delete temp;
}

template<typename T>
T & tForwardList<T>::front()
{
	//TODO: when it is called on empty list?
	return head.data;
}

template<typename T>
const T & tForwardList<T>::front() const
{
	//TODO: when it is called on empty list?
	return head.data;
}

template<typename T>
void tForwardList<T>::remove(const T & val)
{
	//if the next node data is equal to the value change the next node to next next node and delete next node
	Node<T>* node = this->head;
	while (node->next != nullptr) { 
		if (node->next->data == val) {
			Node<T>* temp = node->next;
			node->next = node->next->next;
			delete temp;
		}
		else {
			node = node->next;
		}
	}
	
	//check the first element at the end
	if (head->data == val) {
		node = head;
		head = head->next;
		delete node;
	}
	

}

template<typename T>
bool tForwardList<T>::empty() const
{
	return head == nullptr;
}

template<typename T>
void tForwardList<T>::clear()
{
	//pop all the elements until head is null pointer
	while (head != nullptr) {
		this->pop_front();
	} 
}

template<typename T>
void tForwardList<T>::resize(size_t newSize)
{
	Node<T>* temp = this->head;
	//TODO: do this function
	for (int i = 0; i < newSize; i++) {
		if (temp->next == nullptr) {
			Node<T>* newNode = new Node<T>{T(),nullptr};
			temp->next = newNode;
		}
		else {
			temp = temp->next;
		}
	}
}


//this is a custom function that returns a Node so that I can print the contents of the list without using the iterators in main
template<typename T>
tForwardList<T>::Node<T> * tForwardList<T>::first()
{
	return head;
}

template<typename T>
typename tForwardList<T>::iterator tForwardList<T>::begin()
{
	iterator temp;
	temp.cur = this->first();
	return temp;
}

template<typename T>
typename tForwardList<T>::iterator tForwardList<T>::end()
{
	iterator temp;
	temp.cur = NULL;
	return temp;
}

template<typename T>
 bool tForwardList<T>::iterator::operator==(const tForwardList<T>::iterator & rhs) const
{
	 return this->cur == rhs.cur;
}


template<typename T>
 bool tForwardList<T>::iterator::operator!=(const tForwardList<T>::iterator & rhs) const
{
	 return this->cur != rhs.cur;
}


template<typename T>
 T & tForwardList<T>::iterator::operator*() const
{
	 return (this->cur->data);
}


template<typename T>
typename tForwardList<T>::iterator & tForwardList<T>::iterator::operator++()
{
	this->cur = this->cur->next;
	return *this;
}


template<typename T>
typename tForwardList<T>::iterator tForwardList<T>::iterator::operator+(int j)
{
	for (int i = 0; i < j; i++) {
		this->cur = this->cur->next;
	}
	return *this;
}
