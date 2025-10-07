#include <bits/stdc++.h>
using namespace std;
int dp[505][505];
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string _aux;
  int inf = 10000;
  for (auto u : s) {
    if (_aux.size()>0 && _aux[_aux.size()-1]==u) continue;
    _aux.push_back(u);  
  }
  s = _aux;
  n = s.size();
  for (int i=0;i<n;i++) for (int j=0;j<n-i;j++) {
    dp[j][j+i] = inf;
    if (i>0) dp[j][j+i]= 1+dp[j+1][j+i];
    else dp[j][j+i] = 1;
    for (int k=j+1;k<=j+i;k++) {
      if (s[k]==s[j]) {
        int ans = 0;
        if (k<=j+i) ans += dp[k][j+i];
        if (j+1<=k-1) ans += dp[j+1][k-1];
        dp[j][j+i] = min(dp[j][j+i], ans);
      }
    }
  }
  cout << dp[0][n-1];
  return 0;
}