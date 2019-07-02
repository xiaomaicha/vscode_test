//
// Created by wuqi on 19-6-27.
//

#include "cpp_class_static_function.h"

using namespace std;
int cpp_class_static_function::staitc_var_a_ = 20;

int main() {
  cpp_class_static_function cpp_obj1{};
  int a, b, c;
  a = cpp_class_static_function::staitc_var_a_;
  cout<<"a: "<<a<<endl;

  b = cpp_class_static_function::get_static_var_a();
  cout<<"b: "<<b<<endl;

  c = cpp_obj1.modify_var();
  cout<<"c: "<<c<<endl;


}