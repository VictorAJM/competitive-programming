#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

using ii = pair<int,int>;

int n;
char a[3005][3005];
bool vs[3005][3005];
string ans;
vector<ii> cur;

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) cin >> a[i][j];
  cur.push_back({0, 0});
  while ((int)ans.size() < n+n-1) {
    char aux = 'Z';
    for (auto u : cur) aux = min(aux, a[u.F][u.S]);
    vector<ii> cop;
    ans.push_back(aux);
    for (auto u : cur) if (a[u.F][u.S] == aux) cop.push_back(u);
    cur.clear();
    for (auto u : cop) {
      if (u.F+1 < n && vs[u.F+1][u.S]==0) {
        cur.push_back({u.F+1, u.S});
        vs[u.F+1][u.S]=1;
      } 
      if (u.S+1<n && vs[u.F][u.S+1]==0) {
        cur.push_back({u.F, u.S+1});
        vs[u.F][u.S+1]=1;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}