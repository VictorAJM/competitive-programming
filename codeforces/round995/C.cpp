#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<int,int>;
void solve() {
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> a(m);
  for(int& i:a) cin >> i;
  vector<int> q(k);
  for(int& i:q) cin >> i;
  if (k==n) {
    for (int i=0;i<m;i++) cout<<"1";
    cout<<"\n";
    return;
  }
  if (k+1<n) {
    for (int i=0;i<m;i++) cout<<"0";
    cout<<"\n";
    return;
  }
  set<int> s;
  for (int i=1;i<=n;i++) s.insert(i);
  for (int i:q) s.erase(i);
  for (int i=0;i<m;i++) if (s.count(a[i])) cout<<"1"; else cout<<"0";
  cout << "\n";
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  while (t--) solve();
  return 0;
}