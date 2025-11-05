#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

using ii = pair<int,int>;

int n,m;
vector<string> a;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void solve() {
  cin >> n >> m;
  a.clear();
  a.resize(n);
  for (int i=0;i<n;i++)cin >> a[i];
  int Lx, Ly;
  for (int i=0;i<n;i++) for (int j=0;j<m;j++)
    if (a[i][j]=='L') Lx = i, Ly = j;
  
  auto inside = [&](int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
  };

  vector<vector<int>> d(n, vector<int>(m, 0));
  for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (a[i][j] == '.') {
    for (int k=0;k<4;k++) {
      int _x = i + dx[k];
      int _y = j + dy[k];
      d[i][j] += inside(_x, _y) && a[_x][_y] != '#';
    }
  }
  queue<ii> q;
  vector<vector<char>> used(n, vector<char>(m, 0));
  q.push({Lx, Ly});
  used[Lx][Ly] = 1;
  while (!q.empty()) {
    int x = q.front().F;
    int y = q.front().S;
    q.pop();
    for (int k=0;k<4;k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (!inside(nx, ny) || a[nx][ny] == '#' || used[nx][ny]) continue;
      d[nx][ny]--;
      if (d[nx][ny] <= 1) {
        used[nx][ny] = 1;
        q.push({nx, ny});
      }
    }
  }

  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) if (a[i][j] == '.' && used[i][j]) a[i][j] = '+';
    cout << a[i] << "\n";
  }
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}