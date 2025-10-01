#include <bits/stdc++.h>
using namespace std;

char a[505][505];
char b[505][505];

int main() {
  int n,m;
  cin >> n >> m;
  for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >> a[i][j];

  for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
    set<char> s;
    s.insert('A'); s.insert('B'); s.insert('C'); s.insert('D');
    if (i) s.erase(b[i-1][j]);
    if (j) s.erase(b[i][j-1]);
    s.erase(a[i][j]);
    b[i][j] = *s.begin();
  }
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) cout << b[i][j];
    cout << "\n";
  }
  return 0;
}