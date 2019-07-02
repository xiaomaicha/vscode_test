//
// Created by wuqi on 19-6-23.
//

#ifndef VS_TEST_CPP_FUNCTON_TEST_THIRD_SAMPLE_H
#define VS_TEST_CPP_FUNCTON_TEST_THIRD_SAMPLE_H
#include <iostream>
#include <string>
#include <vector>

namespace third_sample {
static int third_sample_add(int a, int b){
  return a + b;
}

template<typename T>
void print2nd(const T &container) {
  typename T::const_iterator iter(container.begin()); //未加typename, 报错
  ++iter;
  int value = *iter;
  std::cout << value;
}

}

#endif //VS_TEST_CPP_FUNCTON_TEST_THIRD_SAMPLE_H
