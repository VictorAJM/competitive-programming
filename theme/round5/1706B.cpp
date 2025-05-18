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
  map<pair<int,int>,int> m;
  FOR(i,n) m[{i,0}]=m[{i,1}]=0;
  FOR(j,n) {
    int i = a[j];
      if (j%2==1) m[{i,1}]=max(m[{i,1}], m[{i,0}]+1);
      else m[{i,0}]=max(m[{i,0}], m[{i,1}]+1);
  }
  FOR(i,n) {
    cout << max(m[{i+1,0}], m[{i+1,1}]) << " ";
  }
  cout << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}