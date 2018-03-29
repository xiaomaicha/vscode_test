#include <iostream>
#include <boost/signals2.hpp>
#include <boost/bind.hpp>

using namespace std;
using namespace boost::signals2;

void slots1()
{
    cout<<"slots1 called"<<endl;
}

void slots2()
{
    cout<<"slots2 called"<<endl;
}

class A
{
public:
    static int staticMemberFunc(int param)
    {
        cout<<"A::staticMemberFunc called, param: "<<param<<endl;
        return 2;
    }
    int memberFunc(int param)
    {
        cout<<"A::memberFunc called, param: "<<param<<endl;
        return 4;
    }
};

int main()
{
    boost::signals2::signal<void()> sig;
    boost::signals2::signal<int(int)> sig2;

    A a;
    connection c1 = sig.connect(&slots1);
    connection c2 =sig.connect(&slots2);
    cout<<"First call-------------------"<<endl;
    sig();
    if (c2.connected())
    {
        c2.disconnect();
    }
    cout<<"Second call-------------------"<<endl;
    sig();

    connection c3 =sig2.connect(&A::staticMemberFunc);// 绑定成员函数
    connection c4 =sig2.connect(boost::bind(&A::memberFunc, &a, _1));// 绑定静态成员函数

    cout<<"Return code is: "<<*sig2(44)<<endl;// 只能返回最后被调用的插槽的返回值
    return 0;
}