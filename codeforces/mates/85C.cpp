#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int P = 19;
const int mod = 1e9 + 7;
 
int n;
int mask[72];
ll f[2][72];
ll dp[2][1 << 20];
 
bool prime(int x)
{
	for (int i = 2; i*i <= x; i++)
		if (x%i == 0)
			return 0;
	return 1;
}
 
void init()
{
	for (int i = 0; i < 72; i++)
		f[0][i] = 1;
	int cnt = 0;
	for (int i = 2; i < 72; i++)
	{
		if (!prime(i))
			continue;
		for (int j = 1; j < 72; j++)
		{
			int x = j;
			while (x%i == 0)
			{
				x /= i;
				mask[j] ^= (1 << cnt);
			}
		}
		cnt++;
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	init();
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		f[0][x] = f[1][x] = (f[0][x] + f[1][x]) % mod;
	}
	dp[0][0] = 1;
	for (int i = 0; i <= 70; i++)
	{
		int nxt = (i + 1) % 2;
		int cur = i % 2;
		for (int msk = 0; msk < (1<<20); msk++)
		{
			dp[nxt][msk^mask[i]] = dp[nxt][msk^mask[i]] + dp[cur][msk] * f[1][i];
			dp[nxt][msk] = dp[nxt][msk] + dp[cur][msk] * f[0][i];
			if (dp[nxt][msk^mask[i]] >= mod)
				dp[nxt][msk^mask[i]] %= mod;
			if (dp[nxt][msk] >= mod)
				dp[nxt][msk] %= mod;
		}
		for (int msk = 0; msk < (1<<20); msk++)
			dp[cur][msk] = 0;
	}
	cout << (dp[1][0] - 1 + mod)%mod << endl;
}