//
// Created by wuqi on 19-6-27.
//

#ifndef VS_TEST_CPP_TEST_CPP_CLASS_STATIC_FUNCTION_H
#define VS_TEST_CPP_TEST_CPP_CLASS_STATIC_FUNCTION_H

#include <iostream>
#include <vector>
#include <string>

class cpp_class_static_function {
public:
  cpp_class_static_function() : var_a_(1),
                                var_b_(2) {};

  int modify_var() {
    static int staitc_var_a = get_static_var_a();
    return var_a_ + var_b_;
  }

  static int get_static_var_a() {
    return staitc_var_a_;
  }

  int const_function() const {
    std::cout<<"const var: "<<var_a_<<std::endl;
  }

  static int staitc_var_a_;

private:
  int var_a_;
  int var_b_;
};

#endif //VS_TEST_CPP_TEST_CPP_CLASS_STATIC_FUNCTION_H
