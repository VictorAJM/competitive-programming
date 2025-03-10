#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  bool t = 0;
  for (int i:a) if (i==0) t=1;
  if (!t) {
    cout<<n<<"\n";
    return;
  }
  int cnt = 0;
  for (int i:a) if (i>0) cnt++;
  vector<int> b;
  for (int i:a) if (i>0) b.push_back(i);
  reverse(b.begin(), b.end());
  int mex = 1;
  vector<int> c;
  c.push_back(mex);
  set<int> s;
  for (int i:b) {
    s.insert(i);
    while (s.count(mex)) mex++;
    c.push_back(mex);
  }
  reverse(c.begin(),c.end());
  int cur = -1;
  bool gg = 1;
  int mm = *max_element(a.begin(), a.end()) + 5;
  for (int i=0;i<n;i++) {
    if (a[i]>0) {
      cur++;
      mm = min(mm, a[i]);
      if (mm < c[cur+1]) {
        cout<<cnt<<"\n";
        return;
      }  
    }
    else {
      if (mm>=c[cur+1]) {
        cout<<cnt+1<<"\n";
        return;
      } else {
        cout<<cnt<<"\n";
        return;
      }
    }
  }
  cout<<cnt<<"\n";
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}