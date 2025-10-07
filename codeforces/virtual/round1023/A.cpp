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
  int p = *max_element(all(a));
  if (*min_element(all(a))==p) {
    cout<<"No\n";
    return;
  }
  cout<<"Yes\n";
  for (int i=0;i<n;i++) {
    if (a[i]==p) {
      cout<<"2 ";
      p++;
    } else {
      cout<<"1 ";
    }
  }
  cout<<"\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}