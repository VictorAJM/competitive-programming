#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,c=b;i<c;++i)
using namespace std;
typedef long long ll;

const double DINF=
  numeric_limits<double>::infinity();
const double EPS=1e-9;

struct pt {  // for 3D add z coordinate
double x,y;
pt(double x, double y):x(x),y(y){}
pt(){}
double norm2(){return *this**this;}
double norm(){return sqrt(norm2());}
bool operator==(pt p)
  {return abs(x-p.x)<EPS&&abs(y-p.y)<EPS;}
pt operator+(pt p){return pt(x+p.x,y+p.y);}
pt operator-(pt p){return pt(x-p.x,y-p.y);}
pt operator*(double t){return pt(x*t,y*t);}
pt operator/(double t){return pt(x/t,y/t);}
double operator*(pt p){return x*p.x+y*p.y;}
//	pt operator^(pt p){ // only for 3D
// return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
// redefine acos for values out of range
double angle(pt p){ 
  return acos(*this*p/(norm()*p.norm()));}
pt unit(){return *this/norm();}
double operator%(pt p){return x*p.y-y*p.x;}
// 2D from now on
bool operator<(pt p)const{ // for convex hull
  return x<p.x-EPS||(abs(x-p.x)<EPS&&y<p.y-EPS);}
  // is it to the left of directed line pq?
bool left(pt p, pt q){ 
  return (q-p)%(*this-p)>EPS;}
pt rot(pt r){return pt(*this%r,*this*r);}
pt rot(double a)
{return rot(pt(sin(a),cos(a)));}
};
pt ccw90(1,0);
pt cw90(-1,0);

int sgn(double x){return x<0?-1:1;}
struct ln {
pt p,pq;
ln(pt p, pt q):p(p),pq(q-p){}
ln(){}
bool has(pt r){return dist(r)<EPS;}
bool operator/(ln l)
{return abs(pq.unit()%l.pq.unit())<EPS;}// 2D
bool operator==(ln l)
{return *this/l&&has(l.p);}
pt operator^(ln l){ // intersection
  if(*this/l)return pt(DINF,DINF);
  pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
  return r;
}
double angle(ln l){return pq.angle(l.pq);}
int side(pt r){return has(r)?0:sgn(pq%(r-p));} 
pt proj(pt r)
{return p+pq*((r-p)*pq/pq.norm2());}
pt ref(pt r){return proj(r)*2-r;}
double dist(pt r){return (r-proj(r)).norm();}
ln rot(auto a){return ln(p,p+pq.rot(a));}
};
ln bisector(ln l, ln m){ // angle bisector
pt p=l^m;
return ln(p,p+l.pq.unit()+m.pq.unit());
}
 // segment bisector (2D)
ln bisector(pt p, pt q){
return ln((p+q)*.5,p).rot(ccw90);
}

struct circle {
pt o;double r;
circle(pt o, double r):o(o),r(r){}
circle(pt x, pt y, pt z){
  o=bisector(x,y)^bisector(x,z);
  r=(o-x).norm();}
bool has(pt p){return (o-p).norm()<r+EPS;}
vector<pt> operator^(circle c){
  vector<pt> s;
  double d=(o-c.o).norm();
  if(d>r+c.r+EPS||
    d+min(r,c.r)+EPS<max(r,c.r))return s;
  double x=(d*d-c.r*c.r+r*r)/(2*d);
  double y=sqrt(r*r-x*x);
  pt v=(c.o-o)/d;
  s.pb(o+v*x+v.rot(ccw90)*y);
  if(y>EPS)s.pb(o+v*x-v.rot(ccw90)*y);
  return s;
}
vector<pt> operator^(ln l){
  vector<pt> s;
  pt p=l.proj(o);
  double d=(p-o).norm();
  if(d-EPS>r)return s;
  if(abs(d-r)<EPS){s.pb(p);return s;}
  d=sqrt(r*r-d*d);
  s.pb(p+l.pq.unit()*d);
  s.pb(p-l.pq.unit()*d);
  return s;
}
vector<pt> tang(pt p){
  double d=sqrt((p-o).norm2()-r*r);
  return *this^circle(p,d);
}
};

double randd(){return 1.*rand()/RAND_MAX;}
