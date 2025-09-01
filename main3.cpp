#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

const int N = 1005;
using ii = pair<int,int>;
using i3 = pair<ii,int>;

int matriz[N][N];
bool vs[N][N];


int main() {
  int n,q;
  cin >> n >> q;

  queue<i3> que;

  for (int i=0;i<n;i++) {
    int x,y;
    cin >> x >> y;
    que.push({{x,y}, 0});
    vs[x][y]=1;
  }

  int dirx[] = {-1,-1,-1,0,0,1,1,1};
  int diry[] = {-1,0,1,-1,1,-1,0,1};

  while (!que.empty()) {
    auto elem = que.front();
    que.pop();
    for (int i=0;i<8;i++) {
      int _x = elem.F.F + dirx[i];
      int _y = elem.F.S + diry[i];
      if (0 < _x && _x < 1001 && 0 < _y && _y < 1001) {
        if (!vs[_x][_y]) {
      vs[_x][_y]=1;
          matriz[_x][_y] = elem.S+1;
          que.push({{_x,_y},elem.S+1});
        }
      }
    }
  }

  for (int i=0;i<q;i++) {
    int x,y;
    cin >>x >> y;
    cout << matriz[x][y] << "\n";
  }
  // aqui hacer las queries
  return 0;
}