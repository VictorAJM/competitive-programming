#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a,b,m;
void solve(ll pasos) {
  cout << pasos+1<<" ";
  cout << a << " ";
  vector<ll> arr(pasos);
  arr[pasos-1]=1;
  ll cnt=1;
  ll sum = a;
  for (int i=pasos-2;i>=0;i--) arr[i] = cnt, cnt*=2;
  for (int i=0;i<pasos;i++) b -= arr[i];
  for (int i=0;i<pasos;i++) {
    if (b>=(m-1)*arr[i]) {
      b -= (m-1)*arr[i];
      cout << sum+m<<" ";
      sum += sum+m;
    } else {
      ll z = b/arr[i];
      cout << sum+1+z<<" ";
      b %= arr[i];
      sum += sum+1+z;
    }
  }
  cout << "\n";
  return;
}
void solve() {
  cin >> a >> b >> m;
  if (a==b) {
    cout <<"1 "<<a<<"\n";
    return;
  } 
  ll in = 1;
  for (ll i=1;i<=49;i++) {
    if (in*a + in <= b && in*a + in*m >=b) {
      b -= in*a;
      solve(i);
      return;
    } else if (in*a + in > b) {
      cout<<"-1\n";
      return;
    }
    in *= 2;
  }
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}