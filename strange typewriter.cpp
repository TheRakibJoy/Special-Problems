// problem link -https://algo.codemarshal.org/contests/icpc-dhaka-20-preli/problems/G
/*starting with the name of almighty ALLAH*/
/*solved by RAKIB JOY*/
// Practice is the only shortcut to improve
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define vc vector
#define vi vc<int>
#define vl vc<ll>
#define dbg(x) cout<<x<<endl;
#define mp(x,y) make_pair(x,y)
#define yes dbg("YES")
#define no dbg("NO")
#define tst int t;cin>>t;while(t--)
#define srt(v) sort(v.begin(),v.end());
#define rsrt(v) sort(v.rbegin(),v.rend());
#define rj ios::sync_with_stdio(false);cin.tie(0);
#define rvs(v) reverse(v.begin(),v.end());
#define F first
#define S second
#define MOD 9996751
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
const int N=1e5+5;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------
int power(long long n, long long k, const int mod)
{
    int ans = 1 % mod;
    n %= mod;
    if (n < 0)
        n += mod;
    while (k)
    {
        if (k & 1)
            ans = (long long) ans * n % mod;
        n = (long long) n * n % mod;
        k >>= 1;
    }
    return ans;
}

const int MOD1 = 1002487, MOD2 = 1002583;
const int p1 = 141, p2 = 277;
int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec()
{
    pw[0] =  {1, 1};
    for (int i = 1; i < N; i++)
    {
        pw[i].first = 1LL * pw[i - 1].first * p1 % MOD1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % MOD2;
    }
    ip1 = power(p1, MOD1 - 2, MOD1);
    ip2 = power(p2, MOD2 - 2, MOD2);
    ipw[0] =  {1, 1};
    for (int i = 1; i < N; i++)
    {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % MOD1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % MOD2;
    }

}
struct Hashing
{
    int n;
    string s; // 0 - indexed
    vector<pair<int, int>> hs; // 1 - indexed
    Hashing() {}
    Hashing(string _s)
    {
        n = _s.size();
        s = _s;
        hs.emplace_back(0, 0);
        for (int i = 0; i < n; i++)
        {
            pair<int, int> p;
            p.first = (hs[i].first + 1LL * pw[i].first * s[i] % MOD1) % MOD1;
            p.second = (hs[i].second + 1LL * pw[i].second * s[i] % MOD2) % MOD2;
            hs.push_back(p);
        }
    }
    pair<int,int> get_hash(int l, int r)   // 1 - indexed
    {
        assert(1 <= l && l <= r && r <= n);
        pair<int, int> ans;
        ans.first = (hs[r].first - hs[l - 1].first + MOD1) * 1LL * ipw[l - 1].first % MOD1;
        ans.second = (hs[r].second - hs[l - 1].second + MOD2) * 1LL * ipw[l - 1].second % MOD2;
        return ans;
    }
    pair<int,int> get_hash()
    {
        return get_hash(1, n);
    }
};
struct custom_hash
{
    size_t operator()(const pair<int,int>&x)const
    {
        return ((long long)x.first)^(((long long)x.second)<<32);
    }
};
int m[1002487],m1[1002583];
int dp[N];
int sz;
vi ul;
Hashing hh;
int goriberDP(int in)
{
    if(in>=sz)
        return 0;
    if(~dp[in])
        return dp[in];
    int an=sz+1;
    for(auto x:ul)
    {
        if(in+x>sz)
            break;
        auto val=hh.get_hash(in+1,in+x);
        if(m[val.F]==val.S||m1[val.S]==val.F)
        {
            an=min(an,1+goriberDP(in+x));
        }
    }
    return dp[in]=an;
}
int cs=1;
char ss[N];
void solve()
{
    int n;
    scanf("%d",&n);
    set<int>st;
    memset(m,-1,sizeof m);
    memset(m1,-1,sizeof m1);
    fr(i,1,n)
    {
        string s;
        scanf("%s",ss);
        int ln=strlen(ss);
        fr(i,0,ln-1) s+=ss[i];
        auto hs=Hashing(s).get_hash();
        m[hs.F]=hs.S;
        m1[hs.S]=hs.F;
        st.insert(s.size());

    }
    for(auto i:st)
        ul.pb(i);
    string s;
    scanf("%s",ss);
    int ln=strlen(ss);
    fr(i,0,ln-1) s+=ss[i];
    Hashing h(s);
    hh=h;
    sz=s.size();
    fr(i,0,sz) dp[i]=-1;
    int an=goriberDP(0);
    if(an>=sz+1)
    {
        printf("Case %d: ",cs++);
        printf("impossible\n");
    }
    else
    {
        printf("Case %d: %d\n",cs++,an);
    }
    ul.clear();
}

int main()
{
    prec();
    int t;
    scanf("%d",&t);
    fr(i,1,t) solve();
    return 0;
}
