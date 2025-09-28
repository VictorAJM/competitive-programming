#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, m; cin>>n>>m;
  vector<int> best(m,0);
  for(int i  =0 ; i < n; i++){
    for(int j  =0 ; j < m; j++){

      int x; cin>>x;
      best[j] = max(best[j], x);
    }


  }
  long long d = 0;
  for(int i = 0; i < m; i++){
    d += best[i];
  }
  cout<<d<<"\n";
  return 0;
}