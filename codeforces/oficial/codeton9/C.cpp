#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x,y;
  cin>>x>>y;
  long long p=1;
  long long ans=0;
  while (p<=x) p*=2;
  p = min(p,y);
  for (long long i=1;i<=p;i++) {
    long long z = x^i;
    
    if (z%x==0 || z%i==0) ans++;
    if (z%x==0) ans--;
  }
  
  if (y<=p) {
    for (long long i=1;i<=p;i++) {
      long long z = x^i;
      
      if (z%x==0) ans++;
    }
    cout<<ans<<endl;
    return;
  }
  ans+=y/x;
  for (long long i=x*(y/x)+x*10;i>x*(y/x);i-=x) if ((i^x)<=y) ans++;
  for (long long i=x*(y/x);i>=max(0ll,x*(y/x)-x*10);i-=x) if ((i^x)>y) ans--;
  cout<<ans<<"\n";
}
int main() {
  int t;
  cin>>t;
  
  while (t--) solve();
}