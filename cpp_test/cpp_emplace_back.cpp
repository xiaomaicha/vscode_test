//
// Created by wuqi on 19-8-2.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Base {
public:
  Base(int base_a) : base_a_(base_a) {
    cout << "construct!" << endl;
  }
  Base(const Base & ths){
    base_a_ = ths.base_a_;
    cout<<"copy"<<endl;
  }
  Base(Base &&ths){
    base_a_ = ths.base_a_;
    cout<<"moving"<<endl;
  }
private:
  int base_a_;
};

class Foo {
public:
  Foo(std::string str) : name(str) {
    std::cout << "constructor" << std::endl;
  }
  Foo(const Foo& f) : name(f.name) {
    std::cout << "copy constructor" << std::endl;
  }
  Foo(Foo&& f) : name(std::move(f.name)){
    std::cout << "move constructor" << std::endl;
  }

private:
  std::string name;
};

int main(){
  vector<Foo> vec_foo;
  vec_foo.reserve(5);
  Foo tmp("abc");
  vec_foo.push_back(tmp);

//  Foo tmp_1("abc");
  vec_foo.emplace_back("abc");
  vec_foo.push_back({"abs"});

  std::move(vec_foo);
  return EXIT_SUCCESS;
}