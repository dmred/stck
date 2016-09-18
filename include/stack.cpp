#include "stack.h"
template <typename T>
stack<T>::stack() : _array(nullptr), _array_size(0), _count(0) {};

template <typename T>
stack<T>::~stack() {
	delete[] _array;
}

template <typename T>
stack<T>::stack(stack const &stck) : _array_size(stck._array_size), _count(stck._count) {
	_array = new T[_array_size];
	for (int i = 0; i < _count; i++) _array[i] = stck._array[i];
}

template <typename T>
auto stack<T>::operator=(const stack&stck)->stack& {
	if (this != &stck) {
		delete[] _array;
		_count = stck._count;
		_array_size = stck._array_size;
		_array = new T[_array_size];
		copy(stck._array, stck._array + _count, _array);
	}
	return *this;
}

template <typename T>
auto stack<T>::count() const noexcept->size_t { return _count; }

template<typename T>
auto stack<T>::push(T const & value)->void {
	if (_array == nullptr) {
		_array = new T[1];
		_array[0] = value;
		_count++;
		_array_size++;
	}
	else {
		if (_count == _array_size) {
			_array_size *= 2;
			T *tmp = m_c(_count, _array_size, _array);
			delete[] _array;
			_array = tmp;

		}
		_array[_count] = value;
		_count++;
	}
}

template <typename T>
auto stack<T>::top() const -> T& {
	if (_count == 0) throw logic_error("stack's empty");
	return _array[_count];
}

template <typename T>
auto stack<T>::pop() -> T {
	if (_count == 0) throw("stack's empty");
	return --_count;
}

template <typename T>
auto stack<T>::m_c(size_t count_m_c, size_t array_size_m_c, const T * tmp)->T* {
	T *mass = new T[array_size_m_c];
	copy(tmp, tmp + count_m_c, mass);
	return mass;
}
