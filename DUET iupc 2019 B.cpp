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
const int N=1e6;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}
bool prime[N+5];
void primenire()
{
    int i, j;
    prime[0]=true;
    prime[1]=true;
    for(i=4; i<=N; i+=2)
    {
        prime[i]=true;
    }
    for(i=3; i*i<=N; i+=2)
    {
        if(!prime[i])
        {
            for(j=i*i; j<=N; j+=2*i)
            {
                prime[j]=true;
            }
        }
    }
}
vi p;
struct monotonic_queue
{
    deque<pair<int,int> >dq;
    void add(int val,int in)
    {
        while(!dq.empty()&&dq.back().first>=val) //strictly increasing order
            dq.pop_back();
        dq.push_back({val,in});
    }
    void del(int in)
    {
        if(!dq.empty() && dq.front().second==in)
            dq.pop_front();
    }
    int query()
    {
        if(dq.empty())
            return 1e7;
        return dq.front().first;
    }
};
monotonic_queue mq[N];
void up(int a,int val,int in)
{
    for(auto it:p)
    {
        if(it*it>a) break;
        if(a%it==0)
        {
            mq[it].add(val,in);
            while(a%it==0) a/=it;
        }
    }
    if(a)
    {
        mq[a].add(val,in);
    }
}
void del(int a,int in)
{
    for(auto it:p)
    {
        if(it*it>a) break;
        if(a%it==0)
        {
            mq[it].del(in);
            while(a%it==0) a/=it;
        }
    }
    if(a)
    {
        mq[a].del(in);
    }
}
int ga(int a)
{
    int an=1e7;
    int pr=a;
    for(auto it:p)
    {
        if(it*it>a) break;
        if(a%it==0)
        {
            an=min(an,mq[it].query());
            while(a%it==0) a/=it;
        }
    }
    if(a>1)
    {
        an=min(an,mq[a].query());
    }
    return an;
}
void solve()
{
    int n,k;
    scanf("%d%d",&n,&k);
    vi v(n+1);
    fr(i,1,n)
    {
       cin>>v[i];
    }
    vi dp(n+1,INT_MAX);
    dp[n]=0;
    up(v[n],0,n);
    for(int in=n-1;in>=1;in--)
    {
        dp[in]=min(dp[in],1+dp[in+1]);
        dp[in]=min(dp[in],1+ga(v[in]));
        up(v[in],dp[in],in);
        if(in+k<=n)
        {
            del(v[in+k],in+k);
        }
    }
    for(int in=n;in>=1;in--)
    {
        del(v[in],in);
    }
    printf("%d\n",dp[1]);
}
int main()
{
    //int t;cin>>t;fr(i,1,t) cout<<"Case "<<i<<": ",solve();
    primenire();
    fr(i,1,N)
    {
        if(!prime[i])
            p.pb(i);
    }
    ll t;
    scanf("%lld",&t);
    fr(i,1,t) printf("Case %lld: ",i),solve();
    return 0;
}
