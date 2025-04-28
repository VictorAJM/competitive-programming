#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
ll dp[26][1000005];
ll poi[26][1000005];
ll m[1000005];
ll POI[26];
void solve() {
  
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  for (int j=0;j<k;j++) poi[j][n-1]=n;
  for (int i=n-1;i>=0;i--) {
    m[i]=n;
    for (int j=0;j<k;j++) {
      if (poi[j][i]==n) {
        dp[j][i]=1;
        m[i]=min(m[i], dp[j][i]);
      } else {
        dp[j][i] = m[poi[j][i]]+1;
        m[i]=min(m[i], dp[j][i]);
      }
    }
    if (i>0) for (int j=0;j<k;j++) poi[j][i-1]=poi[j][i];
    if (i>0) 
    poi[s[i]-'a'][i-1]=i;

    if (i==0) {
      for (int j=0;j<k;j++) POI[j] = poi[j][0];
      POI[s[i]-'a']=0;
    }
  }
  int q;
  cin >> q;
  for (int i=0;i<q;i++) {
    string t;
    cin >> t;
    int g = t.size();
    int j=0;
    int p=-1;
    while (j<g && p<n) {
      if (p==-1) {
        if (POI[t[j]-'a']==n) {
          p=n;
        } else {
          p=POI[t[j]-'a'];
          j++;
        } 
      } else {
        if (poi[t[j]-'a'][p]==n) {
          p=n;
        } else {
          p=poi[t[j]-'a'][p];
          j++;
        }
      }
    }

    if (j<g) {
      cout<<"0\n";
    } else {
      ll ans = m[p];
      cout << ans << "\n";
    }
  } 
  return 0;
}