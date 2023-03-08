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
#define MOD 1000000007
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
const int N = 2e4 + 5;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}
int a;
vector<pair<int, int>>adj[N];
priority_queue<pair<ll, int>>pq;
int sz[N];
ll tot = 0;
void dfs(int n, int p)
{
    sz[n] = 1;
    for (auto it : adj[n])
    {
        if (it.F == p) continue;
        dfs(it.F, n);
        sz[n] += sz[it.F];
        ll w = (ll)sz[it.F] * (a - sz[it.F]);
        tot += w * it.S;
        if (it.S < 0)
        {
            pq.push(mp(w, it.S));
        }
    }
}
void solve()
{
    scanf("%d", &a);
    for (int i = 2; i <= a; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        adj[x].pb({y, z});
        adj[y].pb({x, z});
    }
    tot = 0;
    dfs(1, 1);
    ll an = 0;
    while (tot < 0)
    {
        auto x = pq.top();
        pq.pop();
        ll lagbe = (-tot + x.F - 1) / x.F;
        ll som = -x.S;
        som = min(som, lagbe);
        an += som;
        tot += x.F * som;
    }
    printf("%lld\n", an);
    while (!pq.empty()) pq.pop();
    for (int i = 1; i <= a; i++) adj[i].clear();
}
int main()
{
    //rj
    //int t;cin>>t;fr(i,1,t) cout<<"Case "<<i<<": ",solve();
    ll t; scanf("%lld", &t); fr(i, 1, t) printf("Case %lld: ", i), solve();
    //solve();
    return 0;
}
