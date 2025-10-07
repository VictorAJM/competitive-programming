#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  ll n, x;
  cin >> n >> x;
  ll p = 1;
  while ((x&p)>0) p+=p;
  if (p < n) {
    for (int i=0;i<p;i++) cout << i << " ";
    cout << x<<" ";
    for (int i=1;i<=n-p-1;i++) cout <<"0 ";
    cout<<"\n";
    return;
  }
  for (int i=1;i<n;i++) cout <<i-1<<" ";
  int ant = 0;
  for (int i=1;i<n;i++) ant |= (i-1);
  if ((((n-1)|ant)&x) == ((n-1)|ant) && ((n-1)|ant) == x) {
    cout<<n-1<<"\n";
  } else 
  cout << (x^ant)<<"\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}