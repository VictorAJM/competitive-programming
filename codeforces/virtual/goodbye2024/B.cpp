#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin>>n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i=0;i<n;i++) cin >> a[i] >> b[i];
  vector<int> f(n+n+2);
  map<int,int> s;
  for (int i=0;i<n;i++) if (a[i] == b[i]) f[a[i]]=1,s[a[i]]++;
  for (int i=1;i<=n+n;i++) f[i]+=f[i-1];
  for (int i=0;i<n;i++) {
    if (a[i] == b[i]) {
      if (s[a[i]]>1) cout<<"0";
      else cout<<"1";
    } else {
      if (f[b[i]]-f[a[i]-1] == b[i]-a[i]+1) cout<<"0";
      else cout <<"1";
    }
  }
  cout<<"\n";
}
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  while (t--) {
    solve();
  }
}