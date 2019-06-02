#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <typeinfo> 
 
class MyNumber
{
public:
    MyNumber(const std::initializer_list<int> &v) {
        for (auto itm : v) {
            mVec.push_back(itm);
        }
    }
 
    void print() {
        for (auto itm : mVec) {
            std::cout << itm << " ";
        }
    }
private:
    std::vector<int> mVec;
};
 
class Test {
public:
    void show()
    {
        for(auto kv : nameToBirthday)
        {
            std::cout<<"key:\t"<<kv.first<<"\tvalue:\t"<<kv.second<<"\n";
        }
    }
private:
    static std::map<std::string, std::string> nameToBirthday;
};
std::map<std::string,std::string> Test::nameToBirthday  = {
    {"lisi", "18841011"},
    {"zhangsan", "18850123"},
    {"wangwu", "18870908"},
    {"zhaoliu", "18810316"}
};
 
class CompareClass 
{
public:
    CompareClass (int,int)
    {std::cout<<"call old const\n";}
    CompareClass (std::initializer_list <int> )
    {std::cout<<"call initializer_list const\n";}
};
 
 
int main()
{
    MyNumber m = { 1, 2, 3, 4 };
    m.print();  // 1 2 3 4
 
    Test t;
    t.show(); 
 
    std::map<int,int> ii_map = {{1,1},{2,2}};
 
    CompareClass foo {10,20};  // calls initializer_list ctor
    CompareClass bar (10,20);  // calls first constructor 
 
 
    for(auto kv : ii_map)
    {
        std::cout<<"key:\t"<<typeid(kv.first).name()<<"\n";
    }
    return 0;
}