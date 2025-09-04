#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

using ll = long long;

void solve() {
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  int q=1;
  vector<int> ans(n);
  for (int i=0;i<n;i++) if (s[i]=='1') {
    ans[i] = q++;
  }
  int prev = 0;
  for (int i=0;i<n;i++) if (ans[i]>0) {
    prev++;
    if (prev>=k) {
      cout<<"NO\n";
      return;
    }
  } else {
    prev=0;
  }
  q=n;
  for (int i=0;i<n;i++) if (ans[i]==0) {
    ans[i] = q--;
  }
  cout << "YES\n";
  for (int i=0;i<n;i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}