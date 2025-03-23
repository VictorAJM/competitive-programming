#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll check(ll m, ll n) {
  ll ret = n*n;
  ret /= 2;
  ret++;
  for (ll i=1;i<=n;i++) {
    if (n*i<=m) ret-=n;
    else ret-=m/i;
    if (ret<=0) return true;
  }
  if (ret<=0) return true;
  return false;
}
int main() {
  ll n;
  cin >> n;
  ll in = 1;
  ll fi = n*n;
  while (in+1 < fi) {
    ll m = (in+fi)/2;
    if (!check(m,n)) in=m;
    else fi=m;
  }
  cout << fi;
  return 0;
}