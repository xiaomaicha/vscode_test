//
// Created by wuqi on 19-6-30.
//

#include <iostream>
#include <vector>

using namespace std;

class Object {
public:
  explicit Object(int obj_a) : object_a(obj_a) {
    cout << "construct Object" << endl;
  }

  Object(const Object &ths) {
    cout << "copy construct Object" << endl;
    this->object_a = ths.object_a;
  }

  Object &operator=(const Object &ths) {
    cout << "assignment construct Object" << endl;
    this->object_a = ths.object_a;
  }
private:
  int object_a;
};

class Base {
public:
  Base() : base_a_(2), object_(2), const_a(1){
    cout << "construct Base" << endl;
  }
public:
  virtual int get_base_a() {
    return base_a_;
  }
protected:
  int base_a_ = 1;
  Object object_;
  const int const_a;
private:
  int private_a;
};

class Derived : public Base {
public:
  Derived() : Base() {
    cout << "construct Derived" << endl;
  }
  int get_base_a() override {
    return base_a_ + 1;
  }
};

void class_function(Base ins){
  //会利用拷贝构造函数初始化形参；
  cout<<"instance value:"<<ins.get_base_a()<<endl;
}

int main() {
  Base *base_ptr = new Derived();
  int obj_a = base_ptr->get_base_a();
  cout << "obj_a:" << obj_a << endl;

  class_function(*base_ptr);
  return 0;
}