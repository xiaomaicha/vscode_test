//
// Created by wuqi on 19-7-3.
//

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

struct Action {
  function<int()> func_;
  int operator()() {
    return func_();
  }
};

class Lambda_region {
public:
  Lambda_region() : lambda_a_(1),
                    action_{[this] { return get_lambda_a(); }} {}

  int get_lambda_a() {
    return lambda_a_;
  }

  void ste_lambda_a(int &a) {
    lambda_a_ = a;
  }

  void demon_lambda() {
    int a = action_();
    cout << "lambda_a: " << a << endl;
  }

private:
  int lambda_a_;
  Action action_;
};

int main() {
  Lambda_region lambda_obj;

  for (int i = 0; i < 100; ++i) {
    lambda_obj.ste_lambda_a(i);
    lambda_obj.demon_lambda();
  }

  int a = 0;
  auto f1 = [=]()  mutable {
    return ++a;
  };
  cout << "f1:" << f1() << endl;
  return 0;
}