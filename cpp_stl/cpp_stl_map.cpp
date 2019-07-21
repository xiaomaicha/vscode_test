//
// Created by wuqi on 19-7-14.
//

#include <map>
#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;

int main() {
  map<int, string> map1;
  map1[0] = "wuqi";

  auto pair1 = make_pair(1, "student_one");
  auto pair2 = pair<int, string>(1, "student_one");

  list<int> list1;

  vector<int> vector1;
  vector1.reserve(8);
  return EXIT_SUCCESS;
}