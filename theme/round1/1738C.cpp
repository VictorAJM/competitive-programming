#include <bits/stdc++.h>

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rev(x) reverse(x)
#define pb(x) push_back(x)
#define sz(x) x.size()
#define FOR(i, a) for (int i=0;i<a;i++)

using namespace std;

const int N = 1e5+5;
const int mod = 1e9+7;

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
int dp[105][105][2][2];
bool vs[105][105][2][2];
bool f(int x, int y, int c, int t) {
  if (vs[x][y][c][t]) return dp[x][y][c][t];
  vs[x][y][c][t]=1;
  if (t==0) {
    bool flag=0;
    if (x>0) flag |=f(x-1,y,c,t^1);
    if (y>0) flag |=f(x,y-1,c^1,t^1);
    dp[x][y][c][t]=flag;
    return dp[x][y][c][t];
  } else {
    bool flag=1;
    if (x>0) flag &=f(x-1,y,c,t^1);
    if (y>0) flag &=f(x,y-1,c,t^1);
    dp[x][y][c][t]=flag;
    return dp[x][y][c][t];
  }
}
void solve() {
  int x=0,y=0;
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  for (int i:a) {
    if (i%2==0) x++;
    else y++;
  }
  for (int i=0;i<=x;i++) for (int j=0;j<=y;j++) {
    vs[x][y][0][0]=vs[x][y][0][1]=vs[x][y][1][0]=vs[x][y][1][1]=0;
  }
  dp[0][0][0][0]=dp[0][0][0][1]=1;
  dp[0][0][1][0]=dp[0][0][1][1]=0;
  vs[0][0][0][0]=vs[0][0][0][1]=vs[0][0][1][0]=vs[0][0][1][1]=1;
  cout << (f(x,y,0,0) ? "Alice" : "Bob") << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}