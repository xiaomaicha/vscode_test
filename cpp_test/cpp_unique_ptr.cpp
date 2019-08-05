//
// Created by wuqi on 19-8-2.
//

/*unique_ptr.h 文件 */
#include <iostream>
#include <string>
//#include"shared_ptr.h"
//#include "unique_ptr.h"
//#include"Delete.h"
#include <assert.h>

using namespace std;
#ifndef _UNIQUE_PTR_H
#define __UNIQUE_H
class Delete {
public:
  template<typename T>
  void operator()(T *p) const {
    delete p;
  }
};
template<typename T, typename D = Delete>
class unique_ptr {
public:
  explicit unique_ptr(T *pp = nullptr, const D &dd = D())
      : un_ptr(pp), del(dd) {
  }
  ~unique_ptr() {
    del(un_ptr);
  }
  /* 不支持拷贝与赋值   */
  unique_ptr(const unique_ptr &) = delete;
  unique_ptr &operator=(const unique_ptr &) = delete;

  /*可以拷贝或者赋值一个将要被销毁的 unique_ptr（右值引用）*/
  unique_ptr(unique_ptr &&right_value) :
      un_ptr(right_value.un_ptr), del(std::move(right_value.del)) {
    right_value.un_ptr = nullptr;
  }
  unique_ptr &operator=(unique_ptr &&right_value) noexcept {
    if (this != &right_value) {
      std::cout << "operator && right_value " << std::endl;
      del(*this);
      un_ptr = right_value.un_ptr;
      del = std::move(right_value.del);
      right_value.un_ptr = nullptr;
    }
    return *this;
  }
  //u.release()   u 放弃对指针的控制权，返回指针，并将 u 置为空
  T *release() {
    T *tmp = un_ptr;
    un_ptr = nullptr;
    return tmp;
  }
  /*
  u.reset()   释放u指向的对象
  u.reset(q)  如果提供了内置指针q，就令u指向这个对象
  u.reset(nullptr) 将 u 置为空
  */
  void reset() { del(un_ptr); }
  void reset(T *q) {
    if (un_ptr) {
      del(un_ptr);
      un_ptr = q;
    } else
      un_ptr = nullptr;
  }
  void swap(unique_ptr &other) noexcept {
    using std::swap;
    swap(un_ptr, other.un_ptr);
    swap(del, other.del);
  }
  T *get() { return un_ptr; }
  D &get_deleter() { return del; }
  T &operator*() { return *un_ptr; }
  T *operator->() { return un_ptr; }
private:
  T *un_ptr = nullptr;
  D del;
};
#endif

/*    main.cpp 文件  */

struct Foo {
  Foo() { std::cout << "Foo()\n"; }
  ~Foo() { std::cout << "~Foo()\n"; }
  Foo(const Foo &) { std::cout << "Foo copy ctor\n"; }
  Foo(Foo &&) { std::cout << "Foo move ctor\n"; }
};
struct Fooo {
  Fooo(int n = 0) noexcept : bar(n) { std::cout << "Fooo: constructor, bar = " << bar << '\n'; }
  ~Fooo() { std::cout << "Fooo: destructor, bar = " << bar << '\n'; }
  int GetBar() const noexcept { return bar; }
private:
  int bar;
};
struct D {
  void bar() { std::cout << "Call deleter D::bar()...\n"; }
  void operator()(Foo *p) const {
    std::cout << "Call delete from function object...\n";
    delete p;
  }
};
using namespace std;
int main() {
  unique_ptr<string> p1(new string("Shengxi-Liu"));
  cout << *p1 << endl;
  {
    std::cout << "======================\nunique_ptr constructor:\n";
    unique_ptr<Foo> up1;
    unique_ptr<Foo> up1b(nullptr);
    unique_ptr<Foo> up2(new Foo);

    Delete d;
    unique_ptr<Foo, Delete> up3(new Foo, d);
    unique_ptr<Foo, Delete &> up3b(new Foo, d);
    unique_ptr<Foo, Delete> up4(new Foo, Delete());
    unique_ptr<Foo> up5b(std::move(up2));
    unique_ptr<Foo, Delete> up6b(std::move(up3));

    unique_ptr<Foo> up7 = std::move(up5b);
    Foo *fp = up7.release();
    assert(up7.get() == nullptr);
    delete fp;

    up6b.reset(new Foo());
    up6b.reset(nullptr);

    unique_ptr<Fooo> up71(new Fooo(1));
    unique_ptr<Fooo> up72(new Fooo(2));

    up71.swap(up72);

    std::cout << "up71->val:" << up71->GetBar() << std::endl;
    std::cout << "up72->val:" << (up72.get())->GetBar() << std::endl;

    unique_ptr<Foo, D> up8(new Foo(), D());
    D &del = up8.get_deleter();
    del.bar();
  }
}