#include <bits/stdc++.h>

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rev(x) reverse(x)
#define pb(x) push_back(x)
#define sz(x) x.size()
#define FOR(i, a) for (int i=0;i<a;i++)

using namespace std;
using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
const int N = 1e5+5;
const int mod = 1e9+7;
const ll inf = 1e18;



void solve() {
  ll n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<ll> a(n);
  for(ll& i:a) cin >> i;
  vector<ll> b(n);
  set<ll> st;
  st.insert(0);
  ll cur=0;
  FOR(i,n) if (s[i]=='1') {
    cur += a[i];
    b[i] = cur - *st.begin();
    st.insert(cur);
  }
  ll p = *max_element(all(b));
  if (p>k) cout<<"No\n";
  else if (p==k) {
    cout<<"Yes\n";
    for (auto u : a) cout<<u<<" ";
    cout<<"\n";
  } else {
    for (int i=0;i<n;i++) {
      if  (s[i]=='0') {
        if ((i==0 || (s[i-1]=='1' && a[i-1]<=0)) && (i==n-1 || (s[i+1]=='1' && a[i+1]<=0))) {

          cout<<"Yes\n";
          for (int j=0;j<n;j++) if (s[j]=='0') a[j]=-inf;
          a[i]=k;
          for (int j=0;j<n;j++) cout << a[j] << " ";
          cout<<"\n";
          return;
        }
      }
    }
    cout << "No\n";
  }
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}