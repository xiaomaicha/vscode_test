//
// Created by wuqi on 19-7-13.
//

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Base {
public:

  explicit Base(int i) : baseI(i) {};

  virtual void print() { cout << "调用了虚函数Base::print()"; }

  virtual void setI() { cout << "调用了虚函数Base::setI()"; }

  virtual ~Base() = default;

private:

  int baseI;

};

int main() {
  Base base(100);
  int *vptrAdree = (int *) (&base);
  cout << "虚函数指针（vprt）的地址是：\t" << vptrAdree << endl;

  using FUNC = void (*)();
  FUNC vfunc = (FUNC) *(int *) (*(int *) (&base));
  vfunc();

  return EXIT_SUCCESS;
}
