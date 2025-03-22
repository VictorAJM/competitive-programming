#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<int,int>;
 
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  vector<int> c;
  for (int i=0;i<n;i++) if (a[i]==0) c.push_back(i);
 
  vector<pair<int,int>> ans;
  int cnt=1;
  for (int i=0;i<n;i++) {
    if (a[i]==0) {
      if (i+1 < n) {
        ans.push_back({cnt, cnt+1});
        a[i+1]=1;
        i++;
        cnt++;
      } else {
        ans.push_back({cnt-1, cnt});
      }
    } else {
      cnt++;
    }
  }
  ans.push_back({1, cnt-1});
  cout << ans.size()<<"\n";
  for (auto u : ans) {
    cout<<u.F << " "<<u.S<<"\n";
  }
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
