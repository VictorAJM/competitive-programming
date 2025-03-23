#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int N = 2e5+5;
const int mod = 1e9+7;
using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
vi p;
bool vs[N];
void solve() {
  int n;
  cin >> n;
  int m = 0;
  int x;
  for (int i=0;i<p.size()&&p[i]<=n;i++) {
    if (min(p[i]-1, n-p[i]) >= m) {
      m = min(p[i]-1, n-p[i]);
      x = p[i];
    }
  }
  int l = x-1;
  int r = x+1;
  cout<<x<<" ";
  while (l>=1 && r<=n) {
    cout<<l<<" ";
    l--;
    cout<<r<<" ";
    r++;
  }
  while (l>=1) {
    cout<<l<<" ";
    l--;
  }
  while (r<=n) {
    cout<<r<<" ";
    r++;
  }
  cout<<"\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  for (int i=2;i<=100000;i++) if (!vs[i]) {
    p.push_back(i);
    for (int j=i;j<=100000;j+=i) vs[j] = 1;
  }

  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}