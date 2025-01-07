#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<int,int>;
void solve() {
  int n,k;
  cin>>n>>k;
  map<int,int> m;
  vector<int> ans;
  for (int i=0;i<n;i++) {
    int x;
    cin>>x;
    m[x]++;
  }
  for (auto u : m) ans.push_back(u.S);
  sort(ans.begin(),ans.end());
  int _ans = ans.size();
  for (int i : ans) {
    if (i<=k) {
      _ans--;
      k-=i;
    }
  }
  if (_ans<1) _ans=1;
  cout <<_ans<<"\n";
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  while (t--) solve();
  return 0;
}