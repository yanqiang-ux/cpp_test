#include <memory>
#include <iostream>
using namespace std;

struct A;
struct B;
struct A {
    shared_ptr<B> B_ptr;
	A() {
		cout << "construct A" << endl;
	}
	~A() {
		cout << "destory A" << endl;
	}
};

struct B {
    shared_ptr<A> A_ptr;
	B() {
		cout << "construct B" << endl;
	}
	~B() {
		cout << "destroy B" << endl;
	}
};

void loop() {
    shared_ptr<A> ap(new A()); // ap 的引用计数是1
    shared_ptr<B> bp(new B()); // bp 的引用计数是1
    cout << ap.use_count() << endl;
    cout << bp.use_count() << endl;
    ap -> B_ptr = bp; //bp的引用计数是2
    bp -> A_ptr = ap; //ap的引用计数是2
    cout << ap.use_count() << endl;
    cout << bp.use_count() << endl;
	// 将 ap 所指向的对象记作 Aobj，将bp所指向的对象记作 Bobj。
	// 准备析构 bp, 此时Bobj的use_count 是 2，因此析构bp不会销毁 Bobj，而是使 Bobj的use_count变为1。
	// 注意：此时 Aobj 的 use_count 是 2，一个来自 ap, 另一个来自 Bobj.A_ptr（记住：Bobj 并未被销毁）
	// 同理析构 ap 只会把 ap的use_count变为 1 而不会销毁 Aobj。这样就造成内存泄漏了。
}

int main() {
    loop();
    return 0;
}
