#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ii = pair<int,int>;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m));
  vector<vector<int>> dist1(n, vector<int>(m, INT_MAX));
  vector<vector<int>> dist2(n, vector<int>(m, INT_MAX));
  vector<vector<int>> reach(n, vector<int>(m, -1));
  vector<vector<char>> path(n, vector<char>(m, '.'));
  queue<pair<ii, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'A') {
        dist1[i][j] = 0;
        q.push({{i, j}, 0});
      } else if (grid[i][j] == 'M') {
        dist2[i][j] = 0;
        q.push({{i, j}, -1});
      }
    }
  }
  vector<ii> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  while (!q.empty()) {
    auto [p, d] = q.front();
    q.pop();
    int x = p.F, y = p.S;
    for (auto [dx, dy] : dir) {
      int nx = x + dx, ny = y + dy;
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (grid[nx][ny] == '#') continue;
      if (d == -1 && dist2[nx][ny] == INT_MAX) {
        dist2[nx][ny] = dist2[x][y] + 1;
        q.push({{nx, ny}, -1});
      } else if (d == 0 && dist1[nx][ny] == INT_MAX) {
        dist1[nx][ny] = dist1[x][y] + 1;
        q.push({{nx, ny}, 0});
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dist1[i][j] < dist2[i][j]) {
        reach[i][j] = dist1[i][j];
        if (reach[i][j] == 0) {
          q.push({{i, j}, 0});
        }
      }
    }
  }
  char a[4] = {'U', 'D', 'L', 'R'};
  while (!q.empty()) {
    auto [p, d] = q.front();
    q.pop();
    int x = p.F, y = p.S;
    int cnt = 0;
    if (x==0 || x==n-1 || y==0 || y==m-1) {
      cout << "YES\n" << reach[x][y] << "\n";
      int xx = x, yy = y;
      string ans = "";
      int len = reach[x][y];
      while (len--) {
        ans += path[xx][yy];
        if (path[xx][yy] == 'U') xx++;
        else if (path[xx][yy] == 'D') xx--;
        else if (path[xx][yy] == 'L') yy++;
        else if (path[xx][yy] == 'R') yy--;
      }
      reverse(ans.begin(), ans.end());
      cout << ans << "\n";

      return 0;
    }
    for (auto [dx, dy] : dir) {
      cnt++;
      int nx = x + dx, ny = y + dy;
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (grid[nx][ny] == '#') continue;
      if (reach[nx][ny] == reach[x][y] + 1) {
        path[nx][ny] = a[cnt - 1];
        q.push({{nx, ny}, 0});
      }
    }
  }
  cout << "NO\n";
}