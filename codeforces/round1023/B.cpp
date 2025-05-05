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
  vi a(n);
  for(int& i:a) cin >> i;
  sort(all(a));
  a[n-1]--;
  sort(all(a));
  if (a[n-1]-a[0]>k) {
    cout<<"Jerry\n";
    return;
  }
  ll s=0;
  for (int i:a) s+=i;
  cout << (s%2==0 ? "Tom\n" : "Jerry\n");
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}