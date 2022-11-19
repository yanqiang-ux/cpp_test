#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>


class Context {
  Context(const Context& other);
  const Context& operator=(const Context& other);

  protected:
  virtual void finish(int r) {
    std::cout << " finish " << std::endl;
  }

  public:
  Context() {}
  virtual ~Context() {}       // we want a virtual destructor!!!
  virtual void complete(int r) {
    finish(r);
    delete this;
  }
};

template<class T>
class ContainerContext : public Context {
  T obj;
  public:
  ContainerContext(T &obj) : obj(obj) {}
  void finish(int r) override {}

  virtual ~ContainerContext() {
    std::cout << " ~ContainerContext " << std::endl;
  }
};

template <typename T>
ContainerContext<T> *make_container_context(T &&t) {
  return new ContainerContext<T>(std::forward<T>(t));
}

struct RunOnDelete {
  Context *to_run;
  RunOnDelete(Context *to_run) : to_run(to_run) {}
  ~RunOnDelete() {
    std::cout << " ~RunOnDelete " << std::endl;
    if (to_run)
      to_run->complete(0);
  }
};
typedef std::shared_ptr<RunOnDelete> RunOnDeleteRef;

int main() {
  Context c;
  // c.complete(0);
  RunOnDeleteRef comp = std::make_shared<RunOnDelete>(&c);

  Context* ct = new ContainerContext<RunOnDeleteRef>(comp);
  comp.reset();
  ct->complete(0);
  std::cout << " hhah " << std::endl;
  int a = 0;
  std::cin >> a;
}
