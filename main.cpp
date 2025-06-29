#include <bits/stdc++.h>
using namespace std;

int matriz[10005][10005];

int main() {
  int n,m;
  cin >> n >> m;
  for (int i=0;i<m;i++) {
    int u,v;
    cin >> u >> v;
    matriz[u][v] = 1;
    matriz[v][u] = 1;
  }

  // 2,4 
  cout << matriz[2][4] << " \n";

  for (int i=1;i<=n;i++) {
    int cnt = 0;
    for (int j=1;j<=n;j++) if (matriz[i][j]) cnt++;
    cout << "Para el nodo "<<i<<" su grado es: "<<cnt<<"\n";
  }
  return 0;
}
