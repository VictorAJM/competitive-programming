#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())

using namespace std;

using ll = long long;

const int N = 1e5+5;
const double eps = 1e-12;
const double eps2 = 5e-8;

ll n;
double h;
double x[N],y[N],z[N],a,b;

struct pt {  // for 3D add z coordinate
	double x,y;int id;
	pt(double x, double y, int id=-1):x(x),y(y),id(id){}
	pt(){}
	double norm2(){return *this**this;}
	double norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<eps&&abs(y-p.y)<eps;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(double t){return pt(t*x,t*y);}
	pt operator/(double t){return pt(x/t,y/t);}
	double operator*(pt p){return x*p.x+y*p.y;}
//	pt operator^(pt p){ // only for 3D
//		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	double angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	pt unit(){return *this/norm();}
	double operator%(pt p){return x*p.y-y*p.x;} // 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-eps||(abs(x-p.x)<eps&&y<p.y-eps);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>-eps;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(double a){return rot(pt(sin(a),cos(a)));}

  static double dot(pt v, pt w) {
    return v.x*w.x + v.y*w.y;
  }

  static double cross(pt v, pt w) {
    return v.x*w.y - v.y*w.x;
  }

  static double orientation(pt a, pt b, pt c) {
    return pt::cross(b-a, c-a);
  }
};
// CCW order
// Includes collinear points (change sign of eps in left to exclude)
vector<pt> chull(vector<pt> p){
	if(SZ(p)<3)return p;
	vector<pt> r;
	sort(p.begin(),p.end()); // first x, then y
	fore(i,0,p.size()){ // lower hull
		while(r.size()>=2&&r.back().left(r[r.size()-2],p[i]))r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	int k=r.size();
	for(int i=p.size()-1;i>=0;--i){ // upper hull
		while(r.size()>=k+2&&r.back().left(r[r.size()-2],p[i]))r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	return r;
}

double cross(const pt &a, const pt &b, const pt &c) {
    // Cross product of (b - a) x (c - a)
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool onDisk(pt a, pt b, pt p) {
  return pt::dot(a-p, b-p) <= 0;
}

bool onSegment(pt &a, pt &b, pt &p) {
  return pt::orientation(a, b, p) == 0 && onDisk(a, b, p);
}

bool isInsideConvexPolygon( vector<pt> &poly, pt p) {
  
    int n = poly.size();
    if (n < 3) return false; // not a polygon

    double prev = 0;
    for (int i = 0; i < n; i++) {
        pt a = poly[i];
        pt b = poly[(i + 1) % n];
        double c = cross(a, b, p); 

        if (fabs(c) < eps) return false; // point on edge -> not strictly inside
        if (fabs(prev) < eps) prev = c;
        else if (prev*c < 0.0) 
            return false; // different side
    }

    if (n == 4) {
      if (onSegment(poly[0], poly[2], p) && onSegment(poly[1], poly[3], p)) return false;
    }

    return true;
}

bool check(double _h) {
  vector<pt> p;
  for (int i=0;i<n;i++) if (z[i]+_h >= h) p.push_back({x[i], y[i]});
  vector<pt> c = chull(p);
  return isInsideConvexPolygon(c, pt(a,b));
}



bool checkAll() {
  vector<pt> p;
  for (int i=0;i<n;i++) p.push_back({x[i], y[i]});
  vector<pt> c = chull(p);

  return isInsideConvexPolygon(c, pt(a,b));
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n >> h;
  for (int i=0;i<n;i++) cin >> x[i] >> y[i] >> z[i];
  cin >> a >> b;

  if (!checkAll()) {
    cout << "-1\n";
    return 0;
  }

  double l = 0.0;
  double r = 2e9;

  while (r-l > eps2) {
    double mid = (l+r)/2.0;
    if (check(mid)) r = mid;
    else l = mid;
  }

  cout << fixed << setprecision(9) << r << "\n";

  return 0;
}