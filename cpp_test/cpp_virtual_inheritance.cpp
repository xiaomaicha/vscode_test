////
//// Created by wuqi on 19-7-2.
////
//
//#include<iostream>
//using namespace std;
//
//class A  //大小为4
//{
//public:
//  A(){
//    cout<<"A CONTRUCT"<<endl;
//  }
//  int a;
//};
//class B :virtual public A  //大小为12，变量a,b共8字节，虚基类表指针4
//{
//public:
//  B(){
//    cout<<"B CONTRUCT"<<endl;
//  }
//  int b;
//};
//class C :virtual public A //与B一样12
//{
//public:
//  C(){
//    cout<<"C CONTRUCT"<<endl;
//  }
//  int c;
//};
//class D :public B, public C //24,变量a,b,c,d共16，B的虚基类指针4，C的虚基类指针
//{
//public:
//  D(){
//    cout<<"D CONTRUCT"<<endl;
//  }
//  int d;
//};
//
//int main()
//{
//  A a;
//  B b;
//  C c;
//  D d;
//  cout << sizeof(a) << endl;
//  cout << sizeof(b) << endl;
//  cout << sizeof(c) << endl;
//  cout << sizeof(d) << endl;
//  system("pause");
//  return 0;
//}

/**
	虚继承（虚基类）
*/

#include <iostream>

// 基类A
class A
{
public:
  int dataA;
};

class B : virtual public A
{
public:
  int dataB;
};

class C : virtual public A
{
public:
  int dataC;
};

class D : public B, public C
{
public:
  int dataD;
};

int main()
{
  D* d = new D;
  d->dataA = 10;
  d->dataB = 100;
  d->dataC = 1000;
  d->dataD = 10000;

  B* b = d; // 转化为基类B
  C* c = d; // 转化为基类C
  A* fromB = (B*) d;
  A* fromC = (C*) d;

  std::cout << "d address    : " << d << std::endl;
  std::cout << "b address    : " << b << std::endl;
  std::cout << "c address    : " << c << std::endl;
  std::cout << "fromB address: " << fromB << std::endl;
  std::cout << "fromC address: " << fromC << std::endl;
  std::cout << std::endl;

  std::cout << "vbptr address: " << (int*)d << std::endl;
  std::cout << "    [0] => " << *(int*)(*(int*)d) << std::endl;
  std::cout << "    [1] => " << *(((int*)(*(int*)d)) + 1)<< std::endl; // 偏移量20
  std::cout << "dataB value  : " << *((int*)d + 1) << std::endl;
  std::cout << "vbptr address: " << ((int*)d + 2) << std::endl;
  std::cout << "    [0] => " << *(int*)(*((int*)d + 2)) << std::endl;
  std::cout << "    [1] => " << *((int*)(*((int*)d + 2)) + 1) << std::endl; // 偏移量12
  std::cout << "dataC value  : " << *((int*)d + 3) << std::endl;
  std::cout << "dataD value  : " << *((int*)d + 4) << std::endl;
  std::cout << "dataA value  : " << *((int*)d + 5) << std::endl;
}