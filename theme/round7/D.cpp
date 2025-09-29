#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

vector<int> g[N];
int f_aux[5],f[5];
int signs[N];
int G[N][5],L[N][5];

void get_elements_signs(string s) {
  int n = s.size();
  for (int i=0;i<5;i++) f_aux[i] = 0;
  for (int i=n-1;i>=0;i--) {
    int val = s[i]-'A';
    int cnt = 0;
    for (int j=val+1;j<5;j++) cnt += f_aux[j];
    if (cnt == 0) signs[i] = 0;
    else signs[i] = 1;
    f_aux[val]++;
  }
} 

void get_freq_dependencies(string s) {
  int n = s.size();
  map<int,int> m;
  for (int i=0;i<5;i++) f_aux[i] = 0;
  for (int i=n-1;i>=0;i--) {
    int val = s[i]-'A';
    int cnt = 0;
    for (int j=val+1;j<5;j++) cnt += f_aux[j];
    if (cnt == 1) {
      for (int j=val+1;j<5;j++) if (f_aux[j]>0) {
        g[m[j]].push_back(i);
      }
    }
    m[s[i]-'A'] = i;
    f_aux[val]++;
  }
} 

void solve() {

  string s;
  cin >> s;

  int n = s.size();
  for (int i=0;i<n;i++) {
    signs[i] = 0;
    g[i].clear(); 
  }
  

  get_elements_signs(s);
  get_freq_dependencies(s);
  for (int i=0;i<n;i++) {
    for (int j=0;j<5;j++) G[i][j] = 0;
    for (auto u : g[i]) {
      int val = s[u]-'A';
      G[i][val]++;
    }
  }

  for (int i=0;i<n;i++) for (int j=0;j<5;j++) L[i][j] = 0;


  for (int i=1;i<n;i++) {
    for (int j=0;j<5;j++) L[i][j] = L[i-1][j];
    if (signs[i-1] == 0) L[i][s[i-1]-'A']++;
  }
  
  map<char,int> m;
  m['A'] = 1; f[0] =1;
  m['B'] = 10; f[1] = 10;
  m['C'] = 100; f[2] = 100;
  m['D'] = 1000; f[3] = 1000;
  m['E'] = 10000; f[4] = 10000;
 
  long long ans = 0;
  for (int i=0;i<n;i++) {
    if (signs[i] == 0) ans += m[s[i]];
    else ans -= m[s[i]];
  }

  long long _ans = ans;
  int before = -1;
  for (int i=n-1;i>=0;i--) {
    for (int j=0;j<5;j++) {
      long long ans2 = ans;
      if (signs[i]==0) ans2 -= m[s[i]];
      else ans2 += m[s[i]];
      for (int j=0;j<5;j++) ans2 += G[i][j]*f[j];
      for (int k=j;k<5;k++) ans2 += G[i][k]*f[k];
      for (int k=0;k<j;k++) ans2 -= G[i][k]*f[k];

      for (int k=0;k<j;k++) ans2 -= 2*L[i][k]*f[k];

      if (before > j) ans2 -= f[j];
      else ans2 += f[j];

      _ans = max(_ans, ans2);
    }

    before = max(before, s[i]-'A');
  }
  cout << _ans << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}