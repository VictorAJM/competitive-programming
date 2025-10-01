#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

using ii = pair<int,int>;

void solve() {
  int n;
  cin >> n;
  queue<ii> q;
  q.push({0, 0});
  vector<int> a(n*n);
  vector<bool> vs(n*n);
  vs[0] = 1;

  int dirX[] = {1,1,2,2,-1,-1,-2,-2};
  int dirY[] = {2,-2,1,-1,2,-2,1,-1};

  while (!q.empty()) {
    auto x = q.front();
    q.pop();
    for (int i=0;i<8;i++) {
      int _x = x.F/n;
      int _y = x.F%n;
      _x += dirX[i];
      _y += dirY[i];
      if (0 <= _x && _x < n && 0 <= _y && _y < n && !vs[_x*n + _y]) {
        vs[_x*n + _y] = 1;
        a[_x*n + _y] = x.S+1;;
        q.push({_x*n + _y, x.S+1});
      } 
    } 
  }
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) cout << a[i*n + j] << " ";
    cout << "\n";
  }
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  solve();
  return 0;
}