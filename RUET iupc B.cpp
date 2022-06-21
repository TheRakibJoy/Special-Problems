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
struct Stree
{
#define lf (nd << 1)
#define rt ((nd << 1) | 1)
    long long t[4 * N], lazy[4 * N];
    Stree()
    {
        memset(t, 0, sizeof t);
        memset(lazy, 0, sizeof lazy);
    }
    inline void push(int nd, int lo, int hi)
    {
        if (lazy[nd] == INT_MAX)
            return;
        t[nd] = min(t[nd], lazy[nd] );
        if (lo != hi)
        {
            lazy[lf] = min(lazy[lf], lazy[nd]);
            lazy[rt] = min(lazy[rt], lazy[nd]);
        }
        lazy[nd] = INT_MAX;;
    }
    inline long long milao(long long x,long long y)
    {
        return min(x, y);
    }
    inline void uthao(int nd)
    {
        t[nd] = min(t[lf], t[rt]);
    }
    void build(int nd, int lo, int hi)
    {
        lazy[nd] = INT_MAX;
        if (lo == hi)
        {
            t[nd] = lo;
            return;
        }
        int mid = (lo + hi) >> 1;
        build(lf, lo, mid);
        build(rt, mid + 1, hi);
        uthao(nd);
    }
    void update(int nd, int lo, int hi, int i, int j, long long val)
    {
        push(nd, lo, hi);
        if (j < lo || hi < i)
            return;
        if (i <= lo && hi <= j)
        {
            lazy[nd] = val; //set lazy
            push(nd, lo, hi);
            return;
        }
        int mid = (lo + hi) >> 1;
        update(lf, lo, mid, i, j, val);
        update(rt, mid + 1, hi, i, j, val);
        uthao(nd);
    }
    long long query(int nd, int lo, int hi, int i, int j)
    {
        push(nd, lo, hi);
        if (i > hi || lo > j)
            return INT_MAX;
        if (i <= lo && hi <= j)
            return t[nd];
        int mid = (lo + hi) >> 1;
        return milao(query(lf, lo, mid, i, j), query(rt, mid + 1, hi, i, j));
    }
};
ll pre[100005][64];
unsigned ll v[100005];
Stree t;
void solve()
{
    ll a,b;
    cin>>a>>b;
    memset(v,0,sizeof v);
    memset(pre,0,sizeof pre);
    t.build(1,1,a);
    while(b--)
    {
        ll l,r;
        cin>>l>>r;
        t.update(1,1,a,l,r,l);
    }
    fr(i,1,a)
    {
        ll l=t.query(1,1,a,i,i)-1;
        for(int j=0; j<64; j++)
        {
            if(pre[i-1][j]-pre[l][j]==0)
            {
                v[i]|=(1ULL<<j);
                pre[i][j]++;
                break;
            }
        }
        for(int j=0; j<64; j++)
        {
            pre[i][j]+=pre[i-1][j];
        }
        if(v[i]==0)
        {
            cout<<"Impossible"<<endl;
            return;
        }
    }
    fr(i,1,a-1) cout<<v[i]<<' ';
    cout<<v[a]<<endl;
}
int main()
{
    rj
    int t;
    cin>>t;
    fr(i,1,t) cout<<"Case "<<i<<":"<<endl,solve();
    //ll t;scanf("%lld",&t);fr(i,1,t) printf("Case %lld: ",i),solve();
    return 0;
}
