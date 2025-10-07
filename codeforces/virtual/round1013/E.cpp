#include <bits/stdc++.h>
using namespace std;
const int N = 10000001;
int dp[N];
long long freq[N];
void solve() {
  int n;
  cin >> n;
  cout<<freq[n]<<"\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  for (int i=2;i<N;i++) if (dp[i]==0) {
    for (int j=i;j<N;j+=i) dp[j]++;
  }
  for (int i=2;i<N;i++) freq[i]=freq[i-1]+dp[i];
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}