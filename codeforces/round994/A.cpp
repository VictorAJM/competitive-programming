#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin>>n;
  vector<int> a(n);
  for(int& i:a) cin>>i;
  bool ok =1;
  for (int i:a) if (i!=0) ok=0;
  if (ok) {
    cout<<"0\n";
    return;
  }
  ok=1;
  int i=0;
  while (i<n && a[i]==0) i++;
  while (i<n && a[i]>0) i++;
  while (i<n && a[i]==0) i++;
  if (i==n) {
    cout<<"1\n";
    return;
  }
  cout<<"2\n";
}
int main() {
  int t;
  cin>>t;
  while (t--) {
    solve();
  }
}