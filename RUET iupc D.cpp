//starting with the name of almighty ALLAH
///Author - RakibJoy
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
const int N=1e5;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}
struct DSU
{
    vector<int>par,sz;
    DSU(int n)
    {
        par.assign(n+1,0);
        sz.assign(n+1,1);
        for(int i=1; i<=n; i++)
            par[i]=i;
    }
    int get_parent(int n)
    {
        if(par[n]==n)
            return n;
        return par[n]=get_parent(par[n]);
    }
    void union_set(int x,int y)
    {
        x=get_parent(x);
        y=get_parent(y);
        if(x!=y)
        {
            if(sz[x]<sz[y])
                swap(x,y);
            par[y]=x;
            sz[x]+=sz[y];
            sz[y]=0;
        }
    }
    int get_size(int n)
    {
        return sz[get_parent(n)];
    }
};
void solve()
{
    int a;
    cin>>a;
    DSU d(a);
    ll an=0;
    for(int i=a; i>=1; i--)
    {
        for(int j=i; j<=a; j+=i)
        {
            if(d.get_parent(i)!=d.get_parent(j))
            {
                an+=i;
                d.union_set(i,j);
            }
        }
    }
    cout<<an<<endl;
}
int main()
{
    rj
    int t;
    cin>>t;
    fr(i,1,t) cout<<"Case "<<i<<": ",solve();
    //ll t;scanf("%lld",&t);fr(i,1,t) printf("Case %lld: ",i),solve();
    return 0;
}
