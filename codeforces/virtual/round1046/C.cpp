#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  vector<vector<int>> nums(n+1,vector<int>());
  vector<int> ans(n+1);
  ans[n] = 0;
  for (int i=n-1;i>=0;i--) {
    nums[a[i]].push_back(i);
    ans[i] = ans[i+1];
    if (nums[a[i]].size()>=a[i]) {
      int sz = nums[a[i]].size() - a[i];
      ans[i] = max(ans[i], ans[nums[a[i]][sz] + 1] + a[i]);
    }
  }
  cout << ans[0] << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}