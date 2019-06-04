//
// Created by wuqi on 19-6-5.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

void readTxt(string &file) // 逐行读入
{
    ifstream infile;
    infile.open(file.data());   //将文件流对象与文件连接起来
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行

    string s;
    while(getline(infile,s))
    {
        cout<<s<<endl;
    }
    infile.close();             //关闭文件输入流
}

void readTxt_2(string file) //逐个字符读入（忽略空格与回车)
{
    ifstream infile;
    infile.open(file.data());   //将文件流对象与文件连接起来
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行

    char c;
    while (!infile.eof())
    {
        infile >> c;
        cout<<c<<endl;

    }
    infile.close();             //关闭文件输入流
}

void readTxt_3(string file){ //逐个字符读入（包括空格与回车）
    ifstream infile;
    infile.open(file.data());   //将文件流对象与文件连接起来
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行

    char c;
    infile >> noskipws;
    while (!infile.eof()) {
        infile >> c;
        cout << c << endl;

    }
    infile.close();             //关闭文件输入流
}

int main(){
    string file = "/home/wuqi/momenta/dms_model/cornercase_pic/all_data_clip/light.txt";
    readTxt(file);
    return 0;
}