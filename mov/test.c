#include <test2.hpp>
/**
 * 参数构造器
 * @param [in] str 字符串值
 */
Test2::Test2(const char* str) :
	_blocks(NULL)
{
	if (str)
		_blocks = ::strdup(str);
}
 
/**
 * 拷贝构造函数
 * @param [in] o 同类型的另一个对象引用
 */
Test2::Test2(const Test2& o) :
	_blocks(NULL)
{
	if (o._blocks)
		_blocks = ::strdup(o._blocks);
}
 
/**
 * Move构造函数
 * @param [in] o 同类型的另一个对象右值引用
 */
Test2::Test2(Test2&& o) :
	_blocks(NULL)
{
	swap(o);
}
 
/**
 * 析构函数
 */
Test2::~Test2()
{
	if (_blocks)
		::free(_blocks);
	_blocks = NULL;
}
 
/**
 * 赋值运算符重载
 * @param [in] o 同类型的另一个对象引用
 * @return 当前类型的另一个引用
 */
Test2& Test2::operator=(const Test2& o)
{
	if (this != &o)
		Test2(o, int()).swap(*this);
	return *this;
}
 
/**
 * 右值引用赋值运算符重载
 * @param [in] o 同类型的另一个对象右值引用
 * @return 当前类型的另一个引用
 */
Test2& Test2::operator=(Test2&& o)
{
	if (this != &o)
	{
		swap(o);
		o.~Test2();
	}
	return *this;
}
 
/**
 * 交换两个对象
 * @param [in] o 同类型的另一个对象
 */
void Test2::swap(Test2& o)
{
  std::swap(_blocks, o._blocks);
}

Test2 return_object()
{
  Test2 res = "test";
  return res;
}

int main () {
  
}
