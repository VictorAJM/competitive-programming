#include <bits/stdc++.h>
using namespace std;
string word,s;
int pos = 0;
int level=0;
vector<vector<string>> ans;
bool readWord() {
  if (pos >= s.size()) return false;
  word.clear();
  while (s[pos]!=',' && pos < s.size()) {
    word.push_back(s[pos]);
    pos++;
  }
  pos++;
  return true;
}
void readTimes() {
  int times = 0;
  while (s[pos]!=',' && pos < s.size()) {
    times*=10;
    times+=s[pos]-'0';
    pos++;
  }
  pos++;
  while (times--) {
    readWord();
    if (ans.size() <= level) ans.push_back(vector<string>());
    ans[level].push_back(word); 
    level++;
    readTimes();
    level--;
  }
}
void solve() {
  cin >> s;
  while (readWord()) {
    if (ans.size() <= level) ans.push_back(vector<string>());
    ans[level].push_back(word); 
    level++;
    readTimes();
    level--;
  }
  cout<<ans.size()<<"\n";
  for (int i=0;i<(int)ans.size();i++) {
    for (auto u : ans[i]) cout << u << " ";
    cout << "\n";
  }
}
int main() {
  cin.tie(0) -> ios_base::sync_with_stdio(0);
  int t;
  // cin >> t;
  t = 1;
  while (t--) solve();
  return 0;
}