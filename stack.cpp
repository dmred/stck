// stack.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//
#include <stdio.h>
#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;


template <typename T>
class stack
{
public:
	stack();
	size_t count() const;
	void push(T const &);
	T pop();
	stack(const stack<T>&);
	stack<T>& operator=(const stack<T>&);
	~stack();
private:
	T * _array;
	size_t _array_size;
	size_t _count;
};

template <typename T>
stack<T>::stack() : _array(nullptr), _array_size(0), _count(0) {};

template <typename T>
stack<T>::~stack() {
	delete[] _array;
}

template <typename T>
stack<T>::stack(const stack<T>& x) : _array_size(x._array_size), count_(x._count){
	_array = new T[_array_size];
	for (int i = 0; i < _count; i++) _array[i] = x._array[i];
}

template<typename T>
stack<T>& stack<T>::operator=(const stack<T>& b){
	if (this != &b){
		swap(b._array_size,_array_size);
		swap(b._count, _count);
		swap(b._array, _array);

	}
return *this;
}
template <typename T>
size_t stack<T>::count() const { return _count; }

template <typename T>
void stack<T>::push(T const &a) {
	if (_array == nullptr) {
		_array = new T[1]; _array[0] = a;
		_count++; _array_size++;
	}
	else {
		if (_count == _array_size) {
			T *p = _array;
			_array = new T[_array_size * 2];
			for (int i = 0; i < _count; i++) _array[i] = p[i];
			delete[]p;
			_array_size *= 2;
		}
		_array[_count] = a;
		_count++;
	}
}

template <typename T>
T stack<T>::pop() {
	if (_count == 0) throw("stack's empty");
	else {
		_count = _count - 1;
		return _array[_count];
	}
}
