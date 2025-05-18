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
  
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  if (n==1) {
    cout << "3";
    return 0;
  }
  n--;
  int p = n/3;
  int cnt = 4+p*4;
  p = n%3;
  if (p==0) {
    cout << cnt;
    return 0;
  }
  if (p==1) {
    cout << cnt+1;
    return 0;
  }
  cout << cnt+3;
  return 0;
}