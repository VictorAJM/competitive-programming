#include<bits/stdc++.h>
using namespace std;

#define s second
#define f first

vector<string> d, t;
vector<pair<long long, long long>> v;
map<string, int> mp;

string next(int k, vector<string> &in){
  bool val;
  vector<int> c;
  for(int i=0; i+k<t.size(); i++){
    val = 1;
    for(int j=0; val && j<k; j++){
      if(t[i+j] != in[k-j-1]) val = 0;
    }
    if(val){
      if(mp.count(t[i+k])) c.push_back(mp[t[i+k]]);
      else c.push_back(v.size()-1);
    }
  }

  if(c.size()==0) return "*";

  long long b = -1e17, dt;
  int bid = -1;
  for(int i=0; i<d.size(); i++){
    dt = 0;
    for(int &cd: c) dt += v[i].f*v[cd].f + v[i].s*v[cd].s;
    if(dt>b) b=dt,bid=i;
  }
  return d[bid];
}

string solve(int k, vector<string> &in){
  k = min(k, (int)in.size());
  string nx = "*";
  while(k&&nx=="*"){
    nx=next(k,in);
    k--;
  }
  return nx;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n,x ,y,m,q,k;
  string s;
  cin >> n;

  d.resize(n);v.resize(n+1);
  
  for(int i=0; i<n; i++){
    cin >> d[i] >> v[i].f >> v[i].s;
    mp[d[i]] = i;
  }
  v[n] = {0,0};

  cin >> m;
  t.resize(m);
  for(int i=0; i<m; i++) cin >> t[i];

  cin >> q >> k;
  while(q--){
    cin >> x;
    vector<string> in(x);
    for(int i=0; i<x; i++) cin >> in[i];
    reverse(in.begin(), in.end());
    for(int i=x-1; i>=0; i--) cout << in[i] << ' ';
    cout << solve(k, in) << '\n';
  }
}