class Test2
{
public:
	Test2() {}
	Test2(const char* str);
	Test2(const Test2& o);
	Test2(Test2&& o);
	virtual ~Test2();
	Test2& operator=(const Test2& o);
	Test2& operator=(Test2&& o);
	void swap(Test2& o);
	const char* cstr() const { return _blocks ? _blocks : ""; }
protected:
	char* _blocks;	// 保存字符串的缓冲区
};
