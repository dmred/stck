#include <memory>
#include <iostream> 
using namespace std;



template <typename T>
class stack
{
public:
	stack(); /*noexcept*/
	stack(stack const & stck);/*strong*/
	auto count() const noexcept->size_t; /*noexcet*/
	auto push(T const & value)->void;/*strong*/
	auto top() const->T&;/*strong*/
	auto pop()->T;/*strong*/
	auto operator=(stack const & stck)->stack &;/*strong*/
	bool operator==(stack const & rhs);/*strong*/
	~stack();/*noexcept*/
private:
	T * _array;
	size_t _array_size;
	size_t _count;
	auto copy_new(size_t count_m_c, size_t array_size_m_c, const T * tmp)->T*;
};

