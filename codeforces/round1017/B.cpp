#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s,t;
  cin >> s >> t;
  vector<int> freq;
  vector<int> tipo;
  int n = 0;
  for (int i=0;i<s.size();) {
    freq.push_back(2);
    tipo.push_back(s[i]);
    n++;
    i++;
    while (i<s.size() && s[i]==s[i-1]) freq[n-1]+=2, i++;
  }
  vector<int> freq2;
  vector<int> tipo2;
  int m = 0;
  for (int i=0;i<t.size();) {
    freq2.push_back(1);
    tipo2.push_back(t[i]);
    m++;
    i++;
    while (i<t.size() && t[i]==t[i-1]) freq2[m-1]+=1, i++;
  }
  if (n!=m) {
    cout << "NO\n";
    return;
  }
  for (int i=0;i<n;i++) {
    if (tipo[i] != tipo2[i]) {
      cout << "NO\n";
      return;
    }
    if (freq[i] < freq2[i] || freq[i]/2 > freq2[i]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}