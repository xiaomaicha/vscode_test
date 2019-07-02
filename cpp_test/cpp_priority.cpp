//
// Created by wuqi on 19-6-28.
//

#include <iostream>
#include <queue>
using namespace std;
struct Node{
  int x, y;
  Node(int a=0, int b=0):
      x(a),y(b){}
};
bool operator<(Node a, Node b){//返回true时，说明a的优先级低于b
  //x值较大的Node优先级低（x小的Node排在队前）
  //x相等时，y大的优先级低（y小的Node排在队前）
  if( a.x== b.x ) return a.y> b.y;
  return a.x> b.x;
}
int main(){
  priority_queue<Node> q;
  for( int i= 0; i< 10; ++i )
    q.push( Node( rand(), rand() ) );
  while( !q.empty() ){
    cout << q.top().x << ' ' << q.top().y << endl;
    q.pop();
  }
  return 0;
}