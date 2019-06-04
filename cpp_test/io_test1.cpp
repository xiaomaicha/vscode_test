#include<iostream>
#include<vector>
using namespace std;

int main()
{
    float num;
    char ch;
    vector<float> list;
    cout<<"please input some numbers:"<<endl;
    //cin.get(ch);
     cout<<"input 0 to finsh!"<<endl;
     cin>>num;
     /*c++的输入流>>会将输入的输入数据先存进数据缓冲区，等待用户输入了回车，
     随后才会从合缓冲区依次读取数据，从第一个非空白字符开始，到与目标类型不符
     的第一个字符之间的内容，输入给第一个变量，接着进行下一个，直到到最后一个
     非法输入输入为止，依次输入给变量*/
     /*
     cin>>会跳过空白符（空格，换行，制表符）;
     cin.get(char),cin.get(void)会读取用户输入的每一个字符，包括空格；
     cin.getline()用于输入字符串。
     */
    while(num != 0)
    {
       
       //cout<<num<<endl;
       list.push_back(num);
       cin>>num;
        //cin.get(ch);
       
    }
    for(int i=0; i<list.size();i++)
    {
        cout<<list.at(i)<<endl;
    }

    return 0;


}