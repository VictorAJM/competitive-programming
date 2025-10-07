#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll r;

struct Trie {
  Trie* letras[26];
  int fin=0;
};
vector<int> Z(string s)
{
    int n=s.size();
    vector<int> z(n);
    int x=0,y=0;
    for(int i=1;i<n;i++){
        z[i]=max(0,min(z[i-x],y-i+1));
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]]){
            x=i;y=i+z[i];z[i]++;
        }
    }
    return z;
}
void calcula(string& t, vector<ll> &a, vector<string>& s) {
  Trie* root = new Trie;
  for (int p=0;p<26;p++) root->letras[p] = nullptr;
  ll n = t.size();
  for (auto& u:s) if (u.size()<=r) {
    Trie* cur = root;
    for (auto v : u) {
      if (cur->letras[v-'a'] != nullptr) {
        cur = cur->letras[v-'a'];
      } else {
        cur->letras[v-'a'] = new Trie;
        cur = cur->letras[v-'a'];
        for (int p=0;p<26;p++) cur->letras[p] = nullptr;
      }
    }
    cur->fin++;
  }
  for (int i=0;i<n;i++) {
    Trie* cur = root;
    for (int j=i;j<min(i+r,n);j++) {
      if (cur->letras[t[j]-'a'] == nullptr) j=n;
      else {
        cur = cur->letras[t[j]-'a'];
        a[i]+=cur->fin;
      }
    }
  }
  for (auto& u:s) if (u.size()>r) {
    string p = u+"$"+t;
    auto z = Z(p);
    for (int i=0;i<z.size();i++) if (z[i]==u.size()) a[i-u.size()-1]++;
  } 

  
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  string t;
  int n;
  cin >> t;
  n = t.size();
  int m;
  cin >> m;
  vector<string> s(m);
  for (int i=0;i<m;i++) cin >> s[i];
  for (int i=0;i<m;i++) r+=s[i].size();
  r = sqrt(r);
  vector<ll> a(n), b(n);
  calcula(t, a, s);
  reverse(t.begin(), t.end());
  for (auto& u : s) reverse(u.begin(), u.end());
  calcula(t, b, s);
  ll ans = 0;
  for (int i=1;i<n;i++) ans += a[i]*b[n-i];
  cout << ans << "\n";
}