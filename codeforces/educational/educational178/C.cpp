#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n==2 && s=="AB") {
    cout << "Alice\n";
    return;
  } 
  if (n==2 && s=="BA") {
    cout<<"Bob\n";
    return;
  }
  if (s[0]==s[n-1]) {
    if (s[0]=='A') cout << "Alice\n";
    else cout << "Bob\n";
    return;
  }
  set<int> A,B;

  for (int i=1;i<n-1;i++) if (s[i]=='A') A.insert(i); else B.insert(i);
  if (s[0]=='A') {
    if (B.size()==0) cout<<"Alice\n";
    else cout << "Bob\n";
    return;
  }
  A.insert(-1);
  B.insert(-1);
  if (*A.rbegin() < *B.rbegin()) cout << "Bob";
  else cout << "Alice";
  cout << "\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}