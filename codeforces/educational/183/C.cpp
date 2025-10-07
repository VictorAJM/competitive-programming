#include <bits/stdc++.h>

using namespace std;

void solve() {
  map<int,int> m;
  int n;
  string s;
  
  cin >> n;
  cin >> s;
  m[0] = -1;
  int x=0,tot=0;
  for (int i=0;i<n;i++) {
    if (s[i]=='a') tot++;
    else tot--;
  }

  int ans = n;
  for (int i=0;i<n;i++) {
    if (s[i]=='a') x++;
    else x--;
    int aux = tot - x;
        m[x] = i;
    if (m.find(-aux) != m.end()) {
      ans = min(ans, i-m[-aux]);
    }



  }
  if (ans == n) ans=-1;
  cout << ans << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}