#include <bits/stdc++.h>
const int inf = 1e9;
using namespace std;
int getDist(pair<int,int> a, pair<int,int> b) {
  int x = a.first-b.first;
  int y = a.second-b.second;
  return x*x + y*y;
}
int dist[25][25];
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  pair<int,int> org;
  cin >> org.first >> org.second;
  int n;
  cin >> n;
  vector<pair<int,int>> a(n);
  
  for(auto& p : a) cin >> p.first >> p.second;
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
    if (i==j) dist[i][j] = dist[j][i] = getDist(a[i], org);
    else dist[i][j] = dist[j][i] = getDist(a[i], a[j]); 
  }
  vector<int> dp((1<<n));
  vector<int> next((1<<n));
  vector<int> cur((1<<n));
  dp[0] = 0;
  next[0] = -1;
  cur[0]=-1;
  vector<int> f((1<<(n+1)));
  for (int i=0;i<=n;i++) {
    f[(1<<i)] = i;
  }
  for (int i=1;i<(1<<n);i++) {
    int m = (i&(-i));
    dp[i] = inf;
    m = f[m];
    cur[i]=m;
    for (int j=0;j<n;j++) if ((i&(1<<j)) > 0) {
      if (dp[i-((1<<j) | (1<<m))] + dist[j][m] < dp[i]) {
        dp[i] = dp[i-((1<<j) | (1<<m))] + dist[j][m];
        next[i] = j;
      }
    }
  }
  int ans = 0;
  for (auto u : a) {
    ans += getDist(u, org);
  }
  
  cout << dp[(1<<n)-1]+ans<<"\n";
  cout<<"0 ";
  int pos = (1<<n)-1;
  while (pos>0) {
    int x = next[pos];
    if (x==cur[pos]) {
      cout<<x+1<<" 0 ";
    } else {
      cout<<cur[pos]+1<<" "<<x+1<<" 0 ";
    }
    pos -= ((1<<x) | (1<<cur[pos]));
  }
  return 0;
}