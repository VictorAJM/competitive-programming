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
  int n;
  cin >> n;
  vi a(n);
  for(int& i:a) cin >> i;
  int p = (n+1)/2;
  p--;
  vi b(n);
  for(int i=0;i<n;i++) b[i]=abs(a[i]);
  sort(all(b));
  int g = a[0];
  for (int i=0;i<n;i++) {
    if (b[i]==abs(g)) {
      if (n-i-1>=p) {
        cout<<"YES\n";
        return;
      }
    }
  }
  cout<<"NO\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}