#include <bits/stdc++.h>
using namespace std;

int juntos(vector<int> &a) {
  int n = a.size();
  int ans = 2000000;
  for (int i=1;i<n;i++) {
    int x = a[i-1];
    int y = a[i];
    if (y > x) swap(x, y);
    int cnt = min(x-y, (x+1)/2);
    x -= 2*cnt; y -= cnt;
    if (x>0 && y>0) {
      cnt += (x+y+2)/3;
    }
    ans = min(ans, cnt);
  }
  return ans;
}

int uno(vector<int>& a) {
  int n = a.size();
  int ans = 2000000;
  for (int i=1;i<n-1;i++) {
    ans = min(ans, (a[i-1]+a[i+1]+1)/2);
  }
  return ans;
}

int varios(vector<int> &a) {
  int n = a.size();
  int cur = (a[0]+1)/2;
  int ans = 2000000;
  for (int i=3;i<n;i++) {
    ans = min(ans, (a[i]+1)/2 + cur);
    cur = min(cur, (a[i-2]+1)/2);
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  cout << min({juntos(a), uno(a), varios(a)}) << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t = 1;
  while (t--) solve();
  return 0;
}