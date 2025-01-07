#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<int,int>;
int f(int u) {
  int p =1 ;
  while (p<=u) p*=2;
  p/=2;
  return p;
}
void solve() {
  int l,r;
  cin>>l>>r;
  int _l = l;
  int _r = r;
  int ans = 0;
  while (f(l) == f(r)) {
    ans += f(l);
    l-=f(l);
    r-=f(r);
  }
  int q = f(r);
  cout<<ans+q<<" "<<ans+q-1<<" ";
  if(ans+q-1==_l) cout<<_r<<"\n";
  else cout<<_l<<"\n";
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  while (t--) solve();
  return 0;
}