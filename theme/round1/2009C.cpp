#include <bits/stdc++.h>

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rev(x) reverse(x)
#define pb(x) push_back(x)
#define sz(x) x.size()
#define FOR(i, a) for (int i=0;i<a;i++)

using namespace std;

const int N = 1e5+5;
const int mod = 1e9+7;

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;

void solve() {
  int x,y,k;
  cin >> x >> y >> k;
  int l = (x+k-1)/k;
  int r = (y+k-1)/k;
  if (l==r) {
    cout<<l*2<<"\n";
  } else if (l<r) {
    cout<<r*2<<"\n";
  } else {
    cout<<l*2-1<<"\n";
  }
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}