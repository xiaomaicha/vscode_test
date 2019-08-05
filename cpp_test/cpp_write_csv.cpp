//
// Created by wuqi on 19-6-6.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
  // 写文件
  ofstream outFile("data.csv");
//    outFile.open("data.csv", ios::out); // 打开模式可省略
  outFile << "name" << ',' << "age" << ',' << "hobby" << endl;
  outFile << "Mike" << ',' << 18 << ',' << "paiting" << endl;
  outFile << "Tom" << ',' << 25 << ',' << "football" << endl;
  outFile << "Jack" << ',' << 21 << ',' << "music" << endl;
//    outFile.close();

  // 读文件
  ifstream inFile("data.csv", ios::in);
  string lineStr;
  vector<vector<string>> strArray;
  while (getline(inFile, lineStr)) {
    // 打印整行字符串
    cout << lineStr << endl;
    // 存成二维表结构
    stringstream ss(lineStr);
    string str;
    vector<string> lineArray;
    // 按照逗号分隔
    while (getline(ss, str, ','))
      lineArray.push_back(str);
    strArray.push_back(lineArray);
  }

//  ifstream infile("data.csv", ios::in);
//  string linestr;
//  vector<vector<string>> strarry;
//
//  while (getline(infile, linestr)) {
//    stringstream ss(linestr);
//    string str;
//    vector<string> linearry;
//    while (getline(ss, str, ',')) {
//      linearry.push_back(str);
//    }
//    strarry.push_back(linearry);
//  }

  getchar();
  return 0;
}