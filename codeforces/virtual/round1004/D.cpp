#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  set<int> s;
  for (int i=1;i<=n;i++) s.insert(i);
  int p = -1;
  for (int i:a) s.erase(i), p =i;
  if (!s.empty()) {
    int q = *s.begin();
    cout <<"? "<<q<<" "<<p<<endl;
    int ans;
    cin >> ans;
    if (ans==0) {
      cout<<"! A"<<endl;
      return;
    } else {
      cout<<"! B"<<endl;
      return;
    }
  }
  int x,y;
  for (int i=1;i<=n;i++) {
    if (a[i-1]==1) x=i;
    else if (a[i-1]==n) y=i;
  }
  cout << "? "<<x<<" "<<y<<endl;
  int ans;
  cin >> ans;

  int ans2; 
  cout << "? "<<y<<" "<<x<<endl;
  cin >> ans2;
  if (ans == ans2 && ans>=n-1) {
    cout<<"! B"<<endl;
  } else {
    cout<<"! A"<<endl;
  }
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}