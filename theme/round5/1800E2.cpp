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
  int n,k;
  cin >> n >> k;
  string a,b;
  cin >> a >> b;
  int p = n-k;
  if (p<=0) {
    if (a==b) cout<<"YES\n";
    else cout << "NO\n";
    return;
  }
  for (int i=p;i<k;i++) if (a[i]!=b[i]) {
    cout<<"NO\n";
    return;
  }
    string x,y;
  if (p>k) {
    sort(a.begin(),a.end());
    sort(b.begin(), b.end());
    if (a==b) cout<<"YES\n";
    else cout << "NO\n";
    return;

  }


  for (int i=0;i<p;i++) {
    x.push_back(a[i]);
    y.push_back(b[i]);
  }
  for (int i=k;i<n;i++) {
    x.push_back(a[i]);
    y.push_back(b[i]);
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  if (x==y) cout<<"YES\n";
  else cout << "NO\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}