#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,p,w,d,x,y,z;
signed main(){
	cin>>n>>p>>w>>d;
	for(y=0;y<w;++y){
		int sum=p-y*d;
		if(sum%w==0){
			x=sum/w;
			z=n-x-y;
			if(x>=0&&z>=0){
				cout<<x<<' '<<y<<' '<<z;
			}else{
				cout<<-1;
			}
			return 0;
		}
	}
	cout<<-1;
	return 0;
}
