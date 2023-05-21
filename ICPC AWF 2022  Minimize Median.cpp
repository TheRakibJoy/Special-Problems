//starting with the name of almighty ALLAH
// Practice is the only shortcut to improve
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define vc vector
#define vi vc<int>
#define vl vc<ll>
#define mp(x,y) make_pair(x,y)
#define yes cout<<"YES"<<'\n';
#define no cout<<"NO"<<'\n';
#define tst int t;cin>>t;while(t--)
#define srt(v) sort(v.begin(),v.end());
#define rsrt(v) sort(v.rbegin(),v.rend());
#define rj ios::sync_with_stdio(false);cin.tie(0);
#define rvs(v) reverse(v.begin(),v.end());
#define F first
#define S second
#define MOD 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define PI 2*acos(0.0)
#define pii pair<int,int>
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define coutv(v) for(auto it:v)cout<<it<<' ';cout<<endl;
#define cinv(v) for(auto &it:v)cin>>it;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define ld long double
#define nl '\n'
const int N = 1e6;
using namespace std;
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(x...)
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r)
{
	return uniform_int_distribution<int>(l, r) (rng);
}
int prime[N + 5];
void primenire()
{
	int i, j;
	prime[0] = true;
	prime[1] = true;
	for (i = 2; i <= N; i += 2)
	{
		prime[i] = 2, prime[i - 1] = i - 1;
	}
	for (i = 3; i * i <= N; i += 2)
	{
		if (prime[i] == i)
		{
			for (j = i * i; j <= N; j += 2 * i)
			{
				if (prime[j] == j)
					prime[j] = i;
			}
		}
	}
}
void gen(int cr, int in, vector<pii>&vv, vi &v)
{
	if (in == vv.size())
	{
		v.push_back(cr);
		return;
	}
	gen(cr, in + 1, vv, v);
	for (int i = 1; i <= vv[in].S; i++)
	{
		cr *= vv[in].F;
		gen(cr, in + 1, vv, v);
	}
}
void gdv(int x, vector<int>&v)
{
	vector<pair<int, int>>vv;
	v.clear();
	while (x > 1)
	{
		int p = prime[x];
		int cnt = 0;
		while (x % p == 0)
		{
			x /= p;
			cnt++;
		}
		vv.push_back({p, cnt});
	}
	gen(1, 0, vv, v);
}
int how(int x, int y)
{
	int lo = 1, hi = (y + x - 1) / x;
	while (lo < hi)
	{
		int mid = (lo + hi) >> 1;
		if (y / mid <= x) hi = mid;
		else lo = mid + 1;
	}
	return hi;
}
void solve()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vector<int>v(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}
	srt(v)
	vector<int>dp(m + 2);
	for (int i = 1; i <= m + 1; i++)
	{
		if (i <= m)
			scanf("%d", &dp[i]);
		else dp[i] = INT_MAX;
	}
	dp[1] = 0;
	vector<int>d;
	for (int i = 2; i <= m; i++)
	{
		gdv(i, d);
		for (auto it : d)
		{
			if (it == 1 || it == i)
			{
				continue;
			}
			dp[i] = min(dp[i], dp[it] + dp[i / it]);
		}
	}
	for (int i = m - 1; i >= 1; i--)
	{
		dp[i] = min(dp[i], dp[i + 1]);
	}
	for (int i = 2; i <= m; i++)
	{
		int l = (m + 1 + i - 1) / i;
		dp[m + 1] = min(dp[m + 1], dp[l] + dp[i]);
	}
	for (int i = m; i >= 1; i--)
	{
		dp[i] = min(dp[i], dp[i + 1]);
	}
	int lo = 1, hi = m;
	while (lo < hi)
	{
		int mid = (lo + hi) >> 1;
		int cnt = 0;
		vector<int>cst;
		for (int i = 0; i < n; i++)
		{
			if (v[i] <= mid) cnt++;
			else
			{
				int l = how(mid, v[i]);
				cst.push_back(dp[l]);
			}
		}
		int req = (n + 1) / 2 - cnt;
		if (req <= 0)
		{
			hi = mid;
			continue;
		}
		srt(cst);
		ll now = 0;
		for (int i = 0; i < req; i++)
		{
			now += cst[i];
		}
		if (now <= k) hi = mid;
		else lo = mid + 1;
	}
	{
		vector<int>cst;
		for (int i = 0; i < n; i++)
		{
			int l = v[i] + 1;
			cst.push_back(dp[l]);
		}
		srt(cst);
		ll now = 0;
		for (int i = 0; i < (n + 1) / 2; i++)
		{
			now += cst[i];
		}
		if (now <= k) hi = 0;
	}
	printf("%d\n", hi);
}
int main()
{
	//rj
	primenire();
	int t;
	scanf("%d", &t);
	while (t--)
		//int t;cin>>t;fr(i,1,t) cout<<"Case "<<i<<": ",solve();
		//ll t;scanf("%lld",&t);fr(i,1,t) printf("Case %lld: ",i),solve();
		solve();
	return 0;
}
