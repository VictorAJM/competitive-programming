// Given a set of points solve nearest point
// querry on O(log n)
// Requires Point struct with +,-,dot impl

#define ll long long
#define ALL(x) x.begin(),x.end()
#define SZ(x) int((x).size())
#define f first

bool onx(Point a, Point b){return a.x<b.x;}
bool ony(Point a, Point b){return a.y<b.y;}
const ll INF = 1e18;
struct Node {
  Point pp;
  ll x0=INF, x1=-INF, y0=INF, y1=-INF;
  Node *first=0, *second=0;
  ll distance(Point p){
    ll x=min(max(x0,p.x),x1);
    ll y=min(max(y0,p.y),y1);
    return (Point(x,y)-p).dot(Point(x,y)-p);
  }
  Node(vector<Point>&& vp):pp(vp[0]){
    for(Point p:vp){
      x0=min(x0,p.x); x1=max(x1,p.x);
      y0=min(y0,p.y); y1=max(y1,p.y);
    }
    if(SZ(vp)>1){
      sort(ALL(vp),x1-x0>=y1-y0?onx:ony);
      int m=SZ(vp)/2;
      first=new Node({vp.begin(),
        vp.begin()+m});
      second=new Node({vp.begin()+m,
        vp.end()});
    }
  }
  };
  struct KDTree {
  Node* root;
  KDTree(const vector<Point>& vp):
    root(new Node({ALL(vp)})) {}
  pair<ll,Point> search(Point p, Node *node){
    if(!node->first){
      //avoid query point as answer
      //if(p==node->pp) {INF,Point()};
      return {(p-node->pp).dot(p-node->pp),
        node->pp};
    }
    Node *f=node->first, *s=node->second;
    ll bf=f->distance(p), bs=s->distance(p);
    if(bf>bs)swap(bf,bs),swap(f,s);
    auto best=search(p,f);
    if(bs<best.f) best=min(best,search(p,s));
    return best;
  }
  pair<ll,Point> nearest(Point p){
    return search(p,root);
  }
};