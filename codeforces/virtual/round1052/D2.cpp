#include <bits/stdc++.h>
using namespace std;


using ll = long long;
ll L;

void f(ll l, ll r, vector<ll>& ans, ll ext) {
  if (l>r) return;
  if (l==r) {
    ans[l+ext-L] = r+ext;
    return; 
  }
  ll p = 1;
  while (p <= r) p*=2;
  ll q = p/2;

  if (q < l) {
    ext += q;
    f(l-q, r-q,ans, ext);
    return;
  }

  ll w = q-1;
  ll h = r-w;
  if (q-h>=l) {
    // it is safe to complete everything
    while (q <= r) {
      ans[q+ext-L] = w+ext;
      ans[w+ext-L] = q+ext;
      q++;
      w--;
    }
    f(l,w, ans, ext);
  } else {
    // lets complete what we can
    // then do recursion
    while (w>=l) {
      ans[q+ext-L] = w+ext;
      ans[w+ext-L] = q+ext;
      q++;
      w--;
    }
    ll P = 1;
    while (P <= r) P *= 2;
    P /=2;
    ext += P;
    f(q - P,r - P,ans, ext);
  }
}

void solve() {
  ll l,r;
  cin >> l >> r;
  vector<ll> ans;
  for (int i=l;i<=r;i++) ans.push_back(0);
  L = l;
  f(l,r, ans, 0);
  long long ANS = 0;
  for (ll i=l;i<=r;i++) {
    ANS += i|ans[i-l];
  }
  cout << ANS << "\n";
  for (ll i=l;i<=r;i++) {
    cout << ans[i-l] << " ";
  }
  cout << "\n";
 }

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  ll t;
  cin >> t;
  while (t--) solve();
  return 0;
}