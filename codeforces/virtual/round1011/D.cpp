#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<int,int>;

void solve() {
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  int cnt=0, tot=0;
  priority_queue<int,vector<int>,greater<int>> pq;
  long long ans = 0;
  for (int i=n-1;i>=0;i--) {
    if (cnt/k > tot) {
      ans += a[i];
      pq.push(a[i]);
      tot++;
    } else {
      cnt++;
      if (!pq.empty() && a[i]>pq.top()) {
        ans -= pq.top();
        ans+=a[i];
        pq.pop();
        pq.push(a[i]);
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}