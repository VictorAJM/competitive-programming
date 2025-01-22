#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  int cnt = 0;
  for (int i:a) if (i%2==0) cnt=1;
  if (cnt==0) {
    cnt--;
  }
  for (int i:a) if (i%2==1) cnt++;
  cout << max(cnt,0) << "\n";
  return;
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}