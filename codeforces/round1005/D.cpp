#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+5;
int nex[N][32];
ll st[4*N];
void ini(int no, int in, int fi, vector<ll>& w) {
  if (in==fi) {
    st[no] = w[in];
    return;
  }
  int m = (in+fi)/2;
  ini(no*2+1, in, m ,w);
  ini(no*2+2, m+1,fi,w);
  st[no] = (st[no*2+1]^st[no*2+2]);
}
ll get(int no, int in, int fi, int l, int r) {
  if (l>r) return 0;
  if (fi < l || r < in) return 0;
  if (l <= in && fi <= r) return st[no];
  int m = (in+fi)/2;
  ll x = get(no*2+1, in, m, l, r);
  ll y = get(no*2+2, m+1, fi,l,r);
  x^=y;
  return x;
}
void solve() {
  ll n,q;
  cin >> n >> q;
  vector<ll> w(n);
  for(auto& i:w) cin >> i;
  vector<ll> x(q);
  for(auto& i:x) cin >> i;
  // create xor seg tree
  ini(0, 0, n-1, w);
  // create next[i][j] = next pos for the X with a bigger power of 2 than j at left from i
  vector<int> dp(32, -1);
  for (int i=0;i<n;i++) {
    for (int j=0;j<=30;j++) nex[i][j] = dp[j];
    ll p = 1;
    ll qq = 0;
    while (p<=w[i]) {
      p+=p;
      qq++;
    }
    qq--;
    dp[qq]=i;
  }
  for (int j=0;j<=30;j++) nex[n][j] = dp[j];
  for (int i=0;i<q;i++) {
    bool flag = 1;
    int prev = n-1;
    while (flag) {
      ll p = 1;
      ll qq = 0;
      if (x[i]==0) {
        cout<<n-prev-1<<" ";
        flag = 0;
      } else {
      while (p<=x[i]) {
        p+=p;
        qq++;
      }
      
      int P = -1;
      for (int j=qq;j<=30;j++) P = max(P, nex[prev+1][j]);
      int Q = nex[prev+1][qq-1];
      if (Q==-1 && P==-1) {
        cout<<n<<" ";
        flag = 0;
      }
       else if (Q < P) {
        cout<<n-P-1<<" ";
        flag = 0;
      } else {
        x[i] ^= get(0, 0, n-1, Q+1, prev);
        if (w[Q]>x[i]) {
          cout<<n-Q-1<<" ";
          flag = 0;
        } else {
          x[i] ^= w[Q];
          prev = Q-1;
        }
      }
    }
    }
  }
  cout<<"\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}