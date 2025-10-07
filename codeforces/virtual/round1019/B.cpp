#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define F first
#define S second

using ii = pair<int, int>;
using vi = vector<int>;
using ll = long long;
using vvi = vector<vi>;
using vii = vector<ii>;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int p = 0;
  int cnt = n;
  for (int i=0;i<n;i++) {
    if (s[i]-'0'!=p) cnt++;
    p = s[i]-'0';
  }
  bool t = 0;
  for (int i=0;i<n;i++) {
    if (s[i]!='1') {
      t = 1;
      break;
    }
  }
  if (!t) {
    cout << cnt << endl;
    return;
  }
  if (n>1) {
    set<pair<char,char>> st;
    st.insert({'0',s[0]});
    for (int i=1;i<n-1;i++) {
      if (st.count({s[i],s[i+1]})>0 && s[i]!=s[i+1]) {
        cout << cnt-2 << endl;
        return;
      } 
      st.insert({s[i-1],s[i]});
    }
    int x = 0;
    while (x<n && s[x]=='0') x++;
    int y = n-1;
    while (y>=0 && s[y]=='1') y--;
    if (x<y) {
      cout << cnt-1 << endl;
      return;
    }
    cout << cnt << endl; 
    return;
  } else {
    cout << cnt << endl;
    return;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) solve();
}
