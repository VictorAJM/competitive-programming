ll st[4*N],lz[4*N];
void add(ll no,ll i,ll f)
{
	st[no] += lz[no];
  if (i != f) {
    lz[no*2+1] += lz[no];
    lz[no*2+2] += lz[no];
  }
  lz[no] = 0;
  if (f < a || i > b) {
    return;
  }
  if (a <= i && f <= b) {
    lz[no] += d;
    st[no] += lz[no];
    if (i != f) {
      lz[no*2+1] += lz[no];
      lz[no*2+2] += lz[no];
      lz[no] = 0;
    } else lz[no] = 0;
    return;
  }
	ll m = (i+f)/2;
	add(no*2+1,i,m);
	add(no*2+2,m+1,f);
	st[no] = min(st[no*2+1] , st[no*2+2]);
	return;
}
void get(ll no,ll i,ll f)
{
	st[no] += lz[no];
  if (i != f) {
    lz[no*2+1] += lz[no];
    lz[no*2+2] += lz[no];}
	lz[no] = 0;
	if (f < a || i > b) {
		return;
	}
	if (a <= i && f <= b) {
		r = min(r,st[no]);
		return;
	}
	ll m = (i+f)/2;
	get(no*2+1,i,m);
	get(no*2+2,m+1,f);
	st[no] = min(st[no*2+1] , st[no*2+2]);
	return;
}