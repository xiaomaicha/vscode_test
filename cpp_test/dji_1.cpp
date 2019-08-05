////
//// Created by wuqi on 19-8-4.
//



#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<int, int> dijistra_distance(unordered_map<int, vector<vector<int >>> &grapgh,
                                          int vertex,
                                          int src,
                                          int targ = 1) {
  unordered_set<int> visited;
  unordered_map<int, int> distancemap;
  for (int i = 0; i < vertex; ++i) {
    if (i != src) {
      distancemap[i] = INT32_MAX;
    }
  }
  visited.insert(src);
  for (auto edge:grapgh[src]) {
    distancemap[edge[0]] = edge[1];
  }

  for (int j = 0; j < vertex; ++j) {
    if (j == src)
      continue;
    int mindisfromstart = INT32_MAX;
    int mindisindex = -1;
    if (!visited.count(j) && distancemap[j] < mindisfromstart) {
      mindisfromstart = distancemap[j];
      mindisindex = j;
    }

    if (mindisindex == -1)
      break;

    visited.insert(mindisindex);
    for (auto edge:grapgh[mindisindex]) {
      if (visited.count(edge[0]))
        continue;
      int predis = distancemap[edge[0]];
      if (edge[1] != INT32_MAX && mindisfromstart + edge[1] < predis) {
        distancemap[edge[0]] = mindisfromstart + edge[1];
      }
    }
  }
  return distancemap;
}

int main() {

  while (true) {
    int n, p, c;
    cin >> n >> p >> c;

    unordered_map<int, vector<vector<int>>> graph_s1;
    vector<int> destination;
    for (int i = 0; i < p; ++i) {
      int a, b, t;
      cin >> a >> b >> t;
      graph_s1[a].push_back({b, t});
      graph_s1[b].push_back({a, t});
    }

    for (int j = 0; j < c; ++j) {
      int des;
      cin >> des;
      destination.push_back(des);
    }

    auto res = dijistra_distance(graph_s1, n, 0);

    int res_sum = 0;
    for (int des: destination) {
      res_sum += res[des];
    }
    cout << res_sum << endl;
//    string number;
//    getline(cin, number);
    getchar();
    if ((getchar() == '\n')) {
      break;
    }
  }

  return 0;
}




//
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
////bool mycomp(pair<int , pair<int, int>>& p1, pair<int , pair<int, int>>& p2)
////{
////  return  p1.first/p1.second.first > p2.first/p2.second.first;
////}
//
//struct mycomp{
//  bool operator()(pair<int , pair<int, int>> p1, pair<int , pair<int, int>> p2) const
//  {
//    return p1.first/p1.second.first > p2.first/p2.second.first;;
//  }
//};
//
//
//int MaxSatify(vector<pair<int , pair<int, int>>>& objects,  int& money)
//{
//  int result = 0;
//  sort(objects.begin(), objects.end(), mycomp());
//
//  if(money < objects[0].second.first)
//    return 0;
//
//  for(auto object: objects)
//  {
//    while(object.second.second>0 && money>object.second.first)
//    {
//      money = money - object.second.first;
//      object.second.second--;
//      result +=  (int)object.first;
//    }
//    if(money < objects.back().second.first)
//      return result;
//  }
//  return  result;
//}
//
//
//int main()
//{
//
//  vector<pair<int , pair<int, int>>> objects;
//
//  int numbers;
//  int money;
//  cin >> numbers >> money;
//
//  for(int i=0; i<numbers; i++)
//  {
//    int a,b,c;
//    double d;
//    cin >> a >> b >> c;
//    pair<int , pair<int, int>> temp;
//    temp = make_pair(b, make_pair(a, c));
//    objects.push_back(temp);
//  }
//
//  cout << MaxSatify(objects, money);
//
//  return 0;
//}
