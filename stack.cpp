// stack.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//
#include <stdio.h> 
#include "stdafx.h" 
#include <iostream> 
#include <vector> 
using namespace std; 
using std::size_t; 
using std::ostream; 


template <typename T> 
class stack 
{ 
public: 
  stack(); 
  stack(stack const & stck); 
  auto count() const noexcept->size_t; 
  auto push(T const & value)->void; 
  auto top() const->T&; 
  auto pop()->void; 
  auto operator=(stack const & stck)->stack &; 
  ~stack(); 
private: 
  T * _array; 
  size_t _array_size; 
  size_t _count; 
  auto m_c(size_t count_m_с, size_t array_size_m_с, const T * tmp)->T*;
}; 

template <typename T> 
stack<T>::stack() : _array(nullptr), _array_size(0), _count(0) {}; 

template <typename T> 
  stack<T>::~stack() { 
  delete[] _array; 
} 

template <typename T> 
stack<T>::stack(stack const &stck) : _array_size(stck._array_size), count_(stck._count) { 
  _array = new T[_array_size]; 
  for (int i = 0; i < _count; i++) _array[i] = stck._array[i]; 
} 

template<typename T> 
auto stack<T>::operator=(stack const & stck) -> stack & { 
  if (this != &stck) { 
    (stack(stck)).swap(*this); 
  } 
  return *this; 
} 

template <typename T> 
auto stack<T>::count() const noexcept->size_t { return _count; } 

template<typename T> 
auto stack<T>::push(T const & value)->void { 
  if (array_ == nullptr) {
		array_ = new T[1];
		array_[0] = val;
		count_++; array_size_++;
	}
	else {
		if (count_ == array_size_) {
			array_size_ *= 2;
			T *tmp = m_c(count_,array_size_,array_);
			delete[] array_;
			array_ = tmp;

		}
		array_[count_] = val;
		count_++;
	}
}

template <typename T> 
auto stack<T>::top() const -> T& { 
  if (_count == 0) throw logic_error("stack's empty"); 
  return _array[_count]; 
} 



template <typename T> 
auto stack<T>::pop() -> void { 
  if (_count == 0) throw("stack's empty"); 
  return --_count; 
}

template <typename T>
auto stack<T>::m_c(size_t count_m_c, size_t array_size_m_c, const T * tmp)->T* {
	T *mass = new T[array_size_m_c];
	copy(tmp, tmp + count_m_c, mass);
	return mass;
}
