#include <bits/stdc++.h>
using namespace std;
int dp[5005][5005];
int solve(int in, int fi, vector<int>& a, int ant=0) {
  if (in>fi) return 0;
  int p = *min_element(a.begin()+in, a.begin()+fi+1);
  int ans = p-ant;
  int prev = in-1;
  for (int i=in;i<=fi;i++) {
    if (a[i]==p) {
      ans+=solve(prev+1, i-1, a, p);
      prev=i;
    }
  }
  ans += solve(prev+1, fi, a, p);
  return min(ans, fi-in+1);
}
int main() {

  int n;
  cin >> n;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  
  cout<<solve(0, n-1, a);
}