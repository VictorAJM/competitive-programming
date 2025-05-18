#include <bits/stdc++.h>

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rev(x) reverse(x)
#define pb(x) push_back(x)
#define sz(x) x.size()
#define FOR(i, a) for (int i=0;i<a;i++)

using namespace std;

const int N = 1e5+5;
const int mod = 1e9+7;

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  ll suma = 0;
  for (char u : s) suma+=u-'0';
  string ans;
  ll prev = 0;
  for (int i=s.size()-1;i>=0;i--) {
    ans.push_back((suma+prev)%10+'0');
    prev = (suma+prev)/10;
    suma -= s[i]-'0';
  }
  ll x = suma+prev;
  while (x) {
    ans.push_back(x%10+'0');
    x/=10;
  }
  reverse(ans.begin(), ans.end());
  ans.erase(0, ans.find_first_not_of('0'));
  if (ans.empty()) ans = "0";
  cout << ans << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}