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
  int get_object_a() {
    return object_a;
  }
private:
  int object_a;
};

class Base {
public:
  Base() : base_a_(2), object_(2), const_a(1) {
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

void class_function(Base ins) {
  //会利用拷贝构造函数初始化形参；
  cout << "instance value:" << ins.get_base_a() << endl;
}

//方法一， 形参给出第二维的长度。
void test_array_dim_2_1(int array_dim_2[][2]) {
  cout << "transfer success" << endl;
}

//方法二，形参声明为指向数组的指针。
void test_array_dim_2_2(int (*array_dim_2)[2]) {
  cout << "transfer success" << endl;
}

//方法三，形参声明为指针的指针。
// 这种方法在取值的时候有一定的要求
void test_array_dim_2_3(int **array_dim_2) {
  cout << "transfer success" << endl;
}

void test_ref_param_copy(Object &obj) {
  cout << "obj:" << obj.get_object_a()<<endl;
}

int main() {
  Object obj = Object(2);
  test_ref_param_copy(obj);
  Object *obj_ptr = &obj;
  cout<<"----------------"<<endl;
  Base *base_ptr = new Derived();
  int obj_a = base_ptr->get_base_a();
  cout << "obj_a:" << obj_a << endl;

  class_function(*base_ptr);

  cout<<"----------------"<<endl;

  int array_dim_2[][2] = {1, 2, 1, 2};
  test_array_dim_2_2(array_dim_2);
  return 0;
}