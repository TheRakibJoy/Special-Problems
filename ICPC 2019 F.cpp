//starting with the name of almighty ALLAH
// Practice is the only shortcut to improve
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define vc vector
#define vi vc<int>
#define vl vc<ll>
#define dbg(x) cerr<<x<<endl;
#define mp(x,y) make_pair(x,y)
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define tst int t;cin>>t;while(t--)
#define srt(v) sort(v.begin(),v.end());
#define rsrt(v) sort(v.rbegin(),v.rend());
#define rj ios::sync_with_stdio(false);cin.tie(0);
#define rvs(v) reverse(v.begin(),v.end());
#define F first
#define S second
#define MOD 132021913
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define PI 2*acos(0.0)
#define pii pair<int,int>
#define fr(i,a,b) for(ll i=a;i<=b;i++)
#define coutv(v) for(auto it:v)cout<<it<<' ';cout<<endl;
#define cinv(v) for(auto &it:v)cin>>it;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define ld long double
#define nl '\n'
const int N = 1e5;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}
int BigMod(long long p, long long q, const int mod)
{
    int ans = 1 % mod;
    p %= mod;
    if (p < 0)
        p += mod;
    while (q)
    {
        if (q & 1)
            ans = (long long) ans * p % mod;
        p = (long long) p * p % mod;
        q >>= 1;
    }
    return ans;
}
void solve()
{
    int a;
    scanf("%d", &a);
    vl sum(N + 1), sop(N + 1);
    for (int p = 1; p <= a; p++)
    {
        int x;
        scanf("%d", &x);
        for (int i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                sop[i] += (sum[i] * x) % MOD;
                sop[i] %= MOD;
                sum[i] += x;
                sum[i] %= MOD;
                if (i * i != x)
                {
                    sop[x / i] += (sum[x / i] * x) % MOD;
                    sop[x / i] %= MOD;
                    sum[x / i] += x;
                    sum[x / i] %= MOD;
                }
            }
        }
    }
    ll an = 0;
    for (int i = N; i >= 1; i--)
    {
        for (int j = 2 * i; j <= N; j += i)
        {
            sop[i] -= sop[j];
            sop[i] %= MOD;
            if (sop[i] < 0) sop[i] += MOD;
        }
        an += (sop[i] * BigMod(i, MOD - 2, MOD)) % MOD;
        an %= MOD;
    }
    printf("%lld\n", an);
}
int main()
{
    ///rj
    //int t;cin>>t;fr(i,1,t) cout<<"Case "<<i<<": ",solve();
    ll t; scanf("%lld", &t); fr(i, 1, t) printf("Case %lld: ", i), solve();
    //solve();
    return 0;
}
