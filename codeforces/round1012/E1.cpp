#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int N = 2e5+5;
const int mod = 1e9+7;
using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n),b(n);
  for(int& i:a) cin >> i;
  for(int& i:b) cin >> i;
  for (int i=0;i<n;i++) {
    int t = min(a[i], b[i]);
    a[i]-=t;
    b[i]-=t;
  }
  int cnt =0;
  for (int i=0;i<n;i++) if (a[i]>0) cnt++;
  if (cnt==0) {
    cout<<"1\n";
    return;
  }
  vector<int> c(n);
  for (int i=0;i<n;i++) if (a[i] > 0) {
    g[i].push_back((i+1)%n);
    out[i]++;
  }
  
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}