#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
int dist[400005];
bool vs[400005];
int c[10],d[10];
int get(vector<int>& a) {
  int ans = 0;
  for (int i=0;i<9;i++) d[i]=i;
  for (int i=0;i<9;i++) {
    ans += d[a[i]]*c[8-i];
    for (int j=a[i]+1;j<9;j++) d[j]--;
  }
  return ans;
}
int main() {
  int n=9;
  c[1] = 1;
  for (int i=2;i<=9;i++) c[i]=i*c[i-1];
  vector<int> a(n);
  for (int& i:a) cin >> i;
  for (int& i:a) i--;
  queue<pair<int,vector<int>>> q;
  vector<int> ini(9);
  for(int i=0;i<9;i++) ini[i] = i;
  q.push({0,ini});
  dist[0] = 0;
  vs[0] = 1;
  while (!q.empty()) {
    auto x = q.front();
    q.pop();
    int idx = get(x.S);

    vector<int>& cop = x.S;
    for (int i=0;i<6;i++) {
      swap(cop[i], cop[i+3]);
      int idy = get(cop);
      if (!vs[idy]) {

        vs[idy]=1;
        dist[idy] = x.F+1;
        q.push({x.F+1, cop});
      }
      swap(cop[i], cop[i+3]);
    } 
    for (int i=0;i<9;i++) {
      if (i%3==2) continue;
      swap(cop[i], cop[i+1]);
      int idy = get(cop);
      if (!vs[idy]) {
        vs[idy]=1;
        dist[idy] = x.F+1;
        q.push({x.F+1, cop});
      }
      swap(cop[i], cop[i+1]);
    } 
  }
  cout << dist[get(a)]<<"\n";
  return 0;
}