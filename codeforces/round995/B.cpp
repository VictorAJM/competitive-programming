#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<int,int>;
void solve() {
  ll n,a,b,c;
  cin >> n >> a >> b >> c;
  ll ans = 0;
  ans = 3*(n/(a+b+c));
  n %= (a+b+c);
  if (n>0) {
    ans++;
    n-=a;
  } else {
    n = 0;
  }
  if (n>0) {
    ans++;
    n-=b;
  } else {
    n = 0;
  }
  if (n>0) {
    ans++;
    n-=c;
  } else {
    n = 0;
  }
  cout<<ans<<"\n";
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  while (t--) solve();
  return 0;
}