#include <bits/stdc++.h>
#define ve vector
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<int,int>;

void solve() {
  ll n;
  ll cnt=0;
  cin >> n;
  cnt = 3*(n/15);
  n%=15;
  n=min(n,2ll);
  cnt+=n+1;
  cout<<cnt<<"\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}