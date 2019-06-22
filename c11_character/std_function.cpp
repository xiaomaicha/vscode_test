#include <functional>
#include <iostream>

using namespace std;

function<int(float)> f;

std::function<int(int)> Functional;

// 普通函数
int TestFunc(int a) {
    return a;
}

// Lambda表达式
auto lambda = [](int a) -> int { return a; };

// 仿函数(functor)
class Functor {
public:
    int operator()(int a) {
        return a;
    }
};

// 1.类成员函数
// 2.类静态函数
class TestClass {
public:
    TestClass() : class_value_(2) {}

    int ClassMember(int a) {
        class_value_ = 3;
        return a;
    }

    static int StaticMember(int a) { return a; }

    int class_value_;
};

int main() {
// 普通函数
    Functional = TestFunc;
    int result = Functional(10);
    cout << "普通函数：" << result << endl;

// Lambda表达式
    Functional = lambda;
    result = Functional(20);
    cout << "Lambda表达式：" << result << endl;

// 仿函数
    Functor testFunctor;
    Functional = testFunctor;
    result = Functional(30);
    cout << "仿函数：" << result << endl;

// 类成员函数
    TestClass testObj;
    Functional = std::bind(&TestClass::ClassMember, ref(testObj), std::placeholders::_1);
    cout << "class_value_:" << testObj.class_value_<<endl;
    result = Functional(40);
    cout << "类成员函数：" << result << endl;
    cout << "class_value_:" << testObj.class_value_<<endl;

// 类静态函数
    Functional = TestClass::StaticMember;
    result = Functional(50);
    cout << "类静态函数：" << result << endl;

    return 0;
}