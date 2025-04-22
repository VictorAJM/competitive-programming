#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int st[4*N], a[N];
int n,m,num[N],cnt,tot;
int pt, t;
void borra(int no, int in, int fi, int x) {
  if (in==fi) {
    st[no] = 0;
    return;
  }
  int mit = (in+fi)/2;
  if (x<=st[no*2+1]) borra(no*2+1, in,mit, x);
  else borra(no*2+2,mit+1,fi, x-st[no*2+1]);
  st[no] = st[no*2+1] + st[no*2+2];
}
void borrar() {
  for (int i=pt-1;i>=0;i--) borra(0,0,n-1,a[i]);
  tot-=pt;
  while (pt>=0 && a[pt]>tot) pt--;  
  if (pt==-1 || (pt<m &&a[pt]<=tot)) pt++;
}
void agrega(int no, int in,int fi, int pos) {
  if (in==fi) {
    st[no] = 1;
    return;
  }
  int mit = (in+fi)/2;
  if (pos<=mit) agrega(no*2+1, in,mit,pos);
  else agrega(no*2+2, mit+1, fi, pos);
  st[no] = st[no*2+1] + st[no*2+2];
  return;
}
void agregar() {
  agrega(0,0,n-1,cnt);
  cnt++;
  tot++;
  while (pt < m && a[pt]<=tot) pt++; 
}
void respuesta(int no, int in, int fi) {
  if (in==fi) {
    t |= st[no];
    if (st[no]) cout << num[in];
    return;
  }
  int mit = (in+fi)/2;
  respuesta(no*2+1, in ,mit);
  respuesta(no*2+2,mit+1,fi);
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i=0;i<m;i++) cin >> a[i];
  for (int i=0;i<n;i++) {
    int x;
    cin >> x;
    if (x==-1) borrar();
    else {
      num[cnt] = x;
      agregar();
    }
 
  }
  respuesta(0,0,n-1);
  if (!t) {
    cout<<"Poor stack!";
    return 0;
  } 
}