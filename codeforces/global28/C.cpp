#include <bits/stdc++.h>
using namespace std;
char XOR(char a, char b) {
  if (a == b) return '0';
  else return  '1';
}
string MAX(string& a, string& b) {
  for (int i=0;i<(int)a.size();i++) if (a[i] != b[i]) {
    if (a[i]<b[i]) a=b; 
    return a;
  }
  return a;
}
void solve() {
  string s;
  cin>>s;
  int n = s.size();
  cout <<"1 "<<n<<" ";
  vector<int> uno, dos;
  for (int i=n-1;i>=0;i--) {
    if (s[i]=='1') uno.push_back(n-i-1);
    else dos.push_back(n-i-1);
  }
  int i=0;
  while (i<n && s[i]=='1') i++;
  int p = n-i;
  if (p==0) {
    cout<<"1 1\n";
    return;
  }
  string ans;
  int x=1,y = 1;
  for (int j=0;j<p;j++) ans+="0";
  for (int j=0;j<=n-p;j++) {
    string _s;
    for (int k=j;k<j+p;k++) {
      _s += XOR(s[k],s[i+k-j]);
    }
    ans = MAX(ans, _s);
    if (ans == _s) x = j+1, y = x+p-1;
  }
  cout << x << " "<<y<<"\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while (t--) {
    solve();
  }
  return 0;
}