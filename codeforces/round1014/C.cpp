#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
ll check(vector<ll> a, vector<ll> b) {
  int n = a.size();
  int m = b.size();
  ll ans = a[n-1];
  a.pop_back();
  n--;
  int t = 0;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  int x = min(n,m);
  for (int i=0;i<x;i++) {
    ans+=a[i]+b[i]-1;
    t=1;
  }
  if (m>x) ans+=b[x];
  else if (n>x && t>0) {
    ans+=1+a[x];
  }
  return ans;
}
void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for(ll& i:a) cin >> i;
  sort(a.begin(), a.end());
  vector<ll> odd,even;
  for (ll i:a) {
    if (i%2==0) even.push_back(i);
    else odd.push_back(i);
  }
  if (even.empty() || odd.empty()) {
    cout<<a[n-1]<<endl;
    return;
  }
  cout << max(check(odd, even), check(even, odd))<<endl;
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}