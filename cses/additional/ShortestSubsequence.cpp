#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s; cin>>s;
    int l = 0, r = 0;
    bool a = 0, b = 0, c = 0, d = 0;
    int n = s.size();
    string ans;
    while(l < n) {
        a = 0, b = 0, c = 0, d = 0;
        a += (s[l] == 'A'); b += (s[l] == 'C');
        c += (s[l] == 'G'); d += (s[l] == 'T');
        r = l+1;
        while(r < n && a+b+c+d != 4) {
            a += (s[r] == 'A'); b += (s[r] == 'C');
            c += (s[r] == 'G'); d += (s[r] == 'T');
            r++;
        }
        if (a+b+c+d == 4)
            ans += s[r-1];
        l = r;
    }

    if (a+b+c+d == 4)
        ans += 'A';
    else if (!a) ans += 'A';
    else if (!b) ans += 'C';
    else if (!c) ans += 'G';
    else if (!d) ans += 'T';
    cout<<ans;
}