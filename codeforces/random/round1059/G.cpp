#include<bits/stdc++.h>
using namespace std;

map<pair<long long, long long>, long long> mqun;
set<long long> range_s;
set<long long> range_e;

void f(long long l, long long r, long long V){
    bool el = false;
    long long L;
    auto it = range_s.upper_bound(l-1); 
    if(it==range_s.begin()) return;
    it--;
    auto it3 = range_e.lower_bound((*it));
    if((*it3)==l-1 && V == mqun[{(*it), l-1}]){
        el = true;
        L = (*it);
    }
    if(el){
        mqun.erase({l,r});
        mqun.erase({L, l-1});
        mqun[{L,r}] = V;
        range_s.erase(l);
        range_e.erase(l-1);
    }
}
void f2(long long l, long long r, long long V){
    long long R;
    bool er = false;
    auto it2 = range_s.lower_bound(r+1);
    if(it2==range_s.end()) return;
    auto it3 = range_e.upper_bound((*it2));
    it3--;
    if((*it3)==r+1 && V == mqun[{r+1, (*it2)}]){
        er = true;
        R = (*it2);
    }

    if(er){
        mqun.erase({l,r});
        mqun.erase({r+1, R});
        mqun[{l,R}] = V;
        range_e.erase(r);
        range_s.erase(r+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    mqun[{1,2e18}]=0;
    range_s.insert(1);
    range_e.insert(2e18);
    int q; cin>>q;
    while(q--){
        char z; cin>>z;
        long long v, l, r; cin>>v>>l;
        if(z == '-') { r = l + v - 1; v = 1; } 
        else r = l;
        auto it = range_s.upper_bound(l);
        it--;
        auto it2 = range_e.lower_bound((*it));
      //  cout<<l<<" "<<r<<"\n";
        if((*it)==l && (*it2)==r){
            cout<<"S";
            long long V = mqun[{l, r}] + v;
            mqun[{l, r}] = V;
            bool el = false;
            long long L, R;
            if(it != range_s.begin()){
                it--;
                auto it3 = range_e.lower_bound((*it));
                if((*it3)==l-1 && V == mqun[{(*it), l-1}]){
                    el = true;
                    L = (*it);
                }
            }
            bool er = false;
            if(it2 != range_e.end()){
                it2++;
                auto it3 = range_s.upper_bound((*it2));
                it3--;
                if((*it3)==r+1 && V == mqun[{r+1, (*it2)}]){
                    er = true;
                    R = (*it2);
                }
            }
            if(el){
                mqun.erase({l,r});
                mqun.erase({L, l-1});
                if(!er) mqun[{L,r}] = V;
                range_s.erase(l);
                range_e.erase(l-1);
            }
            if(er){
                mqun.erase({l,r});
                mqun.erase({r+1, R});
                if(el) mqun[{L,R}] = V;
                else mqun[{l,R}] = V;
                range_e.erase(r);
                range_s.erase(r+1);
            }
        }else if((*it)<=l && (*it2)>=r){
            cout<<"S";
            long long L = (*it), R = (*it2);
            long long V = mqun[{L, R}];
            mqun.erase({L, R});
            if(L <= l-1) mqun[{L, l-1}] = V;
            mqun[{l, r}] = V+v;
            if(r+1<=R) mqun[{r+1, R}] = V;
            range_s.insert(l);
            if(l>L) range_e.insert(l-1);
            range_e.insert(r);
            if(r<R) range_s.insert(r+1);
            if(l==L) f(l,r,V+v);
            else if(R==r) f2(l,r,V+v);
        }else{
            cout<<"U";
        }
 /*       cout<<"\n";
        for(auto ratata: range_s) cout<<ratata<<" ";
        cout<<"\n";
        for(auto ratata: range_e) cout<<ratata<<" ";*/
    }
    cout<<"\n";

    return 0;
}