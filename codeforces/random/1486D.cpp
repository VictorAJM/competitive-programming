#include <bits/stdc++.h>
using namespace std;
 
bool check(vector<int>& b, int k) {
  vector<int> c;
  for (int u : b) {
    c.push_back(u);
    if (c.size()>1) c[c.size()-1] += c[c.size()-2];
  }
  int mini = 0;
  for (int i=k;i<c.size();i++) {
    mini=min(mini, c[i-k]);
    if (c[i]-mini > 0) return true;
  }
  return false;
}
 
bool check(vector<int>& a, int k, int mit) {
  vector<int> b;
  for (auto u : a) {
    if (u >= mit) b.push_back(1);
    else b.push_back(-1);
  }
  if (check(b, k)) return true;
  if (k%2==0 && check(b,k+1)) return true;
  return false;
}
 
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
 
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  for(int& i:a) cin >> i;
 
  if (k==n) {
    sort(a.begin(), a.end());
    cout << a[(n+1)/2 - 1] << "\n";
    return 0;
  }
 
  int l = *min_element(a.begin(), a.end());
  int r = *max_element(a.begin(), a.end()) + 1;
  while (l+1 < r) {
    int mit = (l+r)/2;
    if (check(a, k, mit)) l = mit;
    else r = mit; 
  }
 
  cout << l << "\n";
 
  return 0;
}