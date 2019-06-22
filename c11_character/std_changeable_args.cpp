//
// Created by wuqi on 19-6-16.
//

#include <iostream>

using namespace std;

void print(){
  cout<<"empty"<<endl;
}

template <class T, class ...args>
void print(T head, args... rest){
  cout<<"paramenter: "<<head<<endl;
  print(rest...);
}

int main(){
  print(1,2,3,4);
  return 0;
}