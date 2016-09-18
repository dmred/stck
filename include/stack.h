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
	auto pop()->T;
	auto operator=(stack const & stck)->stack &;
	~stack();
private:
	T * _array;
	size_t _array_size;
	size_t _count;
	auto m_c(size_t count_m_ñ, size_t array_size_m_ñ, const T * tmp)->T*;
};

