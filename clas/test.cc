#include <iostream>

class A {
  public:
    virtual int get_source() const = 0;
    virtual std::string get_name() const = 0;
};

class B : public virtual A {
  public:
    B () {
      std::cout << " B construct " << std::endl;
    }
    ~B () {
      std::cout << " B disconstruct " << std::endl;
    }
    std::string get_name() const override  {
      return "B";
    }
    int get_source() const override {
       return -1;
    }
};

class C : public virtual A {
  public:
    C () {
      std::cout << " C construct " << std::endl;
    }
    ~C () {
      std::cout << " C disconstruct " << std::endl;
    }
    std::string get_name() const override {
      return "C";
    }
};

class D :public B, public C {
  public:
    D () {
      std::cout << " D construct " << std::endl;
    }
    ~D () {
      std::cout << " D disconstruct " << std::endl;
    }
    std::string get_name() const override {
      return "D";
    }
};

int main() {
 // D* d = new D();
 // std::cout << d->get_name() << ":" << d->get_source() << std::endl;
 B *b = new D();
 std::cout << " start cast " << std::endl;
 D* d = static_cast<D*>(b);
}
