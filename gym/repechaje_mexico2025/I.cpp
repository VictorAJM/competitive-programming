#include<bits/stdc++.h>
using namespace std;

#define s second
#define f first
#define ll long long
#define dist(a,b) (abs(a.f-b.f)+abs(a.s-b.s))

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<ll,ll>> p(n), nr(n), fr(n);
  for(int i=0; i<n; i++) cin >> p[i].f >> p[i].s;
  long long d = dist(p[0],p[1]), d2, dd, x;
  nr[0] = fr[0] = {1, d-1};
  for(int i=1; i<n; i++){
    ll d2 = dist(p[i], p[i+1]), dd = min(d, d2)-1;
    
    // max i can exted
    x = d - nr[i-1].f;
    if(x>dd){
      if(i&1) fr[i].f = fr[i-1].f + x-dd;
      else fr[i].s = fr[i-1].s - x-dd; 
      x = dd;
    }else fr[i] = fr[i-1];
    nr[i].s = min(x, dd);

    // min i have to extend
    x = d-nr[i-1].s;
    if(x<1){
      if(i&1) fr[i].s = fr[i-1].s - 1-x;
      else fr[i].f = fr[i-1].f + 1-x; 
      x = 1;
    } else fr[i] = fr[i-1];
    nr[i].f = x;
  
    d = d2;

    cout << nr[i].f << ", " << nr[i].s << " -> " << fr[i].f << ", " << fr[i].s << '\n';
  }

  if(fr[n-1].f > fr[n-1].s) cout << "-1\n";
  else cout << fr[n-1].s << '\n';
}