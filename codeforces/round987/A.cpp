#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin>>t;
  while (t--) {
    int n;
    map<int,int> m;
    cin>>n;
    for(int i=1;i<=n;i++) {
      int x;
      cin>>x;
      m[x]++;
    }
    int ans = n;
    for (auto u : m) ans=min(ans,n-u.second);
    cout<<ans<<"\n";
  }
}