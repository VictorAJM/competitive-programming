#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
vector<int> primos[100005];
int n,m;
ll dp[55][100005],l[10005],r[10005];
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i=1;i<=m;i++) {
    int I = i;
    for (int j=2;j*j<=i;j++) {
      if (I%j==0) {
        primos[i].push_back(j);
      }
      while (I%j==0) I/=j;
    }
  }
  for (int i=1;i<=n;i++) cin >> l[i] >> r[i];
  for (int i=l[1];i<=r[1];i++) dp[1][i]++;
  
}