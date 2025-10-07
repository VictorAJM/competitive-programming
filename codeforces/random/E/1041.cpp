#include<bits/stdc++.h>

using namespace std;

const int N = 200043;

int cnt[N];

int main()
{                
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if(y != n)
		{
			puts("NO");
			return 0;
		}
		cnt[x]++;
	}
	int cur = 0;
	for(int i = 1; i < n; i++)
	{
		cur += cnt[i];
		if(cur > i)
		{
			puts("NO");
			return 0;
		}
	}
	int last = -1;
	puts("YES");
	set<int> unused;
	for(int i = 1; i < n; i++)
		unused.insert(i);
	for(int i = 1; i < n; i++)
	{
		if(cnt[i] > 0)
		{
			unused.erase(i);
			if(last != -1)
				printf("%d %d\n", last, i);
			last = i;
			cnt[i]--;
		}
		while(cnt[i] > 0)
		{
			printf("%d %d\n", last, *unused.begin());
			last = *unused.begin();
			cnt[i]--;
			unused.erase(unused.begin());
		}
	}
	printf("%d %d\n", last, n);
}