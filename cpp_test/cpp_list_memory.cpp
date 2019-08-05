//
// Created by wuqi on 19-8-2.
//

/*
功能说明：
    list的内存分配机制分析。
代码说明：
    list所管理的内存地址可以是不连续的。程序在不断的push_back的过程中，程序仅会将操作的元素进行复制一份，保存到list中。通过复制构造函数和析构函数，可以看到这些操作。
实现方式：

限制条件或者存在的问题：
    无
*/
#include <iostream>
#include <string>
#include <list>
#include <unistd.h>

using namespace std;

class CData
{
public:
  CData()
  {
    sequence = 0;
    this->remark = "default string";

    cout << "CData()\t" << toString() << "\t" << this << endl;
  }

  CData(int i, string &s)
  {
    this->sequence = i;
    this->remark = s;

    cout << "CData(int i,string &s)\t" << toString() << "\t" << this << endl;
  }

  CData(const CData &data)
  {
    this->sequence = data.sequence;
    this->remark = data.remark;

    cout << "CData(const CData &data)\t" << toString() << "\t" << this << endl;
  }

  CData operator = (const CData &data)
  {
    this->sequence = data.sequence;
    this->remark = data.remark;

    cout << "CData operator = (const CData &data)\t" << toString() << "\t" << this << endl;

    return *this;
  }

  void setSequence(const int i)
  {
    this->sequence = i;
  }

  void setRemark(const string &s)
  {
    this->remark = s;
  }

  string toString() const
  {
    char tmp[2048] = { 0 };
    sprintf(tmp, "[sequence:%d | remark:%s]", this->sequence, this->remark.c_str());

    //此处应该有内存复制操作，所以不用担心返回后tmp数组所指向的内存被修改或者不存在的情况。
    return tmp;
  }

  ~CData()
  {
    cout << "~CData()\t" << this << endl;
  }
protected:
private:
  int sequence;
  string remark;
};

int main(int argc, char **argv)
{
  cout << "process begin at " << (void*)&main << endl;

  string str = "baby_test";
  CData data1(1, str);
  CData data2(2, str);
  CData data3(3, str);
  CData data4(4, str);
  CData data5(5, str);
  CData data6(6, str);
  CData data7(7, str);
  CData data8(8, str);
  CData data9(9, str);
  CData data10(10, str);

  cout << "push CData to list" << endl;
  list<CData> lst_data;
  cout << "max size of list<CData> is " << lst_data.max_size() << endl;
  cout << "size of list<CData> is " << lst_data.size() << endl;

  cout << "****************lst_data.push_back(data1)" << endl;
  lst_data.push_back(data1);
  usleep(2 * lst_data.size());

  cout << "****************lst_data.push_back(data2)" << endl;
  lst_data.push_back(data2);
  usleep(2 * lst_data.size());

  cout << "****************lst_data.push_back(data3)" << endl;
  lst_data.push_back(data3);
  usleep(2 * lst_data.size());

  cout << "****************lst_data.push_back(data4)" << endl;
  lst_data.push_back(data4);
  usleep(2 * lst_data.size());

  cout << "****************lst_data.push_back(data5)" << endl;
  lst_data.push_back(data5);
  usleep(2 * lst_data.size());

  cout << "****************lst_data.push_back(data6)" << endl;
  lst_data.push_back(data6);
  usleep(2 * lst_data.size());

  cout << "****************lst_data.push_back(data7)" << endl;
  lst_data.push_back(data7);
  usleep(2 * lst_data.size());

  cout << "****************lst_data.push_back(data8)" << endl;
  lst_data.push_back(data8);
  usleep(2 * lst_data.size());

  cout << "****************lst_data.push_back(data9)" << endl;
  lst_data.push_back(data9);
  usleep(2 * lst_data.size());

  cout << "****************lst_data.push_back(data10)" << endl;
  lst_data.push_back(data10);
  usleep(2 * lst_data.size());

  // 程序到此为止，可以看到在每次push的时候，对象的复制构造函数会调用一次。
  cout << "===============show list by iterator" << endl;
  for (list<CData>::iterator itr = lst_data.begin(); itr != lst_data.end(); itr++)
  {
    // 显示的地址信息，是每次push的时候所复制的对象的地址。
    cout << "address of itr is " << &(*itr) << "\tvalue is " << itr->toString() << endl;
  }

  cout << "===============clear list 1" << endl;
  // list中的元素不是指针，此处的清理，会调用析构函数。
  lst_data.clear();

  cout << "======================end of process" << endl;

  return 0;
}