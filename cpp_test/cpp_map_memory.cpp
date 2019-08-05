//
// Created by wuqi on 19-8-2.
//

/*
功能说明：
    map的内存分配机制分析。
代码说明：
    map所管理的内存地址可以是不连续的。如果key是可以通过<排序的，那么，map最后的结果是有序的。它是通过一个平衡二叉树来保存数据。所以，其查找效率极高。
实现方式：

限制条件或者存在的问题：
    无
*/
#include <iostream>
#include <string>
#include <map>

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

  cout << "push CData to map" << endl;
  map<int,CData> map_data;
  cout << "max size of list<CData> is " << map_data.max_size() << endl;
  cout << "size of list<CData> is " << map_data.size() << endl;

  cout << "****************map_data.push_back(data1)" << endl;
  map_data.insert(make_pair(1, data1));
  usleep(2 * map_data.size());

  cout << "****************map_data.push_back(data2)" << endl;
  map_data.insert(make_pair(2, data2));
  usleep(2 * map_data.size());

  cout << "****************map_data.push_back(data3)" << endl;
  map_data.insert(make_pair(3, data3));
  usleep(2 * map_data.size());

  cout << "****************map_data.push_back(data4)" << endl;
  map_data.insert(make_pair(4, data4));
  usleep(2 * map_data.size());

  cout << "****************map_data.push_back(data5)" << endl;
  map_data.insert(make_pair(5, data5));
  usleep(2 * map_data.size());

  cout << "****************map_data.push_back(data6)" << endl;
  map_data.insert(make_pair(6, data6));
  usleep(2 * map_data.size());

  cout << "****************map_data.push_back(data7)" << endl;
  map_data.insert(make_pair(7, data7));
  usleep(2 * map_data.size());

  cout << "****************map_data.push_back(data8)" << endl;
  map_data.insert(make_pair(8, data8));
  usleep(2 * map_data.size());

  cout << "****************map_data.push_back(data9)" << endl;
  map_data.insert(make_pair(9, data9));
  usleep(2 * map_data.size());

  cout << "****************map_data.push_back(data10)" << endl;
  map_data.insert(make_pair(10, data10));
  usleep(2 * map_data.size());

  // 程序到此为止，可以看到在每次push的时候，对象的复制构造函数会调用2次。为什么是2次？
  cout << "===============show map by iterator" << endl;
  for (map<int,CData>::iterator itr = map_data.begin(); itr != map_data.end(); itr++)
  {
    // 显示的地址信息，是每次push的时候所复制的对象的地址。
    cout<<"key:"<< itr->first<<"\t" << "value:address of itr is " << &(itr->second) << " and msg is " << itr->second.toString() << endl;
  }

  cout << "===============clear map 1" << endl;
  // map中的元素不是指针，此处的清理，会调用析构函数。
  map_data.clear();

  cout << "****************map_data.push_back(data6)" << endl;
  map_data.insert(make_pair(6, data6));
  usleep(2 * map_data.size());

  cout << "****************map_data.push_back(data2)" << endl;
  map_data.insert(make_pair(2, data2));
  usleep(2 * map_data.size());

  cout << "****************map_data.push_back(data3)" << endl;
  map_data.insert(make_pair(3, data3));
  usleep(2 * map_data.size());

  cout << "****************map_data.push_back(data1" << endl;
  map_data.insert(make_pair(1, data1));
  usleep(2 * map_data.size());

  cout << "****************map_data.push_back(data10)" << endl;
  map_data.insert(make_pair(10, data10));
  usleep(2 * map_data.size());

  cout << "****************map_data.push_back(data4)" << endl;
  map_data.insert(make_pair(4, data4));
  usleep(2 * map_data.size());

  cout << "****************map_data.push_back(data7)" << endl;
  map_data.insert(make_pair(7, data7));
  usleep(2 * map_data.size());

  cout << "****************map_data.push_back(data8)" << endl;
  map_data.insert(make_pair(8, data8));
  usleep(2 * map_data.size());

  cout << "****************map_data.push_back(data9)" << endl;
  map_data.insert(make_pair(9, data9));
  usleep(2 * map_data.size());

  cout << "****************map_data.push_back(data5)" << endl;
  map_data.insert(make_pair(5, data5));
  usleep(2 * map_data.size());

  // 程序到此为止，可以看到在每次push的时候，对象的复制构造函数会调用2次。为什么是2次？
  cout << "===============show map by iterator 2" << endl;
  for (map<int, CData>::iterator itr = map_data.begin(); itr != map_data.end(); itr++)
  {
    // 显示的地址信息，是每次push的时候所复制的对象的地址。
    // 可以看到，不管插入的数据是如何的乱序，map的结果是排好序的。
    cout << "key:" << itr->first << "\t" << "value:address of itr is " << &(itr->second) << " and msg is " << itr->second.toString() << endl;
  }

  cout << "===============clear map 2" << endl;
  // map中的元素不是指针，此处的清理，会调用析构函数。
  map_data.clear();

  cout << "======================end of process" << endl;

  return 0;
}