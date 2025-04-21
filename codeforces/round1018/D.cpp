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
struct cmp {
  bool operator()(const ii& a, const ii& b) const {
      if (a.first != b.first) {
          return a.first > b.first;
      } else {
          return a.second < b.second;
      }
  }
};
void borrar(int x, int y, set<ii, cmp> &st, int &X, int &Y) {
  auto it = st.find({x,y});
  if (it != st.end()) {
    st.erase(it);
    if ((x+y)%2==0) X--;
    else Y--;
  } else {
    st.insert({x,y});
    if ((x+y)%2==0) X++;
    else Y++;
  }
}


void solve() {
  int n;
  cin >> n;
  vii a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].F >> a[i].S;
  }
  map<int,int> m;
  for (int i = 0; i < n; i++) {
    m[a[i].F+a[i].S]++;
  }
  int s;
  for (auto [x,y] : m) {
    if (y%2>0) {
      s = x;
    }
  }
  int X=0,Y=0;
  for (int i = 0; i < n; i++) {
    if ((a[i].F+a[i].S)%2==0) X++;
    else Y++;
  }
  sort(all(a));
  set<ii, cmp > st;
  for (int i=0;i<n;i++) st.insert(a[i]);


  int cnt = 0;
  while (st.size() && cnt < 10) {
    cnt++;
    if (X==(s%2==0) && Y==(s%2==1)) {
      cout << (*st.begin()).F << " "<<(*st.begin()).S << endl;
      return;
    }
    auto it = st.begin();
    int x = (*it).F, y = (*it).S;

    borrar(x,y,st,X,Y);
    borrar(x,y+1,st,X,Y);
    borrar(x-1,y+1,st,X,Y);
    borrar(x-1,y+2,st,X,Y);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) solve();
}
