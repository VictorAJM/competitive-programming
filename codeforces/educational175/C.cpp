#include <bits/stdc++.h>
#define ve vector
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<int,int>;
bool ok(int mid, int k, ve<int>& a, string& s) {
  int n = a.size();
  string d;
  int cnt = 0;
  for (int i=0;i<n;i++) if (a[i]>mid) d.push_back(s[i]);
  for (int i=0;i<d.size();i++) {
    if (d[i]=='B') cnt++;
    if (i>0 && d[i]=='B' && d[i-1]=='B') cnt--;
  }
  return cnt <= k;
}
void solve() {
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  ve<int> a(n);
  for(int& i:a) cin >> i;
  int in = -1;
  int fi = 1000000000;
  while (in+1 < fi) {
    int mid = (in+fi)/2;
    if (ok(mid, k, a, s)) fi = mid;
    else in = mid;
  }
  cout << in+1 << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}