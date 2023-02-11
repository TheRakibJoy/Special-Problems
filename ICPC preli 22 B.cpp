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
const int N=1e7;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}
int prime[N+5];
void primenire()
{
    int i, j;
    for(i=2; i<=N; i+=2)
    {
        prime[i]=2,prime[i-1]=i-1;
    }
    for(i=3; i*i<=N; i+=2)
    {
        if(prime[i]==i)
        {
            for(j=i*i; j<=N; j+=2*i)
            {
                if(prime[j]==j)
                {
                    prime[j]=i;
                }
            }
        }
    }
}
int ase[N+2];
void ini(int x)
{
    while(x!=1)
    {
        int f=prime[x];
        ase[f]=1;
        while(x%f==0) x/=f;
    }
}
void bad(int x)
{
    while(x!=1)
    {
        int f=prime[x];
        ase[f]=0;
        while(x%f==0) x/=f;
    }
}
bool chk(int x)
{
    while(x!=1)
    {
        int f=prime[x];
        if(!ase[f]) return 0;
        while(x%f==0) x/=f;
    }
    return 1;
}
void solve()
{
    int a;
    cin>>a;
    vi v(a),vv(a);
    cinv(v)
    cinv(vv)
    for(auto it:v)
    {
        ini(it);
    }
    int al=1;
    for(int i=0;i<a;i++)
    {
        int g=gcd(v[i],vv[i]);
        g=vv[i]/g;
        if(!chk(g))
        {
            al=0;
            break;
        }
    }
    for(auto it:v)
    {
        bad(it);
    }
    if(al) cout<<"Yes ";
    else cout<<"No ";
    int gg=0;
    for(auto it:v) gg=gcd(gg,it);
    ini(gg);
    int add=-1,baad=-1;
    int bb=1;
    for(int i=0;i<a;i++)
    {
        int g=gcd(v[i],vv[i]);
        int ad=vv[i]/g;
        int ba=v[i]/g;
        if(!chk(ad)||!chk(ba))
        {
            bb=0;
            break;
        }
        if(add==-1)
        {
            add=ad;
            baad=ba;
        }
        else
        {
            if(add!=ad||baad!=ba)
            {
                bb=0;
                break;
            }
        }
    }
    bad(gg);
    if(bb) cout<<"Yes"<<nl;
    else cout<<"No"<<nl;
}
int main()
{
    rj
    primenire();
    int t;cin>>t;fr(i,1,t) cout<<"Case "<<i<<": ",solve();
    //ll t;scanf("%lld",&t);fr(i,1,t) printf("Case %lld: ",i),solve();
    //solve();
    return 0;
}
