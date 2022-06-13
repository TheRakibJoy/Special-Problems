// https://toph.co/p/j-cheap-tourist
//starting with the name of almighty ALLAH
///Author - RakibJoy
// Practice is the only shortcut to improve
#include<bits/stdc++.h>
#define ll  long long
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
const int N=1e5;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}
const int sz=200005;
int sptab[sz][22],lvl[sz],par[sz];
void Init_LCA(int n)
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<22; j++)
            sptab[i][j]=-1;
    }
    for(int i=1 ; i<=n ; i++)
        sptab[i][0] = par[i];
    for(int j=1 ; (1<<j)<=n ; j++)
    {
        for(int i=1 ; i<=n ; i++)
        {
            if(sptab[i][j-1] != -1)
            {
                sptab[i][j] = sptab[sptab[i][j-1]][j-1];
            }
        }
    }
}
int get_LCA(int p,int q)
{
    if(lvl[p] < lvl[q])
        swap(p,q);
    int Log=log2(lvl[p])+1;
    for(int i=Log ; i>=0 ; i--)
    {
        if(lvl[p]-(1<<i) >= lvl[q])
            p = sptab[p][i];
    }
    if(p == q)
        return p;
    for(int i=Log ; i>=0 ; i--)
    {
        if(sptab[p][i]!=-1 && sptab[p][i]!=sptab[q][i])
        {
            p=sptab[p][i];
            q=sptab[q][i];
        }
    }
    return par[p];
}
vector<pair<int,int> > adj[sz];
int s[sz],m[sz];
ll pre[sz];
int cnt[sz];
void dfs(int n,int lv,int p)
{
    lvl[n]=lv;
    for(auto it:adj[n])
    {
        if(it.F==p)
            continue;
        par[it.F]=n;
        dfs(it.F,lv+1,n);
    }
}
void dfs2(int n,int p)
{
    for(auto it:adj[n])
    {
        if(p==it.F)
            continue;
        dfs2(it.F,n);
        pre[n]+=pre[it.F];
        cnt[it.S]+=pre[it.F];
    }
}
void solve()
{
    ll a;
    cin>>a;
    fr(i,1,a-1)
    {
        int x,y;
        cin>>x>>y;
        adj[x].pb({y,i});
        adj[y].pb({x,i});
        cin>>s[i]>>m[i];
    }
    dfs(1,0,-1);
    Init_LCA(a);
    fr(i,1,a-1)
    {
        ll l=get_LCA(i,i+1);
        pre[i]++;
        pre[i+1]++;
        pre[l]-=2;
    }
    dfs2(1,-1);
    ll an=0;
    fr(i,1,a-1)
    {
        if((ll)s[i]*cnt[i]<=m[i])
        {
            an+=s[i]*cnt[i];
        }
        else
            an+=m[i];
    }
    cout<<an<<endl;
    fr(i,0,a)
    {
        adj[i].clear();
        cnt[i]=0;
        pre[i]=0;
    }
}
int main()
{
    rj
    tst
    //int t;cin>>t;fr(i,1,t) cout<<"Case "<<i<<": ",solve();
    //ll t;scanf("%lld",&t);fr(i,1,t) printf("Case %lld: ",i),solve();
    solve();
    return 0;
}
