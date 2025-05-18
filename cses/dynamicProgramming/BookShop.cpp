#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> x(n), p(n);
  for (int i=0;i<n;i++) cin >> x[i];
  for (int i=0;i<n;i++) cin >> p[i];
  vector<int> dp(m+1),aux(m+1);
  for (int i=0;i<n;i++) {
    for (int j=0;j<=m;j++) {
      aux[j] = dp[j];
      if (j>=x[i]) aux[j] = max(aux[j], dp[j-x[i]]+p[i]);
    }
    for (int j=0;j<=m;j++) dp[j] = aux[j], aux[j]=0;
  }
  cout << *max_element(dp.begin(), dp.end());
}