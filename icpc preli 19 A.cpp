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
const int N=1200005;
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

const int MOD1 = 127657753, MOD2 = 987654319;
const int b1 = 141, b2 = 277;
int inp1, inp2;
pair<int, int> pw[N], inpw[N];
//Template from YouKnow
void precalc()
{
    pw[0] =  {1, 1};
    for (int i = 1; i < N; i++)
    {
        pw[i].first = 1LL * pw[i - 1].first * b1 % MOD1;
        pw[i].second = 1LL * pw[i - 1].second * b2 % MOD2;
    }
    inp2 = BigMod(b2, MOD2 - 2, MOD2);
    inp1 = BigMod(b1, MOD1 - 2, MOD1);
    inpw[0] =  {1, 1};
    for (int i = 1; i < N; i++)
    {
        inpw[i].first = 1LL * inpw[i - 1].first * inp1 % MOD1;
        inpw[i].second = 1LL * inpw[i - 1].second * inp2 % MOD2;
    }

}
struct Hashing
{
    int sz;
    string s; // 0 - indexed string
    vector<pair<int, int>> h_tab; // 1 - indexed vector
    Hashing() {}
    Hashing(string _ss)
    {
        sz = _ss.size();
        s = _ss;
        h_tab.emplace_back(0, 0);
        for (int i = 0; i < sz; i++)
        {
            pair<int, int> p;
            p.first = (h_tab[i].first + 1LL * pw[i].first * s[i] % MOD1) % MOD1;
            p.second = (h_tab[i].second + 1LL * pw[i].second * s[i] % MOD2) % MOD2;
            h_tab.push_back(p);
        }
    }
    pair<int, int> ghv(int lo, int hi)   // 1 - indexed
    {
        assert(1 <= lo && lo <= hi && hi <= sz);
        pair<int, int> ans;
        ans.first = (h_tab[hi].first - h_tab[lo - 1].first + MOD1) * 1LL * inpw[lo - 1].first % MOD1;
        ans.second = (h_tab[hi].second - h_tab[lo - 1].second + MOD2) * 1LL * inpw[lo - 1].second % MOD2;
        return ans;
    }
    pair<int, int> ghv()
    {
        return ghv(1, sz);
    }
};
string s,ss;
int k;
void solve()
{
    cin>>s>>ss>>k;
    Hashing h(s),hh(ss);
    ll a=s.size(),b=ss.size();
    ll an=0;
    fr(i,1,a-b+1)
    {
        ll l=i,r=i+b-1,oc=0,p=1;
        while(l<=r&&oc<=k)
        {
           if(h.ghv(l,r)==hh.ghv(p,b)) break;
           ll lo=l,hi=r;
           while(lo<hi)
           {
               ll mid=(lo+hi)>>1;
               if(h.ghv(l,mid)!=hh.ghv(p,p+mid-l)) hi=mid;
               else lo=mid+1;
           }
           oc++;
           p+=hi-l+1;
           l=hi+1;
        }
        if(oc<=k) an++;
    }
    cout<<an<<endl;
}
int main()
{
    rj
    precalc();
    int t;
    cin>>t;
    fr(i,1,t) cout<<"Case "<<i<<": ",solve();
    //ll t;scanf("%lld",&t);fr(i,1,t) printf("Case %lld: ",i),solve();
    return 0;
}
