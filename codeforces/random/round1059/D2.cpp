#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> sum, mul;
ll att,n,p,h;

int main() {
    cin >> n >> p >> h;
    char c;
    for (int i=0;i<n;i++) {
        cin >> c;
        if (c=='*') {
            int x;
            cin >> x;
            mul.push_back(x);
        } else if (c=='+') {
            int x;
            cin >> x;
            sum.push_back(x);
        } else {
            att++;
        }
    }
    if (att==0) {
        cout << "*\n";
        return 0;
    }
    bool multi = false;
    for (auto u : mul) if (u>1) multi = true;
    if (p==0 && sum.size()==0) {
        cout <<"*\n";
        return 0;
    }
    ll suma = 0;
    for (auto u : sum) suma += u;
    ll L = 0;
    ll _p = 0;
    ll H = h;
    if (!multi) {
        // aqui no crece exponencialmente
        ll l = 0;
        ll r = h;
        _p = p;
        while (l+1 < r) {
            ll mit = (l+r)/2;
            ll _h = h;
            if (mit*p >= _h) {
                r = mit;
            } else {
                if (mit*p*att >= _h) {
                    r = mit;
                } else {
                    _h -= mit*p*att;
                    ll z = mit*(mit+1);
                    z /= 2;
                    if (_h <= z) {
                        r = mit;
                    } else {
                        z *= att;
                        if (_h <= z) {
                            r = mit;
                        } else {
                            z *= suma;
                            if (_h <= z) {
                                r = mit;
                            } else {
                                l = mit;
                            }
                        }
                    }
                }
            }
        }
        // nos quedamos con l
        L = l;
        p = _p + L*suma;
        H = h - p*L*att - suma*att*((L*(L+1))/2);
    } else {
        ll _h = h;
        L = 0;
        H = h;
        while (_h > 0) {
            _p = p;
            p += suma;
            for (auto u : mul) {
                p *= u;
                if (p>=_h) {
                    _h = 0;
                    p=0;
                }
            }
            _h -= p*att;
            if (_h>0) {
                H -= p*att;
                L++;
            }
        }
        p = _p;
    } 
    sort(sum.begin(),sum.end());
    reverse(sum.begin(),sum.end());
    sort(mul.begin(),mul.end());
    reverse(mul.begin(),mul.end());
    ll ans = n;
    for (ll i=0;i<=n-att;i++) {
        for (ll j=0;j<=i;j++) {
            if (j<=sum.size() && i-j<=mul.size()) {
                ll P = p;
                                    for (ll q=1;q<=att;q++) if (P*q>=H) {
                        ans = min(ans, i+q);
                    }
                for (ll k=1;k<=j;k++) {
                    P += sum[k-1];
                    for (ll q=1;q<=att;q++) if (P*q>=H) {
                        ans = min(ans, i+q);
                    }
                }

                for (ll k=1;k<=i-j;k++) {
                    P *= mul[k-1];
                    for (ll q=1;q<=att;q++) if (P*q>=H) {
                        ans = min(ans, i+q);
                    }
                }
                
                
            }
        }
    }
    cout << ans+n*L<<"\n";
    return 0;
}