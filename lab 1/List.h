#pragma once

template<class T>
class List {

private:
	class Node {		
	public:
		T element;
		Node* next;

		Node();
		Node(const T);
		~Node();
	};

	class Iterator {
	public:
		Node* current;
		Iterator(Node *&);
		~Iterator();
		T& operator* ();
		Iterator& operator++();
		Iterator& operator++(int);
		bool operator ==(const Iterator&);
		bool operator !=(const Iterator&);
		
	};
	


	Node * _begin;
	Node * _dummy;
	size_t _size; 
	friend class Node;
	friend class Iterator;
public:
	List();
	List(const List&);
	~List();
	size_t size() const;
	void clear();
	bool isEmpty() const;
	bool contains(const T&) const;
	T get(const size_t) const;
	void change(const T&, const size_t);
	size_t position(const T&);
	void insert(const T&);
	void insert(const T&, size_t);
	void remove(const T&);
	void remove(const size_t);
	Iterator& begin();
	Iterator& end();
};

template<class T>
List<T>::Node::Node()
{
	next = nullptr;
}

template<class T>
List<T>::Node::Node(const T el) {
	element = el;
	next = nullptr;
}

template<class T>
List<T>::Node::~Node()
{
	if (next) delete next;
}

template<class T>
List<T>::Iterator::Iterator(Node*& cur)
{
	current = cur;
}

template<class T>
List<T>::Iterator::~Iterator()
{
}

template<class T>
T& List<T>::Iterator::operator*()
{
	return current->element;
}

template<class T>
typename List<T>::Iterator& List<T>::Iterator::operator++()
{
	current = current->next;
	return *this;
}

template<class T>
typename List<T>::Iterator& List<T>::Iterator::operator++(int)
{
	Iterator tmp(current);
	++(*this);
	return tmp;
}

template<class T>
bool List<T>::Iterator::operator==(const Iterator& second)
{
	return this->current == second.current;
}

template<class T>
bool List<T>::Iterator::operator!=(const Iterator& second)
{
	return this->current != second.current;
}

template<class T>
List<T>::List()
{
	_dummy = nullptr;
	_size = 0;
	_begin = nullptr;
}

template<class T>
List<T>::List(const List& list)
{
	clear();

}

template<class T>
List<T>::~List()
{
	clear();
}

template<class T>
size_t List<T>::size() const
{
	return _size;
}

template<class T>
void List<T>::clear()
{
	_dummy->next = nullptr;
	if (_begin) delete _begin;

	_size = 0;
}

template<class T>
bool List<T>::isEmpty() const
{
	return _size == 0;
}

template<class T>
bool List<T>::contains(const T& el) const
{
	Node* tmp = _begin;
	while (tmp != _dummy) {
		if (tmp->element == el) return true;
		tmp = tmp->next;
	}
	return false;
}

template<class T>
T List<T>::get(const size_t pos) const
{
	if (pos > _size) throw "error";
	Node* tmp = _begin;
	for (int i = 1; i < pos; i++) tmp = tmp->next;
	return tmp->element;
}

template<class T>
void List<T>::change(const T& el, const size_t pos)
{
	if (pos > _size) throw "error";
	Node* tmp = _begin;
	for (int i = 1; i < pos; i++) tmp = tmp->next;
	tmp->element = el;
}

template<class T>
size_t List<T>::position(const T& el)
{
	size_t pos = 1;
	Node* tmp = _begin;
	while (tmp != _dummy) {
		if (tmp->element = el) return pos;
		tmp = tmp->next;
		pos++;
	}
	throw "error";
}

template<class T>
void List<T>::insert(const T& el)
{
	if (_begin == nullptr) {
		_begin = new Node(el);
		_dummy = new Node(el);
		_begin->next = _dummy;
		_dummy->next = _begin;
	}
	else {
		_dummy->element = el;
		Node* tmp = new Node(el);
		tmp->next = _begin;
		_dummy->next = tmp;
		_dummy = tmp;
	}
	_size++;
}

template<class T>
void List<T>::insert(const T& el, size_t pos)
{
	if (pos > _size) throw "error";
	if (pos == 1) {
		Node* tmp = new Node(el);
		tmp->next = _begin;
		_begin = tmp;
		_dummy->next = _begin;
	}
	else {
		Node* tmp = _dummy;
		for (size_t i = 1; i < pos; i++) tmp = tmp->next;
		Node* newNode = new Node(el);
		newNode->next = tmp->next;
		tmp->next = newNode;
	}
	_size++;
}

template<class T>
void List<T>::remove(const T& el)
{
	Node* tmp = _begin;
	Node* tmpPrev = _dummy;
	while (tmp != _dummy) {
		if (tmp->element == el) {
			tmpPrev = tmp->next;
			tmp->next = nullptr;
			delete tmp;
			_size--;
			return;
		}
		tmp = tmp->next;
		tmpPrev = tmpPrev->next;
	}
	throw "error";
}

template<class T>
void List<T>::remove(const size_t pos)
{
	if (pos > _size || pos == 0) throw "error";
	if (pos == 1) {
		_dummy->next = _begin->next;
		_begin->next = nullptr;
		delete _begin;
		_begin = _dummy->next;
	}
	else {
		Node* tmp = _dummy;
		for (int i = 1; i < pos; i++) tmp = tmp->next;
		tmp->next = tmp->next->next;
		tmp->next->next = nullptr;
		delete tmp->next;
	}
	_size--;
}

template<class T>
typename List<T>::Iterator& List<T>::begin()
{
	return *(new Iterator(_begin));
}

template<class T>
typename List<T>::Iterator& List<T>::end()
{
	return *(new Iterator(_dummy));
}
