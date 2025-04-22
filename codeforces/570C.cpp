#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  string s;
  cin >> s;
  set<int> st;
  for (int i=0;i<n-1;i++) if (s[i]=='.' && s[i+1]=='.') st.insert(i);
  for (int i=1;i<=m;i++) {
    int x;
    char c;
    cin >> x >> c;
    x--;
    if (c=='.') {
      s[x] = '.';
      if (x>0 && s[x-1]=='.') st.insert(x-1);
      if (x+1<n && s[x+1]=='.') st.insert(x);
    } else {
      if (s[x]!='.') {
        s[x] = c;
      } else {
        s[x] = c;
        st.erase(x);
        st.erase(x-1);
      }
    }
    cout << st.size() << "\n";
  }
  return 0;
}