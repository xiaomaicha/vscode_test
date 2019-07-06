//
// Created by wuqi on 19-7-4.
//

#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int speed[10010];//作业时间
int mintime[101];//存放添加作业后完成的时间
bool cmp(const int &x, const int &y) {
  return x > y;//比较函数，求较大值
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int m, n;
    memset(speed, 0, sizeof(speed));//将函数清空
    memset(mintime, 0, sizeof(mintime));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> speed[i];
    }
    sort(speed, speed + n, cmp);//对speed数组进行降序排序
    for (int i = 0; i < n; ++i) {
      *min_element(mintime, mintime + m) += speed[i];//m是机器数，依次对m台机器添中最小的加speed
    }
    cout << *max_element(mintime, mintime + m) << endl;//求mintime数组中的最大值（所有作业都已完成的时间）
  }
  return 0;
}