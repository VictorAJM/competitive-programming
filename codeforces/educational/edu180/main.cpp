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
  vector<int> a(n);
  for(int& i:a) cin >> i;
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  int ans = 0;
  for (int i=1;i<n-1;i++) {
    int k = n-1;
    for (int j=i+1;j<n;j++) {
      if (a[i]+a[j] > a[0]) {
        ans++;
        cout<<1<<"* ";
      }
      int p = a[0]-a[j]-a[i]+1;
      if (j>=k) {
 
      } else {
        while (k>j && a[k]<p) k--;
        if (k>j) ans += k-j, cout<<k-j<<" ";
      }
    }
    cout << "\n";
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